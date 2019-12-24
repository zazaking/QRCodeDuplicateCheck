//******************************************************************************
#include "zzh_tcpcontrol.h"
//******************************************************************************
//构造函数
zzh_TCPControl::zzh_TCPControl()
{
    TCPControl_TCPServerInit();
    setTCPControl_QueryMode(TCPControl_QueryMode_QuerySave);
}
//析构函数
zzh_TCPControl::~zzh_TCPControl()
{
    TCPControl_TCPServerDestroy();
}
//******************************************************************************
//TcpServer_初始化服务器
void zzh_TCPControl::TCPControl_TCPServerInit(void)
{
    m_TCPServer = nullptr;
    m_TCPServerSocket = nullptr;
    m_TCPServer = new QTcpServer();

    QObject::connect(m_TCPServer,&QTcpServer::newConnection,this,&zzh_TCPControl::TCPControl_TCPServerNewConnect);
    if(!m_TCPServer->listen(QHostAddress::Any,1229)) {
        qDebug()<<m_TCPServer->errorString();
        return;
    }
}
//TcpServer_关闭服务器
void zzh_TCPControl::TCPControl_TCPServerDestroy()
{
    if(m_TCPServerSocket!=nullptr){
        m_TCPServerSocket->close();
    }
    if(m_TCPServer!=nullptr){
        m_TCPServer->close();
    }
}
//TcpServer_客户端连接回调
void zzh_TCPControl::TCPControl_TCPServerNewConnect(void)
{
    m_TCPServerSocket = m_TCPServer->nextPendingConnection();
    m_TCPServerClientAddr = m_TCPServerSocket->peerAddress();
    QString strIPAddress = m_TCPServerClientAddr.toString();

    connect(m_TCPServerSocket,&QTcpSocket::readyRead,this,&zzh_TCPControl::TCPControl_TCPServerRecvData);
    connect(m_TCPServerSocket,&QTcpSocket::disconnected,this,&zzh_TCPControl::TCPControl_TCPServerDisconnected);

    cout << "New Client Connect Server:" << strIPAddress << endl;
}
//TcpServer_客户端断开连接回调
void zzh_TCPControl::TCPControl_TCPServerDisconnected(void)
{
    cout << "Client Disconnect Server!" << endl;
}
//TcpServer_信息接收回调
void zzh_TCPControl::TCPControl_TCPServerRecvData()
{
    char *t_strRecvData = m_TCPServerSocket->readAll().data();
    cout << "TCP Server Recv\n" << t_strRecvData <<endl;

    //沾包处理
    char *temp = t_strRecvData;
    char *temp_tail = temp;
    char t_strRecvDataItem[256];
    uint t_uiRecvDataLength = strlen(t_strRecvData);
    for(uint i = 0; i < t_uiRecvDataLength; ++i){
        if(*temp_tail == '\n'){
            memset(t_strRecvDataItem,0,sizeof(t_strRecvDataItem));
            memcpy(t_strRecvDataItem,temp,temp_tail-(temp+1));

            //查询模式判定
            switch(getTCPControl_QueryMode()){
            case TCPControl_QueryMode_SaveOnly:
                setUiSaveFileRow(uiSaveFileRow()+1);
                TCPControl_Save2SaveURL(t_strRecvDataItem);
                break;
            case TCPControl_QueryMode_QueryOnly:
                (ZZH_QueryCore::Core_GetInstance())->Core_LineData_QueryExec(t_strRecvDataItem,0);
                break;
            case TCPControl_QueryMode_QuerySave:
                setUiSaveFileRow(uiSaveFileRow()+1);
                int rst = (ZZH_QueryCore::Core_GetInstance())->Core_LineData_QueryExec(t_strRecvDataItem,uiSaveFileRow());
                if(rst){
                    TCPControl_Save2SaveURL(t_strRecvDataItem);
                }else{
                    setUiSaveFileRow(uiSaveFileRow()-1);
                }
                break;
            }

            temp = temp_tail+1;
        }
        temp_tail++;
    }

    //查询信息刷新信号发送
    emit TCPControl_TCPSendAlarm((ZZH_QueryCore::Core_GetInstance())->Core_GetQueryLogItem());
}
//******************************************************************************
//TcpClient_连接到服务器
int  zzh_TCPControl::TCPControl_TCPClientInit(QString _qstrServerIP,quint16 _i16ServerPort)
{
    //关闭之前的连接
    if(m_TCPClientSocket!=nullptr){
        TCPControl_TCPClientDestroy();
    }

    //创建新连接
    m_TCPClientSocket = new QTcpSocket();

    //信号连接
    QObject::connect(m_TCPClientSocket,&QTcpSocket::readyRead,this,&zzh_TCPControl::TCPControl_TCPClientRecvData);
    QObject::connect(m_TCPClientSocket,&QTcpSocket::connected,this,&zzh_TCPControl::TCPControl_TCPClientNewConnect);
    QObject::connect(m_TCPClientSocket,&QTcpSocket::disconnected,this,&zzh_TCPControl::TCPControl_TCPClientDisconnected);

    //连接指定服务器
    m_TCPClientSocket->connectToHost(QHostAddress(_qstrServerIP),_i16ServerPort,QTcpSocket::ReadWrite);    //connect my TCP_Server
    if(!m_TCPClientSocket->waitForConnected()) {
        delete m_TCPClientSocket;
        m_TCPClientSocket = nullptr;
        return ZZH_ERROR_TCP_CLINRT_CONNECT;
    }

    //发送头部信息
    TCPControl_TCPClientWrite(TCPControl_GetSaveURL());

    return ZZH_SUCCESS;
}
//TcpClient_数据发送
void zzh_TCPControl::TCPControl_TCPClientWrite(QString qstrSendData)
{
    if(m_TCPClientSocket != nullptr){
        m_TCPClientSocket->write(qstrSendData.toLocal8Bit());
    }
}
//TcpClient_关闭连接
void zzh_TCPControl::TCPControl_TCPClientDestroy()
{
    if(m_TCPClientSocket!=nullptr){
        m_TCPClientSocket->disconnectFromHost();
        m_TCPClientSocket = nullptr;
    }
}
//TcpClient_连接至服务器回调
void zzh_TCPControl::TCPControl_TCPClientNewConnect(void)
{
    cout << "以连接至服务器" <<endl;
}
//TcpClient_断开连接回调
void zzh_TCPControl::TCPControl_TCPClientDisconnected(void)
{
    if(m_TCPClientSocket != nullptr){
        m_TCPClientSocket->close();
        m_TCPClientSocket = nullptr;
        //信息加载-信号（待完善）
        cout << "客户端已断开" <<endl;
    }
}
//TcpClient_信息接收回调
void zzh_TCPControl::TCPControl_TCPClientRecvData(void)
{
    char *t_strRecvData = m_TCPClientSocket->readAll().data();
    cout << "TCP Client Recv\n" << t_strRecvData <<endl;

    //沾包处理
    char *temp = t_strRecvData;
    char *temp_tail = temp;
    char t_strRecvDataItem[256];
    uint t_uiRecvDataLength = strlen(t_strRecvData);
    for(uint i = 0; i < t_uiRecvDataLength; ++i){
        if(*temp_tail == '\n'){
            memset(t_strRecvDataItem,0,sizeof(t_strRecvDataItem));
            memcpy(t_strRecvDataItem,temp,temp_tail-(temp+1));

            //查询模式判定
            switch(getTCPControl_QueryMode()){
            case TCPControl_QueryMode_SaveOnly:
                setUiSaveFileRow(uiSaveFileRow()+1);
                TCPControl_Save2SaveURL(t_strRecvDataItem);
                break;
            case TCPControl_QueryMode_QueryOnly:
                (ZZH_QueryCore::Core_GetInstance())->Core_LineData_QueryExec(t_strRecvDataItem,0);
                break;
            case TCPControl_QueryMode_QuerySave:
                setUiSaveFileRow(uiSaveFileRow()+1);
                int rst = (ZZH_QueryCore::Core_GetInstance())->Core_LineData_QueryExec(t_strRecvDataItem,uiSaveFileRow());
                if(rst){
                    TCPControl_Save2SaveURL(t_strRecvDataItem);
                }else{
                    setUiSaveFileRow(uiSaveFileRow()-1);
                }
                break;
            }

            temp = temp_tail+1;
        }
        temp_tail++;
    }

    //查询信息刷新信号发送
    emit TCPControl_TCPSendAlarm((ZZH_QueryCore::Core_GetInstance())->Core_GetQueryLogItem());
}
//******************************************************************************
//扫码器模式_信息处理
int zzh_TCPControl::TCPControl_CodeReaderQueryExec(QString qstrQueryData)
{
    int rst = 0;
    string t_strQueryData = gZZH_QT_QString2str(qstrQueryData);

    //查询模式判定
    switch(getTCPControl_QueryMode()){
    case TCPControl_QueryMode_SaveOnly:
        setUiSaveFileRow(uiSaveFileRow()+1);
        TCPControl_Save2SaveURL(t_strQueryData.c_str());
        break;
    case TCPControl_QueryMode_QueryOnly:
        (ZZH_QueryCore::Core_GetInstance())->Core_LineData_QueryExec(t_strQueryData.c_str(),0);
        break;
    case TCPControl_QueryMode_QuerySave:
        setUiSaveFileRow(uiSaveFileRow()+1);
        int rst = (ZZH_QueryCore::Core_GetInstance())->Core_LineData_QueryExec(t_strQueryData.c_str(),uiSaveFileRow());
        if(rst){
            TCPControl_Save2SaveURL(t_strQueryData.c_str());
        }else{
            setUiSaveFileRow(uiSaveFileRow()-1);
        }
        break;
    }

    //查询信息刷新信号发送
    emit TCPControl_TCPSendAlarm((ZZH_QueryCore::Core_GetInstance())->Core_GetQueryLogItem());

    return rst;
}
//******************************************************************************
//逻辑函数_创建保存文件
int zzh_TCPControl::TCPControl_CreateSaveFile(QString t_qstrCurrentFileURL)
{
    //获取文件路径
    QString t_qstrCurrentFileFolderURL = t_qstrCurrentFileURL.left(t_qstrCurrentFileURL.lastIndexOf("\\"));

    //QString 2 cstr
    string t_cstrCurrentFileURL = gZZH_QT_QString2str(t_qstrCurrentFileURL);
    string t_cstrCurrentFileFolderURL = gZZH_QT_QString2str(t_qstrCurrentFileFolderURL);

    //创建文件夹
    gZZH_Mkdirs(t_cstrCurrentFileFolderURL.c_str());

    //创建文件
    FILE *mFile = fopen(t_cstrCurrentFileURL.c_str(),"w+");
    if(!mFile){
        return ZZH_ERROR_SUBFILE_CREATE;
    } else {
        fclose(mFile);
    }

    //设置当前文件为SaveFile
    TCPControl_SetSaveURL(t_qstrCurrentFileURL);

    return ZZH_SUCCESS;
}
//逻辑函数_删除当前保存文件
int zzh_TCPControl::TCPControl_DeleateSaveFile(void)
{
    if(TCPControl_EmptySaveURL()){
        return ZZH_ERROR_FILEDELETE;
    }

    //URL获取并清除
    string t_strFileURL = gZZH_QT_QString2str(TCPControl_GetSaveURL());
    TCPControl_SetSaveURL("");

    //删除文件
    int rst = remove(t_strFileURL.c_str());
    if(rst == 0){
        return ZZH_SUCCESS;
    }else{
        return ZZH_ERROR_FILEDELETE;
    }
}
//逻辑函数_数据保存至路径
void zzh_TCPControl::TCPControl_Save2SaveURL(const char* t_strSaveData){
    if(TCPControl_EmptySaveURL()){
        return;
    }

    //格式整理
    char t_strSaveDataArr[257];
    strcpy(t_strSaveDataArr,t_strSaveData);
    gZZH_TrimShift(t_strSaveDataArr);
    t_strSaveDataArr[strlen(t_strSaveDataArr)]   = '\n';
    t_strSaveDataArr[strlen(t_strSaveDataArr)+1] = '\0';

    //文件操作
    FILE * mFile = fopen(gZZH_QT_QString2str(m_qstrSaveFileURL).c_str(),"a+");
    if(!mFile){
        return;
    }
    fprintf(mFile,t_strSaveDataArr);
    fclose(mFile);
}
//******************************************************************************
//当前保存文件_GET行信息
uint zzh_TCPControl::uiSaveFileRow() const
{
    return m_uiSaveFileRow;
}
//当前保存文件_GET行信息(指定文件)
uint zzh_TCPControl::uiSaveFileRow(const QString qstrFileURL) const
{
    size_t t_uiSaveFileLength = 0;

    string t_strFileURL = gZZH_QT_QString2str(qstrFileURL);
    FILE *mFile = fopen(t_strFileURL.c_str(),"r");
    if(!mFile){
        return t_uiSaveFileLength;
    }

    //获取数据条数（后面可能改为更好的方法）
    char data_rev_buf[256];
    while(!feof(mFile)){
        memset(data_rev_buf,0,sizeof (data_rev_buf));
        fgets(data_rev_buf,  sizeof (data_rev_buf), mFile);
        if(strcmp(data_rev_buf,"") != 0){
            t_uiSaveFileLength++;
        }
    }
    fclose(mFile);

    return t_uiSaveFileLength;
}
//当前保存文件_SET行信息
void zzh_TCPControl::setUiSaveFileRow(const uint &uiSaveFileRow)
{
    m_uiSaveFileRow = uiSaveFileRow;
}
//当前保存文件_SET行信息(指定文件)
void zzh_TCPControl::setUiSaveFileRow(const QString qstrFileURL)
{
    size_t t_uiSaveFileLength = 0;

    string t_strFileURL = gZZH_QT_QString2str(qstrFileURL);
    FILE *mFile = fopen(t_strFileURL.c_str(),"r");
    if(!mFile){
        m_uiSaveFileRow = t_uiSaveFileLength;
        return;
    }

    //获取数据条数（后面可能改为更好的方法）
    char data_rev_buf[256];
    while(!feof(mFile)){
        memset(data_rev_buf,0,sizeof (data_rev_buf));
        fgets(data_rev_buf,  sizeof (data_rev_buf), mFile);
        if(strcmp(data_rev_buf,"") != 0){
            t_uiSaveFileLength++;
        }
    }
    fclose(mFile);

    m_uiSaveFileRow = t_uiSaveFileLength;
}
//当前保存文件_SET文件URL
int zzh_TCPControl::TCPControl_SetSaveURL(QString _qstrSaveFileURL)
{
    (ZZH_QueryCore::Core_GetInstance())->Core_QueryLogItem_Reset();
    m_qstrSaveFileURL = _qstrSaveFileURL;

    //行信息重置
    setUiSaveFileRow(_qstrSaveFileURL);

    return ZZH_SUCCESS;
}
//当前保存文件_GET文件URL
QString zzh_TCPControl::TCPControl_GetSaveURL(void)
{
    return m_qstrSaveFileURL;
}
//当前保存文件_URL是否为空
bool zzh_TCPControl::TCPControl_EmptySaveURL(void)
{
    if(m_qstrSaveFileURL == ""){
        return true;
    }else{
        return false;
    }
}
//******************************************************************************
//查询模式设置-SET查询模式
void zzh_TCPControl::setTCPControl_QueryMode(int value)
{
    TCPControl_QueryMode = value;
}
//查询模式设置-GET查询模式
int zzh_TCPControl::getTCPControl_QueryMode() const
{
    return TCPControl_QueryMode;
}

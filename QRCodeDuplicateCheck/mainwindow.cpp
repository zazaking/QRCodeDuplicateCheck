//******************************************************************************
#include "mainwindow.h"
#include "ui_mainwindow.h"
//******************************************************************************
//构造函数
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1780,700);

    //UI初始化
    UI_MainWindowWidgetInitial();   //UI控制函数_主界面Widget初始化
    UI_CreateFileListTable(MAX_FILELIST_NUM); //UI控制函数_创建比对信息列表表格
    UI_CreateQueryLogListTable(MAX_QUERYLOGLIST_NUM);   //UI控制函数_创建比对信息列表表格

    //初始化TCP对象
    m_zzh_TCPControl = new zzh_TCPControl();
    QObject::connect(m_zzh_TCPControl,SIGNAL(TCPControl_TCPSendAlarm(vector<QueryLogItem>)),this,SLOT(TCPControl_TCPRecvAlarm(vector<QueryLogItem>)));
}
//析构函数
MainWindow::~MainWindow()
{
    delete m_zzh_TCPControl;
    delete ui;
}
//******************************************************************************
//UI控制函数_主界面初始化
void MainWindow::UI_MainWindowWidgetInitial(void)
{
    //QTableWidget
    m_FileListTable     = ui->f_FileListTable;
    m_QueryLogListTable = ui->f_QueryLogListTable;
    //QLineEdit
    m_MainFileCurrentLineEdit       = ui->f_MainFileCurrentLineEdit;
    m_SaveFileCurrentLineEdit       = ui->f_SaveFileCurrentLineEdit;
    m_ExportFileNameLineEdit        = ui->f_ExportFileNameLineEdit;
    m_CodeGunLineEdit               = ui->f_CodeGunLineEdit;
    m_TCPClientServerIPlineEdit     = ui->f_TCPClientServerIPlineEdit;
    m_TCPClientServerPortLineEdit   = ui->f_TCPClientServerPortLineEdit;
    //QCheckBox
    m_EnableCompaeCheckBox = ui->f_EnableCompaeCheckBox;
    m_EnableMusicCheckBox  = ui->f_EnableMusicCheckBox;
    //QPushButton
    m_TCPClientOpenButton  = ui->f_TCPClientOpenButton;
    //QComboBox
    m_SaveFileField_1   = ui->f_SaveFileField_1;
    m_SaveFileField_2   = ui->f_SaveFileField_2;
    m_SaveFileField_NUM = ui->f_SaveFileField_Num;
    m_SaveFileField_NUM ->clear();
    for(int i=1; i<=999; i++){
        m_SaveFileField_NUM->addItem(QString("%1").arg(i, 3, 10, QChar('0')));
    }
}
//UI控制函数_模式切换/使能控件函数
void MainWindow::UI_Enable_Control(int i)
{

}
//UI控制函数_根据返回值显示提示信息
void MainWindow::UI_ShowMessageBox(int rst)
{
    switch (rst)
    {
        /*成功信息*/
        case ZZH_SUCCESS_NOMSG:
            cout << "ZZH_SUCCESS_NOMSG" << endl;
            break;
        case ZZH_SUCCESS:
            QMessageBox::information(this, tr("提示"),QString(tr("操作成功!")),QMessageBox::Yes);
            break;
        /*警告信息*/
        case ZZH_WARNING_MAINFILE_LOGEMPTY:
            QMessageBox::warning(this, tr("警告"),QString(tr("找不到次数记录文件!")),QMessageBox::Yes);
            break;
        /*主文件错误信息*/
        case ZZH_ERROR_MAINFILE_OPEN:
            QMessageBox::critical(this, tr("错误"),QString(tr("主文件打开失败!")),QMessageBox::Yes);
            break;
        case ZZH_ERROR_MAINFILE_SETPATH:
            QMessageBox::critical(this, tr("错误"),QString(tr("主文件设置路径失败!")),QMessageBox::Yes);
            break;
        case ZZH_ERROR_MAINFILE_PATHEMPTY:
            QMessageBox::critical(this, tr("错误"),QString(tr("主文件路径为空!")),QMessageBox::Yes);
            break;
        /*子文件错误信息*/
        case ZZH_ERROR_SUBFILE_OPEN:
            QMessageBox::critical(this, tr("错误"),QString(tr("子文件打开失败!")),QMessageBox::Yes);
            break;
        case ZZH_ERROR_SUBFILE_EXIST:
            QMessageBox::critical(this, tr("错误"),QString(tr("子文件已经加载过!")),QMessageBox::Yes);
            break;
        case ZZH_ERROR_SUBFILE_SETPATH:
            QMessageBox::critical(this, tr("错误"),QString(tr("子文件设置路径失败!")),QMessageBox::Yes);
            break;
        case ZZH_ERROR_SUBFILE_CREATE:
            QMessageBox::critical(this, tr("错误"),QString(tr("子文件创建失败!")),QMessageBox::Yes);
            break;
        /*内存错误信息*/
        case ZZH_ERROR_FILEDELETE:
            QMessageBox::critical(this, tr("错误"),QString(tr("文件删除失败!")),QMessageBox::Yes);
            break;
        /*内存错误信息*/
        case ZZH_ERROR_MEMOER_RESET:
            QMessageBox::critical(this, tr("错误"),QString(tr("内存重置失败!")),QMessageBox::Yes);
            break;
        case ZZH_ERROR_MEMNUM_RESET:
            QMessageBox::critical(this, tr("错误"),QString(tr("记录次数内存重置失败!")),QMessageBox::Yes);
            break;
        /*其他信息*/
        default:
            QMessageBox::warning(this, tr("警告"),QString(tr("未知信息!(错误号:%1)").arg(rst)),QMessageBox::Yes);
            break;
    }
}
//UI控制函数_创建文件列表表格
void MainWindow::UI_CreateFileListTable(int row)
{
    QTableWidget *t_FileListTable = m_FileListTable;

    //表格属性设置
    t_FileListTable->setRowCount(row);
    t_FileListTable->setColumnCount(3);
    t_FileListTable->setHorizontalHeaderLabels(QStringList()<<"选择"<< "数据量"<<"文件路径"); //设置表头
    t_FileListTable->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置行不可修改 只读方式
    t_FileListTable->setSelectionBehavior(QAbstractItemView::SelectRows); //表格多选
    t_FileListTable->setShowGrid(true);

    //表格设置每列的宽度
    t_FileListTable->setColumnWidth(0,40);
    t_FileListTable->setColumnWidth(1,100);
    t_FileListTable->setColumnWidth(2,450);

    //初始化表格内容
    for(int i = 0; i < row;i++){
        QTableWidgetItem *checkBox = new QTableWidgetItem();
        t_FileListTable->setItem(i,0,checkBox);
        t_FileListTable->setItem(i,1,new QTableWidgetItem(""));
        t_FileListTable->setItem(i,2,new QTableWidgetItem(""));
    }

    //复选框信号
    disconnect(t_FileListTable, SIGNAL(cellChanged(int,int)), this, SLOT(SIGNAL_SelectFileChange(int, int)));
    connect(t_FileListTable, SIGNAL(cellChanged(int,int)), this, SLOT(SIGNAL_SelectFileChange(int, int)));

    //文件记录变量初始化
    m_iFileListNum = 0;
    m_setSubFile.clear();
    m_vecReelectionData.clear();
}
//UI控制函数_文件列表表格移除一项
void MainWindow::UI_FileListTableDeleteItem(int row)
{
     //遍历方式移动数据
     for(int i = row; i < m_iFileListNum; i++){
         m_FileListTable->setItem(i,1,new QTableWidgetItem(m_FileListTable->item(i+1,1)->text()));
         m_FileListTable->setItem(i,2,new QTableWidgetItem(m_FileListTable->item(i+1,2)->text()));
     }

     //重建最后一位的选框
     QTableWidgetItem *checkBox = new QTableWidgetItem();
     m_FileListTable->setItem(m_iFileListNum-1,0,checkBox);

     m_iFileListNum--;
}
//UI控制函数_创建查询信息列表表格
void MainWindow::UI_CreateQueryLogListTable(int row)
{
    QTableWidget *t_QueryLogListTable = m_QueryLogListTable;

    //表格属性设置
    t_QueryLogListTable->setRowCount(row);
    t_QueryLogListTable->setColumnCount(3);
    t_QueryLogListTable->setHorizontalHeaderLabels(QStringList()<<"位置"<<"数据"<<"类型");
    t_QueryLogListTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    t_QueryLogListTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    t_QueryLogListTable->setShowGrid(true);

    //表格设置每列的宽度
    t_QueryLogListTable->setColumnWidth(0,60);
    t_QueryLogListTable->setColumnWidth(1,210);
    t_QueryLogListTable->setColumnWidth(2,80);

    //初始化表格内容
    for(int i = 0;i < row;i++){
        ui->f_QueryLogListTable->setItem(i,0,new QTableWidgetItem(""));
        ui->f_QueryLogListTable->setItem(i,1,new QTableWidgetItem(""));
        ui->f_QueryLogListTable->setItem(i,2,new QTableWidgetItem(""));
    }
}
//******************************************************************************
//信号函数-文件列表复选框勾选信号
void MainWindow::SIGNAL_SelectFileChange(int row, int col)
{
    //复选框勾选
    if((col == 0) &&
       (m_FileListTable->item(row, col)->checkState() == Qt::Checked) &&
       (m_FileListTable->item(row, 2)->text() != ""))
    {
        //入队逻辑
        SelectFile t_SelectFile(m_FileListTable->item(row,2)->text(),row,m_FileListTable->item(row,1)->text().toUInt());
        m_vecReelectionData.push_back(t_SelectFile);

        //打印测试信息
        cout<<"-------------------------------------------"<<endl;
        for(uint i = 0; i<m_vecReelectionData.size(); i++){
            SelectFile t_SelectFile = m_vecReelectionData.at(i);
            cout<<t_SelectFile.m_qstrFileURL<<" "<<t_SelectFile.m_iFileRow<<" "<<t_SelectFile.m_uiFileSize<<endl;
        }
        cout<<"Reelection_list.length()="<<m_vecReelectionData.size()<<endl;
        cout<<"-------------------------------------------"<<endl;
    }

    //复选框取消勾选
    else if((col == 0) &&
            (m_FileListTable->item(row, col)->checkState() == Qt::Unchecked) &&
            (m_FileListTable->item(row, 2)->text() != ""))
    {
        //出队逻辑
        vector<SelectFile>::iterator iter;
        LOOP:
        for(iter=m_vecReelectionData.begin(); iter != m_vecReelectionData.end(); iter++){
            if((*iter).m_qstrFileURL == m_FileListTable->item(row, 2)->text()){
                m_vecReelectionData.erase(iter);
                goto LOOP;
            }
        }

        //打印测试信息
        cout<<"-------------------------------------------"<<endl;
        for(uint i = 0; i<m_vecReelectionData.size(); i++){
            SelectFile t_SelectFile = m_vecReelectionData.at(i);
            cout<<t_SelectFile.m_qstrFileURL<<" "<<t_SelectFile.m_iFileRow<<" "<<t_SelectFile.m_uiFileSize<<endl;
        }
        cout<<"Reelection_list.length()="<<m_vecReelectionData.size()<<endl;
        cout<<"-------------------------------------------"<<endl;
    }
}
//******************************************************************************
//槽位函数-模板文件加载按钮
void MainWindow::on_f_MainFileLoadButton_clicked()
{
    //获取文件URL
    QString t_qstrFilURL = QFileDialog::getOpenFileName(this,tr("选择比对主文件"),"", tr("(*.txt)"));
    if(t_qstrFilURL == ""){
        QMessageBox::information(this, tr("提示"),QString(tr("请重新选择文件")),QMessageBox::Yes);
        return;
    }

    UI_Enable_Control(DISSENABLE_ALL);

    //逻辑操作_加载主文件
    int rst = m_zzh_logiccontrol.logiccontrol_LoadMainFile(t_qstrFilURL);

    //UI初始化
    UI_CreateQueryLogListTable(MAX_QUERYLOGLIST_NUM);
    UI_ShowMessageBox(rst);
    UI_Enable_Control(OFFLINE_MODE);

    //截取主文件文件名-用于显示
    if(rst >= 0){
        QString t_qstrFilName = gZZH_QT_ExtractFileName(t_qstrFilURL);
        m_MainFileCurrentLineEdit->setText(t_qstrFilName);
    }
}
//槽位函数-文件列表加载按钮
void MainWindow::on_f_FileLocalLoadButton_clicked()
{
    int rst = 0;
    size_t t_uiSubFileLength = 0;

    //获取文件URL
    QString t_qstrFileURL = QFileDialog::getOpenFileName(this,tr("选择要添加的子文件"),"", tr("(*.txt)"));
    if(t_qstrFileURL == ""){
        QMessageBox::information(this, tr("提示"),QString(tr("请重新选择文件")),QMessageBox::Yes);
        return;
    }

    UI_Enable_Control(DISSENABLE_ALL);

    //并查集重复文件判断
    if(m_setSubFile.find(t_qstrFileURL) != m_setSubFile.end()){
        rst = ZZH_ERROR_SUBFILE_EXIST;
    }

    //获取子文件条数
    if( rst >= 0 ){
        rst = m_zzh_logiccontrol.logiccontrol_GetFileRow(t_qstrFileURL,t_uiSubFileLength);
    }

    if(rst >= 0){
        int t_iFileListNum = m_iFileListNum;
        //列表文件越界则初始化文件列表
        if(t_iFileListNum >= MAX_FILELIST_NUM){
            UI_CreateFileListTable(MAX_FILELIST_NUM);
            t_iFileListNum = m_iFileListNum;
        }

        //创建新的checkbox
        QTableWidgetItem *checkBox = new QTableWidgetItem();
        m_FileListTable->setItem(t_iFileListNum,0,checkBox);
        m_FileListTable->item(t_iFileListNum,0)->setCheckState(Qt::Unchecked);
        m_FileListTable->setItem(t_iFileListNum,2,new QTableWidgetItem(t_qstrFileURL));  //文件路径显示
        m_FileListTable->setItem(t_iFileListNum,1,new QTableWidgetItem(QString("%1").arg(t_uiSubFileLength)));

        //子文件计数自增
        ++m_iFileListNum;
        m_setSubFile.insert(t_qstrFileURL);
    }

    UI_ShowMessageBox(rst); //UI提示显示
    UI_Enable_Control(OFFLINE_MODE);
}
//槽位函数-子文件批量加载按钮（支持批量）
void MainWindow::on_f_FilesLoadButton_clicked()
{
    //获取文件夹URL
    QString t_qstrFolderURL = QFileDialog::getExistingDirectory(this,tr("打开文件夹"), "", QFileDialog::ShowDirsOnly);
    if(t_qstrFolderURL == ""){
        QMessageBox::information(this, tr("提示"),QString(tr("请重新选择文件夹")),QMessageBox::Yes);
        return;
    }

    //获取文件夹URL下所".txt"文件名
    QStringList files = gZZH_QT_GetTXTFromFolder(t_qstrFolderURL);
    if(files.size()<=0){
        UI_Enable_Control(OFFLINE_MODE);
        QMessageBox::information(this, tr("提示"),QString(tr("文件夹下无.txt文件!")),QMessageBox::Yes);
        return;
    }

    UI_Enable_Control(DISSENABLE_ALL);

    for(auto file : files){
        int rst = 0;
        size_t t_uiSubFileLength = 0;

        //获取文件URL
        QString t_qstrFileURL = t_qstrFolderURL + "/" + file;

        //文件重复判断
        if(m_setSubFile.find(t_qstrFileURL) != m_setSubFile.end()){
            rst = ZZH_ERROR_SUBFILE_EXIST;
        }

        //获取文件条数
        if( rst >= 0 ){
            rst = m_zzh_logiccontrol.logiccontrol_GetFileRow(t_qstrFileURL,t_uiSubFileLength);
        }

        if(rst >= 0){
            int t_iFileListNum = m_iFileListNum;
            //越界文件列表初始化
            if(t_iFileListNum >= MAX_FILELIST_NUM){
                UI_CreateFileListTable(MAX_FILELIST_NUM);
                t_iFileListNum = m_iFileListNum;
            }

            //创建新的checkbox
            QTableWidgetItem *checkBox = new QTableWidgetItem();
            m_FileListTable->setItem(t_iFileListNum,0,checkBox);
            m_FileListTable->item(t_iFileListNum,0)->setCheckState(Qt::Unchecked);
            m_FileListTable->setItem(t_iFileListNum,2,new QTableWidgetItem(t_qstrFileURL));  //文件路径显示
            m_FileListTable->setItem(t_iFileListNum,1,new QTableWidgetItem(QString("%1").arg(t_uiSubFileLength)));

            //子文件计数自增
            ++m_iFileListNum;
            m_setSubFile.insert(t_qstrFileURL);
        }
    }

    UI_Enable_Control(DISSENABLE_ALL);
}
//槽位函数-删除子文件（支持批量）
void MainWindow::on_f_FileDeleteButton_clicked()
{
    if(m_vecReelectionData.size() == 0){
        QMessageBox::critical(this, tr("错误"),QString(tr("请先勾选文件!")),QMessageBox::Yes);
        return;
    }

    UI_Enable_Control(DISSENABLE_ALL);
    for(uint i = 0; i < m_vecReelectionData.size(); ++i){
        QString t_qstrFilURL = m_vecReelectionData[i].m_qstrFileURL;

        /*逻辑操作_删除文件*/
        int rst = m_zzh_logiccontrol.logiccontrol_FileDelete(t_qstrFilURL);

        //并查集中删除
        if((rst >= 0) &&
           (m_setSubFile.find(t_qstrFilURL) != m_setSubFile.end())){
            m_setSubFile.erase(m_setSubFile.find(t_qstrFilURL));
        }

        //删除文件列表表格对应项
        UI_FileListTableDeleteItem(m_vecReelectionData[i].m_iFileRow);

        //重新赋值下标
        for(uint j = 0; j < m_vecReelectionData.size(); ++j){
            if(m_vecReelectionData[j].m_iFileRow > m_vecReelectionData[i].m_iFileRow){
                --m_vecReelectionData[j].m_iFileRow;
            }
        }

        UI_ShowMessageBox(rst); //UI提示显示
    }

    //重置复选信息
    for(int i = 0;i < m_iFileListNum;i++){
        m_FileListTable->item(i,0)->setCheckState(Qt::Unchecked);
    }
    m_vecReelectionData.clear();

    /*UI使能*/
    UI_Enable_Control(DISSENABLE_ALL);
}

//槽位函数-本地文件查重
void MainWindow::on_f_FileLocalCheckExecButton_clicked()
{
    if(m_MainFileCurrentLineEdit->text() == ""){
        QMessageBox::information(this, tr("提示"),QString(tr("请先设置模板文件")),QMessageBox::Yes);
        return;
    }

    if(m_vecReelectionData.size() == 0){
        QMessageBox::critical(this, tr("错误"),QString(tr("请先勾选文件!")),QMessageBox::Yes);
        return;
    }

    /*UI使能*/
    UI_Enable_Control(DISSENABLE_ALL);

    //遍历所有待查文件
    vector<QueryLogItem> t_vecQueryLog;
    for(uint i = 0; i < m_vecReelectionData.size(); ++i){
        QString t_qstrFilURL = m_vecReelectionData[i].m_qstrFileURL;

        /*逻辑操作_文件查重*/
        int rst = m_zzh_logiccontrol.logiccontrol_LocalCheckExec(t_vecQueryLog,t_qstrFilURL);
        if(rst < 0){
            UI_ShowMessageBox(rst); //UI提示显示
            UI_Enable_Control(OFFLINE_MODE);
            return;
        }
    }

    //错误信息显示策略
    uint t_uiQueryLogNum = t_vecQueryLog.size();
    if(t_uiQueryLogNum > 0){
        //报警逻辑
        if(m_EnableMusicCheckBox->isChecked() &&
           m_qtaudioPlayer.state() == m_qtaudioPlayer.StoppedState ){
            m_qtaudioPlayer.setMedia(QUrl("qrc:/sounds/warning.mp3"));
            m_qtaudioPlayer.play();
        }

        //错误信息显示
        UI_CreateQueryLogListTable(MAX_QUERYLOGLIST_NUM);
        for(uint i = 0; i < t_uiQueryLogNum; ++i){
            m_QueryLogListTable->setItem(i,0,new QTableWidgetItem(QString("%1").arg(t_vecQueryLog.at(i).m_uiDataRow)));
            m_QueryLogListTable->setItem(i,1,new QTableWidgetItem(QString::fromLocal8Bit(t_vecQueryLog.at(i).m_strData.c_str())));
            if(t_vecQueryLog.at(i).m_iErrorType == -1){
                m_QueryLogListTable->setItem((int)i,2,new QTableWidgetItem(QString("错号")));
            }else{
                m_QueryLogListTable->setItem((int)i,2,new QTableWidgetItem(QString("重码%1次").arg(t_vecQueryLog.at(i).m_iErrorType)));
            }
        }
    }
    UI_ShowMessageBox(ZZH_SUCCESS); //UI提示显示
    UI_Enable_Control(OFFLINE_MODE);
}

//槽位函数-创建文件
void MainWindow::on_f_SaveFileCurrentCreateButton_clicked()
{
    UI_Enable_Control(DISSENABLE_ALL);

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString qstrCurrentDay  = current_date_time.toString("yy_MM_dd");
    QString qstrCurrentTime = current_date_time.toString("hh_mm_ss");

    m_qstrCurrentFileURL.clear();
    m_qstrCurrentFileURL = "D:\\数据记录\\"
            + m_SaveFileField_1->currentText() + "_"
            + m_SaveFileField_2->currentText() + "_"
            + qstrCurrentDay + "_"
            + qstrCurrentTime + "_"
            + m_SaveFileField_NUM->currentText() + ".txt";

    int rst = m_zzh_TCPControl->TCPControl_CreateSaveFile(m_qstrCurrentFileURL);

    if(rst == ZZH_SUCCESS){
        m_SaveFileCurrentLineEdit->setText(m_qstrCurrentFileURL);
    }

    UI_ShowMessageBox(rst); //UI提示显示
    UI_Enable_Control(CHANGE_FILE);
}

//槽位函数-删除当前文件
void MainWindow::on_f_SaveFileCurrentDeleteButton_clicked()
{
    UI_Enable_Control(DISSENABLE_ALL);
    QString t_SaveFileCurrentLineEdit = m_SaveFileCurrentLineEdit->text();
    if(t_SaveFileCurrentLineEdit == ""){
        return;
    }
    int rst = m_zzh_TCPControl->TCPControl_DeleateSaveFile();
    if(rst >= 0){
        m_SaveFileCurrentLineEdit->setText("");
    }
    UI_ShowMessageBox(rst); //UI提示显示
    UI_Enable_Control(CHANGE_FILE);
}

void MainWindow::TCPControl_TCPRecvAlarm(vector<QueryLogItem> t_vecQueryLog)
{
    //错误信息显示策略
    uint t_uiQueryLogNum = t_vecQueryLog.size();
    if(t_uiQueryLogNum > 0){
        //报警逻辑
        if(m_EnableMusicCheckBox->isChecked() &&
           m_qtaudioPlayer.state() == m_qtaudioPlayer.StoppedState ){
            m_qtaudioPlayer.setMedia(QUrl("qrc:/sounds/warning.mp3"));
            m_qtaudioPlayer.play();
        }

        //错误信息显示
        UI_CreateQueryLogListTable(MAX_QUERYLOGLIST_NUM);
        for(uint i = 0; i < t_uiQueryLogNum; ++i){
            m_QueryLogListTable->setItem(i,0,new QTableWidgetItem(QString("%1").arg(t_vecQueryLog.at(i).m_uiDataRow)));
            m_QueryLogListTable->setItem(i,1,new QTableWidgetItem(QString::fromLocal8Bit(t_vecQueryLog.at(i).m_strData.c_str())));
            if(t_vecQueryLog.at(i).m_iErrorType == -1){
                m_QueryLogListTable->setItem((int)i,2,new QTableWidgetItem(QString("错号")));
            }else{
                m_QueryLogListTable->setItem((int)i,2,new QTableWidgetItem(QString("重码%1次").arg(t_vecQueryLog.at(i).m_iErrorType)));
            }
        }
    }
}

//******************************************************************************
//TCP客户端连接按键函数
void MainWindow::on_f_TCPClientOpenButton_clicked()
{
    if(m_TCPClientOpenButton->text() == "连接"){
        if(m_MainFileCurrentLineEdit->text() == ""){
            QMessageBox::information(this, tr("提示"),QString(tr("请先设置模板文件")),QMessageBox::Yes);
            return;
        }
        if(m_TCPClientServerIPlineEdit->text() == ""){
            QMessageBox::information(this, tr("提示"),QString(tr("连接的TCP IP地址不能为空!")),QMessageBox::Yes);
            return;
        }
        if(m_TCPClientServerPortLineEdit->text() == ""){
            QMessageBox::information(this, tr("提示"),QString(tr("连接的TCP 端口地址不能为空!")),QMessageBox::Yes);
            return;
        }

        UI_Enable_Control(CHANGE_FILE);
        int rst = m_zzh_TCPControl->TCPControl_TCPClientInit(m_TCPClientServerIPlineEdit->text(),m_TCPClientServerPortLineEdit->text().toUInt());
        if(rst >= 0){
            m_TCPClientOpenButton->setText("断开");
        }
        UI_ShowMessageBox(rst); //UI提示显示
        UI_Enable_Control(CHANGE_FILE);
    }else if(m_TCPClientOpenButton->text() == "断开"){
        UI_Enable_Control(CHANGE_FILE);
        m_zzh_TCPControl->TCPControl_TCPClientDestroy();
        m_TCPClientOpenButton->setText("连接");
        UI_ShowMessageBox(ZZH_SUCCESS); //UI提示显示
        UI_Enable_Control(CHANGE_FILE);
    }
}

//TCP文件记录保存按键函数
void MainWindow::on_f_QueryLogSaveButton_clicked()
{
    UI_Enable_Control(DISSENABLE_ALL);
    int rst = m_zzh_logiccontrol.logiccontrol_SaveMainFileLog();
    UI_ShowMessageBox(rst); //UI提示显示
    UI_Enable_Control(CHANGE_FILE);
}

//清空记录队列按键函数
void MainWindow::on_f_QueryLogTableClearButton_clicked()
{
    UI_Enable_Control(DISSENABLE_ALL);
    int rst = m_zzh_logiccontrol.logiccontrol_ClearQueryLog();
    UI_ShowMessageBox(rst); //UI提示显示
    UI_Enable_Control(CHANGE_FILE);
}

void MainWindow::on_f_QueryLogResetButton_clicked()
{
    UI_Enable_Control(DISSENABLE_ALL);
    int rst = m_zzh_logiccontrol.logiccontrol_QueryLogReset();
    UI_ShowMessageBox(rst); //UI提示显示
    UI_Enable_Control(CHANGE_FILE);
}

void MainWindow::on_f_QueryLogLoadButton_clicked()
{
    UI_Enable_Control(DISSENABLE_ALL);

    //Load Main Num File
    int rst = m_zzh_logiccontrol.logiccontrol_QueryLogLoad();
    UI_ShowMessageBox(rst); //UI提示显示
    UI_Enable_Control(CHANGE_FILE);
}

//导出
void MainWindow::on_f_ExportFileExecButton_clicked()
{
    if(m_ExportFileNameLineEdit->text() == ""){
        QMessageBox::critical(this, tr("提示"),QString(tr("输入文件名为空")),QMessageBox::Yes);
        return;
    }
    if(m_vecReelectionData.size() == 0){
        QMessageBox::critical(this, tr("错误"),QString(tr("请先勾选文件!")),QMessageBox::Yes);
        return;
    }

    UI_Enable_Control(DISSENABLE_ALL);     //禁止所有组件

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString qstrCurrentDay  = current_date_time.toString("yy_MM_dd");
    QString qstrCurrentTime = current_date_time.toString("hh_mm_ss");

    QString m_qstrExportURL = "D:\\码包导出output\\"+m_ExportFileNameLineEdit->text()+".txt";
    cout << m_qstrExportURL << endl;

    int rst = 0;
    for(uint i = 0; i < m_vecReelectionData.size(); ++i){
        QString t_qstrFilURL = m_vecReelectionData[i].m_qstrFileURL;

        rst = m_zzh_logiccontrol.logiccontrol_FileAppend(m_qstrExportURL,t_qstrFilURL);
        if(rst < 0){
            break;
        }
    }

    //重置复选信息
    for(int i = 0;i < m_iFileListNum;i++){
        m_FileListTable->item(i,0)->setCheckState(Qt::Unchecked);
    }
    m_vecReelectionData.clear();

    UI_ShowMessageBox(rst); //UI提示显示
    UI_Enable_Control(DISSENABLE_ALL);
}

//扫码枪处理 m_CodeGunLineEdit
void MainWindow::on_f_CodeGunSelectButton_clicked()
{
    if(m_MainFileCurrentLineEdit->text() == ""){
        QMessageBox::information(this, tr("提示"),QString(tr("请先设置模板文件")),QMessageBox::Yes);
        m_CodeGunLineEdit->setText("");
        return;
    }
    if(m_SaveFileCurrentLineEdit->text() == ""){
        QMessageBox::information(this, tr("提示"),QString(tr("保存数据文件名为空!")),QMessageBox::Yes);
        m_CodeGunLineEdit->setText("");
        return;
    }
    if(m_CodeGunLineEdit->text() == ""){
        QMessageBox::information(this, tr("提示"),QString(tr("数据为空!")),QMessageBox::Yes);
        m_CodeGunLineEdit->setText("");
        return;
    }

    QString t_CodeGunData = m_CodeGunLineEdit->text();
    if(t_CodeGunData.length() < 40 || t_CodeGunData.length() > 45){
        QMessageBox::information(this, tr("提示"),QString(tr("数据错误\n数据长度错误!")),QMessageBox::Yes);
        m_CodeGunLineEdit->setText("");
        return;
    }

    int rst = m_zzh_TCPControl->TCPControl_CodeReaderQueryExec(t_CodeGunData);

    UI_ShowMessageBox(rst); //UI提示显示
    UI_Enable_Control(DISSENABLE_ALL);
}

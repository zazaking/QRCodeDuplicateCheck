//******************************************************************************
#include "zzh_querycore.h"
//******************************************************************************
//单例模式对象
ZZH_QueryCore *ZZH_QueryCore::m_instance = new ZZH_QueryCore();
//单例模式-获取单例对象
ZZH_QueryCore* ZZH_QueryCore::Core_GetInstance()
{
    return m_instance;
}
//单例模式-删除单例对象
void ZZH_QueryCore::Core_DeleteInstance()
{
    Core_GetInstance()->~ZZH_QueryCore();
}
//******************************************************************************
//构造函数
ZZH_QueryCore::ZZH_QueryCore(void)
{
    cout<<"Create ZZH_QueryCore Start!"<<endl;

    //内存申请
    if((Core_DataMem_Allocated() < 0) || (Core_NumMem_Allocated() < 0))
    {
        return;
    }

    //临时内存指针数组重置
    if((Core_TempDataMem_Reset() < 0) || (Core_TempNumMem_Reset() < 0))
    {
        return;
    }

    //变量初始化
    Core_MainFile_SetURL("");
    Core_IgnoreHead_SetLength(25);
    Core_QueryLogItem_Reset();

    cout<<"Create ZZH_QueryCore Finished!"<<endl;
}
//析构函数
ZZH_QueryCore::~ZZH_QueryCore(void)
{
    Core_ClearDataMem();
    Core_ClearNumMem();
}
//******************************************************************************
//内存操作-申请数据信息内存
int ZZH_QueryCore::Core_DataMem_Allocated(void)
{
    for(int i = 0; i < MAX_MEMBLOCK_SIZE; ++i)
    {
        Mem_Indicator[i] = new char[MAX_MEMITEM_SIZE*MAX_MEMITEM_DATASIZE];
        if(!Mem_Indicator[i])
        {
            cout << "Data Mem " << i << "Allocated Fail!" << endl;
            return ZZH_ERROR_CORE;
        }
    }
    cout << "Data Mem Allocated Succeed!" << endl;
    return ZZH_SUCCESS;
}
//内存操作-申请重复次数内存
int ZZH_QueryCore::Core_NumMem_Allocated(void)
{
    for(int i = 0; i < MAX_MEMBLOCK_SIZE; ++i)
    {
        Mem_Num_Indicator[i] = new int[MAX_MEMITEM_SIZE];
        if(!Mem_Num_Indicator[i])
        {
            cout << "Num Mem " << i << "Allocated Fail!" << endl;
            return ZZH_ERROR_CORE;
        }
    }
     cout << "Num Mem Allocated Succeed!" << endl;
    return ZZH_SUCCESS;
}
//内存操作-重置数据信息内存
int ZZH_QueryCore::Core_TempDataMem_Reset(void)
{
    cout << "Reset Data Memory Start!" << endl;
    for(int i = 0; i < MAX_MEMBLOCK_SIZE; ++i){
        if(Mem_Indicator[i]){
            Temp_Mem_Indicator[i] = Mem_Indicator[i];
            memset(Mem_Indicator[i],0,MAX_MEMITEM_SIZE*MAX_MEMITEM_DATASIZE);
        }else{
            cout<<"Temp Memory Indicator "<< i <<" Reset Fail!" << endl;
            return ZZH_ERROR_CORE_TEMPMEM_RESET;
        }
    }
    cout<<"Reset Data Memory Finished!" << endl;
    return ZZH_SUCCESS;
}
//内存操作-重置重复次数内存
int ZZH_QueryCore::Core_TempNumMem_Reset(void)
{
    cout << "Reset Num Memory Start!" << endl;
    for(int i = 0; i < MAX_MEMBLOCK_SIZE; ++i){
        if(Mem_Num_Indicator[i]){
            Temp_Mem_Num_Indicator[i] = Mem_Num_Indicator[i];
            memset(Mem_Num_Indicator[i],0,MAX_MEMITEM_SIZE);
        }else{
            cout<<"Temp Memory Indicator "<< i <<" Reset Fail!" << endl;
            return ZZH_ERROR_CORE_TEMPMEM_Num_RESET;
        }
    }
    cout << "Reset Num Memory Finished!" << endl;
    return ZZH_SUCCESS;
}
//内存操作-释放数据记录内存块
void ZZH_QueryCore::Core_ClearDataMem(void)
{
    cout << "Clear Data Memory Start!" << endl;
    for(int i = 0; i < MAX_MEMBLOCK_SIZE; ++i)
    {
        if(Mem_Indicator[i])
        {
            delete [] Mem_Indicator[i];
            Mem_Indicator[i] = nullptr;
            Temp_Mem_Indicator[i] = nullptr;
        }
    }
    cout << "Clear Data Memory Finished!" << endl;
    return;
}
//释放内存-释放查重记录内存块
void ZZH_QueryCore::Core_ClearNumMem(void)
{
    cout << "Clear Num Memory Start!" << endl;
    for(int i = 0;i < MAX_MEMBLOCK_SIZE;++i)
    {
        if(Mem_Num_Indicator[i])
        {
            delete [] Mem_Num_Indicator[i];
            Mem_Num_Indicator[i] = nullptr;
            Temp_Mem_Num_Indicator[i] = nullptr;
        }
    }
    cout << "Clear Num Memory Finished!" << endl;
    return;
}
//******************************************************************************
//主文件操作函数-SET主文件路径
int ZZH_QueryCore::Core_MainFile_SetURL(const char *t_cstrURL)
{
    if(!strncpy(m_cstrMainFileURL,t_cstrURL,strlen(t_cstrURL)+1))
    {
        return ZZH_ERROR_MAINFILE_SETPATH;
    }
    else
    {
        cout << "MainFileURL Change = \"" << m_cstrMainFileURL << "\"" << endl;
        return ZZH_SUCCESS;
    }
}
//主文件操作函数-GET主文件路径
const char *ZZH_QueryCore::Core_MainFile_GetURL(void)
{
    return m_cstrMainFileURL;
}
//主文件操作函数-读取至主文件内存
int ZZH_QueryCore::Core_MainFile_File2DataMem(void)
{
    cout << "Main File Read Start!" << gZZH_GetTime().c_str() << endl;

    //临时内存重置
    if(Core_TempDataMem_Reset() < 0){
        return ZZH_ERROR_MEMOER_RESET;
    }
    if(Core_TempNumMem_Reset() < 0){
        return ZZH_ERROR_MEMNUM_RESET;
    }

    //源文件打开
    FILE *mFile = fopen(m_cstrMainFileURL,"r");
    if(!mFile){
        cout << "Open Main File Fail: "<< m_cstrMainFileURL <<endl;
        return ZZH_ERROR_MAINFILE_OPEN;
    }else{
        cout << "Open Main File Succeed: "<< m_cstrMainFileURL <<endl;
    }

    //开始载入数据
    char t_csrtTempDataARR[MAX_MEMBLOCK_SIZE];
    while(!feof(mFile)){
        memset(t_csrtTempDataARR,0,sizeof(t_csrtTempDataARR));
        fgets(t_csrtTempDataARR,sizeof(t_csrtTempDataARR),mFile);

        //数据格式化
        gZZH_TrimShift(t_csrtTempDataARR);

        //数据合法性判断
        size_t t_csrtTempDataARR_len = strlen(t_csrtTempDataARR);
        if(strcmp(t_csrtTempDataARR,"") == 0){
            continue;
        }else if(m_uiIgnoreHeadLength > t_csrtTempDataARR_len-1){
            fclose(mFile);
            return ZZH_ERROR_CORE_HEADLENGTH;
        }else if((t_csrtTempDataARR_len-m_uiIgnoreHeadLength) > MAX_MEMITEM_DATASIZE){
            fclose(mFile);
            return ZZH_ERROR_CORE_DATAOVERSIZE;
        }

        //计算内存块位置
        int t_iMemBlockPosition = 0;
        char *t_cptrPosition = t_csrtTempDataARR + m_uiIgnoreHeadLength;
        for(unsigned int i = m_uiIgnoreHeadLength+1;i < t_csrtTempDataARR_len;++i){
            t_iMemBlockPosition += *t_cptrPosition;
            t_cptrPosition++;
        }
        t_iMemBlockPosition = t_iMemBlockPosition % MAX_MEMBLOCK_SIZE;

        //写入内存
        memcpy(Temp_Mem_Indicator[t_iMemBlockPosition],t_csrtTempDataARR+m_uiIgnoreHeadLength,t_csrtTempDataARR_len-m_uiIgnoreHeadLength);
        Temp_Mem_Indicator[t_iMemBlockPosition] = Temp_Mem_Indicator[t_iMemBlockPosition] + MAX_MEMITEM_DATASIZE;
    }

    //源文件关闭
    fclose(mFile);

    cout<<"Load Main Data Finished!:"<<gZZH_GetTime().c_str()<<endl;
    return ZZH_SUCCESS;
}
//******************************************************************************
//主文件Log文件操作函数-保存当前次数至LOG文件
int ZZH_QueryCore::Core_Mem2MainFileLog(void)
{
    cout<< "Mem Save To MainFileLog Start!" <<endl;

    //主文件名修改为LOG文件名
    char t_cstrMainFileURL[MAX_MEMBLOCK_SIZE];
    strcpy(t_cstrMainFileURL,Core_MainFile_GetURL());
    if((strcmp(t_cstrMainFileURL,"") == 0) ||
       (strchr(t_cstrMainFileURL,'.') == nullptr)){
        return ZZH_ERROR_CORE_LOG_URL;
    }else{
        *(strchr(t_cstrMainFileURL,'.')) = '\0';
        strcat(t_cstrMainFileURL,".log\0");
    }

    //打开LOG文件
    FILE *mFile = fopen(t_cstrMainFileURL,"w+");
    if(!mFile){
        return ZZH_ERROR_CORE_LOG_OPEN;
    }

    //写入文件记录
    for(int i = 0; i < MAX_MEMBLOCK_SIZE; ++i){
        fprintf(mFile,"Rigon\n");
        char *Select_Temp_Indicator = Mem_Indicator[i];
        int  *Select_Temp_Num_Indicator = Mem_Num_Indicator[i];
        while(Select_Temp_Indicator <= Temp_Mem_Indicator[i]){
            fprintf(mFile,"%d\n",*Select_Temp_Num_Indicator);
            Select_Temp_Num_Indicator++;
            Select_Temp_Indicator += MAX_MEMITEM_DATASIZE;
        }
    }

    //关闭LOG文件
    fclose(mFile);

    cout<< "Mem Save To MainFileLog Finished!" <<endl;
    return ZZH_SUCCESS;
}
//主文件Log文件操作函数-读取LOG文件至当前内存
int ZZH_QueryCore::Core_MainFileLog2Mem(void)
{
    int rst = 0;
    cout<< "Mem Load MainFileLog Start!" <<endl;

    //主文件名修改为LOG文件名
    char t_cstrMainFileURL[MAX_MEMBLOCK_SIZE];
    strcpy(t_cstrMainFileURL,Core_MainFile_GetURL());
    if((strcmp(t_cstrMainFileURL,"") == 0) ||
       (strchr(t_cstrMainFileURL,'.') == nullptr)){
        return ZZH_ERROR_CORE_LOG_URL;
    }else{
        *(strchr(t_cstrMainFileURL,'.')) = '\0';
        strcat(t_cstrMainFileURL,".log\0");
    }

    //记录次数重置
    if((rst = Core_TempNumMem_Reset()) < 0){
        return rst;
    }

    //打开LOG文件
    FILE *mFile = fopen(t_cstrMainFileURL,"r");
    if(!mFile){
        return ZZH_WARNING_MAINFILE_LOGEMPTY;
    }

    //记录次数获取
    int temp_i = -1;
    char t_cstrDataARR[16];
    while(!feof(mFile)){
        memset(t_cstrDataARR,0,sizeof(t_cstrDataARR));
        fgets(t_cstrDataARR,sizeof(t_cstrDataARR),mFile);
        //内存块移动标识
        if(strcmp(t_cstrDataARR,"Rigon\n") == 0){
            ++temp_i;
            Temp_Mem_Num_Indicator[temp_i] = Mem_Num_Indicator[temp_i];
            continue;
        }
        //数据格式化
        gZZH_TrimShift(t_cstrDataARR);
        //数据提取
        *Temp_Mem_Num_Indicator[temp_i] = atoi(t_cstrDataARR);
        Temp_Mem_Num_Indicator[temp_i]++;
    }

    //关闭LOG文件
    fclose(mFile);

    return ZZH_SUCCESS;
}
//******************************************************************************
//查询操作函数-加载文件并查询
int ZZH_QueryCore::Core_FileData_QueryExec(const char *t_cstrMainFileURL)
{
    cout<<"FileData QueryExec Start!:"<<gZZH_GetTime().c_str()<<endl;

    //数据初始化
    int  t_iQueryMark  = 0;
    unsigned int  t_iQueryTimes = 0;
    char t_csrtTempDataARR[MAX_MEMBLOCK_SIZE];

    //打开文件
    FILE *mFile = fopen(t_cstrMainFileURL,"r");
    if(!mFile){
        cout << "Open Sub File Fail: "<< t_cstrMainFileURL <<endl;
        return ZZH_ERROR_SUBFILE_OPEN;
    }else{
        cout << "Open Sub File Succeed: "<< t_cstrMainFileURL <<endl;
    }

    //载入数据
    while(!feof(mFile)){
        t_iQueryTimes++;
        t_iQueryMark = 0;

        memset(t_csrtTempDataARR,0,sizeof(t_csrtTempDataARR));
        fgets(t_csrtTempDataARR,sizeof(t_csrtTempDataARR),mFile);

        //数据格式化
        gZZH_TrimShift(t_csrtTempDataARR);

        //数据合法性判断
        size_t t_csrtTempDataARR_len = strlen(t_csrtTempDataARR);
        if(strcmp(t_csrtTempDataARR,"") == 0){
            continue;
        }else if(m_uiIgnoreHeadLength > t_csrtTempDataARR_len-1){
            fclose(mFile);
            return ZZH_ERROR_CORE_HEADLENGTH;
        }else if((t_csrtTempDataARR_len-m_uiIgnoreHeadLength) > MAX_MEMITEM_DATASIZE){
            fclose(mFile);
            return ZZH_ERROR_CORE_DATAOVERSIZE;
        }

        //计算内存块位置
        int t_iMemBlockPosition = 0;
        char *t_cptrPosition = t_csrtTempDataARR + m_uiIgnoreHeadLength;
        for(unsigned int i = m_uiIgnoreHeadLength+1;i < t_csrtTempDataARR_len;++i){
            t_iMemBlockPosition += *t_cptrPosition;
            t_cptrPosition++;
        }
        t_iMemBlockPosition = t_iMemBlockPosition % MAX_MEMBLOCK_SIZE;

        t_cptrPosition = t_csrtTempDataARR + m_uiIgnoreHeadLength;
        char *Select_Temp_Indicator = Mem_Indicator[t_iMemBlockPosition];
        while(Select_Temp_Indicator <= Temp_Mem_Indicator[t_iMemBlockPosition]){
            if(strcmp(Select_Temp_Indicator,t_cptrPosition) == 0){
                t_iQueryMark = 1;

                //次数记录
                int Num_Location = (Select_Temp_Indicator - Mem_Indicator[t_iMemBlockPosition])/MAX_MEMITEM_DATASIZE;
                int *Temp_Num_Rigon = Mem_Num_Indicator[t_iMemBlockPosition];
                Temp_Num_Rigon = Temp_Num_Rigon + Num_Location;
                *Temp_Num_Rigon = *Temp_Num_Rigon + 1;

                //重复次数大于1的时候才存入队列
                if(*Temp_Num_Rigon > 1){
                    cout << "Select Succeed:" << Select_Temp_Indicator << endl;
                    QueryLogItem t_QueryLogItem(t_cptrPosition,t_iQueryTimes,*Temp_Num_Rigon);

                    mutex_vecQueryLog.lock();
                    m_vecQueryLog.push_back(t_QueryLogItem);
                    if(m_vecQueryLog.size() > MAX_QUERYLOGLIST_NUM){    //越界处理-只保存最新的重复信息
                        m_vecQueryLog.erase(m_vecQueryLog.begin());
                    }
                    mutex_vecQueryLog.unlock();
                }
                break;
            }
            Select_Temp_Indicator += MAX_MEMITEM_DATASIZE;
        }

        //无记录的情况存入队列
        if(t_iQueryMark == 0){
            cout<<"Can't select:"<<t_cptrPosition<<endl;
            QueryLogItem t_QueryLogItem(t_cptrPosition,t_iQueryTimes,-1);

            mutex_vecQueryLog.lock();
            m_vecQueryLog.push_back(t_QueryLogItem);
            if(m_vecQueryLog.size() > MAX_QUERYLOGLIST_NUM){    //越界处理-只保存最新的重复信息
                m_vecQueryLog.erase(m_vecQueryLog.begin());
            }
            mutex_vecQueryLog.unlock();
        }
    }
    fclose(mFile);

    cout<<"Sub File QueryExec Finished!:"<<gZZH_GetTime().c_str()<<endl;
    return ZZH_SUCCESS;
}
//查询操作函数-单条数据查询
int ZZH_QueryCore::Core_LineData_QueryExec(const char *cstr_LineData,unsigned int uiLineDataRow)
{
    cout << "Line Data QueryExec Start!:" << endl;

    //数据初始化
    int   t_iQueryMark  = 0;  //查询标识符
    char  t_csrtTempDataARR[MAX_MEMBLOCK_SIZE];

    memset(t_csrtTempDataARR,0,sizeof(t_csrtTempDataARR));
    strcpy(t_csrtTempDataARR,cstr_LineData);

    //数据格式化
    gZZH_TrimShift(t_csrtTempDataARR);

    //数据合法性判断
    size_t t_csrtTempDataARR_len = strlen(t_csrtTempDataARR);
    if(strcmp(t_csrtTempDataARR,"") == 0){
        return ZZH_ERROR_CORE_DATAEMPTY;
    }else if(m_uiIgnoreHeadLength > t_csrtTempDataARR_len-1){
        return ZZH_ERROR_CORE_HEADLENGTH;
    }else if((t_csrtTempDataARR_len-m_uiIgnoreHeadLength) > MAX_MEMITEM_DATASIZE){
        return ZZH_ERROR_CORE_DATAOVERSIZE;
    }

    //计算内存块位置
    int t_iMemBlockPosition = 0;
    char *t_cptrPosition = t_csrtTempDataARR + m_uiIgnoreHeadLength;
    for(unsigned int i = m_uiIgnoreHeadLength+1;i < t_csrtTempDataARR_len;++i){
        t_iMemBlockPosition += *t_cptrPosition;
        t_cptrPosition++;
    }
    t_iMemBlockPosition = t_iMemBlockPosition % MAX_MEMBLOCK_SIZE;

    //内存遍历查询
    t_cptrPosition = t_csrtTempDataARR + m_uiIgnoreHeadLength;
    char *Select_Temp_Indicator = Mem_Indicator[t_iMemBlockPosition];
    while(Select_Temp_Indicator <= Temp_Mem_Indicator[t_iMemBlockPosition]){
        if(strcmp(Select_Temp_Indicator,t_cptrPosition) == 0){
            t_iQueryMark = 1;

            //次数记录
            int Num_Location = (Select_Temp_Indicator - Mem_Indicator[t_iMemBlockPosition])/MAX_MEMITEM_DATASIZE;
            int *Temp_Num_Rigon = Mem_Num_Indicator[t_iMemBlockPosition];
            Temp_Num_Rigon = Temp_Num_Rigon + Num_Location;
            *Temp_Num_Rigon = *Temp_Num_Rigon + 1;

            //重复次数大于1的时候才存入队列
            if(*Temp_Num_Rigon > 1){
                cout<<"Select Succeed:"<<Select_Temp_Indicator<<endl;
                QueryLogItem t_QueryLogItem(t_cptrPosition,uiLineDataRow,*Temp_Num_Rigon);

                mutex_vecQueryLog.lock();
                m_vecQueryLog.push_back(t_QueryLogItem);
                if(m_vecQueryLog.size() > MAX_QUERYLOGLIST_NUM){    //越界处理-只保存最新的重复信息
                    m_vecQueryLog.erase(m_vecQueryLog.begin());
                }
                mutex_vecQueryLog.unlock();
            }
            return ZZH_SUCCESS;
        }
        Select_Temp_Indicator += MAX_MEMITEM_DATASIZE;
    }

    //无记录的情况存入队列
    if(t_iQueryMark == 0){
        cout<<"Can't select:"<<t_cptrPosition<<endl;
        QueryLogItem t_QueryLogItem(t_cptrPosition,uiLineDataRow,-1);

        mutex_vecQueryLog.lock();
        m_vecQueryLog.push_back(t_QueryLogItem);
        if(m_vecQueryLog.size() > MAX_QUERYLOGLIST_NUM){    //越界处理-只保存最新的重复信息
            m_vecQueryLog.erase(m_vecQueryLog.begin());
        }
        mutex_vecQueryLog.unlock();
    }

    cout << "Line Data QueryExec Finished!:" << endl;
    return ZZH_SUCCESS;
}
//******************************************************************************
//忽略头部长度-SET忽略头部长度
void ZZH_QueryCore::Core_IgnoreHead_SetLength(unsigned int t_iIgnoreHeadLength)
{
    m_uiIgnoreHeadLength = t_iIgnoreHeadLength;
    cout << "head_length Change = " << m_uiIgnoreHeadLength << endl;
    return;
}
//忽略头部长度-GET忽略头部长度
unsigned int ZZH_QueryCore::Core_GetIgnoreHead(void)
{
    return this->m_uiIgnoreHeadLength;
}
//******************************************************************************
//查询记录数组操作-清空记录数组
void ZZH_QueryCore::Core_QueryLogItem_Reset()
{
    mutex_vecQueryLog.lock();
    m_vecQueryLog.clear();
    mutex_vecQueryLog.unlock();
    cout << "Line Query Log Item ReSet!" << endl;
}
//查询记录数组操作-GET记录数组
vector<QueryLogItem> ZZH_QueryCore::Core_GetQueryLogItem()
{
    mutex_vecQueryLog.lock();
    vector<QueryLogItem> t_vecQueryLog = m_vecQueryLog;
    mutex_vecQueryLog.unlock();
    return t_vecQueryLog;
}

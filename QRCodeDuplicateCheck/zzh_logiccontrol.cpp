//******************************************************************************
#include "zzh_logiccontrol.h"
//******************************************************************************
//构造函数（后面需要改 双锁创建内存单例）
zzh_logiccontrol::zzh_logiccontrol()
{
}
//析构函数
zzh_logiccontrol::~zzh_logiccontrol()
{
    (ZZH_QueryCore::Core_GetInstance())->Core_DeleteInstance();
}
//******************************************************************************
//逻辑操作_加载主文件
int zzh_logiccontrol::logiccontrol_LoadMainFile(const QString qstrFileURL)
{
    int rst = 0;

    //设置主文件路径
    string t_strFileURL = gZZH_QT_QString2str(qstrFileURL);
    rst = (ZZH_QueryCore::Core_GetInstance())->Core_MainFile_SetURL(t_strFileURL.c_str());
    if(rst < 0){
        return rst;
    }

    //加载主文件至内存
    rst = (ZZH_QueryCore::Core_GetInstance())->Core_MainFile_File2DataMem();
    if(rst < 0){
        return rst;
    }

    //加载主文件记录
    rst = (ZZH_QueryCore::Core_GetInstance())->Core_MainFileLog2Mem();
    if(rst < 0){
        return rst;
    }

    return rst;
}
//逻辑操作_本地查重
int zzh_logiccontrol::logiccontrol_LocalCheckExec(vector<QueryLogItem> &t_vecQueryLog,QString qstrFileURL)
{
    int rst = 0;

    //QString 2 cstr
    string t_strFileURL = gZZH_QT_QString2str(qstrFileURL);
    //文件查重
    rst = (ZZH_QueryCore::Core_GetInstance())->Core_FileData_QueryExec(t_strFileURL.c_str());
    //获取重复信息
    t_vecQueryLog = (ZZH_QueryCore::Core_GetInstance())->Core_GetQueryLogItem();

    return rst;
}
//******************************************************************************
//文件操作_获取文件数据条数
int zzh_logiccontrol::logiccontrol_GetFileRow(const QString qstrFileURL,size_t &t_uiSubFileLength)
{
    t_uiSubFileLength = 0;

    string t_strFileURL = gZZH_QT_QString2str(qstrFileURL);
    FILE *mFile = fopen(t_strFileURL.c_str(),"r");
    if(!mFile){
        return ZZH_ERROR_SUBFILE_OPEN;
    }

    //获取数据条数（后面可能改为更好的方法）
    char data_rev_buf[256];
    while(!feof(mFile)){
        memset(data_rev_buf,0,sizeof (data_rev_buf));
        fgets(data_rev_buf,  sizeof (data_rev_buf), mFile);
        if(strcmp(data_rev_buf,"") != 0){
            t_uiSubFileLength++;
        }
    }
    fclose(mFile);

    return ZZH_SUCCESS;
}
//文件操作_删除文件
int zzh_logiccontrol::logiccontrol_FileDelete(QString qstrFileURL)
{
    //QString 2 cstr
    string t_strFileURL = gZZH_QT_QString2str(qstrFileURL);

    //删除文件
    int rst = remove(t_strFileURL.c_str());
    if(rst == 0){
        return ZZH_SUCCESS_NOMSG;
    }else{
        return ZZH_ERROR_FILEDELETE;
    }
}
//文件操作_文件拼接
int zzh_logiccontrol::logiccontrol_FileAppend(const QString qstrDstFileURL,const QString qstrSrcFileURL){
    string strSrcFileURL = gZZH_QT_QString2str(qstrSrcFileURL);
    string strDstFileURL = gZZH_QT_QString2str(qstrDstFileURL);
    string strDstFolderURL = strDstFileURL.substr(0,strDstFileURL.find_last_of('\\'));

    //文件夹创建
    gZZH_Mkdirs(strDstFolderURL.c_str());

    //目标文件获取
    FILE *mFile_dst = fopen(strDstFileURL.c_str(),"a+");
    if(!mFile_dst){
        return -1;
    }

    //源文件获取
    FILE * mFile_src = fopen(strSrcFileURL.c_str(),"r");
    if(!mFile_src){
        fclose(mFile_dst);
        return -2;
    }

    //文件拷贝
    char data_rev_buf[256];
    while(!feof(mFile_src)){
        memset(data_rev_buf,0,sizeof(data_rev_buf));
        fgets(data_rev_buf,sizeof(data_rev_buf),mFile_src);
        if(strcmp(data_rev_buf,"") == 0){
            continue;
        }
        fprintf(mFile_dst,data_rev_buf);
    }

    fclose(mFile_src);
    fclose(mFile_dst);

    return ZZH_SUCCESS;
}
//******************************************************************************
//文件LOG函数_保存LOG文件
int zzh_logiccontrol::logiccontrol_SaveMainFileLog(){
    return (ZZH_QueryCore::Core_GetInstance())->Core_Mem2MainFileLog();
}
//文件LOG函数_加载LOG文件
int zzh_logiccontrol::logiccontrol_QueryLogLoad(){
    return (ZZH_QueryCore::Core_GetInstance())->Core_MainFileLog2Mem();
}
//文件LOG函数_清除查重信息
int zzh_logiccontrol::logiccontrol_ClearQueryLog(){
    (ZZH_QueryCore::Core_GetInstance())->Core_QueryLogItem_Reset();
    return ZZH_SUCCESS;
}
//文件LOG函数_重置查重次数
int zzh_logiccontrol::logiccontrol_QueryLogReset(){
    (ZZH_QueryCore::Core_GetInstance())->Core_TempNumMem_Reset();
    return ZZH_SUCCESS;
}





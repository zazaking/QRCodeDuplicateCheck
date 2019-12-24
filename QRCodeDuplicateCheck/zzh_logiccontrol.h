//******************************************************************************
#ifndef ZZH_LOGICCONTROL_H
#define ZZH_LOGICCONTROL_H
//******************************************************************************
#include "zzh_supportfun.h"
#include "zzh_querycore.h"
//******************************************************************************
class zzh_logiccontrol
{
public:
    zzh_logiccontrol(void);
    ~zzh_logiccontrol(void);
    //逻辑操作
    int logiccontrol_LoadMainFile(const QString qstrFileURL);
    int logiccontrol_LocalCheckExec(vector<QueryLogItem> &t_vecQueryLog,QString qstrFileURL);
    //文件操作
    int logiccontrol_FileDelete(QString qstrFileURL);
    int logiccontrol_FileAppend(const QString qstrDstFileURL,const QString qstrSrcFileURL);
    int logiccontrol_GetFileRow(const QString qstrFileURL,size_t &t_uiSubFileLength);
    //文件LOG函数
    int logiccontrol_SaveMainFileLog();
    int logiccontrol_ClearQueryLog();
    int logiccontrol_QueryLogReset();
    int logiccontrol_QueryLogLoad();
};
//******************************************************************************
#endif // ZZH_LOGICCONTROL_H
//******************************************************************************

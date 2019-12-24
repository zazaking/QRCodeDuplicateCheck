//******************************************************************************
//内存内核类
//******************************************************************************
#pragma once
#ifndef ZZH_QUERYCORE_H
#define ZZH_QUERYCORE_H
//******************************************************************************
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <mutex>
#include <io.h>
#include "zzh_supportfun.h"
//******************************************************************************
#define MAX_MEMBLOCK_SIZE       256
#define MAX_MEMITEM_SIZE        100000
#define MAX_MEMITEM_DATASIZE    32
//******************************************************************************
//查询错误信息结构体
typedef struct QueryLogItem{
    string          m_strData;      //错误信息
    int             m_iErrorType;   //错误类型
    unsigned int    m_uiDataRow;    //错误信息在文件中的条数
    QueryLogItem(string _strData,unsigned int _uiDataRow,int _iErrorType):
        m_strData(_strData),
        m_iErrorType(_iErrorType),
        m_uiDataRow(_uiDataRow)
    {}
}QueryLogItem;
//******************************************************************************
class ZZH_QueryCore
{
public:
    //单例函数
    static ZZH_QueryCore* Core_GetInstance();
    static void Core_DeleteInstance();
    //主文件操作函数
    int Core_MainFile_SetURL(const char *t_cstrURL);
    int Core_MainFile_File2DataMem(void);
    //主文件Log文件操作函数
    int Core_Mem2MainFileLog(void);
    int Core_MainFileLog2Mem(void);
    //查询操作函数
    int Core_LineData_QueryExec(const char *cstr_LineData,unsigned int uiLineDataRow);
    int Core_FileData_QueryExec(const char *t_cstrMainFileURL);
    //忽略头部长度
    void Core_IgnoreHead_SetLength(unsigned int t_uiIgnoreHeadLength);
    unsigned int Core_GetIgnoreHead(void);
    //查询信息数组操作函数
    void Core_QueryLogItem_Reset(void);
    vector<QueryLogItem> Core_GetQueryLogItem();
    //内存操作函数
    int Core_TempNumMem_Reset(void);
private:
    ZZH_QueryCore(void);
    ~ZZH_QueryCore(void);
    ZZH_QueryCore(const ZZH_QueryCore &signal);
    const ZZH_QueryCore &operator=(const ZZH_QueryCore &signal);
    //主文件操作函数
    const char *Core_MainFile_GetURL(void);
    //内存操作函数
    int  Core_DataMem_Allocated(void);
    int  Core_NumMem_Allocated(void);
    int  Core_TempDataMem_Reset(void);
    void Core_ClearDataMem(void);
    void Core_ClearNumMem(void);
private:
    //单例对象
    static ZZH_QueryCore* m_instance;
    //内存对象
    char *Mem_Indicator         [MAX_MEMBLOCK_SIZE];    //主内存地址指针数组
    char *Temp_Mem_Indicator    [MAX_MEMBLOCK_SIZE];    //主内存临时位置地址指针数组
    int  *Mem_Num_Indicator     [MAX_MEMBLOCK_SIZE];    //与主内存对应的查重次数地址指针数组
    int  *Temp_Mem_Num_Indicator[MAX_MEMBLOCK_SIZE];    //与主内存对应的查重次数临时地址指针数组
    //成员变量
    char m_cstrMainFileURL      [FILEPATH_LENGTH];      //主文件路径
    char Main_File_Num_Path     [FILEPATH_LENGTH];      //主文件查找次数文件路径
    mutex mutex_vecQueryLog;
    vector<QueryLogItem> m_vecQueryLog;
    unsigned int m_uiIgnoreHeadLength;
};
//******************************************************************************
#endif // ZZH_QUERYCORE_H
//******************************************************************************

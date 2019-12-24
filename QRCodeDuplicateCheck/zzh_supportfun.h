#ifndef ZZH_SUPPORTFUN_H
#define ZZH_SUPPORTFUN_H
//**********************************************************
#include <QString>
#include <QStringList>
#include <QDir>
#include <QDebug>
//**********************************************************
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//********************************************************************
#define cout qDebug()<< "["<<__FILE__<<"]" <<"["<<__LINE__<<"行 ]"
//********************************************************************
#define FILEPATH_LENGTH         1024
//**********************************************************
#define MAX_FILELIST_NUM        999
#define MAX_QUERYLOGLIST_NUM    200
//**********************************************************
//成功定义
#define ZZH_SUCCESS_NOMSG     0       //操作成功但取消提示
#define ZZH_SUCCESS     1               //操作成功
//警告定义
#define ZZH_WARNING_MAINFILE_LOGEMPTY   100     //次数记录文件不存在
//错误定义
#define ZZH_ERROR_MAINFILE_OPEN         -1      //主文件打开失败
#define ZZH_ERROR_MAINFILE_SETPATH      -2      //主文件设置路径失败
#define ZZH_ERROR_MAINFILE_GETPATH      -3      //主文件获取路径失败
#define ZZH_ERROR_MAINFILE_PATHEMPTY    -4      //主文件路径为空

#define ZZH_ERROR_SUBFILE_OPEN          -100      //子文件打开失败
#define ZZH_ERROR_SUBFILE_EXIST         -101      //子文件已经存在
#define ZZH_ERROR_SUBFILE_SETPATH       -102      //子文件设置路径失败
#define ZZH_ERROR_SUBFILE_CREATE       -103      //子文件创建失败

#define ZZH_ERROR_FILEDELETE         -110      //文件删除失败

#define ZZH_ERROR_MEMOER_RESET      -200      //内存重置失败

#define ZZH_ERROR_MEMNUM_RESET      -300      //记录次数内存重置失败

#define ZZH_ERROR_CORE_TEMPMEM_RESET      -500      //内核错误-数据信息内存重置
#define ZZH_ERROR_CORE_TEMPMEM_Num_RESET      -501  //内核错误-重复次数内存重置
#define ZZH_ERROR_CORE_HEADLENGTH   -502    //内核错误-忽略头部数据错误
#define ZZH_ERROR_CORE_DATAEMPTY    -503
#define ZZH_ERROR_CORE_DATAOVERSIZE -504
#define ZZH_ERROR_CORE_SETMAINFILELOGPATH -505  //设置主文件LOG路径
#define ZZH_ERROR_CORE_PARAMETER -506 //参数不合法

#define ZZH_ERROR_CORE_LOG_URL -507 //无法打开LOG文件
#define ZZH_ERROR_CORE_LOG_OPEN -506 //无法打开LOG文件

#define ZZH_ERROR_TCP_CLINRT_CONNECT -1000 //连接到服务器失败

#define ZZH_ERROR_CORE         -2000      //主文件打开失败
//**********************************************************
#include <stdio.h>
#include <direct.h>
#include <stdlib.h>
#include <io.h>
//**********************************************************
extern QString gZZH_QT_ExtractFileName(const QString URL);
extern string gZZH_QT_QString2str(const QString qstr);
extern QStringList gZZH_QT_GetTXTFromFolder(const QString &qstrFolderURL);
//**********************************************************
//文件处理-创建多级文件夹
extern void gZZH_Mkdirs(const char *muldir);
//文件处理-文件路径提取文件名
extern char *gZZH_SplitFileName(const char *cp_FilePath);
//**********************************************************
//字符串处理-去除首尾空格函数
extern void gZZH_TrimSpaces(char *strIn, char *strOut);
extern void gZZH_TrimShift(char *cstr);
//**********************************************************
//时间打印函数
extern string gZZH_GetTime();
#endif // ZZH_SUPPORTFUN_H

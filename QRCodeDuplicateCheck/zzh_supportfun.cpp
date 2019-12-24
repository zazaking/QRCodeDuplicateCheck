#include "zzh_supportfun.h"
//******************************************************************************
//QT功能支持函数-URL提取文件名
QString gZZH_QT_ExtractFileName(const QString URL)
{
    QString rst;
    QStringList t_SplitList_1 = URL.split(".txt");
    if(t_SplitList_1.count() == 1){
        t_SplitList_1 = URL.split(".TXT");
    }
    if(t_SplitList_1.count() == 1){
        return rst;
    }

    QString URL_1 = t_SplitList_1.at(0);
    QStringList t_SplitList_2 = URL_1.split("/");
    if(t_SplitList_2.count() == 1){
        t_SplitList_2 = URL_1.split("\\");
    }
    if(t_SplitList_2.count() == 1){
        return rst;
    }

    rst = t_SplitList_2.at(t_SplitList_2.length()-1);
    return rst;
}

//QT功能支持函数-QString 2 string
string gZZH_QT_QString2str(const QString qstr)
{
    QByteArray cdata = qstr.toLocal8Bit();
    return string(cdata);
}

//QT功能支持函数-获取文件夹下所有txt
QStringList gZZH_QT_GetTXTFromFolder(const QString &qstrFolderURL)
{
    QDir dir(qstrFolderURL);
    QStringList nameFilters;
    nameFilters << "*.txt";
    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
    return files;
}

//******************************************************************************
//文件处理-创建多级文件夹
void gZZH_Mkdirs(const char *cp_DirPath){
    char tArr_DirPath[512];
    strncpy(tArr_DirPath,cp_DirPath,512);
    size_t tui_DirPathLength = strlen(tArr_DirPath);

    unsigned int i;
    for(i = 0; i < tui_DirPathLength; i++) {
        if( tArr_DirPath[i] == '\\') {
            tArr_DirPath[i] = '\0';
            if( access(tArr_DirPath,0) != 0 )
                mkdir(tArr_DirPath);
            tArr_DirPath[i] ='\\';
        }
    }
    if( tui_DirPathLength > 0 && access(tArr_DirPath ,0)!=0)
        mkdir(tArr_DirPath);
    return;
}

//文件处理-文件路径提取文件名
char *gZZH_SplitFileName(const char *cp_FilePath){
    char *rst = nullptr;
    if( (rst = strrchr(cp_FilePath,'\\')) != nullptr ){
        rst = rst + 1;
    } else if ((rst = strrchr(cp_FilePath,'/')) != nullptr){
        rst = rst + 1;
    }

    return rst;
}
//******************************************************************************
//字符串处理-去除首尾空格函数
void gZZH_TrimSpaces(char *strIn, char *strOut){
    size_t i = 0;
    size_t j = strlen(strIn) - 1;

    while(strIn[i] == ' ')
        ++i;

    while(strIn[j] == ' ')
        --j;

    strncpy(strOut, strIn + i , j - i + 1);
    strOut[j - i + 1] = '\0';
}

//字符串处理-去除首尾空格函数
void gZZH_TrimShift(char *cstr){
    while(cstr[strlen(cstr)-1] == '\n' ||
          cstr[strlen(cstr)-1] == '\r'){
        cstr[strlen(cstr)-1] = '\0';
    }
}

//******************************************************************************
//时间打印函数
string gZZH_GetTime(){
    static char nowtime[20];
    time_t rawtime;
    struct tm * ltime;
    ltime = localtime(&rawtime);
    strftime(nowtime,20,"%Y_%m_%d_%H_%M_%S",ltime);
    return nowtime;
}

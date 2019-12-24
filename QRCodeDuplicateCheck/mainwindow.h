void on_f_TCPClientOpenButton_clicked();
//********************************************************************
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//********************************************************************
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTableWidget>
#include <QComboBox>
#include <QMediaPlayer>
#include <QMetaType>
//********************************************************************
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
//********************************************************************
#include "zzh_supportfun.h"
#include "zzh_logiccontrol.h"
#include "zzh_tcpcontrol.h"
//********************************************************************
#define OFFLINE_MODE    0
#define TCP_SERVER      1
#define DISSENABLE_ALL  2
#define ENABLE_ALL      3
#define CHANGE_FILE     4
#define CHANGE_HEAD     5
#define TCP_CLIENT      6
#define EXFILE_MODE     7
//********************************************************************
//选中文件列表结构体
typedef struct SelectFile{
    QString m_qstrFileURL;  //文件URL路径
    int     m_iFileRow;     //文件在文件表格中的行信息
    size_t  m_uiFileSize;   //文件中数据条数
    SelectFile(QString _qstrFileURL,int _iFileRow,size_t _uiFileSize):
        m_qstrFileURL(_qstrFileURL),
        m_iFileRow(_iFileRow),
        m_uiFileSize(_uiFileSize)
    {}
}SelectFile;
//********************************************************************
namespace Ui {
class MainWindow;
}
//********************************************************************
class QTcpSocket;
class QTcpServer;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    /*UI控制函数*/
    void UI_MainWindowWidgetInitial(void);      //UI控制函数_主界面Widget初始化
    void UI_Enable_Control(int i);              //UI控制函数_模式切换/使能控件函数
    void UI_CreateFileListTable(int row);       //UI控制函数_创建文件列表表格
    void UI_FileListTableDeleteItem(int row);   //UI控制函数_文件列表表格移除一项
    void UI_CreateQueryLogListTable(int row);   //UI控制函数_创建比对信息列表表格
    void UI_ShowMessageBox(int rst);            //UI控制函数_根据返回值显示提示信息
private slots:
    void TCPControl_TCPRecvAlarm(vector<QueryLogItem> t_vecQueryLog);
private slots:
    /*信号函数*/
    void SIGNAL_SelectFileChange(int row, int col); //信号函数-文件列表复选框勾选信号
    /*槽位函数*/
    void on_f_MainFileLoadButton_clicked();         //槽位函数-主文件加载按钮
    void on_f_FileLocalLoadButton_clicked();        //槽位函数-子文件加载按钮
    void on_f_FilesLoadButton_clicked();            //槽位函数-子文件批量加载按钮
    void on_f_FileDeleteButton_clicked();           //槽位函数-子文件删除按钮
    void on_f_FileLocalCheckExecButton_clicked();   //槽位函数-本地文件查重
    void on_f_SaveFileCurrentCreateButton_clicked();


    void on_f_TCPClientOpenButton_clicked();

    void on_f_SaveFileCurrentDeleteButton_clicked();

    void on_f_QueryLogSaveButton_clicked();

    void on_f_QueryLogTableClearButton_clicked();

    void on_f_QueryLogResetButton_clicked();

    void on_f_QueryLogLoadButton_clicked();

    void on_f_ExportFileExecButton_clicked();

    void on_f_CodeGunSelectButton_clicked();

private:
    /*界面UI对象*/
    Ui::MainWindow *ui;
    /*逻辑类对象*/
    zzh_logiccontrol m_zzh_logiccontrol;
    zzh_TCPControl *m_zzh_TCPControl;
    /*文件列表数据变量*/
    int m_iFileListNum; //文件列表文件数目
    set<QString> m_setSubFile;  //子文件集合
    vector<SelectFile> m_vecReelectionData; //勾选信息结构体数组
    /*UI属性*/
    QTableWidget    *m_FileListTable;
    QTableWidget    *m_QueryLogListTable;
    QLineEdit       *m_MainFileCurrentLineEdit;
    QLineEdit       *m_SaveFileCurrentLineEdit;
    QLineEdit       *m_ExportFileNameLineEdit;
    QLineEdit       *m_CodeGunLineEdit;
    QLineEdit       *m_TCPClientServerIPlineEdit;
    QLineEdit       *m_TCPClientServerPortLineEdit;
    QCheckBox       *m_EnableCompaeCheckBox;
    QCheckBox       *m_EnableMusicCheckBox;
    QComboBox       *m_SaveFileField_1;
    QComboBox       *m_SaveFileField_2;
    QComboBox       *m_SaveFileField_NUM;

    QPushButton     *m_TCPClientOpenButton;
    /*播放器属性*/
    QMediaPlayer m_qtaudioPlayer;

    QString m_qstrCurrentFileURL;
};
//********************************************************************
#endif // MAINWINDOW_H

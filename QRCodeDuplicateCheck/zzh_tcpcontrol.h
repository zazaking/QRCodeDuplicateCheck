//******************************************************************************
#pragma once
#ifndef ZZH_TCPCONTROL_H
#define ZZH_TCPCONTROL_H
//******************************************************************************
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
//******************************************************************************
#include "zzh_supportfun.h"
#include "zzh_querycore.h"
//******************************************************************************
#define TCPControl_QueryMode_SaveOnly  0
#define TCPControl_QueryMode_QueryOnly 1
#define TCPControl_QueryMode_QuerySave 2
//******************************************************************************
class QTcpSocket;
class QTcpServer;
class zzh_TCPControl : public QObject
{
    Q_OBJECT
public:
    zzh_TCPControl();
    ~zzh_TCPControl();
    //TCP Client Public
    int  TCPControl_TCPClientInit(QString _qstrServerIP,quint16 _i16ServerPort);
    void TCPControl_TCPClientWrite(QString qstrSendData);
    void TCPControl_TCPClientDestroy(void);
    //Logic Public
    int TCPControl_CreateSaveFile(QString t_qstrCurrentFileURL);
    int TCPControl_DeleateSaveFile(void);
    int TCPControl_CodeReaderQueryExec(QString qstrQueryData);
    //TCP Query Mode
    int getTCPControl_QueryMode() const;
    void setTCPControl_QueryMode(int value);
private:
    //TCP Server
    void TCPControl_TCPServerInit(void);
    void TCPControl_TCPServerDestroy(void);
    //Save File Row
    uint uiSaveFileRow() const;
    uint uiSaveFileRow(const QString qstrFileURL) const;
    void setUiSaveFileRow(const uint &uiSaveFileRow);
    void setUiSaveFileRow(const QString qstrFileURL);
    //Save File
    int TCPControl_SetSaveURL(QString _qstrSaveFileURL);
    QString TCPControl_GetSaveURL(void);
    bool TCPControl_EmptySaveURL(void);
    void TCPControl_Save2SaveURL(const char* t_strSaveData);
private slots:
    //TCP Server
    void TCPControl_TCPServerNewConnect(void);
    void TCPControl_TCPServerRecvData(void);
    void TCPControl_TCPServerDisconnected(void);
    //TCP Client
    void TCPControl_TCPClientNewConnect(void);
    void TCPControl_TCPClientRecvData(void);
    void TCPControl_TCPClientDisconnected(void);
signals:
    void TCPControl_TCPSendAlarm(vector<QueryLogItem>);
private:
    //TCP Server
    QTcpServer      *m_TCPServer;           //TCPServer
    QTcpSocket      *m_TCPServerSocket;     //TCPServer_Socket
    QHostAddress    m_TCPServerClientAddr;  //TCPServerClientAddr
    //TCP Client
    QTcpSocket      *m_TCPClientSocket;     //TCP_Socket
    //Save File
    QString m_qstrSaveFileURL;  //SaveFileURL
    uint m_uiSaveFileRow;       //SaveFileROW
    //TCP Query Mode
    int TCPControl_QueryMode = TCPControl_QueryMode_QuerySave;
};
//******************************************************************************
#endif // ZZH_TCPCONTROL_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *f_FileLocalgroupBox;
    QPushButton *f_FileLocalLoadButton;
    QPushButton *f_FileLocalCheckExecButton;
    QGroupBox *f_TCPServerGroupBox;
    QLabel *label_2;
    QLineEdit *f_TCPServerClientLinkAddrLineEdit;
    QPushButton *f_TCPServerOpenButton;
    QPushButton *f_TCPServerCloseButton;
    QGroupBox *f_FileListGroupBox;
    QTableWidget *f_FileListTable;
    QPushButton *f_FileDeleteButton;
    QPushButton *f_FilesLoadButton;
    QGroupBox *f_ExportFileGroupBox;
    QLineEdit *f_ExportFileNameLineEdit;
    QLabel *label_10;
    QPushButton *f_ExportFileExecButton;
    QPushButton *f_ExportFileModeButton;
    QLabel *label_11;
    QPushButton *f_ExportFileFolderOpenButton;
    QGroupBox *f_QueryLogGroupBox;
    QTableWidget *f_QueryLogListTable;
    QCheckBox *f_EnableMusicCheckBox;
    QCheckBox *f_EnableCompaeCheckBox;
    QPushButton *f_QueryLogSaveButton;
    QPushButton *f_QueryLogTableClearButton;
    QPushButton *f_QueryLogResetButton;
    QPushButton *f_QueryLogLoadButton;
    QGroupBox *groupBox_7;
    QLineEdit *f_SelectIgnoreHeadLineEdit;
    QLabel *label_6;
    QPushButton *f_SelectIgnoreHeadModeButton;
    QPushButton *f_SelectIgnoreHeadResetButton;
    QPushButton *f_QueryLogSaveButton_2;
    QGroupBox *f_TCPClientGroupBox;
    QPushButton *f_TCPClientCloseButton;
    QLabel *label_8;
    QLineEdit *f_TCPClientServerIPlineEdit;
    QLabel *label_7;
    QLineEdit *f_TCPClientServerPortLineEdit;
    QPushButton *f_TCPClientOpenButton;
    QGroupBox *f_CodeGunGroupBox;
    QLineEdit *f_CodeGunLineEdit;
    QLabel *label_9;
    QPushButton *f_CodeGunSelectButton;
    QPushButton *f_QueryLogResetButton_2;
    QGroupBox *groupBox_10;
    QGroupBox *f_MainFileGroupBox;
    QLineEdit *f_MainFileCurrentLineEdit;
    QLabel *label;
    QPushButton *f_MainFileLoadButton;
    QGroupBox *f_SaveFileGroupBox;
    QLineEdit *f_SaveFileCurrentLineEdit;
    QLabel *label_3;
    QComboBox *f_SaveFileField_1;
    QPushButton *f_SaveFileModeButton;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *f_SaveFileField_2;
    QPushButton *f_SaveFileCurrentCreateButton;
    QPushButton *f_SaveFileCurrentDeleteButton;
    QComboBox *f_SaveFileField_Num;
    QLabel *label_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(2000, 2000);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        f_FileLocalgroupBox = new QGroupBox(centralWidget);
        f_FileLocalgroupBox->setObjectName(QStringLiteral("f_FileLocalgroupBox"));
        f_FileLocalgroupBox->setGeometry(QRect(690, 560, 641, 91));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        f_FileLocalgroupBox->setFont(font);
        f_FileLocalgroupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(0,128,0);\n"
"            border-width: 3px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            color: rgb(0,128,0);\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        f_FileLocalLoadButton = new QPushButton(f_FileLocalgroupBox);
        f_FileLocalLoadButton->setObjectName(QStringLiteral("f_FileLocalLoadButton"));
        f_FileLocalLoadButton->setGeometry(QRect(60, 30, 381, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setWeight(75);
        f_FileLocalLoadButton->setFont(font1);
        f_FileLocalLoadButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_FileLocalCheckExecButton = new QPushButton(f_FileLocalgroupBox);
        f_FileLocalCheckExecButton->setObjectName(QStringLiteral("f_FileLocalCheckExecButton"));
        f_FileLocalCheckExecButton->setGeometry(QRect(510, 30, 111, 41));
        QFont font2;
        font2.setPointSize(12);
        f_FileLocalCheckExecButton->setFont(font2);
        f_FileLocalCheckExecButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_TCPServerGroupBox = new QGroupBox(centralWidget);
        f_TCPServerGroupBox->setObjectName(QStringLiteral("f_TCPServerGroupBox"));
        f_TCPServerGroupBox->setGeometry(QRect(910, 950, 300, 211));
        f_TCPServerGroupBox->setFont(font2);
        f_TCPServerGroupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(128,0,0);\n"
"            border-width: 2px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            color: rgb(128,0,0);\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        label_2 = new QLabel(f_TCPServerGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 61, 31));
        QFont font3;
        font3.setPointSize(11);
        label_2->setFont(font3);
        f_TCPServerClientLinkAddrLineEdit = new QLineEdit(f_TCPServerGroupBox);
        f_TCPServerClientLinkAddrLineEdit->setObjectName(QStringLiteral("f_TCPServerClientLinkAddrLineEdit"));
        f_TCPServerClientLinkAddrLineEdit->setGeometry(QRect(110, 90, 171, 31));
        QFont font4;
        font4.setPointSize(9);
        f_TCPServerClientLinkAddrLineEdit->setFont(font4);
        f_TCPServerClientLinkAddrLineEdit->setAlignment(Qt::AlignCenter);
        f_TCPServerClientLinkAddrLineEdit->setReadOnly(true);
        f_TCPServerOpenButton = new QPushButton(f_TCPServerGroupBox);
        f_TCPServerOpenButton->setObjectName(QStringLiteral("f_TCPServerOpenButton"));
        f_TCPServerOpenButton->setGeometry(QRect(30, 40, 250, 30));
        f_TCPServerOpenButton->setFont(font2);
        f_TCPServerOpenButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_TCPServerCloseButton = new QPushButton(f_TCPServerGroupBox);
        f_TCPServerCloseButton->setObjectName(QStringLiteral("f_TCPServerCloseButton"));
        f_TCPServerCloseButton->setGeometry(QRect(30, 150, 250, 30));
        f_TCPServerCloseButton->setFont(font2);
        f_TCPServerCloseButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_FileListGroupBox = new QGroupBox(centralWidget);
        f_FileListGroupBox->setObjectName(QStringLiteral("f_FileListGroupBox"));
        f_FileListGroupBox->setGeometry(QRect(10, 10, 671, 511));
        f_FileListGroupBox->setFont(font);
        f_FileListGroupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(25,25,112);\n"
"            border-width: 3px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            color: rgb(25,25,112);\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        f_FileListTable = new QTableWidget(f_FileListGroupBox);
        f_FileListTable->setObjectName(QStringLiteral("f_FileListTable"));
        f_FileListTable->setGeometry(QRect(15, 20, 640, 441));
        f_FileListTable->setLayoutDirection(Qt::LeftToRight);
        f_FileListTable->setTextElideMode(Qt::ElideNone);
        f_FileDeleteButton = new QPushButton(f_FileListGroupBox);
        f_FileDeleteButton->setObjectName(QStringLiteral("f_FileDeleteButton"));
        f_FileDeleteButton->setGeometry(QRect(550, 470, 100, 31));
        f_FileDeleteButton->setFont(font2);
        f_FileDeleteButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_FilesLoadButton = new QPushButton(f_FileListGroupBox);
        f_FilesLoadButton->setObjectName(QStringLiteral("f_FilesLoadButton"));
        f_FilesLoadButton->setGeometry(QRect(20, 470, 131, 31));
        QFont font5;
        font5.setFamily(QStringLiteral("Agency FB"));
        font5.setPointSize(12);
        font5.setBold(false);
        font5.setWeight(50);
        f_FilesLoadButton->setFont(font5);
        f_FilesLoadButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_ExportFileGroupBox = new QGroupBox(centralWidget);
        f_ExportFileGroupBox->setObjectName(QStringLiteral("f_ExportFileGroupBox"));
        f_ExportFileGroupBox->setGeometry(QRect(10, 530, 671, 121));
        f_ExportFileGroupBox->setFont(font);
        f_ExportFileGroupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(	205,92,92);\n"
"            border-width: 3px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            color: rgb(	205,92,92);\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        f_ExportFileNameLineEdit = new QLineEdit(f_ExportFileGroupBox);
        f_ExportFileNameLineEdit->setObjectName(QStringLiteral("f_ExportFileNameLineEdit"));
        f_ExportFileNameLineEdit->setGeometry(QRect(240, 70, 231, 28));
        QFont font6;
        font6.setPointSize(8);
        f_ExportFileNameLineEdit->setFont(font6);
        f_ExportFileNameLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        f_ExportFileNameLineEdit->setReadOnly(false);
        label_10 = new QLabel(f_ExportFileGroupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(170, 70, 71, 31));
        QFont font7;
        font7.setPointSize(14);
        font7.setBold(true);
        font7.setWeight(75);
        label_10->setFont(font7);
        f_ExportFileExecButton = new QPushButton(f_ExportFileGroupBox);
        f_ExportFileExecButton->setObjectName(QStringLiteral("f_ExportFileExecButton"));
        f_ExportFileExecButton->setGeometry(QRect(543, 70, 109, 31));
        f_ExportFileExecButton->setFont(font1);
        f_ExportFileExecButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_ExportFileModeButton = new QPushButton(f_ExportFileGroupBox);
        f_ExportFileModeButton->setObjectName(QStringLiteral("f_ExportFileModeButton"));
        f_ExportFileModeButton->setGeometry(QRect(20, 25, 250, 31));
        f_ExportFileModeButton->setFont(font1);
        f_ExportFileModeButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        label_11 = new QLabel(f_ExportFileGroupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(472, 70, 41, 31));
        label_11->setFont(font7);
        f_ExportFileFolderOpenButton = new QPushButton(f_ExportFileGroupBox);
        f_ExportFileFolderOpenButton->setObjectName(QStringLiteral("f_ExportFileFolderOpenButton"));
        f_ExportFileFolderOpenButton->setGeometry(QRect(20, 70, 111, 30));
        f_ExportFileFolderOpenButton->setFont(font2);
        f_ExportFileFolderOpenButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_QueryLogGroupBox = new QGroupBox(centralWidget);
        f_QueryLogGroupBox->setObjectName(QStringLiteral("f_QueryLogGroupBox"));
        f_QueryLogGroupBox->setGeometry(QRect(1340, 10, 431, 641));
        f_QueryLogGroupBox->setFont(font);
        f_QueryLogGroupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(25,25,112);\n"
"            border-width: 3px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            color: rgb(25,25,112);\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        f_QueryLogListTable = new QTableWidget(f_QueryLogGroupBox);
        f_QueryLogListTable->setObjectName(QStringLiteral("f_QueryLogListTable"));
        f_QueryLogListTable->setGeometry(QRect(20, 50, 391, 441));
        f_EnableMusicCheckBox = new QCheckBox(f_QueryLogGroupBox);
        f_EnableMusicCheckBox->setObjectName(QStringLiteral("f_EnableMusicCheckBox"));
        f_EnableMusicCheckBox->setGeometry(QRect(290, 30, 121, 21));
        QFont font8;
        font8.setPointSize(11);
        font8.setBold(true);
        font8.setUnderline(false);
        font8.setWeight(75);
        f_EnableMusicCheckBox->setFont(font8);
        f_EnableMusicCheckBox->setStyleSheet(QStringLiteral(""));
        f_EnableMusicCheckBox->setChecked(true);
        f_EnableMusicCheckBox->setTristate(false);
        f_EnableCompaeCheckBox = new QCheckBox(f_QueryLogGroupBox);
        f_EnableCompaeCheckBox->setObjectName(QStringLiteral("f_EnableCompaeCheckBox"));
        f_EnableCompaeCheckBox->setGeometry(QRect(290, 10, 121, 21));
        f_EnableCompaeCheckBox->setFont(font8);
        f_EnableCompaeCheckBox->setStyleSheet(QStringLiteral(""));
        f_EnableCompaeCheckBox->setChecked(true);
        f_EnableCompaeCheckBox->setTristate(false);
        f_QueryLogSaveButton = new QPushButton(f_QueryLogGroupBox);
        f_QueryLogSaveButton->setObjectName(QStringLiteral("f_QueryLogSaveButton"));
        f_QueryLogSaveButton->setGeometry(QRect(20, 500, 391, 41));
        QFont font9;
        font9.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font9.setPointSize(19);
        font9.setBold(true);
        font9.setWeight(75);
        f_QueryLogSaveButton->setFont(font9);
        f_QueryLogSaveButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_QueryLogTableClearButton = new QPushButton(f_QueryLogGroupBox);
        f_QueryLogTableClearButton->setObjectName(QStringLiteral("f_QueryLogTableClearButton"));
        f_QueryLogTableClearButton->setGeometry(QRect(20, 550, 191, 30));
        f_QueryLogTableClearButton->setFont(font2);
        f_QueryLogTableClearButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_QueryLogResetButton = new QPushButton(f_QueryLogGroupBox);
        f_QueryLogResetButton->setObjectName(QStringLiteral("f_QueryLogResetButton"));
        f_QueryLogResetButton->setGeometry(QRect(220, 550, 191, 30));
        f_QueryLogResetButton->setFont(font2);
        f_QueryLogResetButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_QueryLogLoadButton = new QPushButton(f_QueryLogGroupBox);
        f_QueryLogLoadButton->setObjectName(QStringLiteral("f_QueryLogLoadButton"));
        f_QueryLogLoadButton->setGeometry(QRect(20, 590, 391, 30));
        f_QueryLogLoadButton->setFont(font2);
        f_QueryLogLoadButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(560, 940, 311, 201));
        groupBox_7->setFont(font);
        groupBox_7->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(25,25,112);\n"
"            border-width: 2px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            color: rgb(25,25,112);\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        f_SelectIgnoreHeadLineEdit = new QLineEdit(groupBox_7);
        f_SelectIgnoreHeadLineEdit->setObjectName(QStringLiteral("f_SelectIgnoreHeadLineEdit"));
        f_SelectIgnoreHeadLineEdit->setGeometry(QRect(30, 102, 250, 31));
        f_SelectIgnoreHeadLineEdit->setFont(font2);
        f_SelectIgnoreHeadLineEdit->setAlignment(Qt::AlignCenter);
        f_SelectIgnoreHeadLineEdit->setReadOnly(false);
        label_6 = new QLabel(groupBox_7);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(165, 80, 112, 21));
        label_6->setFont(font2);
        f_SelectIgnoreHeadModeButton = new QPushButton(groupBox_7);
        f_SelectIgnoreHeadModeButton->setObjectName(QStringLiteral("f_SelectIgnoreHeadModeButton"));
        f_SelectIgnoreHeadModeButton->setGeometry(QRect(30, 29, 250, 41));
        f_SelectIgnoreHeadModeButton->setFont(font1);
        f_SelectIgnoreHeadModeButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_SelectIgnoreHeadResetButton = new QPushButton(groupBox_7);
        f_SelectIgnoreHeadResetButton->setObjectName(QStringLiteral("f_SelectIgnoreHeadResetButton"));
        f_SelectIgnoreHeadResetButton->setGeometry(QRect(30, 155, 250, 30));
        f_SelectIgnoreHeadResetButton->setFont(font2);
        f_SelectIgnoreHeadResetButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_QueryLogSaveButton_2 = new QPushButton(centralWidget);
        f_QueryLogSaveButton_2->setObjectName(QStringLiteral("f_QueryLogSaveButton_2"));
        f_QueryLogSaveButton_2->setGeometry(QRect(1440, 1150, 321, 31));
        f_QueryLogSaveButton_2->setFont(font1);
        f_QueryLogSaveButton_2->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_TCPClientGroupBox = new QGroupBox(centralWidget);
        f_TCPClientGroupBox->setObjectName(QStringLiteral("f_TCPClientGroupBox"));
        f_TCPClientGroupBox->setGeometry(QRect(690, 330, 641, 221));
        f_TCPClientGroupBox->setFont(font);
        f_TCPClientGroupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(128,0,0);\n"
"            border-width: 3px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            color: rgb(128,0,0);\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        f_TCPClientCloseButton = new QPushButton(f_TCPClientGroupBox);
        f_TCPClientCloseButton->setObjectName(QStringLiteral("f_TCPClientCloseButton"));
        f_TCPClientCloseButton->setGeometry(QRect(400, 70, 200, 30));
        f_TCPClientCloseButton->setFont(font2);
        f_TCPClientCloseButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        label_8 = new QLabel(f_TCPClientGroupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 70, 181, 31));
        QFont font10;
        font10.setPointSize(14);
        label_8->setFont(font10);
        f_TCPClientServerIPlineEdit = new QLineEdit(f_TCPClientGroupBox);
        f_TCPClientServerIPlineEdit->setObjectName(QStringLiteral("f_TCPClientServerIPlineEdit"));
        f_TCPClientServerIPlineEdit->setGeometry(QRect(180, 30, 151, 31));
        QFont font11;
        font11.setPointSize(15);
        font11.setBold(true);
        font11.setWeight(75);
        f_TCPClientServerIPlineEdit->setFont(font11);
        f_TCPClientServerIPlineEdit->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(f_TCPClientGroupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 30, 121, 31));
        label_7->setFont(font10);
        f_TCPClientServerPortLineEdit = new QLineEdit(f_TCPClientGroupBox);
        f_TCPClientServerPortLineEdit->setObjectName(QStringLiteral("f_TCPClientServerPortLineEdit"));
        f_TCPClientServerPortLineEdit->setGeometry(QRect(230, 70, 101, 31));
        f_TCPClientServerPortLineEdit->setFont(font11);
        f_TCPClientServerPortLineEdit->setAlignment(Qt::AlignCenter);
        f_TCPClientServerPortLineEdit->setReadOnly(false);
        f_TCPClientOpenButton = new QPushButton(f_TCPClientGroupBox);
        f_TCPClientOpenButton->setObjectName(QStringLiteral("f_TCPClientOpenButton"));
        f_TCPClientOpenButton->setGeometry(QRect(400, 20, 200, 41));
        f_TCPClientOpenButton->setFont(font1);
        f_TCPClientOpenButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_CodeGunGroupBox = new QGroupBox(f_TCPClientGroupBox);
        f_CodeGunGroupBox->setObjectName(QStringLiteral("f_CodeGunGroupBox"));
        f_CodeGunGroupBox->setGeometry(QRect(20, 110, 601, 91));
        f_CodeGunGroupBox->setFont(font);
        f_CodeGunGroupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(210,105,30);\n"
"            border-width: 3px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            color: rgb(210,105,30);\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        f_CodeGunLineEdit = new QLineEdit(f_CodeGunGroupBox);
        f_CodeGunLineEdit->setObjectName(QStringLiteral("f_CodeGunLineEdit"));
        f_CodeGunLineEdit->setGeometry(QRect(20, 44, 351, 28));
        f_CodeGunLineEdit->setFont(font6);
        f_CodeGunLineEdit->setReadOnly(false);
        label_9 = new QLabel(f_CodeGunGroupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(290, 17, 81, 31));
        label_9->setFont(font2);
        f_CodeGunSelectButton = new QPushButton(f_CodeGunGroupBox);
        f_CodeGunSelectButton->setObjectName(QStringLiteral("f_CodeGunSelectButton"));
        f_CodeGunSelectButton->setGeometry(QRect(385, 40, 201, 31));
        f_CodeGunSelectButton->setFont(font1);
        f_CodeGunSelectButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_QueryLogResetButton_2 = new QPushButton(centralWidget);
        f_QueryLogResetButton_2->setObjectName(QStringLiteral("f_QueryLogResetButton_2"));
        f_QueryLogResetButton_2->setGeometry(QRect(1280, 1130, 150, 31));
        f_QueryLogResetButton_2->setFont(font2);
        f_QueryLogResetButton_2->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        groupBox_10 = new QGroupBox(centralWidget);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(690, 10, 641, 311));
        groupBox_10->setFont(font);
        groupBox_10->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(25,25,112);\n"
"            border-width: 3px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            color: rgb(25,25,112);\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        f_MainFileGroupBox = new QGroupBox(groupBox_10);
        f_MainFileGroupBox->setObjectName(QStringLiteral("f_MainFileGroupBox"));
        f_MainFileGroupBox->setGeometry(QRect(20, 30, 601, 101));
        f_MainFileGroupBox->setFont(font);
        f_MainFileGroupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(25,25,112);\n"
"            border-width: 2px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            color: rgb(25,25,112);\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        f_MainFileCurrentLineEdit = new QLineEdit(f_MainFileGroupBox);
        f_MainFileCurrentLineEdit->setObjectName(QStringLiteral("f_MainFileCurrentLineEdit"));
        f_MainFileCurrentLineEdit->setGeometry(QRect(300, 50, 271, 30));
        f_MainFileCurrentLineEdit->setFont(font4);
        f_MainFileCurrentLineEdit->setAlignment(Qt::AlignCenter);
        f_MainFileCurrentLineEdit->setReadOnly(true);
        label = new QLabel(f_MainFileGroupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(470, 20, 101, 26));
        label->setFont(font2);
        f_MainFileLoadButton = new QPushButton(f_MainFileGroupBox);
        f_MainFileLoadButton->setObjectName(QStringLiteral("f_MainFileLoadButton"));
        f_MainFileLoadButton->setGeometry(QRect(20, 40, 200, 41));
        f_MainFileLoadButton->setFont(font1);
        f_MainFileLoadButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_SaveFileGroupBox = new QGroupBox(groupBox_10);
        f_SaveFileGroupBox->setObjectName(QStringLiteral("f_SaveFileGroupBox"));
        f_SaveFileGroupBox->setGeometry(QRect(20, 140, 601, 151));
        f_SaveFileGroupBox->setFont(font);
        f_SaveFileGroupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"            border-color: rgb(25,25,112);\n"
"            border-width: 2px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"        }\n"
"        QGroupBox::title {\n"
"            color: rgb(25,25,112);\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        f_SaveFileCurrentLineEdit = new QLineEdit(f_SaveFileGroupBox);
        f_SaveFileCurrentLineEdit->setObjectName(QStringLiteral("f_SaveFileCurrentLineEdit"));
        f_SaveFileCurrentLineEdit->setEnabled(true);
        f_SaveFileCurrentLineEdit->setGeometry(QRect(240, 47, 271, 30));
        f_SaveFileCurrentLineEdit->setFont(font6);
        f_SaveFileCurrentLineEdit->setReadOnly(true);
        label_3 = new QLabel(f_SaveFileGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 20, 115, 21));
        label_3->setFont(font2);
        f_SaveFileField_1 = new QComboBox(f_SaveFileGroupBox);
        f_SaveFileField_1->setObjectName(QStringLiteral("f_SaveFileField_1"));
        f_SaveFileField_1->setEnabled(true);
        f_SaveFileField_1->setGeometry(QRect(75, 110, 50, 21));
        QFont font12;
        font12.setPointSize(13);
        f_SaveFileField_1->setFont(font12);
        f_SaveFileField_1->setCursor(QCursor(Qt::PointingHandCursor));
        f_SaveFileModeButton = new QPushButton(f_SaveFileGroupBox);
        f_SaveFileModeButton->setObjectName(QStringLiteral("f_SaveFileModeButton"));
        f_SaveFileModeButton->setGeometry(QRect(20, 40, 200, 41));
        f_SaveFileModeButton->setFont(font1);
        f_SaveFileModeButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        label_4 = new QLabel(f_SaveFileGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 110, 50, 21));
        label_4->setFont(font12);
        label_5 = new QLabel(f_SaveFileGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(140, 110, 50, 21));
        label_5->setFont(font12);
        f_SaveFileField_2 = new QComboBox(f_SaveFileGroupBox);
        f_SaveFileField_2->setObjectName(QStringLiteral("f_SaveFileField_2"));
        f_SaveFileField_2->setEnabled(true);
        f_SaveFileField_2->setGeometry(QRect(195, 110, 50, 21));
        f_SaveFileField_2->setFont(font12);
        f_SaveFileField_2->setCursor(QCursor(Qt::PointingHandCursor));
        f_SaveFileCurrentCreateButton = new QPushButton(f_SaveFileGroupBox);
        f_SaveFileCurrentCreateButton->setObjectName(QStringLiteral("f_SaveFileCurrentCreateButton"));
        f_SaveFileCurrentCreateButton->setGeometry(QRect(370, 100, 115, 31));
        f_SaveFileCurrentCreateButton->setFont(font2);
        f_SaveFileCurrentCreateButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_SaveFileCurrentDeleteButton = new QPushButton(f_SaveFileGroupBox);
        f_SaveFileCurrentDeleteButton->setObjectName(QStringLiteral("f_SaveFileCurrentDeleteButton"));
        f_SaveFileCurrentDeleteButton->setGeometry(QRect(524, 28, 61, 61));
        f_SaveFileCurrentDeleteButton->setFont(font2);
        f_SaveFileCurrentDeleteButton->setStyleSheet(QLatin1String("QPushButton{border-radius:10px;\n"
"border:2px solid black;;\n"
"color:black;\n"
"background:transparent;\n"
"}\n"
"QPushButton:hover{\n"
"border:2px solid rgb(	128,0,0);\n"
"color:rgb(	128,0,0);\n"
"background:transparent;\n"
"}\n"
"QPushButton:!enabled\n"
"{\n"
"border:2px solid rgb(130,130,130);\n"
"color:rgb(130,130,130);\n"
"}\n"
""));
        f_SaveFileField_Num = new QComboBox(f_SaveFileGroupBox);
        f_SaveFileField_Num->setObjectName(QStringLiteral("f_SaveFileField_Num"));
        f_SaveFileField_Num->setEnabled(true);
        f_SaveFileField_Num->setGeometry(QRect(305, 110, 50, 21));
        f_SaveFileField_Num->setFont(font12);
        f_SaveFileField_Num->setCursor(QCursor(Qt::PointingHandCursor));
        label_12 = new QLabel(f_SaveFileGroupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(250, 110, 50, 21));
        label_12->setFont(font12);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 2000, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        f_FileLocalgroupBox->setTitle(QApplication::translate("MainWindow", "\346\234\254\345\234\260\346\226\207\344\273\266\346\237\245\351\207\215", Q_NULLPTR));
        f_FileLocalLoadButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\234\254\345\234\260\346\237\245\351\207\215\346\226\207\344\273\266", Q_NULLPTR));
        f_FileLocalCheckExecButton->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\346\237\245\351\207\215", Q_NULLPTR));
        f_TCPServerGroupBox->setTitle(QApplication::translate("MainWindow", "TCP\346\234\215\345\212\241\345\231\250\346\250\241\345\274\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257IP", Q_NULLPTR));
        f_TCPServerOpenButton->setText(QApplication::translate("MainWindow", "\345\220\257\347\224\250\346\234\215\345\212\241\345\231\250(\347\253\257\345\217\243\345\217\267:1229)", Q_NULLPTR));
        f_TCPServerCloseButton->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        f_FileListGroupBox->setTitle(QApplication::translate("MainWindow", "\346\237\245\351\207\215\346\226\207\344\273\266\345\210\227\350\241\250", Q_NULLPTR));
        f_FileDeleteButton->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\346\226\207\344\273\266", Q_NULLPTR));
        f_FilesLoadButton->setText(QApplication::translate("MainWindow", "\350\277\230\345\216\237\345\210\227\350\241\250", Q_NULLPTR));
        f_ExportFileGroupBox->setTitle(QApplication::translate("MainWindow", "\345\257\274\345\207\272\346\225\260\346\215\256\346\250\241\345\274\217", Q_NULLPTR));
        f_ExportFileNameLineEdit->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\220\215:", Q_NULLPTR));
        f_ExportFileExecButton->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272", Q_NULLPTR));
        f_ExportFileModeButton->setText(QApplication::translate("MainWindow", "\345\220\257\347\224\250\345\257\274\345\207\272\346\250\241\345\274\217", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", ".txt", Q_NULLPTR));
        f_ExportFileFolderOpenButton->setText(QApplication::translate("MainWindow", "\347\240\201\345\214\205", Q_NULLPTR));
        f_QueryLogGroupBox->setTitle(QApplication::translate("MainWindow", "\351\207\215\345\244\215\344\277\241\346\201\257", Q_NULLPTR));
        f_EnableMusicCheckBox->setText(QApplication::translate("MainWindow", "\345\220\257\347\224\250\346\212\245\350\255\246\351\237\263\344\271\220", Q_NULLPTR));
        f_EnableCompaeCheckBox->setText(QApplication::translate("MainWindow", "\345\220\257\347\224\250\345\257\271\346\257\224", Q_NULLPTR));
        f_QueryLogSaveButton->setText(QApplication::translate("MainWindow", "*\344\277\235\345\255\230\346\237\245\350\257\242\350\256\260\345\275\225", Q_NULLPTR));
        f_QueryLogTableClearButton->setText(QApplication::translate("MainWindow", "\346\270\205\345\261\217", Q_NULLPTR));
        f_QueryLogResetButton->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256\346\211\200\346\234\211\346\237\245\351\207\215\346\225\260\346\215\256", Q_NULLPTR));
        f_QueryLogLoadButton->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\344\270\212\346\254\241\346\237\245\351\207\215\350\256\260\345\275\225", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\244\264\351\203\250\350\256\276\347\275\256", Q_NULLPTR));
        f_SelectIgnoreHeadLineEdit->setText(QApplication::translate("MainWindow", "http://qr.ynzyiot.com/", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\345\277\275\347\225\245\345\244\264\351\203\250\345\255\227\347\254\246\344\270\262", Q_NULLPTR));
        f_SelectIgnoreHeadModeButton->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\346\225\260\346\215\256\345\244\264\351\203\250", Q_NULLPTR));
        f_SelectIgnoreHeadResetButton->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260\345\244\264\351\203\250\346\225\260\346\215\256", Q_NULLPTR));
        f_QueryLogSaveButton_2->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\237\245\350\257\242\350\256\260\345\275\225", Q_NULLPTR));
        f_TCPClientGroupBox->setTitle(QApplication::translate("MainWindow", "TCP\345\256\242\346\210\267\347\253\257\346\250\241\345\274\217", Q_NULLPTR));
        f_TCPClientCloseButton->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\351\223\276\346\216\245\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267:", Q_NULLPTR));
        f_TCPClientServerIPlineEdit->setText(QApplication::translate("MainWindow", "127.0.0.1", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\351\223\276\346\216\245\346\234\215\345\212\241\345\231\250IP:", Q_NULLPTR));
        f_TCPClientServerPortLineEdit->setText(QApplication::translate("MainWindow", "1239", Q_NULLPTR));
        f_TCPClientOpenButton->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", Q_NULLPTR));
        f_CodeGunGroupBox->setTitle(QApplication::translate("MainWindow", "\346\211\253\347\240\201\346\236\252\346\250\241\345\274\217", Q_NULLPTR));
        f_CodeGunLineEdit->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "\346\211\253\347\240\201\346\236\252\346\225\260\346\215\256", Q_NULLPTR));
        f_CodeGunSelectButton->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\211\253\347\240\201\346\236\252\346\225\260\346\215\256", Q_NULLPTR));
        f_QueryLogResetButton_2->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256\351\207\215\345\244\215\346\254\241\346\225\260", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "\345\237\272\347\241\200\344\277\241\346\201\257\344\277\256\346\224\271", Q_NULLPTR));
        f_MainFileGroupBox->setTitle(QApplication::translate("MainWindow", "\346\250\241\346\235\277\346\226\207\344\273\266\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\345\257\271\346\257\224\347\240\201\345\214\205", Q_NULLPTR));
        f_MainFileLoadButton->setText(QApplication::translate("MainWindow", "\350\275\275\345\205\245\345\257\271\346\257\224\346\226\207\344\273\266", Q_NULLPTR));
        f_SaveFileGroupBox->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266\344\277\235\345\255\230", Q_NULLPTR));
        f_SaveFileCurrentLineEdit->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\344\277\235\345\255\230\346\226\207\344\273\266\345\220\215", Q_NULLPTR));
        f_SaveFileField_1->clear();
        f_SaveFileField_1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "T24", Q_NULLPTR)
        );
#ifndef QT_NO_WHATSTHIS
        f_SaveFileField_1->setWhatsThis(QApplication::translate("MainWindow", "\345\234\206\345\274\247\351\200\211\346\213\251", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        f_SaveFileModeButton->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\210\233\345\273\272\346\250\241\345\274\217", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\345\255\227\346\256\2651:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\345\255\227\346\256\2652:", Q_NULLPTR));
        f_SaveFileField_2->clear();
        f_SaveFileField_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\272\2421", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\231\2752", Q_NULLPTR)
        );
#ifndef QT_NO_WHATSTHIS
        f_SaveFileField_2->setWhatsThis(QApplication::translate("MainWindow", "\345\234\206\345\274\247\351\200\211\346\213\251", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        f_SaveFileCurrentCreateButton->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", Q_NULLPTR));
        f_SaveFileCurrentDeleteButton->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\n"
"\345\211\215\346\226\207\344\273\266", Q_NULLPTR));
        f_SaveFileField_Num->clear();
        f_SaveFileField_Num->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
        );
#ifndef QT_NO_WHATSTHIS
        f_SaveFileField_Num->setWhatsThis(QApplication::translate("MainWindow", "\345\234\206\345\274\247\351\200\211\346\213\251", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        label_12->setText(QApplication::translate("MainWindow", "\345\272\217\345\217\267:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

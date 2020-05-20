/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Config;
    QAction *actionSave_Config;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionMIDI_Interface;
    QAction *actionSettings;
    QAction *actionMIDI_Instruments;
    QAction *actionScale_Settings;
    QAction *actionSave_Config_As;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1268, 719);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        actionOpen_Config = new QAction(MainWindow);
        actionOpen_Config->setObjectName(QString::fromUtf8("actionOpen_Config"));
        actionSave_Config = new QAction(MainWindow);
        actionSave_Config->setObjectName(QString::fromUtf8("actionSave_Config"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionMIDI_Interface = new QAction(MainWindow);
        actionMIDI_Interface->setObjectName(QString::fromUtf8("actionMIDI_Interface"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionMIDI_Instruments = new QAction(MainWindow);
        actionMIDI_Instruments->setObjectName(QString::fromUtf8("actionMIDI_Instruments"));
        actionScale_Settings = new QAction(MainWindow);
        actionScale_Settings->setObjectName(QString::fromUtf8("actionScale_Settings"));
        actionSave_Config_As = new QAction(MainWindow);
        actionSave_Config_As->setObjectName(QString::fromUtf8("actionSave_Config_As"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1268, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen_Config);
        menuFile->addAction(actionSave_Config);
        menuFile->addAction(actionSave_Config_As);
        menuSettings->addAction(actionSettings);
        menuSettings->addAction(actionMIDI_Instruments);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_Config->setText(QCoreApplication::translate("MainWindow", "Open Config", nullptr));
        actionSave_Config->setText(QCoreApplication::translate("MainWindow", "Save Config", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "&Open File", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close File", nullptr));
        actionMIDI_Interface->setText(QCoreApplication::translate("MainWindow", "MIDI Interface", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        actionMIDI_Instruments->setText(QCoreApplication::translate("MainWindow", "MIDI Instruments", nullptr));
        actionScale_Settings->setText(QCoreApplication::translate("MainWindow", "Scale Settings", nullptr));
        actionSave_Config_As->setText(QCoreApplication::translate("MainWindow", "Save Config As", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Extras", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

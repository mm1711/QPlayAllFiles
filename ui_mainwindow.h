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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
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
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *channelWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *label_5;
    QLabel *label_14;
    QFrame *frame;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *currGroupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *KeysComboBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QComboBox *ModesComboBox;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QComboBox *octaveComboBox;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QPushButton *btnSetNotes;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *record_checkBox;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QPushButton *playBtn;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_3;
    QPushButton *stopBtn;
    QWidget *segmentsWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 719);
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 10, 1191, 661));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1189, 659));
        channelWidget = new QWidget(scrollAreaWidgetContents);
        channelWidget->setObjectName(QString::fromUtf8("channelWidget"));
        channelWidget->setGeometry(QRect(0, 9, 341, 541));
        sizePolicy.setHeightForWidth(channelWidget->sizePolicy().hasHeightForWidth());
        channelWidget->setSizePolicy(sizePolicy);
        channelWidget->setMinimumSize(QSize(200, 500));
        channelWidget->setMaximumSize(QSize(16777215, 16777215));
        layoutWidget = new QWidget(channelWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 331, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(70, 30));

        horizontalLayout_2->addWidget(label_6);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(130, 30));

        horizontalLayout_2->addWidget(label_13);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(label_5);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(0, 30));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_14);

        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(350, 0, 821, 61));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 819, 60));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(label);

        currGroupBox = new QLineEdit(layoutWidget1);
        currGroupBox->setObjectName(QString::fromUtf8("currGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(currGroupBox->sizePolicy().hasHeightForWidth());
        currGroupBox->setSizePolicy(sizePolicy1);
        currGroupBox->setMinimumSize(QSize(40, 30));
        currGroupBox->setMaximumSize(QSize(40, 30));

        verticalLayout->addWidget(currGroupBox);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(label_2);

        KeysComboBox = new QComboBox(layoutWidget1);
        KeysComboBox->setObjectName(QString::fromUtf8("KeysComboBox"));
        sizePolicy.setHeightForWidth(KeysComboBox->sizePolicy().hasHeightForWidth());
        KeysComboBox->setSizePolicy(sizePolicy);
        KeysComboBox->setMinimumSize(QSize(120, 30));
        KeysComboBox->setMaximumSize(QSize(16777215, 30));
        KeysComboBox->setSizeIncrement(QSize(5, 5));
        KeysComboBox->setEditable(true);

        verticalLayout_2->addWidget(KeysComboBox);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 20));

        verticalLayout_3->addWidget(label_3);

        ModesComboBox = new QComboBox(layoutWidget1);
        ModesComboBox->setObjectName(QString::fromUtf8("ModesComboBox"));
        sizePolicy.setHeightForWidth(ModesComboBox->sizePolicy().hasHeightForWidth());
        ModesComboBox->setSizePolicy(sizePolicy);
        ModesComboBox->setMinimumSize(QSize(150, 30));
        ModesComboBox->setMaximumSize(QSize(16777215, 30));
        ModesComboBox->setEditable(true);

        verticalLayout_3->addWidget(ModesComboBox);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16777215, 20));

        verticalLayout_7->addWidget(label_4);

        octaveComboBox = new QComboBox(layoutWidget1);
        octaveComboBox->setObjectName(QString::fromUtf8("octaveComboBox"));
        sizePolicy.setHeightForWidth(octaveComboBox->sizePolicy().hasHeightForWidth());
        octaveComboBox->setSizePolicy(sizePolicy);
        octaveComboBox->setMinimumSize(QSize(70, 30));
        octaveComboBox->setMaximumSize(QSize(16777215, 30));
        octaveComboBox->setEditable(true);

        verticalLayout_7->addWidget(octaveComboBox);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        btnSetNotes = new QPushButton(layoutWidget1);
        btnSetNotes->setObjectName(QString::fromUtf8("btnSetNotes"));
        sizePolicy.setHeightForWidth(btnSetNotes->sizePolicy().hasHeightForWidth());
        btnSetNotes->setSizePolicy(sizePolicy);
        btnSetNotes->setMinimumSize(QSize(0, 30));
        btnSetNotes->setMaximumSize(QSize(120, 30));

        verticalLayout_4->addWidget(btnSetNotes);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_4);

        record_checkBox = new QCheckBox(layoutWidget1);
        record_checkBox->setObjectName(QString::fromUtf8("record_checkBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(record_checkBox->sizePolicy().hasHeightForWidth());
        record_checkBox->setSizePolicy(sizePolicy2);
        record_checkBox->setMinimumSize(QSize(120, 30));
        record_checkBox->setMaximumSize(QSize(150, 30));
        record_checkBox->setBaseSize(QSize(0, 0));

        verticalLayout_9->addWidget(record_checkBox);


        horizontalLayout->addLayout(verticalLayout_9);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        playBtn = new QPushButton(layoutWidget1);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(playBtn->sizePolicy().hasHeightForWidth());
        playBtn->setSizePolicy(sizePolicy3);
        playBtn->setMinimumSize(QSize(28, 30));
        playBtn->setMaximumSize(QSize(28, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/media-play-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        playBtn->setIcon(icon);
        playBtn->setIconSize(QSize(16, 16));

        verticalLayout_5->addWidget(playBtn);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);

        stopBtn = new QPushButton(layoutWidget1);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));
        sizePolicy3.setHeightForWidth(stopBtn->sizePolicy().hasHeightForWidth());
        stopBtn->setSizePolicy(sizePolicy3);
        stopBtn->setMinimumSize(QSize(28, 30));
        stopBtn->setMaximumSize(QSize(28, 30));
        stopBtn->setLayoutDirection(Qt::RightToLeft);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/media-stop-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopBtn->setIcon(icon1);
        stopBtn->setIconSize(QSize(16, 16));

        verticalLayout_6->addWidget(stopBtn);


        horizontalLayout->addLayout(verticalLayout_6);

        segmentsWidget = new QWidget(scrollAreaWidgetContents);
        segmentsWidget->setObjectName(QString::fromUtf8("segmentsWidget"));
        segmentsWidget->setGeometry(QRect(351, 70, 819, 500));
        sizePolicy.setHeightForWidth(segmentsWidget->sizePolicy().hasHeightForWidth());
        segmentsWidget->setSizePolicy(sizePolicy);
        segmentsWidget->setMinimumSize(QSize(0, 500));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 255, 200, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        segmentsWidget->setPalette(palette);
        segmentsWidget->setAutoFillBackground(true);
        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 21));
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
        label_6->setText(QCoreApplication::translate("MainWindow", "Voice", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Note", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Velocity", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Group", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Group", nullptr));
        currGroupBox->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Octave", nullptr));
#if QT_CONFIG(tooltip)
        btnSetNotes->setToolTip(QCoreApplication::translate("MainWindow", "Apply Scale/Mode/Octave to Group", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        btnSetNotes->setStatusTip(QCoreApplication::translate("MainWindow", "Apply Scale/Mode/Octave to Group", nullptr));
#endif // QT_CONFIG(statustip)
        btnSetNotes->setText(QCoreApplication::translate("MainWindow", "Set Notes", nullptr));
        record_checkBox->setText(QCoreApplication::translate("MainWindow", "Record", nullptr));
#if QT_CONFIG(tooltip)
        playBtn->setToolTip(QCoreApplication::translate("MainWindow", "Play/Pause ", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        playBtn->setStatusTip(QCoreApplication::translate("MainWindow", "Play/Pause", nullptr));
#endif // QT_CONFIG(statustip)
        playBtn->setText(QString());
#if QT_CONFIG(tooltip)
        stopBtn->setToolTip(QCoreApplication::translate("MainWindow", "Stop", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        stopBtn->setStatusTip(QCoreApplication::translate("MainWindow", "Stop", nullptr));
#endif // QT_CONFIG(statustip)
        stopBtn->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Extras", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

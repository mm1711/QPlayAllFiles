/********************************************************************************
** Form generated from reading UI file 'midiinstrumentsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIDIINSTRUMENTSDIALOG_H
#define UI_MIDIINSTRUMENTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMIDIInstrumentsDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_8;
    QLabel *midi_voice_lbl_0;
    QComboBox *midi_voice_comboBox_0;
    QHBoxLayout *horizontalLayout_9;
    QLabel *midi_voice_lbl_1;
    QComboBox *midi_voice_comboBox_1;
    QHBoxLayout *horizontalLayout_10;
    QLabel *midi_voice_lbl_2;
    QComboBox *midi_voice_comboBox_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *midi_voice_lbl_3;
    QComboBox *midi_voice_comboBox_3;
    QHBoxLayout *horizontalLayout_25;
    QLabel *midi_voice_lbl_16;
    QComboBox *midi_voice_comboBox_4;
    QHBoxLayout *horizontalLayout_13;
    QLabel *midi_voice_lbl_5;
    QComboBox *midi_voice_comboBox_5;
    QHBoxLayout *horizontalLayout_14;
    QLabel *midi_voice_lbl_6;
    QComboBox *midi_voice_comboBox_6;
    QHBoxLayout *horizontalLayout_15;
    QLabel *midi_voice_lbl_7;
    QComboBox *midi_voice_comboBox_7;
    QHBoxLayout *horizontalLayout_16;
    QLabel *midi_voice_lbl_8;
    QComboBox *midi_voice_comboBox_8;
    QHBoxLayout *horizontalLayout_17;
    QLabel *midi_voice_lbl_9;
    QComboBox *midi_voice_comboBox_9;
    QHBoxLayout *horizontalLayout_18;
    QLabel *midi_voice_lbl_10;
    QComboBox *midi_voice_comboBox_10;
    QHBoxLayout *horizontalLayout_19;
    QLabel *midi_voice_lbl_11;
    QComboBox *midi_voice_comboBox_11;
    QHBoxLayout *horizontalLayout_20;
    QLabel *midi_voice_lbl_12;
    QComboBox *midi_voice_comboBox_12;
    QHBoxLayout *horizontalLayout_21;
    QLabel *midi_voice_lbl_13;
    QComboBox *midi_voice_comboBox_13;
    QHBoxLayout *horizontalLayout_22;
    QLabel *midi_voice_lbl_14;
    QComboBox *midi_voice_comboBox_14;
    QHBoxLayout *horizontalLayout_23;
    QLabel *midi_voice_lbl_15;
    QComboBox *midi_voice_comboBox_15;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CMIDIInstrumentsDialog)
    {
        if (CMIDIInstrumentsDialog->objectName().isEmpty())
            CMIDIInstrumentsDialog->setObjectName(QString::fromUtf8("CMIDIInstrumentsDialog"));
        CMIDIInstrumentsDialog->resize(184, 461);
        layoutWidget = new QWidget(CMIDIInstrumentsDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 158, 443));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(40, 0));
        label_9->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_24->addWidget(label_9);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_24->addWidget(label_10);


        verticalLayout_3->addLayout(horizontalLayout_24);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        midi_voice_lbl_0 = new QLabel(layoutWidget);
        midi_voice_lbl_0->setObjectName(QString::fromUtf8("midi_voice_lbl_0"));
        midi_voice_lbl_0->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_0->setMaximumSize(QSize(20, 20));

        horizontalLayout_8->addWidget(midi_voice_lbl_0);

        midi_voice_comboBox_0 = new QComboBox(layoutWidget);
        midi_voice_comboBox_0->setObjectName(QString::fromUtf8("midi_voice_comboBox_0"));
        midi_voice_comboBox_0->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_0->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_0->setEditable(true);

        horizontalLayout_8->addWidget(midi_voice_comboBox_0);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        midi_voice_lbl_1 = new QLabel(layoutWidget);
        midi_voice_lbl_1->setObjectName(QString::fromUtf8("midi_voice_lbl_1"));
        midi_voice_lbl_1->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_1->setMaximumSize(QSize(20, 20));

        horizontalLayout_9->addWidget(midi_voice_lbl_1);

        midi_voice_comboBox_1 = new QComboBox(layoutWidget);
        midi_voice_comboBox_1->setObjectName(QString::fromUtf8("midi_voice_comboBox_1"));
        midi_voice_comboBox_1->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_1->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_1->setEditable(true);

        horizontalLayout_9->addWidget(midi_voice_comboBox_1);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        midi_voice_lbl_2 = new QLabel(layoutWidget);
        midi_voice_lbl_2->setObjectName(QString::fromUtf8("midi_voice_lbl_2"));
        midi_voice_lbl_2->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_2->setMaximumSize(QSize(20, 20));

        horizontalLayout_10->addWidget(midi_voice_lbl_2);

        midi_voice_comboBox_2 = new QComboBox(layoutWidget);
        midi_voice_comboBox_2->setObjectName(QString::fromUtf8("midi_voice_comboBox_2"));
        midi_voice_comboBox_2->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_2->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_2->setEditable(true);

        horizontalLayout_10->addWidget(midi_voice_comboBox_2);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        midi_voice_lbl_3 = new QLabel(layoutWidget);
        midi_voice_lbl_3->setObjectName(QString::fromUtf8("midi_voice_lbl_3"));
        midi_voice_lbl_3->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_3->setMaximumSize(QSize(20, 20));

        horizontalLayout_11->addWidget(midi_voice_lbl_3);

        midi_voice_comboBox_3 = new QComboBox(layoutWidget);
        midi_voice_comboBox_3->setObjectName(QString::fromUtf8("midi_voice_comboBox_3"));
        midi_voice_comboBox_3->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_3->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_3->setEditable(true);

        horizontalLayout_11->addWidget(midi_voice_comboBox_3);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        midi_voice_lbl_16 = new QLabel(layoutWidget);
        midi_voice_lbl_16->setObjectName(QString::fromUtf8("midi_voice_lbl_16"));
        midi_voice_lbl_16->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_16->setMaximumSize(QSize(20, 20));

        horizontalLayout_25->addWidget(midi_voice_lbl_16);

        midi_voice_comboBox_4 = new QComboBox(layoutWidget);
        midi_voice_comboBox_4->setObjectName(QString::fromUtf8("midi_voice_comboBox_4"));
        midi_voice_comboBox_4->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_4->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_4->setEditable(true);

        horizontalLayout_25->addWidget(midi_voice_comboBox_4);


        verticalLayout_3->addLayout(horizontalLayout_25);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        midi_voice_lbl_5 = new QLabel(layoutWidget);
        midi_voice_lbl_5->setObjectName(QString::fromUtf8("midi_voice_lbl_5"));
        midi_voice_lbl_5->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_5->setMaximumSize(QSize(20, 20));

        horizontalLayout_13->addWidget(midi_voice_lbl_5);

        midi_voice_comboBox_5 = new QComboBox(layoutWidget);
        midi_voice_comboBox_5->setObjectName(QString::fromUtf8("midi_voice_comboBox_5"));
        midi_voice_comboBox_5->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_5->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_5->setEditable(true);

        horizontalLayout_13->addWidget(midi_voice_comboBox_5);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        midi_voice_lbl_6 = new QLabel(layoutWidget);
        midi_voice_lbl_6->setObjectName(QString::fromUtf8("midi_voice_lbl_6"));
        midi_voice_lbl_6->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_6->setMaximumSize(QSize(20, 20));

        horizontalLayout_14->addWidget(midi_voice_lbl_6);

        midi_voice_comboBox_6 = new QComboBox(layoutWidget);
        midi_voice_comboBox_6->setObjectName(QString::fromUtf8("midi_voice_comboBox_6"));
        midi_voice_comboBox_6->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_6->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_6->setEditable(true);

        horizontalLayout_14->addWidget(midi_voice_comboBox_6);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        midi_voice_lbl_7 = new QLabel(layoutWidget);
        midi_voice_lbl_7->setObjectName(QString::fromUtf8("midi_voice_lbl_7"));
        midi_voice_lbl_7->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_7->setMaximumSize(QSize(20, 20));

        horizontalLayout_15->addWidget(midi_voice_lbl_7);

        midi_voice_comboBox_7 = new QComboBox(layoutWidget);
        midi_voice_comboBox_7->setObjectName(QString::fromUtf8("midi_voice_comboBox_7"));
        midi_voice_comboBox_7->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_7->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_7->setEditable(true);

        horizontalLayout_15->addWidget(midi_voice_comboBox_7);


        verticalLayout_3->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        midi_voice_lbl_8 = new QLabel(layoutWidget);
        midi_voice_lbl_8->setObjectName(QString::fromUtf8("midi_voice_lbl_8"));
        midi_voice_lbl_8->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_8->setMaximumSize(QSize(20, 20));

        horizontalLayout_16->addWidget(midi_voice_lbl_8);

        midi_voice_comboBox_8 = new QComboBox(layoutWidget);
        midi_voice_comboBox_8->setObjectName(QString::fromUtf8("midi_voice_comboBox_8"));
        midi_voice_comboBox_8->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_8->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_8->setEditable(true);

        horizontalLayout_16->addWidget(midi_voice_comboBox_8);


        verticalLayout_3->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        midi_voice_lbl_9 = new QLabel(layoutWidget);
        midi_voice_lbl_9->setObjectName(QString::fromUtf8("midi_voice_lbl_9"));
        midi_voice_lbl_9->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_9->setMaximumSize(QSize(20, 20));

        horizontalLayout_17->addWidget(midi_voice_lbl_9);

        midi_voice_comboBox_9 = new QComboBox(layoutWidget);
        midi_voice_comboBox_9->setObjectName(QString::fromUtf8("midi_voice_comboBox_9"));
        midi_voice_comboBox_9->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_9->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_9->setEditable(true);

        horizontalLayout_17->addWidget(midi_voice_comboBox_9);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        midi_voice_lbl_10 = new QLabel(layoutWidget);
        midi_voice_lbl_10->setObjectName(QString::fromUtf8("midi_voice_lbl_10"));
        midi_voice_lbl_10->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_10->setMaximumSize(QSize(20, 20));

        horizontalLayout_18->addWidget(midi_voice_lbl_10);

        midi_voice_comboBox_10 = new QComboBox(layoutWidget);
        midi_voice_comboBox_10->setObjectName(QString::fromUtf8("midi_voice_comboBox_10"));
        midi_voice_comboBox_10->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_10->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_10->setEditable(true);

        horizontalLayout_18->addWidget(midi_voice_comboBox_10);


        verticalLayout_3->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        midi_voice_lbl_11 = new QLabel(layoutWidget);
        midi_voice_lbl_11->setObjectName(QString::fromUtf8("midi_voice_lbl_11"));
        midi_voice_lbl_11->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_11->setMaximumSize(QSize(20, 20));

        horizontalLayout_19->addWidget(midi_voice_lbl_11);

        midi_voice_comboBox_11 = new QComboBox(layoutWidget);
        midi_voice_comboBox_11->setObjectName(QString::fromUtf8("midi_voice_comboBox_11"));
        midi_voice_comboBox_11->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_11->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_11->setEditable(true);

        horizontalLayout_19->addWidget(midi_voice_comboBox_11);


        verticalLayout_3->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        midi_voice_lbl_12 = new QLabel(layoutWidget);
        midi_voice_lbl_12->setObjectName(QString::fromUtf8("midi_voice_lbl_12"));
        midi_voice_lbl_12->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_12->setMaximumSize(QSize(20, 20));

        horizontalLayout_20->addWidget(midi_voice_lbl_12);

        midi_voice_comboBox_12 = new QComboBox(layoutWidget);
        midi_voice_comboBox_12->setObjectName(QString::fromUtf8("midi_voice_comboBox_12"));
        midi_voice_comboBox_12->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_12->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_12->setEditable(true);

        horizontalLayout_20->addWidget(midi_voice_comboBox_12);


        verticalLayout_3->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        midi_voice_lbl_13 = new QLabel(layoutWidget);
        midi_voice_lbl_13->setObjectName(QString::fromUtf8("midi_voice_lbl_13"));
        midi_voice_lbl_13->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_13->setMaximumSize(QSize(20, 20));

        horizontalLayout_21->addWidget(midi_voice_lbl_13);

        midi_voice_comboBox_13 = new QComboBox(layoutWidget);
        midi_voice_comboBox_13->setObjectName(QString::fromUtf8("midi_voice_comboBox_13"));
        midi_voice_comboBox_13->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_13->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_13->setEditable(true);

        horizontalLayout_21->addWidget(midi_voice_comboBox_13);


        verticalLayout_3->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        midi_voice_lbl_14 = new QLabel(layoutWidget);
        midi_voice_lbl_14->setObjectName(QString::fromUtf8("midi_voice_lbl_14"));
        midi_voice_lbl_14->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_14->setMaximumSize(QSize(20, 20));

        horizontalLayout_22->addWidget(midi_voice_lbl_14);

        midi_voice_comboBox_14 = new QComboBox(layoutWidget);
        midi_voice_comboBox_14->setObjectName(QString::fromUtf8("midi_voice_comboBox_14"));
        midi_voice_comboBox_14->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_14->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_14->setEditable(true);

        horizontalLayout_22->addWidget(midi_voice_comboBox_14);


        verticalLayout_3->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        midi_voice_lbl_15 = new QLabel(layoutWidget);
        midi_voice_lbl_15->setObjectName(QString::fromUtf8("midi_voice_lbl_15"));
        midi_voice_lbl_15->setMinimumSize(QSize(20, 20));
        midi_voice_lbl_15->setMaximumSize(QSize(20, 20));

        horizontalLayout_23->addWidget(midi_voice_lbl_15);

        midi_voice_comboBox_15 = new QComboBox(layoutWidget);
        midi_voice_comboBox_15->setObjectName(QString::fromUtf8("midi_voice_comboBox_15"));
        midi_voice_comboBox_15->setMinimumSize(QSize(120, 20));
        midi_voice_comboBox_15->setMaximumSize(QSize(140, 16777215));
        midi_voice_comboBox_15->setEditable(true);

        horizontalLayout_23->addWidget(midi_voice_comboBox_15);


        verticalLayout_3->addLayout(horizontalLayout_23);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(CMIDIInstrumentsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CMIDIInstrumentsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CMIDIInstrumentsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CMIDIInstrumentsDialog);
    } // setupUi

    void retranslateUi(QDialog *CMIDIInstrumentsDialog)
    {
        CMIDIInstrumentsDialog->setWindowTitle(QCoreApplication::translate("CMIDIInstrumentsDialog", "Dialog", nullptr));
        label_9->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "Voice", nullptr));
        label_10->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "MIDI Instrument", nullptr));
        midi_voice_lbl_0->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "0", nullptr));
        midi_voice_comboBox_0->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_1->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "1", nullptr));
        midi_voice_comboBox_1->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_2->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "2", nullptr));
        midi_voice_comboBox_2->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_3->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "3", nullptr));
        midi_voice_comboBox_3->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_16->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "4", nullptr));
        midi_voice_comboBox_4->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_5->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "5", nullptr));
        midi_voice_comboBox_5->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_6->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "6", nullptr));
        midi_voice_comboBox_6->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_7->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "7", nullptr));
        midi_voice_comboBox_7->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_8->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "8", nullptr));
        midi_voice_comboBox_8->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_9->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "9", nullptr));
        midi_voice_comboBox_9->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_10->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "10", nullptr));
        midi_voice_comboBox_10->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_11->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "11", nullptr));
        midi_voice_comboBox_11->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_12->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "12", nullptr));
        midi_voice_comboBox_12->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_13->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "13", nullptr));
        midi_voice_comboBox_13->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_14->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "14", nullptr));
        midi_voice_comboBox_14->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
        midi_voice_lbl_15->setText(QCoreApplication::translate("CMIDIInstrumentsDialog", "15", nullptr));
        midi_voice_comboBox_15->setCurrentText(QCoreApplication::translate("CMIDIInstrumentsDialog", "AcoustivGrandPiano", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CMIDIInstrumentsDialog: public Ui_CMIDIInstrumentsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIDIINSTRUMENTSDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSettingsDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSpinBox *channels_spinBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QLineEdit *BPM_lineEdit;
    QLabel *label_3;
    QSpinBox *Numerator_spinBox;
    QLabel *label_10;
    QComboBox *Denominator_comboBox;
    QLabel *label_12;
    QSpinBox *Accent_spinBox;
    QLabel *label_13;
    QLabel *label_14;
    QComboBox *shortestNote_comboBox;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *intervalVariation_checkBox;
    QLabel *label_15;
    QSpinBox *minIntervalVariation_spinBox;
    QLabel *label_16;
    QSpinBox *maxIntervalVariation_spinBox;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *metronome_checkBox;
    QSpinBox *metronom_spinBox;
    QComboBox *metronomInstrument_comboBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *staccato_checkBox;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *loop_checkBox;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *firstSegment_lineEdit;
    QPushButton *set_first_segment_Btn;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *lastSegment_lineEdit;
    QPushButton *set_last_segment_Btn;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *audio_Interface_comboBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QComboBox *audio_codec_comboBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QComboBox *audio_sampling_rate_comboBox;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QComboBox *audio_container_comboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *MIDI_Interface_comboBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CSettingsDialog)
    {
        if (CSettingsDialog->objectName().isEmpty())
            CSettingsDialog->setObjectName(QString::fromUtf8("CSettingsDialog"));
        CSettingsDialog->resize(1000, 502);
        CSettingsDialog->setMinimumSize(QSize(1000, 0));
        layoutWidget = new QWidget(CSettingsDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 761, 481));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setMaximumSize(QSize(16777215, 16777215));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_5);

        channels_spinBox = new QSpinBox(layoutWidget);
        channels_spinBox->setObjectName(QString::fromUtf8("channels_spinBox"));
        channels_spinBox->setMinimumSize(QSize(0, 0));
        channels_spinBox->setMinimum(1);
        channels_spinBox->setMaximum(72);
        channels_spinBox->setValue(13);

        horizontalLayout_2->addWidget(channels_spinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 0));
        label_11->setMaximumSize(QSize(16777215, 16777215));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(label_11);

        BPM_lineEdit = new QLineEdit(layoutWidget);
        BPM_lineEdit->setObjectName(QString::fromUtf8("BPM_lineEdit"));
        BPM_lineEdit->setMinimumSize(QSize(0, 0));
        BPM_lineEdit->setMaximumSize(QSize(16777215, 16777215));
        BPM_lineEdit->setMaxLength(4);

        horizontalLayout_12->addWidget(BPM_lineEdit);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_12->addWidget(label_3);

        Numerator_spinBox = new QSpinBox(layoutWidget);
        Numerator_spinBox->setObjectName(QString::fromUtf8("Numerator_spinBox"));
        Numerator_spinBox->setMinimum(1);
        Numerator_spinBox->setMaximum(16);
        Numerator_spinBox->setValue(4);

        horizontalLayout_12->addWidget(Numerator_spinBox);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_12->addWidget(label_10);

        Denominator_comboBox = new QComboBox(layoutWidget);
        Denominator_comboBox->setObjectName(QString::fromUtf8("Denominator_comboBox"));

        horizontalLayout_12->addWidget(Denominator_comboBox);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_12->addWidget(label_12);

        Accent_spinBox = new QSpinBox(layoutWidget);
        Accent_spinBox->setObjectName(QString::fromUtf8("Accent_spinBox"));
        Accent_spinBox->setMinimum(1);
        Accent_spinBox->setMaximum(32);

        horizontalLayout_12->addWidget(Accent_spinBox);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(95, 0));
        label_13->setTextFormat(Qt::PlainText);

        horizontalLayout_12->addWidget(label_13);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_12->addWidget(label_14);

        shortestNote_comboBox = new QComboBox(layoutWidget);
        shortestNote_comboBox->setObjectName(QString::fromUtf8("shortestNote_comboBox"));

        horizontalLayout_12->addWidget(shortestNote_comboBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        intervalVariation_checkBox = new QCheckBox(layoutWidget);
        intervalVariation_checkBox->setObjectName(QString::fromUtf8("intervalVariation_checkBox"));
        intervalVariation_checkBox->setLayoutDirection(Qt::RightToLeft);
        intervalVariation_checkBox->setChecked(true);

        horizontalLayout_8->addWidget(intervalVariation_checkBox);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_8->addWidget(label_15);

        minIntervalVariation_spinBox = new QSpinBox(layoutWidget);
        minIntervalVariation_spinBox->setObjectName(QString::fromUtf8("minIntervalVariation_spinBox"));
        minIntervalVariation_spinBox->setMaximum(10);
        minIntervalVariation_spinBox->setValue(5);

        horizontalLayout_8->addWidget(minIntervalVariation_spinBox);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_8->addWidget(label_16);

        maxIntervalVariation_spinBox = new QSpinBox(layoutWidget);
        maxIntervalVariation_spinBox->setObjectName(QString::fromUtf8("maxIntervalVariation_spinBox"));
        maxIntervalVariation_spinBox->setMinimum(10);
        maxIntervalVariation_spinBox->setMaximum(100);
        maxIntervalVariation_spinBox->setValue(20);

        horizontalLayout_8->addWidget(maxIntervalVariation_spinBox);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_8->addWidget(label_17);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        metronome_checkBox = new QCheckBox(layoutWidget);
        metronome_checkBox->setObjectName(QString::fromUtf8("metronome_checkBox"));
        metronome_checkBox->setLayoutDirection(Qt::RightToLeft);
        metronome_checkBox->setChecked(true);

        horizontalLayout_8->addWidget(metronome_checkBox);

        metronom_spinBox = new QSpinBox(layoutWidget);
        metronom_spinBox->setObjectName(QString::fromUtf8("metronom_spinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(metronom_spinBox->sizePolicy().hasHeightForWidth());
        metronom_spinBox->setSizePolicy(sizePolicy);
        metronom_spinBox->setMinimum(35);
        metronom_spinBox->setMaximum(81);
        metronom_spinBox->setValue(75);

        horizontalLayout_8->addWidget(metronom_spinBox);

        metronomInstrument_comboBox = new QComboBox(layoutWidget);
        metronomInstrument_comboBox->setObjectName(QString::fromUtf8("metronomInstrument_comboBox"));
        metronomInstrument_comboBox->setMinimumSize(QSize(220, 0));

        horizontalLayout_8->addWidget(metronomInstrument_comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        staccato_checkBox = new QCheckBox(layoutWidget);
        staccato_checkBox->setObjectName(QString::fromUtf8("staccato_checkBox"));
        staccato_checkBox->setMinimumSize(QSize(0, 0));
        staccato_checkBox->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_6->addWidget(staccato_checkBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        loop_checkBox = new QCheckBox(layoutWidget);
        loop_checkBox->setObjectName(QString::fromUtf8("loop_checkBox"));
        loop_checkBox->setMinimumSize(QSize(0, 0));
        loop_checkBox->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_7->addWidget(loop_checkBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 0));
        label_8->setMaximumSize(QSize(16777215, 16777215));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_8);

        firstSegment_lineEdit = new QLineEdit(layoutWidget);
        firstSegment_lineEdit->setObjectName(QString::fromUtf8("firstSegment_lineEdit"));
        firstSegment_lineEdit->setMinimumSize(QSize(0, 0));
        firstSegment_lineEdit->setMaximumSize(QSize(16777215, 16777215));
        firstSegment_lineEdit->setMaxLength(10);

        horizontalLayout_4->addWidget(firstSegment_lineEdit);

        set_first_segment_Btn = new QPushButton(layoutWidget);
        set_first_segment_Btn->setObjectName(QString::fromUtf8("set_first_segment_Btn"));
        set_first_segment_Btn->setMinimumSize(QSize(0, 0));
        set_first_segment_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(set_first_segment_Btn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 0));
        label_7->setMaximumSize(QSize(16777215, 16777215));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_7);

        lastSegment_lineEdit = new QLineEdit(layoutWidget);
        lastSegment_lineEdit->setObjectName(QString::fromUtf8("lastSegment_lineEdit"));
        lastSegment_lineEdit->setMinimumSize(QSize(0, 0));
        lastSegment_lineEdit->setMaximumSize(QSize(16777215, 16777215));
        lastSegment_lineEdit->setMaxLength(10);

        horizontalLayout_5->addWidget(lastSegment_lineEdit);

        set_last_segment_Btn = new QPushButton(layoutWidget);
        set_last_segment_Btn->setObjectName(QString::fromUtf8("set_last_segment_Btn"));
        set_last_segment_Btn->setMinimumSize(QSize(0, 0));
        set_last_segment_Btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(set_last_segment_Btn);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        audio_Interface_comboBox = new QComboBox(layoutWidget);
        audio_Interface_comboBox->setObjectName(QString::fromUtf8("audio_Interface_comboBox"));
        audio_Interface_comboBox->setMinimumSize(QSize(0, 0));
        audio_Interface_comboBox->setEditable(true);

        horizontalLayout_3->addWidget(audio_Interface_comboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(label_4);

        audio_codec_comboBox = new QComboBox(layoutWidget);
        audio_codec_comboBox->setObjectName(QString::fromUtf8("audio_codec_comboBox"));
        audio_codec_comboBox->setMinimumSize(QSize(0, 0));
        audio_codec_comboBox->setEditable(true);

        horizontalLayout_9->addWidget(audio_codec_comboBox);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 0));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_6);

        audio_sampling_rate_comboBox = new QComboBox(layoutWidget);
        audio_sampling_rate_comboBox->setObjectName(QString::fromUtf8("audio_sampling_rate_comboBox"));
        audio_sampling_rate_comboBox->setMinimumSize(QSize(0, 0));
        audio_sampling_rate_comboBox->setEditable(true);

        horizontalLayout_10->addWidget(audio_sampling_rate_comboBox);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 0));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_9);

        audio_container_comboBox = new QComboBox(layoutWidget);
        audio_container_comboBox->setObjectName(QString::fromUtf8("audio_container_comboBox"));
        audio_container_comboBox->setMinimumSize(QSize(0, 0));
        audio_container_comboBox->setEditable(true);

        horizontalLayout_11->addWidget(audio_container_comboBox);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        MIDI_Interface_comboBox = new QComboBox(layoutWidget);
        MIDI_Interface_comboBox->setObjectName(QString::fromUtf8("MIDI_Interface_comboBox"));
        MIDI_Interface_comboBox->setMinimumSize(QSize(0, 0));
        MIDI_Interface_comboBox->setEditable(true);

        horizontalLayout->addWidget(MIDI_Interface_comboBox);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(CSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *CSettingsDialog)
    {
        CSettingsDialog->setWindowTitle(QCoreApplication::translate("CSettingsDialog", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("CSettingsDialog", "Channels", nullptr));
#if QT_CONFIG(tooltip)
        channels_spinBox->setToolTip(QCoreApplication::translate("CSettingsDialog", "Number of Channels per Segment", nullptr));
#endif // QT_CONFIG(tooltip)
        label_11->setText(QCoreApplication::translate("CSettingsDialog", "Beats/Minute", nullptr));
#if QT_CONFIG(tooltip)
        BPM_lineEdit->setToolTip(QCoreApplication::translate("CSettingsDialog", "Start Segment to Play", nullptr));
#endif // QT_CONFIG(tooltip)
        BPM_lineEdit->setText(QCoreApplication::translate("CSettingsDialog", "180", nullptr));
        label_3->setText(QCoreApplication::translate("CSettingsDialog", "Bar", nullptr));
        label_10->setText(QCoreApplication::translate("CSettingsDialog", "/", nullptr));
        label_12->setText(QCoreApplication::translate("CSettingsDialog", "Accent", nullptr));
        label_13->setText(QCoreApplication::translate("CSettingsDialog", "Shortest 1", nullptr));
        label_14->setText(QCoreApplication::translate("CSettingsDialog", " / ", nullptr));
        intervalVariation_checkBox->setText(QCoreApplication::translate("CSettingsDialog", "Interval Variation", nullptr));
        label_15->setText(QCoreApplication::translate("CSettingsDialog", "Min.", nullptr));
        label_16->setText(QCoreApplication::translate("CSettingsDialog", "Max", nullptr));
        label_17->setText(QCoreApplication::translate("CSettingsDialog", "ms", nullptr));
        metronome_checkBox->setText(QCoreApplication::translate("CSettingsDialog", "Metronome", nullptr));
#if QT_CONFIG(tooltip)
        staccato_checkBox->setToolTip(QCoreApplication::translate("CSettingsDialog", "Active: note off after each note", nullptr));
#endif // QT_CONFIG(tooltip)
        staccato_checkBox->setText(QCoreApplication::translate("CSettingsDialog", "Staccato", nullptr));
#if QT_CONFIG(tooltip)
        loop_checkBox->setToolTip(QCoreApplication::translate("CSettingsDialog", "Loop First to Last Segment", nullptr));
#endif // QT_CONFIG(tooltip)
        loop_checkBox->setText(QCoreApplication::translate("CSettingsDialog", "Loop", nullptr));
        label_8->setText(QCoreApplication::translate("CSettingsDialog", "First Segment", nullptr));
#if QT_CONFIG(tooltip)
        firstSegment_lineEdit->setToolTip(QCoreApplication::translate("CSettingsDialog", "Start Segment to Play", nullptr));
#endif // QT_CONFIG(tooltip)
        firstSegment_lineEdit->setText(QCoreApplication::translate("CSettingsDialog", "0", nullptr));
#if QT_CONFIG(tooltip)
        set_first_segment_Btn->setToolTip(QCoreApplication::translate("CSettingsDialog", "Set \"Last Segment\" to last segment in file", nullptr));
#endif // QT_CONFIG(tooltip)
        set_first_segment_Btn->setText(QCoreApplication::translate("CSettingsDialog", "First", nullptr));
        label_7->setText(QCoreApplication::translate("CSettingsDialog", "Last Segment", nullptr));
#if QT_CONFIG(tooltip)
        lastSegment_lineEdit->setToolTip(QCoreApplication::translate("CSettingsDialog", "Last Segment to Play", nullptr));
#endif // QT_CONFIG(tooltip)
        lastSegment_lineEdit->setText(QCoreApplication::translate("CSettingsDialog", "0", nullptr));
#if QT_CONFIG(tooltip)
        set_last_segment_Btn->setToolTip(QCoreApplication::translate("CSettingsDialog", "Set \"Last Segment\" to last segment in file", nullptr));
#endif // QT_CONFIG(tooltip)
        set_last_segment_Btn->setText(QCoreApplication::translate("CSettingsDialog", "Last", nullptr));
        label_2->setText(QCoreApplication::translate("CSettingsDialog", "Audio  Interface", nullptr));
        label_4->setText(QCoreApplication::translate("CSettingsDialog", "Audio  Codec", nullptr));
        label_6->setText(QCoreApplication::translate("CSettingsDialog", "Audio  Sampling Rate", nullptr));
        label_9->setText(QCoreApplication::translate("CSettingsDialog", "Audio  Container", nullptr));
        label->setText(QCoreApplication::translate("CSettingsDialog", "MIDI Interface", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSettingsDialog: public Ui_CSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H

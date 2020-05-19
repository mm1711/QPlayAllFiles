/********************************************************************************
** Form generated from reading UI file 'channelproperties.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNELPROPERTIES_H
#define UI_CHANNELPROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CChannelProperties
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpinBox *channel_voice_spinBox;
    QComboBox *channel_note_comboBox;
    QComboBox *channel_velocity_comboBox;
    QLineEdit *channel_group_lineEdit;

    void setupUi(QWidget *CChannelProperties)
    {
        if (CChannelProperties->objectName().isEmpty())
            CChannelProperties->setObjectName(QString::fromUtf8("CChannelProperties"));
        CChannelProperties->resize(500, 30);
        CChannelProperties->setMinimumSize(QSize(500, 0));
        CChannelProperties->setMaximumSize(QSize(16777215, 16777215));
        layoutWidget = new QWidget(CChannelProperties);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 431, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        channel_voice_spinBox = new QSpinBox(layoutWidget);
        channel_voice_spinBox->setObjectName(QString::fromUtf8("channel_voice_spinBox"));
        channel_voice_spinBox->setMinimumSize(QSize(60, 0));
        channel_voice_spinBox->setMaximumSize(QSize(60, 16777215));
        channel_voice_spinBox->setMaximum(15);

        horizontalLayout->addWidget(channel_voice_spinBox);

        channel_note_comboBox = new QComboBox(layoutWidget);
        channel_note_comboBox->setObjectName(QString::fromUtf8("channel_note_comboBox"));
        channel_note_comboBox->setMinimumSize(QSize(220, 0));
        channel_note_comboBox->setMaximumSize(QSize(16777215, 16777215));
        channel_note_comboBox->setEditable(true);

        horizontalLayout->addWidget(channel_note_comboBox);

        channel_velocity_comboBox = new QComboBox(layoutWidget);
        channel_velocity_comboBox->setObjectName(QString::fromUtf8("channel_velocity_comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(channel_velocity_comboBox->sizePolicy().hasHeightForWidth());
        channel_velocity_comboBox->setSizePolicy(sizePolicy);
        channel_velocity_comboBox->setMinimumSize(QSize(90, 0));
        channel_velocity_comboBox->setMaximumSize(QSize(90, 16777215));
        channel_velocity_comboBox->setEditable(true);
        channel_velocity_comboBox->setMaxVisibleItems(20);

        horizontalLayout->addWidget(channel_velocity_comboBox);

        channel_group_lineEdit = new QLineEdit(layoutWidget);
        channel_group_lineEdit->setObjectName(QString::fromUtf8("channel_group_lineEdit"));
        channel_group_lineEdit->setMinimumSize(QSize(30, 0));
        channel_group_lineEdit->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(channel_group_lineEdit);


        retranslateUi(CChannelProperties);

        QMetaObject::connectSlotsByName(CChannelProperties);
    } // setupUi

    void retranslateUi(QWidget *CChannelProperties)
    {
        CChannelProperties->setWindowTitle(QCoreApplication::translate("CChannelProperties", "Form", nullptr));
        channel_velocity_comboBox->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class CChannelProperties: public Ui_CChannelProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNELPROPERTIES_H

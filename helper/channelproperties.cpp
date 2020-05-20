/*! \file  channelproperties.cpp

Widget code for handling the channel properties

<b>Copyright   :</b> (C) 2019 Michael Moser

<b>Last edit	:</b>

<b>History   :</b>	26-09-2019mm		creation by Michael Moser

*/

/**
 ** This file is part of the QPlayAllFiles project.
 ** Copyright 2019 Michael Moser mmoser@moser-engineering.de.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include "channelproperties.h"
#include "ui_channelproperties.h"


CChannelProperties::CChannelProperties(QWidget *parent, qint32 max_channels) :
  QWidget(parent)
{
  m_channel_count = max_channels;

  gridLayout = new QGridLayout();
  gridLayout->setContentsMargins(0, 0, 0, 0);
  gridLayout->setSpacing(2);
  gridLayout->setSizeConstraint(QLayout::SetMinimumSize);

  header1 = new QLabel;
  header1->setText(tr("Voice"));
  header1->setMinimumHeight(c_chn_height);
  header1->setMaximumHeight(c_chn_height);
  gridLayout->addWidget(header1, 0, 0 );

  header2 = new QLabel;
  header2->setText(tr("Note"));
  header2->setMinimumHeight(c_chn_height);
  header2->setMaximumHeight(c_chn_height);
  gridLayout->addWidget(header2, 0, 1 );

  header3 = new QLabel;
  header3->setText(tr("Velocity"));
  header3->setMinimumHeight(c_chn_height);
  header3->setMaximumHeight(c_chn_height);
  gridLayout->addWidget(header3, 0, 2 );

  header4 = new QLabel;
  header4->setText(tr("Group"));
  header4->setMinimumHeight(c_chn_height);
  header4->setMaximumHeight(c_chn_height);
  gridLayout->addWidget(header4, 0, 3 );

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->setSizeConstraint(QLayout::SetMinimumSize);
  mainLayout->setContentsMargins(0, 0, 0, 0);

  for(int ix = 0; ix < m_channel_count; ix++)
  {
    channel_voice_spinBox[ix] = new QSpinBox();
    channel_voice_spinBox[ix]->setObjectName(QString::number(ix));
    channel_voice_spinBox[ix]->setMinimumSize(QSize(60, 0));
    channel_voice_spinBox[ix]->setMaximumSize(QSize(60, c_chn_height));
    channel_voice_spinBox[ix]->setMaximum(15);
    channel_voice_spinBox[ix]->setValue(0);
    gridLayout->addWidget(channel_voice_spinBox[ix], ix+1, 0 );

    channel_note_comboBox[ix] = new QComboBox();
    channel_note_comboBox[ix]->setMinimumSize(QSize(220, 0));
    channel_note_comboBox[ix]->setMaximumSize(QSize(220, c_chn_height));
    channel_note_comboBox[ix]->addItems(c_note_names);
    channel_note_comboBox[ix]->setCurrentIndex(ix);
    gridLayout->addWidget(channel_note_comboBox[ix], ix+1, 1 );

    channel_velocity_comboBox[ix] = new QComboBox();
    channel_velocity_comboBox[ix]->setMinimumSize(QSize(90, 0));
    channel_velocity_comboBox[ix]->setMaximumSize(QSize(90, c_chn_height));
    channel_velocity_comboBox[ix]->addItems(c_velocity_names);
    channel_velocity_comboBox[ix]->setCurrentIndex(channel_velocity_comboBox[ix]->findText(c_velocity_names[6]));
    gridLayout->addWidget(channel_velocity_comboBox[ix], ix+1, 2 );

    channel_group_lineEdit[ix] = new QLineEdit();
    channel_group_lineEdit[ix]->setMinimumSize(QSize(50, 0));
    channel_group_lineEdit[ix]->setMaximumSize(QSize(50, c_chn_height));
    channel_group_lineEdit[ix]->setMaxLength(4);
    channel_group_lineEdit[ix]->setText("0");
    gridLayout->addWidget(channel_group_lineEdit[ix], ix+1, 3 );

    connect(channel_voice_spinBox[ix], SIGNAL(valueChanged(int)), this, SLOT(on_channel_voice_spinBox_valueChanged(int)));

  }

  mainLayout->addLayout(gridLayout);

  QSpacerItem *verticalSpacer;
  verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

  mainLayout->addItem(verticalSpacer);
  setLayout(mainLayout);
  adjustSize();
  qDebug("CChannelProperties::size= %d, %d", size().width(), size().height());
}

CChannelProperties::~CChannelProperties()
{
}

void CChannelProperties::show( qint32 chn )
{
  channel_voice_spinBox[chn]->show();
  channel_note_comboBox[chn]->show();
  channel_velocity_comboBox[chn]->show();
  channel_group_lineEdit[chn]->show();
}

void CChannelProperties::hide( qint32 chn )
{
  channel_voice_spinBox[chn]->hide();
  channel_note_comboBox[chn]->hide();
  channel_velocity_comboBox[chn]->hide();
  channel_group_lineEdit[chn]->hide();
}

void CChannelProperties::setChannelCount(qint32 chn_cnt)
{
  m_channel_count = chn_cnt;
}

/*! Return current voice index

  \return current voice index

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
qint32 CChannelProperties::getCurrentVoiceIndex(qint32 chn)
{
  return channel_voice_spinBox[chn]->value();
}

/*! Set current voice index

    \param index  voice index

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CChannelProperties::setVoiceIndex(qint32 chn, qint32 index)
{
  channel_voice_spinBox[chn]->setValue(index);
}

/*! Return current velocity index

  \return current velocity index

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
qint32 CChannelProperties::getCurrentVelocityIndex(qint32 chn )
{
  return channel_velocity_comboBox[chn]->currentIndex();
}

/*! Return current velocity value

  \return current velocity value

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
qint32 CChannelProperties::getCurrentVelocityValue(qint32 chn )
{
  return c_velocity_map[channel_velocity_comboBox[chn]->currentText()];
}

/*! Set current velocity index

    \param index  velocity index

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void  CChannelProperties::setVelocityIndex(qint32 chn, qint32 index)
{
  channel_velocity_comboBox[chn]->setCurrentIndex(index);
}

/*! Return current note index

  \return current note value

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
qint32 CChannelProperties::getCurrentNoteIndex(qint32 chn)
{
  return channel_note_comboBox[chn]->currentIndex();
}

/*! Return current note text

  \return current note text

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
QString CChannelProperties::getCurrentNoteText(qint32 chn)
{
  return channel_note_comboBox[chn]->currentText();
}

void CChannelProperties::resetChannels()
{
  for(int ix = 0; ix < m_channel_count; ix++)
  {
    channel_voice_spinBox[ix]->setValue(0);
    channel_note_comboBox[ix]->setCurrentIndex(ix);
    channel_velocity_comboBox[ix]->setCurrentIndex(channel_velocity_comboBox[ix]->findText(c_velocity_names[6]));
    channel_group_lineEdit[ix]->setText("0");
  }
}

qint8   CChannelProperties::getChannelHeight()
{
  qint32 y_pos_0 = channel_voice_spinBox[0]->geometry().y();
  qint32 y_pos_1 = channel_voice_spinBox[1]->geometry().y();
  return (y_pos_1 - y_pos_0);
}

/*! Set current note index

    \param index  note index

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CChannelProperties::setNoteIndex(qint32 chn, qint32 index)
{
  if( index >= c_note_names.size() )
  {
    index = c_note_names.size()-1;
  }
  channel_note_comboBox[chn]->setCurrentIndex(index);
}

/*! Return current group

  \return current group

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
qint32 CChannelProperties::getCurrentGroup(qint32 chn )
{
 return channel_group_lineEdit[chn]->text().toInt();
}

/*! Set current group

    \param index  group

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CChannelProperties::setGroup(qint32 chn, qint32 index)
{
  channel_group_lineEdit[chn]->setText(QString::number(index));
}


/*! Return channel settings as ";" separated QString


<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
QString CChannelProperties::toString(qint32 chn )
{
  return  c_prop_id +
          QString::number(channel_voice_spinBox[chn]->value()) + ";" +
          QString::number(channel_note_comboBox[chn]->currentIndex()) + ";" +
          QString::number(channel_velocity_comboBox[chn]->currentIndex()) + ";" +
          channel_group_lineEdit[chn]->text() + ";";
}

/*! Set channel settings from ";" separated QString

    \param settings  ";" separated settings

<b>History   :</b>	 26-09-2019mm created by Michael Moser
*/
void CChannelProperties::fromString(qint32 chn, QString settings)
{
  QStringList values = settings.split(";",QString::SkipEmptyParts);
  if(values.size() == c_chn_props_v1_0_len)
  {
    QString id = values.at(0) + ";";
    if(id == c_prop_id)
    {
      int ix = values.at(1).toInt();
      channel_voice_spinBox[chn]->setValue(ix);
      ix = values.at(2).toInt();
      if(values.at(1).toInt() == 9)
      {
        if(ix > c_percussion_name_start_index)
        {
          ix -= c_percussion_name_start_index;
        }
      }
      channel_note_comboBox[chn]->setCurrentIndex(ix);
      ix = values.at(3).toInt();
      channel_velocity_comboBox[chn]->setCurrentIndex(values.at(3).toInt());
      channel_group_lineEdit[chn]->setText(values.at(4));
    }
  }
}

void CChannelProperties::on_channel_voice_spinBox_valueChanged(int arg1)
{
  QSpinBox *spinBox = qobject_cast<QSpinBox *>(sender());
  qint32 ix = spinBox->objectName().toInt();
  channel_note_comboBox[ix]->clear();
  if(arg1 == 9)
  {
    // percussion
    channel_note_comboBox[ix]->addItems(c_percussion_names);
  }
  else
  {
    channel_note_comboBox[ix]->addItems(c_note_names);
  }
}

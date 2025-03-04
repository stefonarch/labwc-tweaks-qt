/*

    Copyright (C) 2013  Hong Jen Yee (PCMan) <pcman.tw@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#include "fontbutton.h"
#include <QFontDialog>

using namespace Fm;

FontButton::FontButton(QWidget* parent): QPushButton(parent) {
  connect(this, SIGNAL(clicked(bool)), SLOT(onClicked()));
}

FontButton::~FontButton() {
}

void FontButton::onClicked() {
  QFontDialog dlg(font_);
  if(dlg.exec() == QDialog::Accepted) {
    setFont(dlg.selectedFont());
  }
}

void FontButton::setFont(QFont font) {
  font_ = font;
  QString text = font.family();
  if(font.bold()) {
    text += QLatin1String(" ");
    text += tr("Bold");
  }
  if(font.italic()) {
    text += QLatin1String(" ");
    text += tr("Italic");
  }
  text += QStringLiteral(" %1").arg(font.pointSize());
  setText(text);
  Q_EMIT changed();
}

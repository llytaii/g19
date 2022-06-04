/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014  <copyright holder> <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "wallpaper.hpp"
#include "../../g19daemon.hpp"
#include "../../gscreen.hpp"
#include <QImage>
#include <QPainter>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QtCore>

#include <iostream>

Wallpaper::Wallpaper() {
  Q_INIT_RESOURCE(wallpaper);

  isActive = false;
  screen = new Gscreen(QImage(":/wallpaper/icon.png"), tr("Wallpaper"));

  QTimer* timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, QOverload<>::of(&Wallpaper::paint));
  timer->start(5000);

  image.load("/home/llytaii/g19/wallpaper.jpg");
}

Wallpaper::~Wallpaper() { delete screen; }

QString Wallpaper::getName() { return tr("Wallpaper"); }

void Wallpaper::lKeys(int keys) {}

void Wallpaper::mKeys(int keys) {}

void Wallpaper::setActive(bool active) {
  isActive = active;

  if (active) {
    paint();
  }
}

void Wallpaper::paint() {
  if (isActive) {
    // update image
    image.load("/home/llytaii/g19/wallpaper.jpg");

    // draw image    
    QPainter *p;
    p = screen->beginFullScreen();
    p->drawImage(QRect(0,0,320,240), image);
    screen->end();
    emit doAction(displayFullScreen, screen);
  }
}

bool Wallpaper::isPopup() { return false; }

QObject *Wallpaper::getQObject() { return this; }

QImage Wallpaper::getIcon() { return QImage(":/wallpaper/menu_icon.png"); }

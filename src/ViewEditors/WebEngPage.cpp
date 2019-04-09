/************************************************************************
**
**  Copyright (C) 2019 Kevin B. Hendricks, Stratford Ontario Canada
**
**  This file is part of Sigil.
**
**  Sigil is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Sigil is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Sigil.  If not, see <http://www.gnu.org/licenses/>.
**
*************************************************************************/
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QDebug>
#include "ViewEditors/WebEngPage.h"

WebEngPage::WebEngPage(QObject *parent)
    : QWebEnginePage(parent)
{
}

// Because you can not delegate all links in QtWebEngine we must override here and generate
// our own link requests
bool WebEngPage::acceptNavigationRequest(const QUrl & url, QWebEnginePage::NavigationType type, bool isMainFrame)
{
    if (type == QWebEnginePage::NavigationTypeLinkClicked) {
        // qDebug() << "acceptNavigationRequest " << url.toString() << " , " << type << " , " << isMainFrame;
        emit LinkClicked(url);
        return false;
    }
    return true;
}


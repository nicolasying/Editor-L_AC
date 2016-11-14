#include "syntax.h"
#include "documenthandler.h"
#include "networkgetlangfile.h"

#ifndef UNIVERSALHEADER_H
#define UNIVERSALHEADER_H

#include <QApplication>
#include <QFileInfo>
#include <QGuiApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMainWindow>
#include <QMenuBar>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlFile>
#include <QQuickStyle>
#include <QQuickTextDocument>
#include <QString>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QTextCodec>
#include <QTextCursor>
#include <QTextDocument>
#include <QWindow>

typedef enum codingLanguage {
    Lac,
    C
} codingLanguage;

QString getLangFileInfo(codingLanguage langFlag) {
    switch (langFlag) {
    case Lac:
        return QStringLiteral("lac_language.json");
        break;
    case C:
        return QStringLiteral("c_language.json");
        break;
    default:
        qWarning("invalid language configured.");
        exit(201);
    }
}

#endif // UNIVERSALHEADER_H

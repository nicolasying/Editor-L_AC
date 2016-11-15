#ifndef SYNTAX_H
#define SYNTAX_H

#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickItem>
#include <QQuickTextDocument>
#include <QSyntaxHighlighter>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include <QEventLoop>
#include <QVariantList>
#include "networkgetlangfile.h"
#include "universalheader.h"

class customizedSyntaxHighligher : public QSyntaxHighlighter {
    Q_OBJECT

friend class syntaxHilighterHandler;

protected:
    void highlightBlock(const QString &text);
public:
    customizedSyntaxHighligher(QTextDocument * parent = NULL, codingLanguage langFlag = C);
private:
    struct HighlightingRule {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;
    codingLanguage langFlag;
    QRegExp commentStartExpression;
    QRegExp commentEndExpression;
    QTextCharFormat keywordFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat stringFormat;
};

#endif // SYNTAX_H

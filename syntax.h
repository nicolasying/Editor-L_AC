#ifndef SYNTAX_H
#define SYNTAX_H

#include <QQmlApplicationEngine>
#include <QObject>
#include <QSyntaxHighlighter>
#include <QJsonDocument>
#include <QFile>
#include "networkgetlangfile.h"
#include "universalheader.h"

class customizedSyntaxHighligher : public QSyntaxHighlighter {
    Q_OBJECT
friend class syntaxHilighterHandler;
protected:
    void highlightBlock(const QString &text);
public:
    customizedSyntaxHighligher(QTextDocument * parent, codingLanguage langFlag);

private slots:
    void constructorRest(codingLanguage langFlag);
private:
    struct HighlightingRule {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat stringFormat;
};

#endif // SYNTAX_H

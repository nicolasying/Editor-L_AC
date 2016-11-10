#include <QObject>
#include <QString>
#include <QMainWindow>
#include <QQuickTextDocument>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>

#ifndef SYNTAX_H
#define SYNTAX_H

class customizedSyntaxHighligher : public QSyntaxHighlighter {
    Q_OBJECT
protected:
    void highlightBlock(const QString &text);
public:
    customizedSyntaxHighligher(QTextDocument * parent);
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

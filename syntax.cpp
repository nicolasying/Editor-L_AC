#include "syntax.h"

void customizedSyntaxHighligher::highlightBlock(const QString &text) {
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }

    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0) {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                    + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}

customizedSyntaxHighligher::customizedSyntaxHighligher(QTextDocument *parent, codingLanguage langFlag) : QSyntaxHighlighter(parent) {
    QFile langFile(getLangFileInfo(langFlag));

    if (!langFile.exists()) {
        langFileFetcher * tempFetcher = new langFileFetcher(langFlag);
        qDebug("Downloading file.");
        connect(tempFetcher, SIGNAL(downloaded()), this, SLOT(constructorRest(codingLanguage langFlag)));
        return;
    }
    constructorRest(langFlag);
}

void customizedSyntaxHighligher::constructorRest(codingLanguage flag) {
    QFile langFile(getLangFileInfo(flag));

    qDebug("with local language file.");
    if (!langFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
    }

    HighlightingRule rule;

    keywordFormat.setForeground(Qt::yellow);
    QStringList keywordPatterns;
    keywordPatterns << "\\bdup\\b" << "\\bdrop\\b" << "\\bswap\\b" << "\\bif\\b" << "\\belse\\b" << "\\bthen\\b"
                    << "(^| )[.]( |\t|$)" << "\\bcount\\b" << "\\btype\\b" << "(^| )[:]( |\t|$)";
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    stringFormat.setForeground(QColor(32, 142, 255));
    rule.pattern = QRegExp("(^| |\t)\" [^\n]*\"( |\t|$)");
    rule.format = stringFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(QColor(128, 128, 128, 200));
    rule.pattern = QRegExp("(^| |\t)\\\\(( [^\n]*)|$)");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(QColor(128, 128, 128, 200));

    commentStartExpression = QRegExp("(^| |\t)[(] ");
    commentEndExpression = QRegExp("[)]");
}

//void syntaxHilighterHandler::newTabCreated(const char * objectName) {
//    QQuickTextDocument * activeCodeText = childObject<QQuickTextDocument*>(engine, objectName, "textDocument");
//    Q_ASSERT(activeCodeText != 0);
//    highlighters[counter++] = new customizedSyntaxHighligher(activeCodeText->textDocument());
//}

//void syntaxHilighterHandler::newTabDestroyed(const char * objectName) {
//    // delete the parser
//    return;
//}

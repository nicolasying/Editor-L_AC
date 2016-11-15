#include "highlighterhandler.h"

syntaxHilighterHandler::syntaxHilighterHandler() : QObject(nullptr) {
    counter = 0;
    return;
}

syntaxHilighterHandler::~syntaxHilighterHandler() {
    for (; counter>=0; counter--) {
        if (highlighters[counter] != NULL)
            delete highlighters[counter];
    }
}

void syntaxHilighterHandler::langFileReady (codingLanguage langFlag) {
    QQuickTextDocument * activeCodeText = childObject<QQuickTextDocument*>(engine, "activeCodeText", "textDocument");
    Q_ASSERT(activeCodeText != 0);

    highlighters[0] = new customizedSyntaxHighligher(activeCodeText->textDocument(), langFlag);
}

void syntaxHilighterHandler::langChanged(const codingLanguage &langFlag) {

    if (highlighters[0] != NULL) {
        try { delete highlighters[0]; }
        catch (...) {
            qWarning("langChanged: delete failed.");
        }
    }
    this->constructHighlighter(langFlag);
}

void syntaxHilighterHandler::constructHighlighter(codingLanguage langFlag) {
    QFile langFile(getLangFileInfo(langFlag));

    if (!langFile.exists()) {
        qDebug("Downloading file.");
        QEventLoop loop;
        langFileFetcher * tempFetcher = new langFileFetcher(langFlag);
        qDebug("Fetcher constructed");
        connect(tempFetcher, SIGNAL(downloaded(codingLanguage)), this, SLOT(langFileReady(codingLanguage)));
        qDebug("Singal connected");
        return;
    }
    langFileReady(langFlag);
}

#include "highlighterhandler.h"

extern QQmlApplicationEngine * engine_p;

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
    QQuickTextDocument * activeCodeText = childObject<QQuickTextDocument*>((*engine_p), "activeCodeText", "textDocument");
    Q_ASSERT(activeCodeText != 0);

    highlighters[0] = new customizedSyntaxHighligher(activeCodeText->textDocument(), langFlag);
    counter++;
}

void syntaxHilighterHandler::langChanged(const QString &arg) {
    qDebug("synHandler: language changed.");
    if (counter == 0) return;
    if (highlighters[0] != NULL) {
        qDebug("synHandler: deleting highlighter.");
        try { delete highlighters[0]; }
        catch (...) {
            qWarning("langChanged: delete failed.");
        }
    }
    counter--;
    codingLanguage langFlag = C;
    if (arg != "C") langFlag = Lac;
    this->constructHighlighter(langFlag);
}

void syntaxHilighterHandler::constructHighlighter(codingLanguage langFlag) {
    qDebug("Constructing a new highlighter.");
    QFile langFile(getLangFileInfo(langFlag));

    if (!langFile.exists()) {
        qDebug("Downloading file.");
        //QEventLoop loop;
        langFileFetcher * tempFetcher = new langFileFetcher(langFlag);
        qDebug("Fetcher constructed");
        connect(tempFetcher, SIGNAL(downloaded(codingLanguage)), this, SLOT(langFileReady(codingLanguage)));
        qDebug("Singal connected");
        return;
    }
    langFileReady(langFlag);
}

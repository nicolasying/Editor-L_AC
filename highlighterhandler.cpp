#include "highlighterhandler.h"

extern QQmlApplicationEngine * engine_p;

syntaxHilighterHandler::syntaxHilighterHandler() : QObject(nullptr) {
    counter = 0;
    return;
}

syntaxHilighterHandler::~syntaxHilighterHandler() {

    if (counter != 0 || highlighters[0] != NULL)
        delete highlighters[counter];

}

void syntaxHilighterHandler::langFileReady (codingLanguage langFlag) {
    if (tempFetcher != NULL) delete tempFetcher;
    QQuickTextDocument * activeCodeText = childObject<QQuickTextDocument*>((*engine_p), "activeCodeText", "textDocument");
    Q_ASSERT(activeCodeText != 0);
    counter++;
    highlighters[0] = new customizedSyntaxHighligher(activeCodeText->textDocument(), langFlag);
}

void syntaxHilighterHandler::langChanged(const QString &arg) {
    qDebug("synHandler: language changed.");
    static int changeInstance = 0;
    changeInstance++;
    if (changeInstance == 1) return;
    codingLanguage langFlag = C;
    if (arg != "C") langFlag = Lac;

    if (counter == 0) {
        qDebug("synHandler: initial highlighter.");
        this->constructHighlighter(langFlag);
        return;
    }

    if (highlighters[0] != NULL) {
        qDebug("synHandler: deleting highlighter.");
        try { delete highlighters[0]; }
        catch (...) {
            qWarning("langChanged: delete failed.");
        }
    }
    counter--;
    this->constructHighlighter(langFlag);
}

void syntaxHilighterHandler::constructHighlighter(codingLanguage langFlag) {
    qDebug("Constructing a new highlighter.");
    QFile langFile(getLangFileInfo(langFlag));

    if (!langFile.exists()) {
        qDebug("Downloading file.");
        //QEventLoop loop;
        tempFetcher = new langFileFetcher(langFlag);
        qDebug("Fetcher constructed");
        connect(tempFetcher, SIGNAL(downloaded(codingLanguage)), this, SLOT(langFileReady(codingLanguage)));
        qDebug("Singal connected");
        return;
    }
    langFileReady(langFlag);
}

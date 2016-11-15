#include "universalheader.h"
#include <QDebug>
#include <QGuiApplication>
#include <QQuickTextDocument>
#include "syntax.h"
#include "documenthandler.h"
#include "highlighterhandler.h"

int main(int argc, char *argv[])
{
    codingLanguage flag = C;
    qDebug() << "http://nicolasying.github.io/" + getLangFileInfo(flag);

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    qmlRegisterType<DocumentHandler>("local.nicolasien.editorlac", 1, 0, "DocumentHandler");
    qmlRegisterType<syntaxHilighterHandler>("local.nicolasien.editorlac", 1, 0, "HighliterHandler");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    syntaxHilighterHandler * highlighterHandler = new syntaxHilighterHandler();
    highlighterHandler->constructHighlighter(flag);

    int ret = app.exec();
    //delete parser;
    return ret;
}

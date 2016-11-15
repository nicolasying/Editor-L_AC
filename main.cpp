#include "universalheader.h"
#include <QDebug>
#include <QGuiApplication>
#include <QQuickTextDocument>
#include "syntax.h"
#include "documenthandler.h"
#include "highlighterhandler.h"

QQmlApplicationEngine * engine_p;

int main(int argc, char *argv[])
{
//    codingLanguage flag = Lac;

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    qmlRegisterType<DocumentHandler>("local.nicolasien.editorlac", 1, 0, "DocumentHandler");
    qmlRegisterType<syntaxHilighterHandler>("local.nicolasien.editorlac", 1, 0, "HighliterHandler");
    QQmlApplicationEngine engine;
    engine_p = &engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

//    syntaxHilighterHandler * highlighterHandler = new syntaxHilighterHandler();
//    highlighterHandler->constructHighlighter(flag);

    int ret = app.exec();
    return ret;
}

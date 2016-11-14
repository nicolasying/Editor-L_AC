#include "syntax.h"
#include "documenthandler.h"
#include <QApplication>
#include <QWindow>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QMenuBar>
#include <QQmlContext>
#include <QJsonDocument>
#include <QJsonObject>

int main(int argc, char *argv[])
{
    QFile langFile(QStringLiteral("lac_language.json"));

    if (!langFile.open(QIODevice::ReadOnly)) {
        return 101;
    }

    QJsonDocument langInfo(QJsonDocument::fromJson((QByteArray)langFile.readAll()));
    QJsonObject langObj = langInfo.object();
    qWarning() << langObj["version"].toString().toLatin1().data();
//    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//    QGuiApplication app(argc, argv);
//    qmlRegisterType<DocumentHandler>("local.nicolasien.editorlac", 1, 0, "DocumentHandler");
//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

//    syntaxHilighterHandler highlighterHandler;
//    (engine.rootContext())->setContextProperty("_Highlighters", &highlighterHandler);

    //int ret = app.exec();
    //delete parser;
    return 0;
}

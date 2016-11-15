#include "universalheader.h"
#include <QDebug>
#include <QGuiApplication>
#include <QQuickTextDocument>
#include "syntax.h"
#include "documenthandler.h"

int main(int argc, char *argv[])
{
    codingLanguage flag = C;
    qDebug() << "http://nicolasying.github.io/" + getLangFileInfo(flag);

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    qmlRegisterType<DocumentHandler>("local.nicolasien.editorlac", 1, 0, "DocumentHandler");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    QQuickTextDocument * activeCodeText = childObject<QQuickTextDocument*>(engine, "activeCodeText", "textDocument");
    Q_ASSERT(activeCodeText != 0);
    customizedSyntaxHighligher * newH = new customizedSyntaxHighligher(activeCodeText->textDocument(), flag);

    int ret = app.exec();
    //delete parser;
    return ret;
}

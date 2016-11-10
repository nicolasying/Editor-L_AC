#include "syntax.h"
#include "documenthandler.h"
#include <QApplication>
#include <QWindow>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QMenuBar>

template <class T> T childObject(QQmlApplicationEngine& engine,
                                 const QString& objectName,
                                 const QString& propertyName)
{
    QList<QObject*> rootObjects = engine.rootObjects();
    foreach (QObject* object, rootObjects)
    {
        QObject* child = object->findChild<QObject*>(objectName);
        if (child != 0)
        {
            std::string s = propertyName.toStdString();
            QObject* object = child->property(s.c_str()).value<QObject*>();
            Q_ASSERT(object != 0);
            T prop = dynamic_cast<T>(object);
            Q_ASSERT(prop != 0);
            return prop;
        }
    }
    return (T) 0;
}

int main(int argc, char *argv[])
{

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    qmlRegisterType<DocumentHandler>("local.nicolasien.editorlac", 1, 0, "DocumentHandler");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

//    QQuickTextDocument * activeCodeText = childObject<QQuickTextDocument*>(engine, "activeCodeText", "textDocument");
//    Q_ASSERT(activeCodeText != 0);

//    customizedSyntaxHighligher * parser = new customizedSyntaxHighligher(activeCodeText->textDocument());
    int ret = app.exec();
//    delete parser;
    return ret;
}

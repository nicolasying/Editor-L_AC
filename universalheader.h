#ifndef UNIVERSALHEADER_H
#define UNIVERSALHEADER_H

#include <QString>
#include <QQmlApplicationEngine>
#include <QObject>

typedef enum codingLanguage {
    Lac,
    C
} codingLanguage;

QString getLangFileInfo(codingLanguage langFlag);

extern QQmlApplicationEngine * engine_p;

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


#endif // UNIVERSALHEADER_H

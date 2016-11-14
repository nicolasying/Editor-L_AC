#include "universalheader.h"

#ifndef SYNTAX_H
#define SYNTAX_H


extern QQmlApplicationEngine engine;

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

class customizedSyntaxHighligher : public QSyntaxHighlighter {
    Q_OBJECT
protected:
    void highlightBlock(const QString &text);
public:
    customizedSyntaxHighligher(QTextDocument * parent, codingLanguage langFlag);

//public slots:
//    void newTabCreated(const char * objectName);
//    void newTabDestroyed(const char * objectName);
private:
    struct HighlightingRule {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat stringFormat;
};

//class syntaxHilighterHandler : public QObject {
//    Q_OBJECT
//private:
//    QVector<customizedSyntaxHighligher *> highlighters;
//    int counter;
//public:
//    syntaxHilighterHandler() : QObject() {
//        counter = 0;
//    }

//public Q_SLOTS:
//    void newTabCreated(const char * objectName);
//    void newTabDestroyed(const char * objectName);
//};

#endif // SYNTAX_H

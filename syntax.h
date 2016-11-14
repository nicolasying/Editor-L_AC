#ifndef SYNTAX_H
#define SYNTAX_H

#include "universalheader.h"

typedef enum codingLanguage {
    Lac,
    C
} codingLanguage;

void getLangFile (codingLanguage) {
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    switch (langFlag) {
    case LAC:
        QFile langFile(QStringLiteral("lac_language.json"));
        break;
    case C:
        QFile langFile(QStringLiteral("c_language.json"));
        break;
    default:
        qWarning("not a valid coding language");
        exit(100);
    }
    QNetworkReply * manager->get(QNetworkRequest(QUrl("http://nicolasying.github.io/lac_language.json")));
}

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

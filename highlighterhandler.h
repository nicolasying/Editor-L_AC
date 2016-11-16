#ifndef HIGHLIGHTERHANDLER_H
#define HIGHLIGHTERHANDLER_H

#include <QObject>
#include <QVector>
#include <QTextDocument>
#include <QQuickTextDocument>
#include "syntax.h"
#include "universalheader.h"

class syntaxHilighterHandler : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString targetLang READ targetLang WRITE langChanged)
private:
    customizedSyntaxHighligher * highlighters[2];
    int counter;
//    QQuickItem *m_target;
//    QObject * whatever;
    langFileFetcher * tempFetcher;
    QString m_targetLang;
    QString targetLang() const {return m_targetLang;}
public:
    syntaxHilighterHandler();
    ~syntaxHilighterHandler();
    void constructHighlighter(codingLanguage langFlag);

public slots:
    void langChanged(const QString &arg);
    void langFileReady(codingLanguage langFlag);
};

#endif // HIGHLIGHTERHANDLER_H

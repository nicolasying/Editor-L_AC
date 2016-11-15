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
    Q_PROPERTY(codingLanguage targetLang READ targetLang WRITE langChanged)
private:
    QVector<customizedSyntaxHighligher *> highlighters;
    int counter;
//    QQuickItem *m_target;
    codingLanguage m_targetLang;
    codingLanguage targetLang() const {return m_targetLang;}
public:
    syntaxHilighterHandler();
    ~syntaxHilighterHandler();
    void constructHighlighter(codingLanguage langFlag);

public slots:
    void langChanged(const codingLanguage &arg);
    void langFileReady(codingLanguage langFlag);
};

#endif // HIGHLIGHTERHANDLER_H

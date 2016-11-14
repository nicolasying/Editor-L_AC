#ifndef DOCUMENTHANDLER_H
#define DOCUMENTHANDLER_H

#include "universalheader.h"
#include <QObject>
#include <QQuickItem>
#include <QQuickTextDocument>
#include <QQmlFile>
#include <QTextCodec>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class DocumentHandler : public QObject
{
    Q_OBJECT

    Q_ENUMS(HAlignment)

    Q_PROPERTY(QQuickItem *target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(QUrl fileUrl READ fileUrl WRITE setFileUrl NOTIFY fileUrlChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString documentTitle READ documentTitle WRITE setDocumentTitle NOTIFY documentTitleChanged)

public:
    DocumentHandler();

    QQuickItem *target() { return m_target; }

    void setTarget(QQuickItem *target);

    QUrl fileUrl() const;
    QString text() const;

    QString documentTitle() const;

public Q_SLOTS:

    void setFileUrl(const QUrl &arg);
    void setText(const QString &arg);
    void saveAs(const QUrl &arg, const QString &fileType);
 //   void save(const QUrl &arg);

    void setDocumentTitle(QString arg);

Q_SIGNALS:
    void targetChanged();
    void cursorPositionChanged();

    void fileUrlChanged();

    void textChanged();
    void documentTitleChanged();
    void error(QString message);

private:
    void reset();

    QQuickItem *m_target;
    QTextDocument *m_doc;

    QUrl m_fileUrl;
    QString m_text;
    QString m_documentTitle;
};

#endif

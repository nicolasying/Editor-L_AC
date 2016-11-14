#include "documenthandler.h"


DocumentHandler::DocumentHandler()
    : m_target(0)
    , m_doc(0)
{
}

void DocumentHandler::setTarget(QQuickItem *target)
{
    m_doc = 0;
    m_target = target;
    if (!m_target)
        return;

    QVariant doc = m_target->property("textDocument");
    if (doc.canConvert<QQuickTextDocument*>()) {
        QQuickTextDocument *qqdoc = doc.value<QQuickTextDocument*>();
        if (qqdoc)
            m_doc = qqdoc->textDocument();
    }
    emit targetChanged();
}

void DocumentHandler::setFileUrl(const QUrl &arg)
{
    if (m_fileUrl != arg) {
        m_fileUrl = arg;
        QString fileName = QQmlFile::urlToLocalFileOrQrc(arg);
        if (QFile::exists(fileName)) {
            QFile file(fileName);
            if (file.open(QFile::ReadOnly)) {
                QByteArray data = file.readAll();
                QTextCodec *codec = QTextCodec::codecForHtml(data);
                setText(codec->toUnicode(data));
                if (m_doc)
                    m_doc->setModified(false);
                if (fileName.isEmpty())
                    m_documentTitle = QStringLiteral("untitled.txt");
                else
                    m_documentTitle = QFileInfo(fileName).fileName();

                emit textChanged();
                emit documentTitleChanged();

                reset();
            }
        }
        emit fileUrlChanged();
    }
}

QString DocumentHandler::documentTitle() const
{
    return m_documentTitle;
}

void DocumentHandler::setDocumentTitle(QString arg)
{
    if (m_documentTitle != arg) {
        m_documentTitle = arg;
        emit documentTitleChanged();
    }
}

void DocumentHandler::setText(const QString &arg)
{
    if (m_text != arg) {
        m_text = arg;
        emit textChanged();
    }
}

void DocumentHandler::saveAs(const QUrl &arg, const QString &fileType)
{
    bool isLac = fileType.contains(QLatin1String("lac"));
    QLatin1String ext(isLac ? ".lac" : ".txt");
    QString localPath = arg.toLocalFile();
    if (!localPath.endsWith(ext))
        localPath += ext;
    QFile f(localPath);
    if (!f.open(QFile::WriteOnly | QFile::Truncate | (isLac ? QFile::NotOpen : QFile::Text))) {
        emit error(tr("Cannot save: ") + f.errorString());
        return;
    }
    f.write((isLac ? m_doc->toHtml() : m_doc->toPlainText()).toLocal8Bit());
    f.close();
    setFileUrl(QUrl::fromLocalFile(localPath));
}

//void DocumentHandler::save (const QUrl &arg) {
//    QString localPath = arg.toLocalFile();

//}

QUrl DocumentHandler::fileUrl() const
{
    return m_fileUrl;
}

QString DocumentHandler::text() const
{
    return m_text;
}

void DocumentHandler::reset()
{
    return;
}

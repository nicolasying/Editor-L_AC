#include "networkgetlangfile.h"

langFileFetcher::langFileFetcher(codingLanguage flag, QObject *parent) :
    QObject(parent)
{
    connect(
                &m_WebCtrl, SIGNAL (finished(QNetworkReply*)),
                this, SLOT (fileDownloaded(QNetworkReply*))
                );

    this->flag = flag;
    QUrl fileUrl("http://nicolasying.github.io/" + getLangFileInfo(flag));
    QNetworkRequest request(fileUrl);
    qDebug("Fetcher: sending get request.");
    m_WebCtrl.setNetworkAccessible(QNetworkAccessManager::Accessible);
    m_WebCtrl.get(request);
    qDebug("Fetcher: get request sent.");
}

langFileFetcher::~langFileFetcher() { }

void langFileFetcher::fileDownloaded(QNetworkReply* pReply) {
    qDebug("downloaded.");
    m_DownloadedData = pReply->readAll();
    saveFile();
    qDebug("saved.");
    emit downloaded();
}

QByteArray langFileFetcher::downloadedData() const {
    return m_DownloadedData;
}

void langFileFetcher::saveFile() {
    qDebug("File saver.");
    QFile * destFile = new QFile(getLangFileInfo(flag));
    destFile->open(QIODevice::WriteOnly);
    if(destFile->isOpen()) {
        destFile->write(m_DownloadedData);
        destFile->close();
    }
    else qWarning("File not avaible.");
    return;
}


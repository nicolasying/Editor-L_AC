#ifndef NETWORKGETLANGFILE_H
#define NETWORKGETLANGFILE_H

#include "universalheader.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>

class langFileFetcher : public QObject
{
    Q_OBJECT
public:
    explicit langFileFetcher(codingLanguage flag, QObject *parent = 0);
    virtual ~langFileFetcher();
    QByteArray downloadedData() const;

signals:
    void downloaded(codingLanguage flag);

private slots:
    void fileDownloaded(QNetworkReply* pReply);
    void saveFile();

private:
    codingLanguage flag;
    QNetworkAccessManager m_WebCtrl;
    QByteArray m_DownloadedData;
};

#endif // NETWORKGETLANGFILE_H

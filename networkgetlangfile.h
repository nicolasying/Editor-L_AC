#include "universalheader.h"

#ifndef NETWORKGETLANGFILE_H
#define NETWORKGETLANGFILE_H



void getLangFile (codingLanguage flag) {
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));


    //QNetworkReply * Reply manager->get(QNetworkRequest(QUrl("http://nicolasying.github.io/"+getLangFileInfo(codingLanguage))));
}

#endif // NETWORKGETLANGFILE_H

#include "universalheader.h"

QString getLangFileInfo(codingLanguage langFlag) {
    switch (langFlag) {
    case Lac:
        return QStringLiteral("lac_language.json");
        break;
    case C:
        return QStringLiteral("c_language.json");
        break;
    default:
        qWarning("invalid language configured.");
        exit(201);
    }
}


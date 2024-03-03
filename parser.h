#include <QStringList>

#ifndef PARSER_H
#define PARSER_H

QStringList parse_local(QString text);
QStringList parseRemote(QString text);
QStringList parseAttached(QString text);
QStringList parseModules(QString lsmod);

#endif // PARSER_H

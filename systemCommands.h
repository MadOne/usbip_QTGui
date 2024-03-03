#include <QStringList>

#ifndef SYSTEMCOMMANDS_H
#define SYSTEMCOMMANDS_H

QString remoteGet(QString ip);
void remoteAttach(QString ip, QString busid);
QString localGet();
void localBind(QString busid);
void localUnbind(QString busid);
QString attachedGet();
void attachedDetach(QString port);
void modulesLoad(QStringList missingModules);
QString lsmodTxt();

#endif // SYSTEMCOMMANDS_H

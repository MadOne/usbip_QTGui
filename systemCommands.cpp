#include "QDebug"
#include "QProcess"

QString remoteGet(QString ip)
{
    QProcess process;
    // QString ip = ui->leIp->text();
    QStringList params = {"list", "-r", ip};
    process.start("usbip", params);
    bool finished = process.waitForFinished(500);
    QString stdout = process.readAllStandardOutput();
    QString stderr = process.readAllStandardError();
    if (!finished)
    {
        qDebug() << "Timeout!";
        return "error";
    }
    if (stdout != "")
    {
        qDebug() << stdout;
    }

    if (stderr != "")
    {
        qDebug() << stderr;
    }
    return stdout;
}

void remoteAttach(QString ip, QString busid)
{
    QProcess process;
    QStringList params = {"usbip", "attach", "-r", ip, "-b", busid};
    process.start("pkexec", params);
    bool finished = process.waitForFinished(10000);
    if (!finished)
    {
        return;
    }
    QString stdout = process.readAllStandardOutput();
    QString stderr = process.readAllStandardError();
    if (stdout != "")
    {
        qDebug() << stdout;
    }

    if (stderr != "")
    {
        qDebug() << stderr;
    }
}

QString localGet()
{
    QProcess process;
    QStringList params = {"list", "-l"};
    process.start("usbip", params);
    process.waitForFinished(500);
    QString stdout = process.readAllStandardOutput();
    QString stderr = process.readAllStandardError();
    return stdout;
}

void localBind(QString busid)
{
    QProcess process;
    QStringList params = {"usbip", "bind", "-b", busid};
    process.start("pkexec", params);
    process.waitForFinished(10000);
    QString stdout = process.readAllStandardOutput();
    QString stderr = process.readAllStandardError();
    if (stdout != "")
    {
        qDebug() << stdout;
    }

    if (stderr != "")
    {
        qDebug() << stderr;
    }
}

void localUnbind(QString busid)
{
    QProcess process;
    QStringList params = {"usbip", "unbind", "-b", busid};
    process.start("pkexec", params);
    process.waitForFinished(10000);
    QString stdout = process.readAllStandardOutput();
    QString stderr = process.readAllStandardError();
    if (stdout != "")
    {
        qDebug() << stdout;
    }

    if (stderr != "")
    {
        qDebug() << stderr;
    }
}

QString attachedGet()
{
    QProcess process;
    QStringList params = {"port"};
    process.start("usbip", params);
    process.waitForFinished(500);
    QString stdout = process.readAllStandardOutput();
    QString stderr = process.readAllStandardError();
    if (stdout != "")
    {
        qDebug() << stdout;
    }

    if (stderr != "")
    {
        qDebug() << stderr;
    }
    return stdout;
}

void attachedDetach(QString port)
{
    QProcess process;
    QStringList params = {"usbip", "detach", "-p", port};
    process.start("pkexec", params);
    process.waitForFinished(10000);
    QString stdout = process.readAllStandardOutput();
    QString stderr = process.readAllStandardError();
    if (stdout != "")
    {
        qDebug() << stdout;
    }

    if (stderr != "")
    {
        qDebug() << stderr;
    }
}

void modulesLoad(QStringList missingModules)
{
    QProcess process;
    if (missingModules.length() == 0)
    {
        return;
    }
    QStringList params = missingModules;
    params.prepend("modprobe");
    process.start("pkexec", params);
    process.waitForFinished(10000);
    QString stdout = process.readAllStandardOutput();
    QString stderr = process.readAllStandardError();
    if (stdout != "")
    {
        qDebug() << stdout;
    }

    if (stderr != "")
    {
        qDebug() << stderr;
    }
}

QString lsmodTxt()
{
    QProcess process;
    QStringList params = {};
    process.start("lsmod", params);
    process.waitForFinished(10000);
    QString lsmod = process.readAllStandardOutput();
    return lsmod;
}
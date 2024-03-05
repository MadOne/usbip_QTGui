#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"
#include "QProcess"
#include "QStandardItemModel"
#include "QMessageBox"
#include <string>
#include <unistd.h>
#include "servermanager.h"
#include "systemCommands.h"
#include "parser.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // loadModules();
    checkModules();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateLocal(QStringList deviceList)
{

    ui->tvLocal->setRowCount(0);
    int rows = deviceList.count() / 3;
    for (int i = 0; i < rows; i++)
    {
        ui->tvLocal->insertRow(ui->tvLocal->rowCount());
        ui->tvLocal->setItem(i, 0, new QTableWidgetItem(deviceList[i * 3]));
        ui->tvLocal->setItem(i, 1, new QTableWidgetItem(deviceList[i * 3 + 1]));
        ui->tvLocal->setItem(i, 2, new QTableWidgetItem(deviceList[i * 3 + 2]));
    }
}

void MainWindow::populateRemote(QStringList deviceList)
{
    ui->tvRemote->setRowCount(0);
    int rows = deviceList.count() / 3;
    qDebug() << rows;
    for (int i = 0; i < rows; i++)
    {
        ui->tvRemote->insertRow(ui->tvRemote->rowCount());
        ui->tvRemote->setItem(i, 0, new QTableWidgetItem(deviceList[i * 3]));
        ui->tvRemote->setItem(i, 1, new QTableWidgetItem(deviceList[i * 3 + 1]));
        ui->tvRemote->setItem(i, 2, new QTableWidgetItem(deviceList[i * 3 + 2]));
    }
}

void MainWindow::populateAttached(QStringList deviceList)
{
    ui->tvAttached->setRowCount(0);
    int rows = deviceList.count() / 5;
    for (int i = 0; i < rows; i++)
    {
        ui->tvAttached->insertRow(ui->tvRemote->rowCount());
        ui->tvAttached->setItem(i, 0, new QTableWidgetItem(deviceList[i * 3]));
        ui->tvAttached->setItem(i, 1, new QTableWidgetItem(deviceList[i * 3 + 1]));
        ui->tvAttached->setItem(i, 2, new QTableWidgetItem(deviceList[i * 3 + 2]));
        ui->tvAttached->setItem(i, 3, new QTableWidgetItem(deviceList[i * 3 + 3]));
        ui->tvAttached->setItem(i, 4, new QTableWidgetItem(deviceList[i * 3 + 4]));
    }
}

void MainWindow::btnRemoteRefresh()
{
    QString ip = ui->leIp->text();
    QString remoteTxt = remoteGet(ip);
    QStringList myReturn = parseRemote(remoteTxt);
    populateRemote(myReturn);
}

void MainWindow::btnRemoteAttach()
{
    QProcess process;
    QString ip = ui->leIp->text();
    QString busid;
    if (ui->tvRemote->currentRow() >= 0)
    {
        busid = ui->tvRemote->item(ui->tvRemote->currentRow(), 0)->text();
        busid = busid.trimmed();
    }
    remoteAttach(ip, busid);
    btnRemoteRefresh();
    sleep(1);
    btnAttachedRefresh();
}

void MainWindow::btnLocalRefresh()
{

    QString localDevicesTxt = localGet();
    QStringList deviceReturn = parse_local(localDevicesTxt);
    populateLocal(deviceReturn);
}

void MainWindow::btnLocalBind()
{

    QString busid;
    if (ui->tvLocal->currentRow() >= 0)
    {
        busid = ui->tvLocal->item(ui->tvLocal->currentRow(), 0)->text();
    }
    localBind(busid);
}

void MainWindow::btnLocalUnbind()
{
    QString busid;
    if (ui->tvLocal->currentRow() >= 0)
    {
        busid = ui->tvLocal->item(ui->tvLocal->currentRow(), 0)->text();
    }
    localUnbind(busid);
}

void MainWindow::btnAttachedRefresh()
{
    QString attachedTxt = attachedGet();
    QStringList myReturn = parseAttached(attachedTxt);
    populateAttached(myReturn);
}

void MainWindow::btnAttachedDetach()
{
    QString port;
    if (ui->tvAttached->currentRow() >= 0)
    {
        port = ui->tvAttached->item(ui->tvAttached->currentRow(), 1)->text();
        attachedDetach(port);
        btnAttachedRefresh();
        btnRemoteRefresh();
    }
}

void MainWindow::on_actionServer_Manager_triggered()
{
    serverManager *newSM = new serverManager();
    if (newSM->exec())
    {
        QString Ip = newSM->getIp();
        setIp(Ip);
    }
}

void MainWindow::setIp(QString ip)
{
    ui->leIp->setText(ip);
}

void MainWindow::checkModules()
{
    QString lsmod = lsmodTxt();
    QStringList missingModules = parseModules(lsmod);
    if (missingModules.length() > 0)
    {
        QMessageBox messageBox;
        messageBox.setText("Do you want to load the following modules:\n" + missingModules.join("\n"));
        messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        messageBox.setDefaultButton(QMessageBox::No);
        int ret = messageBox.exec();

        if (ret == QMessageBox::Yes)
        {
            modulesLoad(missingModules);
        }
        else
        {
            qDebug() << "No modules loaded";
        }
    }
}

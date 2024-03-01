#include "servermanager.h"
#include "ui_servermanager.h"
#include <QSettings>
#include <QDebug>

struct server
{
    QString name;
    QString ip;
};

serverManager::serverManager(QWidget *parent)
    : QDialog(parent), ui(new Ui::serverManager)
{
    ui->setupUi(this);
    loadSettings();
}

serverManager::~serverManager()
{
    delete ui;
}

void serverManager::on_btnAdd_clicked()
{
    ui->twServer->insertRow(ui->twServer->rowCount());
    ui->twServer->setItem(ui->twServer->rowCount() - 1, 0, new QTableWidgetItem("name"));
    ui->twServer->setItem(ui->twServer->rowCount() - 1, 1, new QTableWidgetItem("IP"));
}

void serverManager::on_btnDel_clicked()
{

    ui->twServer->removeRow(ui->twServer->currentRow());
}

void serverManager::saveSettings()
{
    qDebug() << "saving settings";
    QSettings settings;
    int serverCount = ui->twServer->rowCount();
    settings.beginWriteArray("server");
    for (int i = 0; i < serverCount; i++)
    {
        QString name = ui->twServer->item(i, 0)->text();
        QString ip = ui->twServer->item(i, 1)->text();
        settings.setArrayIndex(i);
        settings.setValue("name", name);
        settings.setValue("ip", ip);
    }
    settings.endArray();
}

void serverManager::loadSettings()
{
    qDebug() << "loading settings";
    ui->twServer->setRowCount(0);
    QSettings settings;
    int size = settings.beginReadArray("server");
    for (int i = 0; i < size; ++i)
    {
        settings.setArrayIndex(i);
        ui->twServer->insertRow(ui->twServer->rowCount());
        ui->twServer->setItem(i, 0, new QTableWidgetItem(settings.value("name").toString()));
        ui->twServer->setItem(i, 1, new QTableWidgetItem(settings.value("ip").toString()));
    }
    settings.endArray();
}

void serverManager::on_btnOk_clicked()
{
    // w->setIp("10.10.1.177");
}

void serverManager::on_btnCancel_clicked()
{
}

void serverManager::on_btnSave_clicked()
{
    saveSettings();
}

QString serverManager::getIp()
{
    return ui->twServer->item(ui->twServer->currentRow(), 1)->text();
}

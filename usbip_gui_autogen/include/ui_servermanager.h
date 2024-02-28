/********************************************************************************
** Form generated from reading UI file 'servermanager.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERMANAGER_H
#define UI_SERVERMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_serverManager
{
public:
    QTableWidget *twServer;
    QPushButton *btnAdd;
    QPushButton *btnDel;
    QPushButton *btnCancel;
    QPushButton *btnOk;
    QPushButton *btnSave;

    void setupUi(QDialog *serverManager)
    {
        if (serverManager->objectName().isEmpty())
            serverManager->setObjectName(QString::fromUtf8("serverManager"));
        serverManager->resize(505, 548);
        twServer = new QTableWidget(serverManager);
        if (twServer->columnCount() < 2)
            twServer->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        twServer->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        twServer->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        twServer->setObjectName(QString::fromUtf8("twServer"));
        twServer->setGeometry(QRect(0, 20, 361, 441));
        btnAdd = new QPushButton(serverManager);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(380, 30, 87, 26));
        btnDel = new QPushButton(serverManager);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));
        btnDel->setGeometry(QRect(380, 70, 87, 26));
        btnCancel = new QPushButton(serverManager);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(80, 490, 87, 26));
        btnOk = new QPushButton(serverManager);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setGeometry(QRect(190, 490, 87, 26));
        btnSave = new QPushButton(serverManager);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(380, 110, 87, 26));

        retranslateUi(serverManager);

        QMetaObject::connectSlotsByName(serverManager);
    } // setupUi

    void retranslateUi(QDialog *serverManager)
    {
        serverManager->setWindowTitle(QCoreApplication::translate("serverManager", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = twServer->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("serverManager", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = twServer->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("serverManager", "IP", nullptr));
        btnAdd->setText(QCoreApplication::translate("serverManager", "Add", nullptr));
        btnDel->setText(QCoreApplication::translate("serverManager", "Remove", nullptr));
        btnCancel->setText(QCoreApplication::translate("serverManager", "cancel", nullptr));
        btnOk->setText(QCoreApplication::translate("serverManager", "Ok", nullptr));
        btnSave->setText(QCoreApplication::translate("serverManager", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serverManager: public Ui_serverManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERMANAGER_H

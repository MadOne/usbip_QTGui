/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionServer_Manager;
    QWidget *centralwidget;
    QPushButton *btnLocalRefresh;
    QPushButton *btnLocalBind;
    QPushButton *btnLocalUnbind;
    QLineEdit *leIp;
    QPushButton *btnRemoteRefresh;
    QPushButton *btnRemoteAttach;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnAttachedRefresh;
    QPushButton *btnAttatchedDetatch;
    QLabel *label_3;
    QTableWidget *tvLocal;
    QTableWidget *tvRemote;
    QTableWidget *tvAttached;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(804, 828);
        actionServer_Manager = new QAction(MainWindow);
        actionServer_Manager->setObjectName(QString::fromUtf8("actionServer_Manager"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("img/server-network-outline.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionServer_Manager->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnLocalRefresh = new QPushButton(centralwidget);
        btnLocalRefresh->setObjectName(QString::fromUtf8("btnLocalRefresh"));
        btnLocalRefresh->setGeometry(QRect(150, 250, 87, 27));
        btnLocalBind = new QPushButton(centralwidget);
        btnLocalBind->setObjectName(QString::fromUtf8("btnLocalBind"));
        btnLocalBind->setGeometry(QRect(260, 250, 87, 27));
        btnLocalUnbind = new QPushButton(centralwidget);
        btnLocalUnbind->setObjectName(QString::fromUtf8("btnLocalUnbind"));
        btnLocalUnbind->setGeometry(QRect(370, 250, 101, 27));
        leIp = new QLineEdit(centralwidget);
        leIp->setObjectName(QString::fromUtf8("leIp"));
        leIp->setGeometry(QRect(250, 0, 113, 27));
        btnRemoteRefresh = new QPushButton(centralwidget);
        btnRemoteRefresh->setObjectName(QString::fromUtf8("btnRemoteRefresh"));
        btnRemoteRefresh->setGeometry(QRect(390, 0, 87, 27));
        btnRemoteAttach = new QPushButton(centralwidget);
        btnRemoteAttach->setObjectName(QString::fromUtf8("btnRemoteAttach"));
        btnRemoteAttach->setGeometry(QRect(500, 0, 91, 27));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 191, 19));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 250, 151, 19));
        btnAttachedRefresh = new QPushButton(centralwidget);
        btnAttachedRefresh->setObjectName(QString::fromUtf8("btnAttachedRefresh"));
        btnAttachedRefresh->setGeometry(QRect(180, 500, 87, 27));
        btnAttatchedDetatch = new QPushButton(centralwidget);
        btnAttatchedDetatch->setObjectName(QString::fromUtf8("btnAttatchedDetatch"));
        btnAttatchedDetatch->setGeometry(QRect(310, 500, 111, 27));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 500, 141, 19));
        tvLocal = new QTableWidget(centralwidget);
        if (tvLocal->columnCount() < 3)
            tvLocal->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tvLocal->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tvLocal->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tvLocal->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tvLocal->setObjectName(QString::fromUtf8("tvLocal"));
        tvLocal->setGeometry(QRect(0, 290, 801, 192));
        tvLocal->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvLocal->verticalHeader()->setVisible(false);
        tvRemote = new QTableWidget(centralwidget);
        if (tvRemote->columnCount() < 3)
            tvRemote->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tvRemote->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tvRemote->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tvRemote->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        tvRemote->setObjectName(QString::fromUtf8("tvRemote"));
        tvRemote->setGeometry(QRect(0, 40, 801, 192));
        tvRemote->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvRemote->verticalHeader()->setVisible(false);
        tvAttached = new QTableWidget(centralwidget);
        if (tvAttached->columnCount() < 5)
            tvAttached->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tvAttached->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tvAttached->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tvAttached->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tvAttached->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tvAttached->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        tvAttached->setObjectName(QString::fromUtf8("tvAttached"));
        tvAttached->setGeometry(QRect(0, 540, 801, 192));
        tvAttached->setSelectionBehavior(QAbstractItemView::SelectRows);
        tvAttached->verticalHeader()->setVisible(false);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionServer_Manager);

        retranslateUi(MainWindow);
        QObject::connect(btnRemoteRefresh, SIGNAL(clicked()), MainWindow, SLOT(btnRemoteRefresh()));
        QObject::connect(btnRemoteAttach, SIGNAL(clicked()), MainWindow, SLOT(btnRemoteAttach()));
        QObject::connect(btnLocalRefresh, SIGNAL(clicked()), MainWindow, SLOT(btnLocalRefresh()));
        QObject::connect(btnLocalBind, SIGNAL(clicked()), MainWindow, SLOT(btnLocalBind()));
        QObject::connect(btnLocalUnbind, SIGNAL(clicked()), MainWindow, SLOT(btnLocalUnbind()));
        QObject::connect(btnAttachedRefresh, SIGNAL(clicked()), MainWindow, SLOT(btnAttachedRefresh()));
        QObject::connect(btnAttatchedDetatch, SIGNAL(clicked()), MainWindow, SLOT(btnAttachedDetach()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionServer_Manager->setText(QCoreApplication::translate("MainWindow", "Server Manager", nullptr));
        btnLocalRefresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        btnLocalBind->setText(QCoreApplication::translate("MainWindow", "Bind Device", nullptr));
        btnLocalUnbind->setText(QCoreApplication::translate("MainWindow", "Unbind Device", nullptr));
        leIp->setText(QCoreApplication::translate("MainWindow", "10.10.1.177", nullptr));
        btnRemoteRefresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        btnRemoteAttach->setText(QCoreApplication::translate("MainWindow", "Attach Device", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Remote USB Devices for IP:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Local USB Devices", nullptr));
        btnAttachedRefresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        btnAttatchedDetatch->setText(QCoreApplication::translate("MainWindow", "Detach Device", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Attatched Devices", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tvLocal->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Bus_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tvLocal->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Manufacturer", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tvLocal->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tvRemote->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Bus_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tvRemote->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Manufacturer", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tvRemote->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tvAttached->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Host", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tvAttached->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tvAttached->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Bus_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tvAttached->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Manufactoror", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tvAttached->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

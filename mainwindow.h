#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void btnRemoteRefresh();
    void btnRemoteAttach();
    void btnLocalRefresh();
    void btnLocalBind();
    void btnLocalUnbind();
    void btnAttachedRefresh();
    void btnAttachedDetach();

    void populateLocal(QStringList deviceList);
    void populateRemote(QStringList deviceList);
    void populateAttached(QStringList deviceList);
    void on_actionServer_Manager_triggered();
    void setIp(QString ip);
    void loadModules(QStringList missingModules);
    void checkModules();
    QStringList parseModules(QString lsmod);
};
#endif // MAINWINDOW_H

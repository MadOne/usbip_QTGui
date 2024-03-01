#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QDialog>

namespace Ui
{
    class serverManager;
}

class serverManager : public QDialog
{
    Q_OBJECT

public:
    explicit serverManager(QWidget *parent = nullptr);
    QString getIp();
    ~serverManager();

private slots:
    void on_btnAdd_clicked();
    void on_btnDel_clicked();
    void saveSettings();
    void loadSettings();
    void on_btnOk_clicked();
    void on_btnCancel_clicked();
    void on_btnSave_clicked();

private:
    Ui::serverManager *ui;
};

#endif // SERVERMANAGER_H

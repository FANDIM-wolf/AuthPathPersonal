#ifndef UPDATE_USER_DIALOG_H
#define UPDATE_USER_DIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QMessageBox>
#include <QString>
#include <QTableView>
#include <QSqlTableModel>

namespace Ui {
class Update_user_dialog;
}

class Update_user_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Update_user_dialog(QWidget *parent = nullptr);
    ~Update_user_dialog();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Update_user_dialog *ui;
    QSqlQuery *query ;
};

#endif // UPDATE_USER_DIALOG_H

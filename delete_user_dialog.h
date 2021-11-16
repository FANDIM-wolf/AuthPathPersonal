#ifndef DELETE_USER_DIALOG_H
#define DELETE_USER_DIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QMessageBox>
#include <QString>
#include <QTableView>
#include <QSqlTableModel>
namespace Ui {
class Delete_user_dialog;
}

class Delete_user_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Delete_user_dialog(QWidget *parent = nullptr);
    ~Delete_user_dialog();

private slots:
    void on_delete_user_Button_clicked();

private:
    Ui::Delete_user_dialog *ui;
    QSqlQuery *query ;
};

#endif // DELETE_USER_DIALOG_H

#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QMessageBox>
#include <QString>
#include <QTableView>
#include <QSqlTableModel>
namespace Ui {
class adduserdialog;
}

class adduserdialog : public QDialog
{
    Q_OBJECT

public:
    explicit adduserdialog(QWidget *parent = nullptr);
    ~adduserdialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::adduserdialog *ui;
    QSqlDatabase db;
    QSqlQuery *query ;
    QSqlTableModel *modal;
    int row;
};

#endif // ADDUSERDIALOG_H

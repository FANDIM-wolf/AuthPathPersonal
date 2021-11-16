#include "delete_user_dialog.h"
#include "ui_delete_user_dialog.h"
#include "mainwindow.h"

Delete_user_dialog::Delete_user_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete_user_dialog)
{
    ui->setupUi(this);
}

Delete_user_dialog::~Delete_user_dialog()
{
    delete ui;
}

void Delete_user_dialog::on_delete_user_Button_clicked()
{
    QString user_id = ui->lineEdit->text();


    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("home");

    if(db.open())
           {
            qDebug("open");
             query = new QSqlQuery(db);
           //write down sql request
           query->prepare("DELETE FROM employees WHERE name=? ");
            //bind Values
            query->bindValue(0,user_id);

            //exec sql request
            if(query->exec()){
                QMessageBox::information(this,"Information","User deleted succesfully");
            }
            //close data base
            db.close();
        }
        else{
            qDebug("no open");
        }


}


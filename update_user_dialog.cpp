#include "update_user_dialog.h"
#include "ui_update_user_dialog.h"
#include "mainwindow.h"


Update_user_dialog::Update_user_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Update_user_dialog)
{
    ui->setupUi(this);

}

Update_user_dialog::~Update_user_dialog()
{
    delete ui;
}

void Update_user_dialog::on_pushButton_clicked()
{
    QString user_name = ui->lineEdit_search->text();

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
           query->prepare("SELECT FROM employees WHERE name=? ");
            //bind Values
            query->bindValue(0,user_name);

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


void Update_user_dialog::on_pushButton_2_clicked()
{

    QString user_name = ui->lineEdit_search->text();
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
           query->prepare("SELECT * FROM employees WHERE name=? ");
            //bind Values
            query->bindValue(0,user_name);

            //exec sql request
            if(query->exec()){
            if(query->first()){
               QString name =query->value(1).toString();
               QString position = query->value(2).toString();
               ui->lineEdit_name->setText(name);
               ui->lineEdit_position->setText(position);
            }
                QMessageBox::information(this,"Information","User is found successfully");
            }



            //close data base
            db.close();
        }
        else{
            qDebug("no open");
        }

}


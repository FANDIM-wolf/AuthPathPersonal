#include "adduserdialog.h"
#include "ui_adduserdialog.h"
#include "mainwindow.h"
adduserdialog::adduserdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adduserdialog)
{
    ui->setupUi(this);
}

adduserdialog::~adduserdialog()
{
    delete ui;
}

void adduserdialog::on_pushButton_clicked()
{
   QString name = ui->lineEdit->text();
   QString position = ui->lineEdit_2->text();

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
          query->prepare("INSERT INTO employees (name,position) "
                    "VALUES (:name,:position)");
           //bind Values
           query->bindValue(":name",name);
           query->bindValue(":position",position);
           //exec sql request
           query->exec();
           //close data base
      db.close();
       }
       else{
           qDebug("no open");
       }



}


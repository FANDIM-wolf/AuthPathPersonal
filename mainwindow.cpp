#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adduserdialog.h"
#include "delete_user_dialog.h"
#include "update_user_dialog.h"
#include "information_about_app.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("home");
    if(db.open())
           {
            qDebug("open");
            adduserdialog adduser_window;
            adduser_window.setModal(false);
            adduser_window.exec();
        }
        else{
            qDebug("no open");
        }



    db.close();



}


void MainWindow::on_pushButton_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("home");
    if(db.open())
           {
            qDebug("open");
    }
        else{
            qDebug("no open");
        }
    // get model
    modal = new QSqlTableModel(this,db);
    QSqlQuery* query = new QSqlQuery(db);
    QSqlQueryModel * modal = new QSqlQueryModel();
    query->prepare("select * from employees");
    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);

    db.close();
}


void MainWindow::on_pushButton_3_clicked()
{
    qDebug("open");
    Delete_user_dialog adduser_window;
    adduser_window.setModal(false);
    adduser_window.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
     Update_user_dialog user_update_window;
     user_update_window.setModal(false);
     user_update_window.exec();
}




// Get index of user
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
    QString id = QString::number(row);
    ui->label_1->setText(id);

}


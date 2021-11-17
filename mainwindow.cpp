#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_maindialog.h"
#include "adduserdialog.h"


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

   main_dialog = new MainDialog(this);
   main_dialog->show();
   //MainDialog head_dialog;
   //head_dialog.setModal(true);
   //head_dialog.exec();

   QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
   db.setHostName("127.0.0.1");
   db.setUserName("root");
   db.setPassword("");
   db.setDatabaseName("home");

}


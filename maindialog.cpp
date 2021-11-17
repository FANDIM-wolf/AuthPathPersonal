#include "maindialog.h"
#include "ui_maindialog.h"
#include "adduserdialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_pushButton_clicked()
{
    //MainDialog head_dialog;
    //head_dialog.setModal(true);
    //head_dialog.exec();

    // call a new window
    AddUserDialog add_user_dialog;
    add_user_dialog.setModal(false);
    add_user_dialog.exec();

}





#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/HP/Downloads/login_image.png");
    ui->ImageLabel->setPixmap(pix.scaled(111,111,Qt::KeepAspectRatio));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_LoginButton_clicked()
{
    MainWindow X;
    QString username= ui->UsernameLineEdit->text();
    QString password= ui->PasswordLineEdit->text();

    if((username=="123")&&(password=="123")){
        QMessageBox::information(this,"Login","Username & Password are correct.");
        hide();
        mainwindow= new MainWindow;
        mainwindow->show();
    }
    else
        QMessageBox::warning(this,"Login","Username & Password are incorrect.");
}

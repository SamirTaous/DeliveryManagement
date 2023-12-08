#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QtSql>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/HP/Downloads/windowicon.png");
    setWindowIcon(icon);
    //QPixmap pix4("C:/Users/HP/Downloads/expressdelivery.png");
    //ui->ExpressDeliveryImage->setPixmap(pix4.scaled(400,175,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    //QPixmap pix("C:/Users/HP/Downloads/login_image.jpg");
    //ui->ImageLabel->setPixmap(pix.scaled(481,281,Qt::KeepAspectRatio));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_LoginButton_clicked()
{
    QString username= ui->UsernameLineEdit->text();
    QString password= ui->PasswordLineEdit->text();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM login WHERE user=:username AND pass=:password");
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);
    if (qry.exec() && qry.next() && username==QString::fromStdString("root")){
        QMessageBox::information(this,"Login","Username & Password are correct.");
        hide();
        mainwindow= new MainWindow(username);
        mainwindow->show();
    }
    else if (qry.exec() && qry.next() && username!=QString::fromStdString("root")){
        QMessageBox::information(this,"Login","Username & Password are correct.");
        hide();
        overview= new Overview();
        overview->show();
    }
    else
        QMessageBox::warning(this,"Login","Username & Password are incorrect.");
}



#include "addlogin.h"
#include "ui_addlogin.h"
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

addlogin::addlogin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addlogin)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/HP/Downloads/windowicon.png");
    setWindowIcon(icon);
}

addlogin::~addlogin()
{
    delete ui;
}

void addlogin::on_AddLoginButton_clicked()
{
    std::string name=ui->NameLineEdit->text().toStdString();
    std::string email=ui->EmailLineEdit->text().toStdString();
    std::string user=ui->UserLineEdit->text().toStdString();
    std::string password=ui->PasswordLineEdit->text().toStdString();
    QSqlQuery qry;
    qry.prepare("INSERT INTO login VALUES('"
                + QString::fromStdString(name) + "','"
                + QString::fromStdString(email) + "','"
                + QString::fromStdString(user) + "','"
                + QString::fromStdString(password) + "')");

    if (qry.exec()){
        QMessageBox::critical(this, tr("Save"), tr("Saved"));
        this->close();
    }
    else
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
}


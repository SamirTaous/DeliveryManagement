#include "deleteemployee.h"
#include "ui_deleteemployee.h"
#include <QtSql>
#include <QMessageBox>
#include "employe.h"

DeleteEmployee::DeleteEmployee(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeleteEmployee)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/HP/Downloads/windowicon.png");
    setWindowIcon(icon);
}

DeleteEmployee::~DeleteEmployee()
{
    delete ui;
}


void DeleteEmployee::on_DeleteButton_clicked()
{
    int idemp=ui->IDLineEdit->text().toInt();
    QSqlQuery qry;
    qry.prepare("DELETE FROM employe WHERE id='"+ QString::number(idemp) +"'");

    if (qry.exec())
        QMessageBox::critical(this, tr("Delete"), tr("Deleted"));
    else
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
}


#include "addemployee.h"
#include "ui_addemployee.h"
#include <QtSql>
#include <QMessageBox>
#include "employe.h"

AddEmployee::AddEmployee(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddEmployee)
{
    ui->setupUi(this);

}

AddEmployee::~AddEmployee()
{
    delete ui;
}

int idemp=0;
void AddEmployee::on_AddButton_clicked()
{
    Employe x(ui->NameLineEdit->text(), ui->ContactLineEdit->text(), ui->RoleLineEdit->text(), ui->HoursLineEdit->text().toInt(), ui->PerformanceLineEdit->text().toInt());
    idemp+=1;
    QSqlQuery qry;
    qry.prepare("INSERT INTO employe(id,name,contact,role,hours,performance) VALUES('"
                + QString::number(idemp) + "','"  // Convert to QString
                + QString::fromStdString(x.getNom()) + "','"  // Convert to QString
                + QString::fromStdString(x.getContact()) + "','"  // Convert to QString
                + QString::fromStdString(x.getRole()) + "','"
                + QString::number(x.getHeures()) + "','"
                + QString::number(x.getPerformance()) + "')");

    if (qry.exec())
        QMessageBox::critical(this, tr("Save"), tr("Saved"));
    else
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
}


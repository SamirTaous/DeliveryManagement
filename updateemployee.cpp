#include "updateemployee.h"
#include "ui_updateemployee.h"
#include <QtSql>
#include <QMessageBox>
#include "employe.h"

UpdateEmployee::UpdateEmployee(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UpdateEmployee)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/HP/Downloads/windowicon.png");
    setWindowIcon(icon);
}

UpdateEmployee::~UpdateEmployee()
{
    delete ui;
}

void UpdateEmployee::on_UpdateButton_clicked()
{
    Employe x(ui->NameLineEdit->text(), ui->ContactLineEdit->text(), ui->RoleLineEdit->text(), ui->HoursLineEdit->text().toInt(), ui->PerformanceLineEdit->text().toInt());
    int idemp=ui->IDLineEdit->text().toInt();
    QSqlQuery qry;
    qry.prepare("UPDATE employe SET name='"  // Convert to QString
                + QString::fromStdString(x.getNom()) + "',contact='"  // Convert to QString
                + QString::fromStdString(x.getContact()) + "',role='"  // Convert to QString
                + QString::fromStdString(x.getRole()) + "',hours='"
                + QString::number(x.getHeures()) + "',performance='"
                + QString::number(x.getPerformance()) + "' WHERE id='"+ QString::number(idemp) +"'");

    if (qry.exec())
        QMessageBox::critical(this, tr("Update"), tr("Updated"));
    else
        QMessageBox::critical(this, tr("error::"), qry.lastError().text());
}


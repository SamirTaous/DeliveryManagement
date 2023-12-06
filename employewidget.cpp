#include "employewidget.h"
#include "ui_employewidget.h"
#include "addemployee.h"
#include "updateemployee.h"
#include "deleteemployee.h"
#include <QtSql>
#include <QMessageBox>

employewidget::employewidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employewidget)
{
    ui->setupUi(this);
    }

employewidget::~employewidget()
{
    delete ui;
}

void employewidget::on_AddEmployeeButton_clicked()
{
    addemployee= new AddEmployee;
    //this->hide();
    addemployee->show();
}

void employewidget::on_UpdateEmployeButton_clicked()
{
    updateemployee= new UpdateEmployee;
    //this->hide();
    updateemployee->show();
}


void employewidget::on_DeleteEmployeeButton_clicked()
{
    deleteemployee= new DeleteEmployee;
    this->hide();
    deleteemployee->show();
}


void employewidget::on_LoadTableButton_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();

    QSqlQuery qry;
    qry.prepare("SELECT id AS Employee_ID,name AS Employee_Name,contact AS Contact,role AS Role,hours AS Hours,performance AS Performance FROM employe ORDER BY id ASC");
    qry.exec();
    if (qry.exec("SELECT id AS Employee_ID,name AS Employee_Name,contact AS Contact,role AS Role,hours AS Hours,performance AS Performance FROM employe ORDER BY id ASC")) {
        qDebug() << "Query executed successfully";
    } else {
        qDebug() << "Query failed:" << qry.lastError().text();
    }

    modal->setQuery(qry);
    ui->EmployeeTable->setModel(modal);
}


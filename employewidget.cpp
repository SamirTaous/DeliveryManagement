#include "employewidget.h"
#include "ui_employewidget.h"
#include "addemployee.h"
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
    this->hide();
    addemployee->show();
}

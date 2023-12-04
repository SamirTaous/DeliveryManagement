#include "addemployee.h"
#include "ui_addemployee.h"
#include "employewidget.h"
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

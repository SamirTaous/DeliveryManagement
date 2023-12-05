#include "adddelivery.h"
#include "ui_adddelivery.h"

AddDelivery::AddDelivery(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddDelivery)
{
    ui->setupUi(this);
}

AddDelivery::~AddDelivery()
{
    delete ui;
}

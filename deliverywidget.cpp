#include "deliverywidget.h"
#include "ui_deliverywidget.h"
#include <QtSql>
#include <QMessageBox>
#include "adddelivery.h"

deliverywidget::deliverywidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deliverywidget)
{
    ui->setupUi(this);
}

deliverywidget::~deliverywidget()
{
    delete ui;
}



void deliverywidget::on_LoadDeliveryTable_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();

    QSqlQuery qry;
    qry.prepare("SELECT * FROM delivery");
    qry.exec();
    if (qry.exec("SELECT * FROM delivery")) {
        qDebug() << "Query executed successfully";
    } else {
        qDebug() << "Query failed:" << qry.lastError().text();
    }

    modal->setQuery(qry);
    ui->DeliveryTable->setModel(modal);
}


void deliverywidget::on_AddDeliveryButton_clicked()
{
    adddelivery= new AddDelivery;
    this->hide();
    adddelivery->show();
}


void deliverywidget::on_DeleteDeliveryButton_clicked()
{
    int idemp=ui->OrderIDLineEdit->text().toInt();
    QSqlQuery qry;
    qry.prepare("DELETE FROM delivery WHERE orderid='"+ QString::number(idemp) +"'");

    if (qry.exec())
        QMessageBox::critical(this, tr("Delete"), tr("Deleted"));
    else
        QMessageBox::critical(this, tr("error::"), tr("Order ID not found!"));
}

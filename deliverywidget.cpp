#include "deliverywidget.h"
#include "ui_deliverywidget.h"
#include <QtSql>
#include <QMessageBox>

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


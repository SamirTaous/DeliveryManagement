#include "overview.h"
#include "ui_overview.h"
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

Overview::Overview(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Overview)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/HP/Downloads/windowicon.png");
    setWindowIcon(icon);
    QSqlQuery qry,qry2,qry3;
    qry.prepare("SELECT COUNT(id) FROM employe");
    if (qry.exec() && qry.next()) {
        int employeCount = qry.value(0).toInt();
        ui->EmployeNumber->setText(QString::number(employeCount));
    } else {
        qDebug() << "Error fetching employe count:" << qry.lastError().text();
    }
    qry2.prepare("SELECT COUNT(orderid) FROM delivery");
    if (qry2.exec() && qry2.next()) {
        int deliverycount = qry2.value(0).toInt();
        ui->DeliveryNumber->setText(QString::number(deliverycount));
    } else {
        qDebug() << "Error fetching delivery count:" << qry.lastError().text();
    }
    qry3.prepare("SELECT COUNT(prodid) FROM product");
    if (qry3.exec() && qry3.next()) {
        int productcount = qry3.value(0).toInt();
        ui->ProductNumber->setText(QString::number(productcount));
    } else {
        qDebug() << "Error fetching product count:" << qry.lastError().text();
    }
    QSqlQueryModel *modal4=new QSqlQueryModel();
    QSqlQueryModel *modal5=new QSqlQueryModel();
    QSqlQueryModel *modal6=new QSqlQueryModel();

    QSqlQuery qry4;
    qry4.prepare("SELECT id AS Employee_ID,name AS Employee_Name,contact AS Contact,role AS Role,hours AS Hours,performance AS Performance FROM employe ORDER BY id ASC");
    qry4.exec();
    modal4->setQuery(qry4);
    ui->EmployeeTable->setModel(modal4);
    QSqlQuery qry5;
    qry5.prepare("SELECT orderid AS Order_ID, prodid AS Product_ID, itemcount AS Amount, customerinfo AS Customer_Information, address AS Delivery_Address, status AS Delivery_Status FROM delivery ORDER BY orderid ASC");
    qry5.exec();
    modal5->setQuery(qry5);
    ui->DeliveryTable->setModel(modal5);
    QSqlQuery qry6;
    qry6.prepare("SELECT product.prodid AS ID_Produit, COALESCE(product.prodcount - SUM(itemcount), product.prodcount) AS Stock FROM product LEFT JOIN delivery ON product.prodid = delivery.prodid GROUP BY product.prodid ORDER BY product.prodid ASC;");
    qry6.exec();
    modal6->setQuery(qry6);
    ui->ProductTable->setModel(modal6);
}

Overview::~Overview()
{
    delete ui;
}

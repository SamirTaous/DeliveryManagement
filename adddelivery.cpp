#include "adddelivery.h"
#include "ui_adddelivery.h"
#include <QtSql>
#include <QMessageBox>
#include "deliveryorder.h"

AddDelivery::AddDelivery(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddDelivery)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/HP/Downloads/windowicon.png");
    setWindowIcon(icon);
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("SELECT orderid AS Order_ID, prodid AS Product_ID, itemcount AS Amount, customerinfo AS Customer_Information, address AS Delivery_Address, status AS Delivery_Status FROM delivery ORDER BY orderid ASC");
    qry.exec();
    if (qry.exec("SELECT orderid AS Order_ID, prodid AS Product_ID, itemcount AS Amount, customerinfo AS Customer_Information, address AS Delivery_Address, status AS Delivery_Status FROM delivery ORDER BY orderid ASC")) {
        qDebug() << "Query executed successfully";
    } else {
        qDebug() << "Query failed:" << qry.lastError().text();
    }
    modal->setQuery(qry);
    ui->tableView->setModel(modal);
}

AddDelivery::~AddDelivery()
{
    delete ui;
}

void AddDelivery::on_LoadTableButton_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();

    QSqlQuery qry;
    qry.prepare("SELECT orderid AS Order_ID, prodid AS Product_ID, itemcount AS Amount, customerinfo AS Customer_Information, address AS Delivery_Address, status AS Delivery_Status FROM delivery ORDER BY orderid ASC");
    qry.exec();
    if (qry.exec("SELECT orderid AS Order_ID, prodid AS Product_ID, itemcount AS Amount, customerinfo AS Customer_Information, address AS Delivery_Address, status AS Delivery_Status FROM delivery ORDER BY orderid ASC")) {
        qDebug() << "Query executed successfully";
    } else {
        qDebug() << "Query failed:" << qry.lastError().text();
    }
    modal->setQuery(qry);
    ui->tableView->setModel(modal);
}

void AddDelivery::on_AddDeliveryButton_clicked()
{
    DeliveryOrder deliveryorder(ui->OrderIDLineEdit->text().toInt(),ui->CustomerLineEdit->text().toStdString(),ui->AddressLineEdit->text().toStdString(),ui->AmountLineEdit->text().toInt(),"Delivering");
    int item=ui->ProductLineEdit->text().toInt();
    if (isInventorySufficient(item, deliveryorder.getOrderItems())) {
    QSqlQuery qry;
    qry.prepare("INSERT INTO delivery(orderid,prodid,itemcount,customerinfo,address) VALUES('"
                + QString::number(deliveryorder.getOrderID()) +"','"
                + QString::number(item) + "','"
                + QString::number(deliveryorder.getOrderItems())+"','"
                + QString::fromStdString(deliveryorder.getCustomerInfo()) +"','"
                + QString::fromStdString(deliveryorder.getDeliveryAddress()) + "')");
    if (qry.exec()){
        QMessageBox::critical(this, tr("Save"), tr("Saved"));
        this->close();
    }
    else
        QMessageBox::critical(this, tr("error::"), tr("OrderID exists!"));}
    else {
        QMessageBox::critical(this, tr("Error"), tr("Insufficient inventory for the specified amount"));
    }
}

bool AddDelivery::isInventorySufficient(int productID, int requestedAmount) const
{
    QSqlQuery inventoryQuery;
    inventoryQuery.prepare("SELECT product.prodcount-SUM(itemcount) FROM delivery,product WHERE delivery.prodid=product.prodid AND delivery.prodid=:productID group by delivery.prodid;");
    inventoryQuery.bindValue(":productID", productID);

    if (inventoryQuery.exec() && inventoryQuery.next()) {
        int availableStock = inventoryQuery.value(0).toInt();
        return availableStock >= requestedAmount;
    } else {
        qDebug() << "Error checking inventory:" << inventoryQuery.lastError().text();
        return false;
    }
}


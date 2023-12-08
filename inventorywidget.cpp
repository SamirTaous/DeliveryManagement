#include "inventorywidget.h"
#include "ui_inventorywidget.h"
#include <QtSql>
#include <QMessageBox>

InventoryWidget::InventoryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InventoryWidget)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/HP/Downloads/windowicon.png");
    setWindowIcon(icon);
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("SELECT product.prodid AS ID_Produit, COALESCE(product.prodcount - SUM(itemcount), product.prodcount) AS Stock FROM product LEFT JOIN delivery ON product.prodid = delivery.prodid GROUP BY product.prodid ORDER BY product.prodid ASC;");
    qry.exec();
    if (qry.exec("SELECT product.prodid AS ID_Produit, COALESCE(product.prodcount - SUM(itemcount), product.prodcount) AS Stock FROM product LEFT JOIN delivery ON product.prodid = delivery.prodid GROUP BY product.prodid ORDER BY product.prodid ASC;")) {
        qDebug() << "Query executed successfully";
    } else {
        qDebug() << "Query failed:" << qry.lastError().text();
    }

    modal->setQuery(qry);
    ui->InventoryTable->setModel(modal);
}

InventoryWidget::~InventoryWidget()
{
    delete ui;
}

void InventoryWidget::on_LoadButton_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();

    QSqlQuery qry;
    qry.prepare("SELECT product.prodid AS ID_Produit, COALESCE(product.prodcount - SUM(itemcount), product.prodcount) AS Stock FROM product LEFT JOIN delivery ON product.prodid = delivery.prodid GROUP BY product.prodid ORDER BY product.prodid ASC;");
    qry.exec();
    if (qry.exec("SELECT product.prodid AS ID_Produit, COALESCE(product.prodcount - SUM(itemcount), product.prodcount) AS Stock FROM product LEFT JOIN delivery ON product.prodid = delivery.prodid GROUP BY product.prodid ORDER BY product.prodid ASC;")) {
        qDebug() << "Query executed successfully";
    } else {
        qDebug() << "Query failed:" << qry.lastError().text();
    }

    modal->setQuery(qry);
    ui->InventoryTable->setModel(modal);
}


void InventoryWidget::on_AddProductButton_clicked()
{
    int productID=ui->ProductIDLineEdit->text().toInt();
    int amount=ui->AmountLineEdit->text().toInt();
    QSqlQuery qry;
    qry.prepare("INSERT INTO product VALUES('"
                + QString::number(productID) + "','"
                + QString::number(amount) + "')");

    if (qry.exec()){
        QMessageBox::critical(this, tr("Save"), tr("Saved"));
        this->close();
    }
    else
        QMessageBox::critical(this, tr("error::"), tr("Product ID exists!"));
}


void InventoryWidget::on_DeleteProductButton_clicked()
{
    int productID=ui->ProductIDLineEdit_2->text().toInt();
    QSqlQuery qry;
    qry.prepare("DELETE FROM product WHERE prodid='"+ QString::number(productID) +"'");

    if (qry.exec())
        QMessageBox::critical(this, tr("Delete"), tr("Deleted"));
    else
        QMessageBox::critical(this, tr("error::"), tr("Product ID not found!"));
}


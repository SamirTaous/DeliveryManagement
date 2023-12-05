#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>
#include <QDebug>
#include <QtSql>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug()<<"start";
    QSqlDatabase db;
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/HP/Desktop/sqlll/db.sqlite");

    if(!db.open())
        qDebug()<<"problem while opening the database";
    QString query1="CREATE TABLE employe("
                    "id int ,"
                    "name varchar(20),"
                    "contact varchar(30),"
                    "role varchar(30),"
                    "hours int,"
                    "performance int,"
                    "PRIMARY KEY(id));"
                    ;
    QString query2="CREATE TABLE delivery("
                    "orderid int,"
                    "prodid int,"
                    "itemcount int,"
                    "customerinfo varchar(50),"
                    "address varchar(50),"
                    "status varchar(30),"
                    "PRIMARY KEY(orderid),"
                    "FOREIGN KEY(prodid) REFERENCES product(prodid)); "
                    ;
    QString query3="CREATE TABLE product("
                    "prodid int,"
                    "prodcount int,"
                    "PRIMARY KEY(prodid));"
                    ;
    QSqlQuery qry;
    if(!qry.exec(query1))
        qDebug()<<"error creating employee table";
    if(!qry.exec(query2))
        qDebug()<<"error creating delivery table";
    if(!qry.exec(query3))
        qDebug()<<"error creating product table";
    LoginWindow w;
    w.show();
    qDebug()<<"end";
    return a.exec();
}

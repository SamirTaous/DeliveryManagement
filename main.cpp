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
    QString query="CREATE TABLE employe("
                    "id int ,"
                    "name varchar(20),"
                    "contact varchar(30),"
                    "role varchar(30),"
                    "hours int,"
                    "performance int,"
                    "PRIMARY KEY(id));"
                    ;
    QSqlQuery qry;
    if(!qry.exec(query))
        qDebug()<<"error creating table";
    LoginWindow w;
    w.show();
    qDebug()<<"end";
    return a.exec();
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "employewidget.h"
#include "deliverywidget.h"
#include "inventorywidget.h"
#include <QTimer>
#include <QDateTime>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/HP/Downloads/mainwindowimg.png");
    //ui->MainBackground->setPixmap(pix.scaled(1081,681,Qt::KeepAspectRatio));
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}

void MainWindow::showTime(){
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->ClockLabel->setText(time_text);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_EmployeButton_clicked()
{
    EmployeWidget= new employewidget;
    EmployeWidget->show();
}


void MainWindow::on_DeliveryButton_clicked()
{
    DeliveryWidget= new deliverywidget;
    DeliveryWidget->show();
}


void MainWindow::on_InventoryButton_clicked()
{
    inventorywidget= new InventoryWidget;
    inventorywidget->show();
}


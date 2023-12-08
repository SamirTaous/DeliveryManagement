#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "employewidget.h"
#include "deliverywidget.h"
#include "inventorywidget.h"
#include "addlogin.h"
#include "overview.h"
#include <QTimer>
#include <QDateTime>
#include <QPixmap>
#include <QMessageBox>

MainWindow::MainWindow(const QString& username,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/HP/Downloads/windowicon.png");
    setWindowIcon(icon);
    QPixmap pix6("C:/Users/HP/Downloads/overviewimage.png");
    ui->OverviewImage->setPixmap(pix6.scaled(51,51,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    QPixmap pix5("C:/Users/HP/Downloads/backgroundimage.jpg");
    ui->BackgroundImage->setPixmap(pix5.scaled(1500,1000,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    QPixmap pix4("C:/Users/HP/Downloads/expressdelivery.png");
    ui->ExpressDeliveryImage->setPixmap(pix4.scaled(666,375,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    QPixmap pix("C:/Users/HP/Downloads/employee.png");
    ui->EmployeeImage->setPixmap(pix.scaled(51,51,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    QPixmap pix2("C:/Users/HP/Downloads/delivery.png");
    ui->DeliveryImage->setPixmap(pix2.scaled(91,81,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    QPixmap pix3("C:/Users/HP/Downloads/inventory.png");
    ui->InventoryImage->setPixmap(pix3.scaled(71,71,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
    ui->Welcometext->setText(username);
    ui->Welcometext->setStyleSheet("background-color: transparent;border:none;font-size: 100pt;color: #AE1B1B;");
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


void MainWindow::on_AddLoginButton_clicked()
{
    if(ui->PasswordLineEdit->text().toInt()!=246807531){
        QMessageBox::critical(this, tr("error"), tr("Incorrect Root Password"));
    }
    else{
        AddLogin= new addlogin;
        AddLogin->show();
    }
}


void MainWindow::on_OverviewButton_clicked()
{
    overview= new Overview;
    overview->show();
}


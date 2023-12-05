#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "employewidget.h"
#include "deliverywidget.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_EmployeButton_clicked()
{
    employewidget X;
    this->hide();
    X.setModal(true);
    X.exec();
}


void MainWindow::on_DeliveryButton_clicked()
{
    DeliveryWidget= new deliverywidget;
    this->hide();
    DeliveryWidget->show();
}


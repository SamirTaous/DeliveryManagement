#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSql>
#include <QMainWindow>
#include "employewidget.h"
#include "deliverywidget.h"
#include "inventorywidget.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_EmployeButton_clicked();
    void showTime();
    void on_DeliveryButton_clicked();

    void on_InventoryButton_clicked();

private:
    Ui::MainWindow *ui;
    deliverywidget* DeliveryWidget;
    employewidget* EmployeWidget;
    InventoryWidget* inventorywidget;

};
#endif // MAINWINDOW_H

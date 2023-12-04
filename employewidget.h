#ifndef EMPLOYEWIDGET_H
#define EMPLOYEWIDGET_H

#include <QDialog>
#include "addemployee.h"
#include "employe.h"
namespace Ui {
class employewidget;
}

class employewidget : public QDialog
{
    Q_OBJECT

public:
    explicit employewidget(QWidget *parent = nullptr);
    ~employewidget();

private slots:
    void on_AddEmployeeButton_clicked();

private:
    Ui::employewidget *ui;
    AddEmployee* addemployee;
};

#endif // EMPLOYEWIDGET_H

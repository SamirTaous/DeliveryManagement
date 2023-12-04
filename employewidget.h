#ifndef EMPLOYEWIDGET_H
#define EMPLOYEWIDGET_H

#include <QDialog>
#include "addemployee.h"
#include "employe.h"
#include "updateemployee.h"
#include "deleteemployee.h"

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

    void on_UpdateEmployeButton_clicked();

    void on_DeleteEmployeeButton_clicked();

    void on_LoadTableButton_clicked();

private:
    Ui::employewidget *ui;
    AddEmployee* addemployee;
    UpdateEmployee* updateemployee;
    DeleteEmployee* deleteemployee;
};

#endif // EMPLOYEWIDGET_H

#ifndef ADDEMPLOYEE_H
#define ADDEMPLOYEE_H

#include <QWidget>

namespace Ui {
class AddEmployee;
}

class AddEmployee : public QWidget
{
    Q_OBJECT

public:
    explicit AddEmployee(QWidget *parent = nullptr);
    ~AddEmployee();
    int id_number();

private slots:
    void on_AddButton_clicked();

private:
    Ui::AddEmployee *ui;
};

#endif // ADDEMPLOYEE_H

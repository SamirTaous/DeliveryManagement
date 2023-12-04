#ifndef DELETEEMPLOYEE_H
#define DELETEEMPLOYEE_H

#include <QWidget>

namespace Ui {
class DeleteEmployee;
}

class DeleteEmployee : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteEmployee(QWidget *parent = nullptr);
    ~DeleteEmployee();

private slots:
    void on_DeleteButton_clicked();

private:
    Ui::DeleteEmployee *ui;
};

#endif // DELETEEMPLOYEE_H

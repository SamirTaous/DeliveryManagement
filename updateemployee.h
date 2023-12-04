#ifndef UPDATEEMPLOYEE_H
#define UPDATEEMPLOYEE_H

#include <QWidget>

namespace Ui {
class UpdateEmployee;
}

class UpdateEmployee : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateEmployee(QWidget *parent = nullptr);
    ~UpdateEmployee();

private slots:
    void on_UpdateButton_clicked();

private:
    Ui::UpdateEmployee *ui;
};

#endif // UPDATEEMPLOYEE_H

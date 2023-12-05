#ifndef DELIVERYWIDGET_H
#define DELIVERYWIDGET_H

#include <QWidget>

namespace Ui {
class deliverywidget;
}

class deliverywidget : public QWidget
{
    Q_OBJECT

public:
    explicit deliverywidget(QWidget *parent = nullptr);
    ~deliverywidget();

private slots:

    void on_LoadDeliveryTable_clicked();

private:
    Ui::deliverywidget *ui;
};

#endif // DELIVERYWIDGET_H

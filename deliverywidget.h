#ifndef DELIVERYWIDGET_H
#define DELIVERYWIDGET_H

#include <QWidget>
#include "adddelivery.h"

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

    void on_AddDeliveryButton_clicked();

    void on_DeleteDeliveryButton_clicked();

private:
    Ui::deliverywidget *ui;
    AddDelivery* adddelivery;
};

#endif // DELIVERYWIDGET_H

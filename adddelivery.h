#ifndef ADDDELIVERY_H
#define ADDDELIVERY_H

#include <QWidget>

namespace Ui {
class AddDelivery;
}

class AddDelivery : public QWidget
{
    Q_OBJECT

public:
    explicit AddDelivery(QWidget *parent = nullptr);
    ~AddDelivery();
    bool isInventorySufficient(int productID, int requestedAmount) const;

private slots:
    void on_LoadTableButton_clicked();


    void on_AddDeliveryButton_clicked();

private:
    Ui::AddDelivery *ui;
};

#endif // ADDDELIVERY_H

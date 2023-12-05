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

private:
    Ui::AddDelivery *ui;
};

#endif // ADDDELIVERY_H

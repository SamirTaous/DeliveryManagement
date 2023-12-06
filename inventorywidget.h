#ifndef INVENTORYWIDGET_H
#define INVENTORYWIDGET_H

#include <QWidget>

namespace Ui {
class InventoryWidget;
}

class InventoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryWidget(QWidget *parent = nullptr);
    ~InventoryWidget();

private slots:
    void on_LoadButton_clicked();

    void on_AddProductButton_clicked();

    void on_DeleteProductButton_clicked();

private:
    Ui::InventoryWidget *ui;
};

#endif // INVENTORYWIDGET_H

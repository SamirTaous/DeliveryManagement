#ifndef ADDLOGIN_H
#define ADDLOGIN_H

#include <QWidget>

namespace Ui {
class addlogin;
}

class addlogin : public QWidget
{
    Q_OBJECT

public:
    explicit addlogin(QWidget *parent = nullptr);
    ~addlogin();

private slots:
    void on_AddLoginButton_clicked();

private:
    Ui::addlogin *ui;
};

#endif // ADDLOGIN_H

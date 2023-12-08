#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "mainwindow.h"
#include "overview.h"
namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();


private slots:
    void on_LoginButton_clicked();

private:
    Ui::LoginWindow *ui;
    MainWindow *mainwindow;
    Overview* overview;
};

#endif // LOGINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_FibonacciOrders.h"
#include "MainController.h"

class FibonacciOrders : public QMainWindow
{
    Q_OBJECT

public:
    FibonacciOrders(QWidget *parent = nullptr);
    ~FibonacciOrders();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FibonacciOrdersClass ui;
    MainController* main_controller;
};

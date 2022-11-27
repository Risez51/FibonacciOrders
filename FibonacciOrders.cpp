#include "FibonacciOrders.h"
#include "OrderController.h"
#include "MainController.h"

FibonacciOrders::FibonacciOrders(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.lineEditNumber->setValidator(new QIntValidator(0, 999, this));
    main_controller = new MainController();
}

FibonacciOrders::~FibonacciOrders()
{
}

void FibonacciOrders::on_pushButton_clicked() 
{
    main_controller->new_order(ui.treeWidget, ui.lineEditName, ui.lineEditNumber);
}

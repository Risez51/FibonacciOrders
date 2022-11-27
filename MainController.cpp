#pragma execution_character_set("utf-8")
#include "MainController.h"

MainController::MainController() {
    validator = new Validator();

}

void MainController::new_order(QTreeWidget* qtw, QLineEdit* name_line, QLineEdit* number_line) {
    if (validator->is_valid_LineEdit(name_line->text(), "���� ��� ������") &&
        (validator->is_valid_LineEdit(number_line->text(), "���� ����� ������")))
    {
        OrderController* orderController = new OrderController(qtw, name_line, number_line);
        orderController->new_order();
        orderController->show();
        orderController->set_order_result();
    }

}
#pragma once
#include <qobject.h>
#include <qtreewidget.h>
#include <qlineedit.h>
#include "OrderController.h"
#include "Validator.h"

class MainController :
    public QObject
{
    Q_OBJECT
public: 
    explicit MainController();
    void new_order(QTreeWidget*, QLineEdit*, QLineEdit*);
    void remove_selected_order();

private:
    OrderController* order_controller;
    Validator* validator;
};
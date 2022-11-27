#pragma once
#include <qobject.h>
#include <qtreewidget.h>
#include <qlineedit.h>

#include "Order.h"
#include "API.h"

class OrderController :
    public QObject
{
    Q_OBJECT
public:
    explicit OrderController(QTreeWidget *tw,  QLineEdit *name, QLineEdit *number);
    void new_order();
    void show();
    void set_order_result();

public slots:
    void onResultReady(int);
    void OnRequestSended();

private:
    Order* order;
    API* api;
    QTreeWidget* tree_widget;
    QTreeWidgetItem* tree_widget_item;
    QLineEdit* nameLineEdit;
    QLineEdit* numberLineEdit;

    void set_in_column_name();
    void set_in_column_date();
    void set_in_column_status();
    void set_in_column_number();
    void set_in_column_result();
    void add_to_TreeWidget();
};


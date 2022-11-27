#pragma execution_character_set("utf-8")
#include "OrderController.h"
#include "API.h"


OrderController::OrderController(QTreeWidget* qtw, QLineEdit* name_line, QLineEdit* number_line) {
	tree_widget = qtw;
	nameLineEdit = name_line;
	numberLineEdit = number_line;
	tree_widget_item = new QTreeWidgetItem();
	order = new Order();
	api = new API();
	connect(api, SIGNAL(RequestSended()), this, SLOT(OnRequestSended()));
	connect(api, SIGNAL(ResultReady(int)), this, SLOT(onResultReady(int)));
}

void OrderController::new_order() 
{
	order->set_name(nameLineEdit->text().toStdString());
	order->set_status("Cформирована");
	order->set_number(numberLineEdit->text().toInt());
}


void OrderController::show() {
	add_to_TreeWidget();
}

void OrderController::add_to_TreeWidget() {
	set_in_column_name();
	set_in_column_date();
	set_in_column_status();
	set_in_column_number();
	tree_widget->addTopLevelItem(tree_widget_item);
}

void OrderController::set_in_column_name() {
	tree_widget_item->setText(0, QString::fromStdString(order->get_name()));
}

void OrderController::set_in_column_date() {
	tree_widget_item->setText(1, QString::fromStdString(order->get_date()));
}

void OrderController::set_in_column_status() {
	tree_widget_item->setText(2, QString::fromStdString(order->get_status()));
}

void OrderController::set_in_column_number() {
	tree_widget_item->setText(3, QString::number(order->get_number()));
}

void OrderController::set_in_column_result() {
	tree_widget_item->setText(4, QString::number(order->get_result()));
}

void OrderController::set_order_result() {
	// запрос к API на получение результата
	api->set_index(order->get_number());
	api->start();
}

//SLOT срабатывает при получение результата из внешней среды
void OrderController::onResultReady(int result) {
	order->set_status("Готово");
	set_in_column_status();
	order->set_result(result);
	set_in_column_result();	
}
//SLOT срабатывает при отправке заявки во внешнюю среду
void OrderController::OnRequestSended() {
	order->set_status("В обработке");
	set_in_column_status();
}
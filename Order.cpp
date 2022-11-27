#pragma execution_character_set("utf-8")
#include "Order.h"
#include <ctime>

Order::Order() {
	set_date();
}


void Order::set_name(string value) {
	name = value;
}

void Order::set_number(int value) {
	number = value;
}

void Order::set_date() {
	const time_t tm = time(nullptr);
	char buf[64];
	strftime(buf, std::size(buf), "%d.%m.%Y", localtime(&tm));
	date = string(buf);
}

void Order::set_status(string value) {
	status = value;
}

void Order::set_result(int value) {
	result = value;
}

string Order::get_name() {
	return name;
}

string Order::get_date() {
	return date;
}

string Order::get_status() {
	return status;
}

int Order::get_number() {
	return number;
}

int Order::get_result() {
	return result;
}

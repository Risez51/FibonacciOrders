#pragma once
using namespace std;
#include "qstring.h"


class Order
{
public:
	explicit Order();
	// Set functions
	void set_status(string);
	void set_result(int);
	void set_name(string);
	void set_number(int);
	
	// Get functions
	string get_name();
	string get_date();
	string get_status();
	int get_number();
	int get_result();

private:
	string name;
	string date;
	string status;
	int number;
	int result;
	void set_date();

};


#include "API.h"
#include <ctime>

API::API(QObject* parent)
    : QThread{ parent }
{   
    external_system = new ExternalSystem();
}

void API::set_index(int index_value) {
    index = index_value;
}

void API::run()
{
    //�������� �������� ������� �� ������� �������.
    this->msleep(2000);
    // ������, ��� ������ ���������.
    emit RequestSended();
    //���������� ����� �������� �� ������� �������.
    int fibonacci_result = external_system->get_fibonacci_by_index(index);
    //�������� ��������� ������� �� ������� ������.
    this->sleep(get_random_value());
    // ������, ��� ��������� ��������.
    emit ResultReady(fibonacci_result);
}

int API::get_random_value() {
    srand(time(NULL));
    return rand() % 10;
}
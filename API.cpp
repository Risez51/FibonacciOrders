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
    //Ёмул€ци€ отправки запроса во внешнюю систему.
    this->msleep(2000);
    // —игнал, что запрос отправлен.
    emit RequestSended();
    //¬ычисление числа фибоначи во внешней системе.
    int fibonacci_result = external_system->get_fibonacci_by_index(index);
    //Ёмул€ци€ обработки запроса во внешней средой.
    this->sleep(get_random_value());
    // —игнал, что результат вычислен.
    emit ResultReady(fibonacci_result);
}

int API::get_random_value() {
    srand(time(NULL));
    return rand() % 10;
}
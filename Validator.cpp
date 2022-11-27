#pragma execution_character_set("utf-8")
#include "Validator.h"
#include <QMessageBox>

Validator::Validator(QWidget* parent)
    : QWidget{ parent }
{

}

bool Validator::is_valid_LineEdit(QString text, QString label)
{
    if (text == "")
    {
        show_message(label);
        return false;
    }
    else {
        return true;
    }
}

void Validator::show_message(QString label)
{
    QMessageBox::information(this, "¬ведите значение", label, QMessageBox::Ok);
}

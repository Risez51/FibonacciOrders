#pragma once
#include <qwidget.h>

class Validator :
    public QWidget
{
    Q_OBJECT
public:
    explicit Validator(QWidget* parent = nullptr);
    bool is_valid_LineEdit(QString line, QString label);
    void show_message(QString label);
    
};


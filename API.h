#pragma once
#include <QThread>
#include <qobject.h>
#include "ExternalSystem.h"

class API :
    public QThread
{
    Q_OBJECT

public:
    explicit API(QObject* parent = nullptr);
    void set_index(int);
    void run();

signals:
    void RequestSended();
    void ResultReady(int);

private:
    int get_random_value();
    int index = 0;
    ExternalSystem* external_system;
};


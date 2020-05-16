#ifndef WEATHERRECEIVER_H
#define WEATHERRECEIVER_H

#include <QObject>

class WeatherReceiver: public QObject
{
    Q_OBJECT

public:
    WeatherReceiver();

public slots:
    void getCurrent(const QString &text);
};

#endif // WEATHERRECEIVER_H

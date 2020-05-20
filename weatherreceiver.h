#ifndef WEATHERRECEIVER_H
#define WEATHERRECEIVER_H

#include "parser.h"

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

class WeatherReceiver: public QObject
{
    Q_OBJECT

public:
    WeatherReceiver();

public slots:
    void setWeatherData(WeatherData *weatherData);
    void getCurrent();
    QStringList recentLocations() const;

private:
    QScopedPointer<QNetworkAccessManager> manager;
    QNetworkRequest networkRequest;
    Parser parser;
};

#endif // WEATHERRECEIVER_H

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
    /*!
     * \brief set weather data to work with actual weather data
     * \param pointer to weatherData class
     */
    void setWeatherData(WeatherData *weatherData);
    /*!
     * \brief  obtain full weather forecast
     */
    void getWeather();
    /*!
     * \brief get recent locations
     * \return
     */
    QStringList recentLocations() const;
    /*!
     * \brief check if any of recent locations exists
     * \return recent locations exists or not
     */
    bool recentLocationsExists() const;

private:
    QScopedPointer<QNetworkAccessManager> manager;
    QNetworkRequest networkRequest;
    Parser parser;
};

#endif // WEATHERRECEIVER_H

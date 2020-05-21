#include "weatherreceiver.h"

#include <QNetworkReply>
#include <QUrl>

#include <QDebug>

#include "weatherdata.h"

using namespace std;

namespace { const QString key =  "1be64cf1902d6591b23a204618b08468"; }

WeatherReceiver::WeatherReceiver()
{
    manager.reset(new QNetworkAccessManager(this));
}

void WeatherReceiver::setWeatherData(WeatherData* weatherData)
{
    parser.setWeatherData(weatherData);
}

void WeatherReceiver::getCurrent()
{
    qDebug () << "parser.getWeatherData()->location()" << parser.getWeatherData()->location();

    networkRequest.setUrl(QUrl("https://api.openweathermap.org/data/2.5/find?q=" + parser.getWeatherData()->location() + "&units=metric&appid=" + key));
    QNetworkReply *reply = manager->get(networkRequest);
    connect(reply, &QIODevice::readyRead, this, [=] { parser.parse(reply->readAll()); });
}

void WeatherReceiver::getForecast(int daysCount)
{
    //cnt=10
    //community-open-weather-map.p.rapidapi.com/forecast/daily?q=
}

QStringList WeatherReceiver::recentLocations() const
{
    return parser.getWeatherData()->recentLocations();
}

bool WeatherReceiver::recentLocationsExists() const
{
    return !parser.getWeatherData()->recentLocations().isEmpty();
}




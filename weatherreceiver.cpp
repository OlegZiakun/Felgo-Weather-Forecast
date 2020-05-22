#include "weatherreceiver.h"

#include <QNetworkReply>
#include <QUrl>

#include "weatherdata.h"

using namespace std;
using parsePtr = void (Parser::*) (const QString&);

void WeatherReceiver::getWeather()
{
    const QString key = "1be64cf1902d6591b23a204618b08468"; // you can add your Open Weather Map key here
    const QStringList urlParts = { "https://api.openweathermap.org/data/2.5/", "?q=" + parser.getWeatherData()->location() + "&units=metric&appid=" + key };

    const auto request = [this] (const QString& request, parsePtr parse)
    {
        networkRequest.setUrl(QUrl(request));
        QNetworkReply *reply = manager->get(networkRequest);

        connect(reply, &QIODevice::readyRead, this, [=] { (parser.*parse)(reply->readAll()); });
    };

    request(urlParts[0] + "find" + urlParts[1], &Parser::parseCurrent);  // make request for current weather
    request(urlParts[0] + "forecast" + urlParts[1], &Parser::parseForecast); // make request for weather forecast for 5 days
}

WeatherReceiver::WeatherReceiver()
{
    manager.reset(new QNetworkAccessManager(this));
}

void WeatherReceiver::setWeatherData(WeatherData* weatherData)
{
    parser.setWeatherData(weatherData);
}

QStringList WeatherReceiver::recentLocations() const
{
    return parser.getWeatherData()->recentLocations();
}

bool WeatherReceiver::recentLocationsExists() const
{
    return !parser.getWeatherData()->recentLocations().isEmpty();
}




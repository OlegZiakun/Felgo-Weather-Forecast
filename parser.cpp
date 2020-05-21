#include "parser.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "weatherdata.h"

#include <QDebug>

void Parser::parse(const QString &content)
{
    Data data;
    const QJsonDocument& jsonResponse = QJsonDocument::fromJson(content.toUtf8());
    const QJsonObject& jsonObject = jsonResponse.object();
    const QJsonArray& list = jsonObject["list"].toArray();

    if(jsonObject["cod"].toInt() != 0)
    {
        data.error = jsonObject["message"].toString();
        weatherData->update(data);

        return;
    }

    if(list.size() > 0)
    {
        const QJsonObject& mainList = list[0].toObject();
        const QJsonObject& main = mainList["main"].toObject();
        const QJsonObject& sys = mainList["sys"].toObject();
        const QJsonArray& weather = mainList["weather"].toArray();

        if(weather.size() > 0)
        {
            const QJsonObject& mainWeather  = weather[0].toObject();
            data.description = mainWeather["main"].toString();
        }

        data.currentTemperature = main["temp"].toDouble();
        data.humidity = main["humidity"].toInt();
        data.country = sys["country"].toString();
    }
    else
        data.error = QObject::tr("City doesn't exists");

    weatherData->update(data);
}

void Parser::setWeatherData(WeatherData* weatherData)
{
    this->weatherData = weatherData;
}

WeatherData* Parser::getWeatherData() const
{
    return weatherData;
}

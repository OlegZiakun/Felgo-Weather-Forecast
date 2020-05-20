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
    const QJsonArray& weather = jsonObject["weather"].toArray();
    const QJsonObject& main = jsonObject["main"].toObject();
    const QJsonObject& sys = jsonObject["sys"].toObject();

    data.error = jsonObject["message"].toString();
    data.currentTemperature = main["temp"].toDouble();
    data.humidity = main["humidity"].toInt();
    data.country = sys["country"].toString();

    for(const QJsonValue& value: weather)
        data.description = value.toObject()["description"].toString();

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

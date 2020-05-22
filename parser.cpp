#include "parser.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDate>

#include "weatherdata.h"
#include "utils.h"

void Parser::parseCurrent(const QString &content)
{
    CurrentData data;

    const QJsonDocument& jsonResponse = QJsonDocument::fromJson(content.toUtf8());
    const QJsonObject& jsonObject = jsonResponse.object();
    const QJsonArray& list = jsonObject["list"].toArray();

    // "cod" return not a 0 in case of error
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

void Parser::parseForecast(const QString &content)
{
    const QJsonDocument& jsonResponse = QJsonDocument::fromJson(content.toUtf8());
    const QJsonObject& jsonObject = jsonResponse.object();
    const QJsonArray& list = jsonObject["list"].toArray();

    if(jsonObject["cod"].toInt() != 0)
    {
        CurrentData data;
        data.error = jsonObject["message"].toString();
        weatherData->update(data);

        return;
    }

    QString day;
    QVector<ForecastData> forecastData;

    if(list.size() > 0)
    {
        const Utils::Time time = Utils::timeStrFromUnixTime(list[0].toObject()["dt"].toInt());
        day = time.day;
    }

    constexpr double unreachableTemparature = 90.; // just unreachable temparature value to initialize min/max variables
    double minTemperature = unreachableTemparature, maxTemperature = -unreachableTemparature;

    for(const auto& val: list)
    {
        const QJsonObject& currentVal = val.toObject();
        const Utils::Time time = Utils::timeStrFromUnixTime(currentVal["dt"].toInt());
        const QJsonObject& main = currentVal["main"].toObject();
        const QJsonArray& weather = currentVal["weather"].toArray();
        QString description;

        if(weather.size() > 0)
            description = weather[0].toObject()["main"].toString();

        minTemperature = qMin(minTemperature, main["temp_min"].toDouble());
        maxTemperature = qMax(maxTemperature, main["temp_max"].toDouble());

        if(day != time.day)
        {
            forecastData.push_back(ForecastData(day + "/" + time.month, description, minTemperature, maxTemperature));

            day = time.day;
            minTemperature = unreachableTemparature;
            maxTemperature = -unreachableTemparature;
        }
    }

     weatherData->update(forecastData);
}

void Parser::setWeatherData(WeatherData* weatherData)
{
    this->weatherData = weatherData;
}

WeatherData* Parser::getWeatherData() const
{
    return weatherData;
}

#include "weatherdata.h"

#include <QDebug>

WeatherData::WeatherData()
{

}

void WeatherData::update(const Data &data)
{
    qDebug() << "location()" << location();

    qDebug() << "data.currentTemperature" << data.currentTemperature;
    qDebug() << "data.humidity" << data.humidity;
    qDebug() << "data.country" << data.country;
    qDebug() << "data.weatherDescription" << data.weatherDescription;

    setCurrentTemperature(data.currentTemperature);
    setLocation(locationStr + ", " + data.country);
}

double WeatherData::currentTemperature() const
{
    return currentTemperatureValue;
}

void WeatherData::setCurrentTemperature(double value)
{
    if(currentTemperatureValue != value)
    {
        currentTemperatureValue = value;
        currentTemperatureChanged();
    }
}

QString WeatherData::location() const
{
    return locationStr;
}

void WeatherData::setLocation(const QString &value)
{
    if(locationStr != value)
    {
        locationStr = value;
        currentlocationChanged();
    }
}

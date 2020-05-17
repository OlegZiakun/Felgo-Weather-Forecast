#include "weatherdata.h"

#include <QDebug>

WeatherData::WeatherData()
{

}

void WeatherData::update(const Data &data)
{
    setCurrentTemperature(data.currentTemperature);
    setLocation(locationStr + ", " + data.country);
    setHumidity(data.humidity);
    setDescription(data.description);
}

int WeatherData::humidity() const
{
    return humidityValue;
}

void WeatherData::setHumidity(int value)
{
    if(humidityValue != value)
    {
        humidityValue = value;
        humidityChanged();
    }
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
        currentLocationChanged();
    }
}

QString WeatherData::description() const
{
    return descriptionStr;
}

void WeatherData::setDescription(const QString &value)
{
    if(descriptionStr != value)
    {
        descriptionStr = value;
        descriptionChanged();
    }
}

#include "weatherdata.h"

WeatherData::WeatherData()
{

}

void WeatherData::update(const Data &data)
{
    setCurrentTemperature(data.currentTemperature);
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
        currentTemperatureChanged();
    }
}

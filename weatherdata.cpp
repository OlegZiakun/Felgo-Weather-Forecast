#include "weatherdata.h"

#include <QDebug>

WeatherData::WeatherData()
{

}

void WeatherData::update(const Data &data)
{
    const bool visible = data.message.isEmpty();

    setVisible(visible);

    if(visible)
    {
        setCurrentTemperature(data.currentTemperature);
        setLocation(locationStr + ", " + data.country);
        setHumidity(data.humidity);
        setDescription(data.description);
    }
    else
        setMessage(data.message);
}

int WeatherData::humidity() const
{
    return humidityVal;
}

void WeatherData::setHumidity(int value)
{
    if(humidityVal != value)
    {
        humidityVal = value;
        humidityChanged();
    }
}

double WeatherData::currentTemperature() const
{
    return currentTemperatureVal;
}

void WeatherData::setCurrentTemperature(double value)
{
    if(currentTemperatureVal != value)
    {
        currentTemperatureVal = value;
        currentTemperatureChanged();
    }
}

bool WeatherData::visible() const
{
    return visibleVal;
}

void WeatherData::setVisible(bool value)
{
    if(visibleVal != value)
    {
        visibleVal = value;
        visibleChanged();
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

QString WeatherData::message() const
{
    return messageStr;
}

void WeatherData::setMessage(const QString &value)
{
    if(messageStr != value)
    {
        messageStr = value;
        messageChanged();
    }
}

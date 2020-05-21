#include "weatherdata.h"

#include <QDebug>

WeatherData::WeatherData()
{

}

void WeatherData::update(const Data &data)
{
    const bool visible = data.error.isEmpty();

    setVisible(visible);
    setError(data.error);

    if(visible)
    {
        settings.saveLocation(locationStr);

        setCurrentTemperature(data.currentTemperature);
        setLocation(locationStr + ", " + data.country);
        setHumidity(data.humidity);
        setDescription(data.description);
    }
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
        emit humidityChanged();
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
        emit currentTemperatureChanged();
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
        emit visibleChanged();
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
        emit currentLocationChanged();
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
        emit descriptionChanged();
    }
}

QString WeatherData::error() const
{
    return errorStr;
}

void WeatherData::setError(const QString &value)
{
    if(errorStr != value)
    {
        errorStr = value;
        emit errorChanged();
    }
}

QStringList WeatherData::recentLocations() const
{
    return settings.getLocations();
}

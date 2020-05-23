#include "weatherdata.h"

namespace { constexpr int forecastDaysCount = 5; }

WeatherData::WeatherData()
{
    for(int i = 0; i < forecastDaysCount; ++i)
    {
        daysList.push_back(QString());
        descriptionList.push_back(QString());
        minTemperatures.push_back(0);
        maxTemperatures.push_back(0);
    }
}

void WeatherData::update(const CurrentData &data)
{
    const bool visible = data.error.isEmpty();

    setVisible(visible);
    setError(data.error);
    setLocation(data.location);

    if(visible)
    {
        settings.saveLocation(locationStr);

        setCurrentTemperature(data.currentTemperature);
        setLocation(locationStr + ", " + data.country);
        setHumidity(data.humidity);
        setDescription(data.description);
    }
}

void WeatherData::update(const QVector<ForecastData> &data)
{
    if(data.size() != forecastDaysCount)
        return;

    setForecastDay1(data[0].day); setForecastDay2(data[1].day); setForecastDay3(data[2].day); setForecastDay4(data[3].day); setForecastDay5(data[4].day);
    setForecastDescription1(data[0].description); setForecastDescription2(data[1].description); setForecastDescription3(data[2].description);  setForecastDescription4(data[3].description); setForecastDescription5 (data[4].description);
    setForecastMinTemperature1(data[0].minTemperature); setForecastMinTemperature2(data[1].minTemperature); setForecastMinTemperature3(data[2].minTemperature); setForecastMinTemperature4 (data[3].minTemperature); setForecastMinTemperature5(data[4].minTemperature);
    setForecastMaxTemperature1(data[0].maxTemperature); setForecastMaxTemperature2(data[1].maxTemperature); setForecastMaxTemperature3(data[2].maxTemperature); setForecastMaxTemperature4(data[3].maxTemperature); setForecastMaxTemperature5(data[4].maxTemperature);
}

void WeatherData::setHumidity(int value)
{
    if(humidityVal != value)
    {
        humidityVal = value;
        emit humidityChanged();
    }
}

void WeatherData::setCurrentTemperature(double value)
{
    if(currentTemperatureVal != value)
    {
        currentTemperatureVal = value;
        emit currentTemperatureChanged();
    }
}

void WeatherData::setVisible(bool value)
{
    if(visibleVal != value)
    {
        visibleVal = value;
        emit visibleChanged();
    }
}

void WeatherData::setLocation(const QString &value)
{
    if(locationStr != value)
    {
        locationStr = value;
        emit currentLocationChanged();
    }
}


void WeatherData::setDescription(const QString &value)
{
    if(descriptionStr != value)
    {
        descriptionStr = value;
        emit descriptionChanged();
    }
}

void WeatherData::setError(const QString &value)
{
    if(errorStr != value)
    {
        errorStr = value;
        emit errorChanged();
    }
}

void WeatherData::setForecastStrVal(QString &data, const QString &value)
{
    if(data != value)
    {
        data = value;
        emit forecastChanged();
    }
}

void WeatherData::setForecastDoubleVal(double &data, double value)
{
    if(data != value)
    {
        data= value;
        emit forecastChanged();
    }
}

bool WeatherData::visible() const { return visibleVal; }
double WeatherData::currentTemperature() const { return currentTemperatureVal; }
int WeatherData::humidity() const { return humidityVal; }
QString WeatherData::location() const { return locationStr; }
QString WeatherData::description() const { return descriptionStr; }
QString WeatherData::error() const { return errorStr; }
QStringList WeatherData::recentLocations() const { return settings.getLocations(); }

QString WeatherData::forecastDay1() const { return daysList[0]; }
void WeatherData::setForecastDay1(const QString &value) { setForecastStrVal(daysList[0], value); }

QString WeatherData::forecastDay2() const { return daysList[1]; }
void WeatherData::setForecastDay2(const QString& value){ setForecastStrVal(daysList[1], value); }

QString WeatherData::forecastDay3() const { return daysList[2]; }
void WeatherData::setForecastDay3(const QString& value) { setForecastStrVal(daysList[2], value); }

QString WeatherData::forecastDay4() const { return daysList[3]; }
void WeatherData::setForecastDay4(const QString& value){ setForecastStrVal(daysList[3], value); }

QString WeatherData::forecastDay5() const { return daysList[4]; }
void WeatherData::setForecastDay5(const QString& value) { setForecastStrVal(daysList[4], value); }

QString WeatherData::forecastDescription1() const { return descriptionIcons[descriptionList[0]]; }
void WeatherData::setForecastDescription1(const QString& value) { setForecastStrVal(descriptionList[0], value); }

QString WeatherData::forecastDescription2() const { return descriptionIcons[descriptionList[1]]; }
void WeatherData::setForecastDescription2(const QString& value) { setForecastStrVal(descriptionList[1], value); }

QString WeatherData::forecastDescription3() const { return descriptionIcons[descriptionList[2]]; }
void WeatherData::setForecastDescription3(const QString& value) { setForecastStrVal(descriptionList[2], value); }

QString WeatherData::forecastDescription4() const { return descriptionIcons[descriptionList[3]]; }
void WeatherData::setForecastDescription4(const QString& value) { setForecastStrVal(descriptionList[3], value); }

QString WeatherData::forecastDescription5() const { return descriptionIcons[descriptionList[4]]; }
void WeatherData::setForecastDescription5(const QString& value) { setForecastStrVal(descriptionList[4], value); }

double WeatherData::forecastMinTemperature1() const { return minTemperatures[0]; }
void WeatherData::setForecastMinTemperature1(double value) { setForecastDoubleVal(minTemperatures[0], value); }

double WeatherData::forecastMinTemperature2() const { return minTemperatures[1]; }
void WeatherData::setForecastMinTemperature2(double value) { setForecastDoubleVal(minTemperatures[1], value); }

double WeatherData::forecastMinTemperature3() const { return minTemperatures[2]; }
void WeatherData::setForecastMinTemperature3(double value) { setForecastDoubleVal(minTemperatures[2], value); }

double WeatherData::forecastMinTemperature4() const { return minTemperatures[3]; }
void WeatherData::setForecastMinTemperature4(double value) { setForecastDoubleVal(minTemperatures[3], value); }

double WeatherData::forecastMinTemperature5() const { return minTemperatures[4]; }
void WeatherData::setForecastMinTemperature5(double value) { setForecastDoubleVal(minTemperatures[4], value); }

double WeatherData::forecastMaxTemperature1() const { return maxTemperatures[0]; }
void WeatherData::setForecastMaxTemperature1(double value) { setForecastDoubleVal(maxTemperatures[0], value); }

double WeatherData::forecastMaxTemperature2() const { return maxTemperatures[1]; }
void WeatherData::setForecastMaxTemperature2(double value) { setForecastDoubleVal(maxTemperatures[1], value); }

double WeatherData::forecastMaxTemperature3() const { return maxTemperatures[2]; }
void WeatherData::setForecastMaxTemperature3(double value) { setForecastDoubleVal(maxTemperatures[2], value); }

double WeatherData::forecastMaxTemperature4() const { return maxTemperatures[3]; }
void WeatherData::setForecastMaxTemperature4(double value) { setForecastDoubleVal(maxTemperatures[3], value); }

double WeatherData::forecastMaxTemperature5() const { return maxTemperatures[4]; }
void WeatherData::setForecastMaxTemperature5(double value) { setForecastDoubleVal(maxTemperatures[4], value); }

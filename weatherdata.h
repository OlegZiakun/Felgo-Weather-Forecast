#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>

struct Data
{
    double currentTemperature = 0;
    int humidity = 0;
    QString country;
    QString description;
};

class WeatherData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double currentTemperature READ currentTemperature WRITE setCurrentTemperature NOTIFY currentTemperatureChanged)
    Q_PROPERTY(int humidity READ humidity WRITE setHumidity NOTIFY humidityChanged)
    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY currentLocationChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)

public:
    WeatherData();

    void update(const Data& data);

    int humidity() const;
    void setHumidity(int value);

    double currentTemperature() const;
    void setCurrentTemperature(double value);

     QString location() const;
     void setLocation(const QString& value);

     QString description() const;
     void setDescription(const QString& value);

signals:
    void currentTemperatureChanged();
    void currentLocationChanged();
    void humidityChanged();
    void descriptionChanged();

private:
    double currentTemperatureValue = 0;
    int humidityValue = 0;
    QString locationStr;
    QString descriptionStr;
};

#endif // WEATHERDATA_H

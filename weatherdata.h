#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>

struct Data
{
    double currentTemperature = 0;
    int humidity = 0;
    QString country;
    QString description;
    QString message;
};

class WeatherData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double currentTemperature READ currentTemperature WRITE setCurrentTemperature NOTIFY currentTemperatureChanged)
    Q_PROPERTY(int humidity READ humidity WRITE setHumidity NOTIFY humidityChanged)
    Q_PROPERTY(bool visible READ visible WRITE setVisible NOTIFY visibleChanged)
    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY currentLocationChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    WeatherData();

    void update(const Data& data);

    int humidity() const;
    void setHumidity(int value);

    double currentTemperature() const;
    void setCurrentTemperature(double value);

    bool visible() const;
    void setVisible(bool value);

     QString location() const;
     void setLocation(const QString& value);

     QString description() const;
     void setDescription(const QString& value);

     QString message() const;
     void setMessage(const QString& value);

signals:
    void currentTemperatureChanged();
    void currentLocationChanged();
    void humidityChanged();
    void descriptionChanged();
    void visibleChanged();
    void messageChanged();

private:
    double currentTemperatureVal = 0;
    int humidityVal = 0;
    bool visibleVal = false;
    QString locationStr;
    QString descriptionStr;
    QString messageStr;
};

#endif // WEATHERDATA_H

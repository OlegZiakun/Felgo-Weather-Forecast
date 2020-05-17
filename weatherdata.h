#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>

struct Data
{
    double currentTemperature = 0;
};

class WeatherData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double currentTemperature READ currentTemperature WRITE setCurrentTemperature NOTIFY currentTemperatureChanged)
    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY currentlocationChanged)

public:
    WeatherData();

    void update(const Data& data);

    double currentTemperature() const;
    void setCurrentTemperature(double value);

     QString location() const;
     void setLocation(const QString& value);

signals:
    void currentTemperatureChanged();
    void currentlocationChanged();

private:
    double currentTemperatureValue = 0;
    QString locationStr;
};

#endif // WEATHERDATA_H

#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>

#include "settings.h"

struct CurrentData
{
    double currentTemperature = 0;
    int humidity = 0;
    QString country;
    QString description;
    QString error;
};

struct ForecastData
{
    ForecastData(const QString& d, const QString& desc, double minTemp, double maxTemp) :
        minTemperature(minTemp), maxTemperature(maxTemp), day(d), description(desc)
    {
    }

    double minTemperature = 0;
    double maxTemperature = 0;
    QString day;
    QString description;
};

#define SET_FORECAST_DAY(n) setForecastDay##n(data[n - 1].day)

class WeatherData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double currentTemperature READ currentTemperature WRITE setCurrentTemperature NOTIFY currentTemperatureChanged)
    Q_PROPERTY(int humidity READ humidity WRITE setHumidity NOTIFY humidityChanged)
    Q_PROPERTY(bool visible READ visible WRITE setVisible NOTIFY visibleChanged)
    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY currentLocationChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString error READ error WRITE setError NOTIFY errorChanged)

    Q_PROPERTY(QString forecastDay1 READ forecastDay1 WRITE setForecastDay1 NOTIFY forecastChanged)
    Q_PROPERTY(QString forecastDay2 READ forecastDay2 WRITE setForecastDay2 NOTIFY forecastChanged)
    Q_PROPERTY(QString forecastDay3 READ forecastDay3 WRITE setForecastDay3 NOTIFY forecastChanged)
    Q_PROPERTY(QString forecastDay4 READ forecastDay4 WRITE setForecastDay4 NOTIFY forecastChanged)
    Q_PROPERTY(QString forecastDay5 READ forecastDay5 WRITE setForecastDay5 NOTIFY forecastChanged)

    Q_PROPERTY(QString forecastDescription1 READ forecastDescription1 WRITE setForecastDescription1 NOTIFY forecastChanged)
    Q_PROPERTY(QString forecastDescription2 READ forecastDescription2 WRITE setForecastDescription2 NOTIFY forecastChanged)
    Q_PROPERTY(QString forecastDescription3 READ forecastDescription3 WRITE setForecastDescription3 NOTIFY forecastChanged)
    Q_PROPERTY(QString forecastDescription4 READ forecastDescription4 WRITE setForecastDescription4 NOTIFY forecastChanged)
    Q_PROPERTY(QString forecastDescription5 READ forecastDescription5 WRITE setForecastDescription5 NOTIFY forecastChanged)

    Q_PROPERTY(double forecastMinTemperature1 READ forecastMinTemperature1 WRITE setForecastMinTemperature1 NOTIFY forecastChanged)
    Q_PROPERTY(double forecastMinTemperature2 READ forecastMinTemperature2 WRITE setForecastMinTemperature2 NOTIFY forecastChanged)
    Q_PROPERTY(double forecastMinTemperature3 READ forecastMinTemperature3 WRITE setForecastMinTemperature3 NOTIFY forecastChanged)
    Q_PROPERTY(double forecastMinTemperature4 READ forecastMinTemperature4 WRITE setForecastMinTemperature4 NOTIFY forecastChanged)
    Q_PROPERTY(double forecastMinTemperature5 READ forecastMinTemperature5 WRITE setForecastMinTemperature5 NOTIFY forecastChanged)

    Q_PROPERTY(double forecastMaxTemperature1 READ forecastMaxTemperature1 WRITE setForecastMaxTemperature1 NOTIFY forecastChanged)
    Q_PROPERTY(double forecastMaxTemperature2 READ forecastMaxTemperature2 WRITE setForecastMaxTemperature2 NOTIFY forecastChanged)
    Q_PROPERTY(double forecastMaxTemperature3 READ forecastMaxTemperature3 WRITE setForecastMaxTemperature3 NOTIFY forecastChanged)
    Q_PROPERTY(double forecastMaxTemperature4 READ forecastMaxTemperature4 WRITE setForecastMaxTemperature4 NOTIFY forecastChanged)
    Q_PROPERTY(double forecastMaxTemperature5 READ forecastMaxTemperature5 WRITE setForecastMaxTemperature5 NOTIFY forecastChanged)

public:
    WeatherData();

    void update(const CurrentData& data);
    void update(const QVector<ForecastData> &data);

public:
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

     QString error() const;
     void setError(const QString& value);

     QStringList recentLocations() const;

     QString forecastDay1() const;
     void setForecastDay1(const QString& value);
     QString forecastDay2() const;
     void setForecastDay2(const QString& value);
     QString forecastDay3() const;
     void setForecastDay3(const QString& value);
     QString forecastDay4() const;
     void setForecastDay4(const QString& value);
     QString forecastDay5() const;
     void setForecastDay5(const QString& value);

     QString forecastDescription1() const;
     void setForecastDescription1(const QString& value);
     QString forecastDescription2() const;
     void setForecastDescription2(const QString& value);
     QString forecastDescription3() const;
     void setForecastDescription3(const QString& value);
     QString forecastDescription4() const;
     void setForecastDescription4(const QString& value);
     QString forecastDescription5() const;
     void setForecastDescription5(const QString& value);

     double forecastMinTemperature1() const;
     void setForecastMinTemperature1(double value);
     double forecastMinTemperature2() const;
     void setForecastMinTemperature2(double value);
     double forecastMinTemperature3() const;
     void setForecastMinTemperature3(double value);
     double forecastMinTemperature4() const;
     void setForecastMinTemperature4(double value);
     double forecastMinTemperature5() const;
     void setForecastMinTemperature5(double value);

     double forecastMaxTemperature1() const;
     void setForecastMaxTemperature1(double value);
     double forecastMaxTemperature2() const;
     void setForecastMaxTemperature2(double value);
     double forecastMaxTemperature3() const;
     void setForecastMaxTemperature3(double value);
     double forecastMaxTemperature4() const;
     void setForecastMaxTemperature4(double value);
     double forecastMaxTemperature5() const;
     void setForecastMaxTemperature5(double value);

signals:
    void currentTemperatureChanged();
    void currentLocationChanged();
    void humidityChanged();
    void descriptionChanged();
    void visibleChanged();
    void errorChanged();
    void forecastChanged();

private:
    void setForecastStrVal(QString &data, const QString &value);
    void setForecastDoubleVal(double &data, double value);

private:
    double currentTemperatureVal = 0;
    int humidityVal = 0;
    bool visibleVal = false;
    QString locationStr;
    QString descriptionStr;
    QString errorStr;
    Settings settings;
    QStringList daysList;
    QStringList descriptionList;
    QVector<double> minTemperatures;
    QVector<double> maxTemperatures;
    QHash<QString, QString> descriptionIcon;
};

#endif // WEATHERDATA_H

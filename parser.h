#ifndef PARSER_H
#define PARSER_H

#include <QObject>

class WeatherData;

class Parser
{
public:
    void parse(const QString &content);
    void setWeatherData(WeatherData *weatherData);
    WeatherData* getWeatherData() const;

private:
    WeatherData* weatherData = nullptr;
};

#endif // PARSER_H

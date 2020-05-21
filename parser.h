#ifndef PARSER_H
#define PARSER_H

#include <QString>

class WeatherData;

class Parser
{
public:
    void parseCurrent(const QString &content);
    void parseForecast(const QString &content);
    void setWeatherData(WeatherData *weatherData);
    WeatherData* getWeatherData() const;

private:
    WeatherData* weatherData = nullptr;
};

#endif // PARSER_H

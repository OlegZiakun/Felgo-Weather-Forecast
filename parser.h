#ifndef PARSER_H
#define PARSER_H

#include <QObject>

#include "weatherdata.h"

class Parser
{
public:
    Parser();

    void parse(const QString &content);

    void setWeatherData(WeatherData *weatherData);
    WeatherData* getWeatherData() const;

private:
    WeatherData* weatherData = nullptr;
};

#endif // PARSER_H

#ifndef PARSER_H
#define PARSER_H

#include <QObject>

#include "weatherdata.h"

class Parser
{
public:
    Parser();

    void parse(WeatherData* weatherData, const QString &content);
};

#endif // PARSER_H

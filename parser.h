#ifndef PARSER_H
#define PARSER_H

#include <QString>

class WeatherData;

class Parser
{
public:
    /*!
     * \brief parse reply for current weather
     * \param content returned by web request
     */
    void parseCurrent(const QString &content);
    /*!
     * \brief parse reply for weather forecast
     * \param content returned by web request
     */
    void parseForecast(const QString &content);
    /*!
     * \brief set weather data to work with actual weather data
     * \param pointer to weatherData class
     */
    void setWeatherData(WeatherData *weatherData);
    /*!
     * \brief get weather data
     * \return pointer to weatherData class
     */
    WeatherData* getWeatherData() const;

private:
    WeatherData* weatherData = nullptr;
};

#endif // PARSER_H

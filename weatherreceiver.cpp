#include "weatherreceiver.h"

#include <QNetworkReply>
#include <QUrl>

#include <QDebug>

#include "weatherdata.h"

using namespace std;

WeatherReceiver::WeatherReceiver()
{
    manager.reset(new QNetworkAccessManager(this));
}

void WeatherReceiver::getCurrent(WeatherData* weatherData)
{
    //http://openweathermap.org/img/w/04n.png

//    networkRequest.setRawHeader("x-rapidapi-host", "community-open-weather-map.p.rapidapi.com");
//    networkRequest.setRawHeader("x-rapidapi-key", "976d4b6bfamsh9ee3894ee6d3f3ep1ab798jsnea29f25aea69");

//    networkRequest.setUrl(QUrl("https://community-open-weather-map.p.rapidapi.com/weather?units=metric&q=" + weatherData->location()));

//    QNetworkReply *reply = manager->get(networkRequest);

//    connect(reply, &QIODevice::readyRead, this, [=] { parser.parse(weatherData, reply->readAll()); });

   parser.parse(weatherData, "{\"coord\":{\"lon\":24.71,\"lat\":48.92},\"weather\":[{\"id\":804,\"main\":\"Clouds\",\"description\":\"overcast clouds\",\"icon\":\"04n\"}],\"base\":\"stations\",\"main\":{\"temp\":7.84,\"feels_like\":6.49,\"temp_min\":7.84,\"temp_max\":7.84,\"pressure\":1023,\"humidity\":86,\"sea_level\":1023,\"grnd_level\":992},\"wind\":{\"speed\":0.51,\"deg\":170},\"clouds\":{\"all\":99},\"dt\":1589673389,\"sys\":{\"country\":\"UA\",\"sunrise\":1589682983,\"sunset\":1589738338},\"timezone\":10800,\"id\":707471,\"name\":\"" + weatherData->location() +"\",\"cod\":200}");
   // parser.parse(weatherData, "{\n    \"message\": \"You have exceeded the DAILY quota for Basic on your current plan, BASIC. Upgrade your plan at https://rapidapi.com/community/api/open-weather-map\"\n}\n");
}

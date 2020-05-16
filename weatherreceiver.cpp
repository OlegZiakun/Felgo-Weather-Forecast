#include "weatherreceiver.h"

#include <QNetworkReply>
#include <QUrl>

#include <QDebug>

using namespace std;

WeatherReceiver::WeatherReceiver()
{
    manager.reset(new QNetworkAccessManager(this));
}

void WeatherReceiver::getCurrent(const QString &text)
{
    //http://openweathermap.org/img/w/04n.png

    networkRequest.setRawHeader("x-rapidapi-host", "community-open-weather-map.p.rapidapi.com");
    networkRequest.setRawHeader("x-rapidapi-key", "976d4b6bfamsh9ee3894ee6d3f3ep1ab798jsnea29f25aea69");

    networkRequest.setUrl(QUrl("https://community-open-weather-map.p.rapidapi.com/weather?callback=test&units=metric&mode=json&q=Ivano-Frankivsk"));

    QNetworkReply *reply = manager->get(networkRequest);

    connect(reply, &QIODevice::readyRead, this, [=] {qDebug() << "readyRead" << reply->readAll(); });
    connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error), this, [=] (QNetworkReply::NetworkError code) {qDebug() << "error" << code; });
    connect(reply, &QNetworkReply::sslErrors, this, [] (const QList<QSslError> &errors) {qDebug() << "sslErrors" << errors; });
}

#include "parser.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QDebug>

Parser::Parser()
{
}

void Parser::parse(WeatherData* weatherData, const QString &content)
{
    Data data;
    const QJsonDocument &jsonResponse = QJsonDocument::fromJson(content.toUtf8());
    const QJsonObject &jsonObject = jsonResponse.object();
    const QJsonArray &weather = jsonObject["weather"].toArray();

    //const QJsonObject &coord = jsonObject["coord"].toObject();
    const QJsonObject &main = jsonObject["main"].toObject();
    const QJsonObject &sys = jsonObject["sys"].toObject();

    qDebug() << jsonResponse.toJson(QJsonDocument::Indented);
    qDebug() << "------------->  weatherData->location()" <<  weatherData->location();
    //    qDebug() << "-------------> message" <<  jsonObject["message"].toString();
    //    qDebug() << "-------------> base" <<  jsonObject["base"].toString();
    //    qDebug() << "-------------> cod" <<  jsonObject["cod"].toInt();
    //    qDebug() << "-------------> lat" <<  coord["lat"].toDouble();
    //    qDebug() << "-------------> temp" <<  main["temp"].toDouble();

    data.currentTemperature = main["temp"].toDouble();
    data.humidity = main["humidity"].toInt();
    data.country = sys["country"].toString();

    foreach (const QJsonValue & value, weather) {
        const QJsonObject &weatherObj = value.toObject();

        //       qDebug() << "description" << weatherObj["description"].toString();
        //       qDebug() << "main" << weatherObj["main"].toString();
        //       qDebug() << "icon" << weatherObj["icon"].toString();
        //       qDebug() << "id" << weatherObj["id"].toInt();

        data.description = weatherObj["description"].toString();
        //const QJsonArray &phonesObj = accountObj["phones"].toArray();

        //        for (int i = 0; i < phonesObj.size(); ++i) {
        //            const QJsonObject &rec = phonesObj[i].toObject();
        //            data.account.phones.push_back(Phone(rec["number"].toString(), rec["type"].toString(), rec["validated"].toBool()));
        //        }
    }

    weatherData->update(data);
}

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
    const QJsonArray &jsonArray = jsonObject["weather"].toArray();

    const QJsonObject &coord = jsonObject["coord"].toObject();
    const QJsonObject &main = jsonObject["main"].toObject();

    qDebug() << jsonResponse.toJson(QJsonDocument::Indented);

    qDebug() << "-------------> message" <<  jsonObject["message"].toString();
    qDebug() << "-------------> base" <<  jsonObject["base"].toString();
    qDebug() << "-------------> cod" <<  jsonObject["cod"].toInt();
    qDebug() << "-------------> lat" <<  coord["lat"].toDouble();
    qDebug() << "-------------> temp" <<  main["temp"].toDouble();

    data.currentTemperature = main["temp"].toDouble();

    foreach (const QJsonValue & value, jsonArray) {
       const QJsonObject &mainObj = value.toObject();

       qDebug() << "description" << mainObj["description"].toString();
       qDebug() << "main" << mainObj["main"].toString();
       qDebug() << "icon" << mainObj["icon"].toString();
       qDebug() << "id" << mainObj["id"].toInt();



        //const QJsonArray &phonesObj = accountObj["phones"].toArray();

        //        for (int i = 0; i < phonesObj.size(); ++i) {
        //            const QJsonObject &rec = phonesObj[i].toObject();
        //            data.account.phones.push_back(Phone(rec["number"].toString(), rec["type"].toString(), rec["validated"].toBool()));
        //        }
    }

    weatherData->update(data);
}

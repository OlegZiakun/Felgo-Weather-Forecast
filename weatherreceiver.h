#ifndef WEATHERRECEIVER_H
#define WEATHERRECEIVER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

class WeatherReceiver: public QObject
{
    Q_OBJECT

public:
    WeatherReceiver();

public slots:
    void getCurrent(const QString &text);

private:
    QScopedPointer<QNetworkAccessManager> manager;
    QNetworkRequest networkRequest;

};

#endif // WEATHERRECEIVER_H

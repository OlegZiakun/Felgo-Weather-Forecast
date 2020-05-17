#include <QApplication>
#include <FelgoApplication>
#include <QQmlContext>

#include "weatherreceiver.h"
#include "weatherdata.h"

#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  FelgoApplication felgo;

  felgo.setPreservePlatformFonts(true);

  QQmlApplicationEngine engine;

  felgo.initialize(&engine);
  felgo.setLicenseKey(PRODUCT_LICENSE_KEY);

  felgo.setMainQmlFileName(QStringLiteral("qml/WeatherMain.qml"));

  WeatherReceiver* weatherReceiver = new WeatherReceiver();

  qmlRegisterType<WeatherData>("com.OlegZiakun", 1, 0, "WeatherData");

  engine.rootContext()->setContextProperty("weatherReceiverObject", weatherReceiver);
  engine.load(QUrl(felgo.mainQmlFileName()));

  return app.exec();
}


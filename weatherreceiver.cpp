#include "weatherreceiver.h"
#include <curl/curl.h>

#include <QDebug>

using namespace std;

WeatherReceiver::WeatherReceiver()
{

}

void WeatherReceiver::getCurrent(const QString &text)
{
    QString buffer;
    CURL *curl = curl_easy_init();
    struct curl_slist *headers = curl_slist_append(headers = nullptr, "x-rapidapi-host: community-open-weather-map.p.rapidapi.com");

    headers = curl_slist_append(headers, "x-rapidapi-key: 976d4b6bfamsh9ee3894ee6d3f3ep1ab798jsnea29f25aea69");

    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(curl, CURLOPT_URL, "https://community-open-weather-map.p.rapidapi.com/weather?callback=test&units=metric&mode=json&q=Ivano-Frankivsk");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, *[](char *contents, size_t size, size_t nmemb, void *userp) -> size_t
    {
        (static_cast<QString*>(userp))->append(static_cast<char*>(contents));
        return size * nmemb;
    });


    CURLcode ret = curl_easy_perform(curl);

    qDebug() << buffer;
}

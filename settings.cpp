#include "settings.h"

#include <QStringList>

QStringList Settings::getLocations() const
{
    QStringList locationsList;
    const int locationsCount = value("locations/count", 0).toInt();

    for(int i = 0; i < locationsCount; ++i)
        locationsList.push_front(value("locations/" + QString::number(i + 1)).toString());

    return locationsList;
}

void Settings::saveLocation(const QString &location)
{
   //clear(); return;
    QStringList locationsList;
    int locationsCount = value("locations/count", 0).toInt();

    for(int i = 0; i < locationsCount; ++i)
    {
        locationsList.push_front(value("locations/" + QString::number(i + 1)).toString());

        if(locationsList.front() == location)
            return;
    }

    if(locationsCount <= 2)
    {
        setValue("locations/count", ++locationsCount);
        setValue("locations/" + QString::number(locationsCount), location);
        locationsList.push_front(value("locations/" + QString::number(locationsCount)).toString());
    }
    else
    {
        if(!locationsList.isEmpty())
        {
            locationsList.pop_back();
            locationsList.push_front(location);
        }

        for(int i = 0; i < locationsCount; ++i)
            setValue("locations/" + QString::number(i + 1), locationsList[locationsCount - i - 1]);
    }
}

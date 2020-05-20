#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class Settings: public QSettings
{
public slots:
   void saveLocation(const QString &location);
   QStringList getLocations() const;
};

#endif // SETTINGS_H

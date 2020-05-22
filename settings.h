#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class Settings: public QSettings
{
public slots:
    /*!
     * \brief save all the most recent locations, up to 6 locations
     */
   void saveLocation(const QString &location);
   /*!
    * \brief get all the most recent locations
    * \return the most recent locations
    */
   QStringList getLocations() const;
};

#endif // SETTINGS_H

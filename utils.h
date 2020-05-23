#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QDateTime>

namespace Utils
{
/*!
 * \brief The Time struct holds current time info
 */
struct Time
{
    Time (const QString& d, const QString& m, const QString& y) :
        day(d), month(m), year(y)
    {}

    QString day, month, year;
};

/*!
 * \brief converts unix time digits into hunman readable time
 * \param unixTime
 * \return current time info in Time struct
 */
static const Time timeStrFromUnixTime(unsigned int unixTime)
{
    QDateTime timestamp;
    timestamp.setTime_t(unixTime);

    return Time(timestamp.toString("dd"), timestamp.toString("MM"), timestamp.toString("yyyy"));
}
};

#endif // UTILS_H


#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QTranslator>

#include "clogger.h"

cLogger::cLogger()
{
    m_qsFileName    = "childminders.log";
}

cLogger::~cLogger()
{

}

void cLogger::_writeToLog( const QString &p_qsMessage )
{
    QFile file( m_qsFileName );

    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << p_qsMessage << "\n";

    file.close();
}

QString cLogger::_currentDateTime() const
{
    return QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
}

void cLogger::storeUserLogin( const QString &p_qsUserName )
{
    _writeToLog( QString("%1\t%2\tUser logged in").arg(_currentDateTime()).arg(p_qsUserName) );
}

void cLogger::storeApplicationStarted()
{
    _writeToLog( QString("%1\t\tApplication started").arg(_currentDateTime()) );
}

void cLogger::storeApplicationHalted( const QString &p_qsUserName )
{
    _writeToLog( QString("%1\t%2\tApplication stopped").arg(_currentDateTime()).arg(p_qsUserName) );
}


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

void cLogger::storeUserLogin( const QString &p_qsUserName )
{
    _writeToLog( QString("User: <%1> logged in at %2").arg(p_qsUserName).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")) );
}

void cLogger::storeApplicationStarted( const QString &p_qsUserName )
{
    _writeToLog( QString("User: <%1> started the application at %2").arg(p_qsUserName).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")) );
}

void cLogger::storeApplicationHalted( const QString &p_qsUserName )
{
    _writeToLog( QString("User: <%1> halted the application at %2").arg(p_qsUserName).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")) );
}

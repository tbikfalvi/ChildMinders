
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
    _writeToLog( QString("%1 - User: <%2> logged in").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(p_qsUserName) );
}

void cLogger::storeApplicationStarted( const QString &p_qsUserName )
{
    _writeToLog( QString("%1 - User: <%2> started the application").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(p_qsUserName) );
}

void cLogger::storeApplicationHalted( const QString &p_qsUserName )
{
    _writeToLog( QString("%1 - User: <%2> halted the application").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(p_qsUserName) );
}

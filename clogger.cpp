//====================================================================================
//
// Child Minders alkalmazas (c) Pagony Multimedia Studio Bt - 2011
//
//====================================================================================
//
// Filename    : clogger.cpp
// AppVersion  : 1.0
// FileVersion : 1.0
// Author      : Bikfalvi Tamas
//
//====================================================================================
// Source file for logging class.
//====================================================================================

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QTranslator>

#include "childminders.h"
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
    out << _currentDateTime() << "\t" << p_qsMessage << "\n";

    file.close();
}

QString cLogger::_currentDateTime() const
{
    return QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
}

void cLogger::storeUserLogin( const QString &p_qsUserName )
{
    _writeToLog( QString("%1\tUser logged in").arg(p_qsUserName) );
}

void cLogger::storeApplicationStarted()
{
    _writeToLog( QString("\tApplication started") );
    g_poPrefs->setCurrentUser( "", true );
}

void cLogger::storeApplicationHalted( const QString &p_qsUserName )
{
    _writeToLog( QString("%1\tApplication stopped").arg(p_qsUserName) );
}

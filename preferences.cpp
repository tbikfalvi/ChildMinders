//====================================================================================
//
// Child Minders alkalmazas (c) Pagony Multimedia Studio Bt - 2011
//
//====================================================================================
//
// Filename    : preferences.cpp
// AppVersion  : 1.0
// FileVersion : 1.0
// Author      : Bikfalvi Tamas
//
//====================================================================================
// Alkalmazas beallitasok allomanya.
//====================================================================================

#include "preferences.h"

cPreferences::cPreferences()
{
    init();
}

cPreferences::cPreferences( const QString &p_qsFileName )
{
    init();
    setFileName( p_qsFileName );
    loadConfFileSettings();
}

cPreferences::~cPreferences()
{
}

void cPreferences::init()
{
    m_qsFileName            = "";
    m_qsCurrentUser         = "";
}

void cPreferences::setFileName( const QString &p_qsFileName )
{
    m_qsFileName = p_qsFileName;
}

QString cPreferences::getFileName() const
{
    return m_qsFileName;
}

void cPreferences::loadConfFileSettings()
{
    QSettings obPrefFile( m_qsFileName, QSettings::IniFormat );

    if( obPrefFile.status() != QSettings::NoError )
    {
//        g_obLogger(cSeverity::WARNING) << "Failed to load preferences from file: " << m_qsFileName << EOM;
    }
    else
    {
        m_qsCurrentUser = obPrefFile.value( QString::fromAscii( "Logging/CurrentUser" ), "" ).toString();
    }
}

void cPreferences::save()
{
    QSettings  obPrefFile( m_qsFileName, QSettings::IniFormat );

    obPrefFile.setValue( QString::fromAscii( "Logging/CurrentUser" ), m_qsCurrentUser );
}

QString cPreferences::getCurrentUser() const
{
    return m_qsCurrentUser;
}

void cPreferences::setCurrentUser( const QString &p_qsUserName, bool p_boSaveNow )
{
    m_qsCurrentUser = p_qsUserName;

    if( p_boSaveNow )
    {
        QSettings  obPrefFile( m_qsFileName, QSettings::IniFormat );
        obPrefFile.setValue( QString::fromAscii( "Logging/CurrentUser" ), m_qsCurrentUser );
    }
}

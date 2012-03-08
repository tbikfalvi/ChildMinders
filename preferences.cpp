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
    m_qsFileName        = "";
    m_qsCurrentUser     = "";

    m_qslUsersList.clear();
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
        QString m_qsUser = obPrefFile.value( QString::fromAscii( "Users" ), "" ).toString();

        if( m_qsUser.length() > 0 )
        {
            m_qslUsersList = m_qsUser.split( QChar('#') );
        }
    }
}

void cPreferences::save()
{
    QSettings  obPrefFile( m_qsFileName, QSettings::IniFormat );

    obPrefFile.setValue( QString::fromAscii( "Logging/CurrentUser" ), m_qsCurrentUser );
    obPrefFile.setValue( QString::fromAscii( "Users" ), m_qslUsersList.join( QChar('#') ) );
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

QString cPreferences::getUserDisplayName( const QString &p_qsUserName ) const
{
    QSettings   obPrefFile( m_qsFileName, QSettings::IniFormat );
    QString     qsDisplayName = p_qsUserName;

    if( obPrefFile.status() == QSettings::NoError )
    {
        qsDisplayName = obPrefFile.value( QString( "%1/DisplayName" ).arg(p_qsUserName), p_qsUserName ).toString();
    }
    return qsDisplayName;
}

QDateTime cPreferences::getUserLastLogin( const QString &p_qsUserName ) const
{
    QSettings   obPrefFile( m_qsFileName, QSettings::IniFormat );
    QDateTime   qdtLastLogin( QDateTime::fromString("2000.01.01. 0:00:00","yyyy.MM.dd. H:mm:ss") );

    if( obPrefFile.status() == QSettings::NoError )
    {
        qdtLastLogin = QDateTime::fromString( obPrefFile.value( QString( "%1/LastLogin" ).arg(p_qsUserName), "2000.01.01. 0:00:00" ).toString(), "yyyy.MM.dd. H:mm:ss" );
    }
    return qdtLastLogin;
}

void cPreferences::setUserData( const QString &p_qsUserName, const QString &p_qsUserDisplayName, const QDateTime &qdtLastLogin ) const
{
    QSettings   obPrefFile( m_qsFileName, QSettings::IniFormat );

    if( p_qsUserDisplayName.length() )
        obPrefFile.setValue( QString( "%1/DisplayName" ).arg(p_qsUserName), p_qsUserDisplayName );
    obPrefFile.setValue( QString( "%1/LastLogin" ).arg(p_qsUserName), qdtLastLogin.toString( "yyyy.MM.dd. H:mm:ss" ) );
}

QStringList cPreferences::getUserList() const
{
    return m_qslUsersList;
}

void cPreferences::addUserToList( const QString &p_qsUserName )
{
    if( m_qslUsersList.contains( p_qsUserName, Qt::CaseInsensitive ) )
        return;

    m_qslUsersList << p_qsUserName;

    save();
}

void cPreferences::removeUserFromList( const QString &p_qsUserName )
{
    if( !m_qslUsersList.contains( p_qsUserName, Qt::CaseInsensitive ) )
        return;

    m_qslUsersList.removeAt( m_qslUsersList.indexOf( p_qsUserName ) );

    save();
}


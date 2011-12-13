//====================================================================================
//
// Child Minders alkalmazas (c) Pagony Multimedia Studio Bt - 2011
//
//====================================================================================
//
// Filename    : preferences.h
// AppVersion  : 1.0
// FileVersion : 1.0
// Author      : Bikfalvi Tamas
//
//====================================================================================
// Alkalmazas beallitasok allomanya.
//====================================================================================

#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QString>
#include <QSettings>
#include <QDateTime>

class cPreferences
{
public:
    cPreferences();
    cPreferences( const QString &p_qsFileName );
    ~cPreferences();

    void            setFileName( const QString &p_qsFileName );
    QString         getFileName() const;

    void            loadConfFileSettings();
    void            save();

    QString         getCurrentUser() const;
    void            setCurrentUser( const QString &p_qsUserName, bool p_boSaveNow = false );
    QString         getUserDisplayName( const QString &p_qsUserName ) const;
    QDateTime       getUserLastLogin( const QString &p_qsUserName ) const;
    void            setUserData( const QString &p_qsUserName, const QString &p_qsUserDisplayName, const QDateTime &qdtLastLogin ) const;

private:
    QString         m_qsFileName;
    QString         m_qsCurrentUser;

    void init();
};

#endif

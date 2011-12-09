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

private:
    QString         m_qsFileName;
    QString         m_qsCurrentUser;

    void init();
};

#endif

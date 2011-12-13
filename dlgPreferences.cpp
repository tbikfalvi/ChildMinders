//====================================================================================
//
// Child Minders alkalmazas (c) Pagony Multimedia Studio Bt - 2011
//
//====================================================================================
//
// Filename    : dlgPreferences.cpp
// AppVersion  : 1.0
// FileVersion : 1.0
// Author      : Bikfalvi Tamas
//
//====================================================================================
// Sourc file for Preferences dialog.
//====================================================================================

#include <QMessageBox>
#include <QPushButton>

//====================================================================================

#include "windows.h"

#include "childminders.h"
#include "dlgPreferences.h"

//====================================================================================
cDlgPreferences::cDlgPreferences( QWidget *p_poParent )
    : QDialog( p_poParent )
{
    setupUi( this );

    m_poPreferencesAction = new QAction( tr( "Edit Preferences" ), this );
    connect( m_poPreferencesAction, SIGNAL( triggered() ), this, SLOT( show() ) );

    m_poQuitAction = new QAction( tr( "Quit" ), this );
    connect( m_poQuitAction, SIGNAL( triggered() ), qApp, SLOT( quit() ) );

    m_poTrayIconMenu = new QMenu( this );
    m_poTrayIconMenu->addAction( m_poPreferencesAction );
    m_poTrayIconMenu->addSeparator();
    m_poTrayIconMenu->addAction( m_poQuitAction );

    m_poTrayIcon = new QSystemTrayIcon( this );
    m_poTrayIcon->setContextMenu( m_poTrayIconMenu );
    m_poTrayIcon->setIcon( QIcon( ":/icons/resources/childminders.ico" ) );
    m_poTrayIcon->setVisible( true );
    m_poTrayIcon->setToolTip( tr("Child minders application\nTo protect you and your children ...") );

    m_bDataChanged = false;

    m_bChangedGeneral = false;
    m_bChangedLogging = false;
}
//====================================================================================
void cDlgPreferences::showEvent(QShowEvent *event)
{

    QDialog::showEvent(event);
}
//====================================================================================
void cDlgPreferences::setIconToolTip( const QString &p_qsToolTip )
{
    m_poTrayIcon->setToolTip( p_qsToolTip );
}
//====================================================================================
void cDlgPreferences::accept()
{

    QDialog::accept();
}
//====================================================================================
void cDlgPreferences::setGeneralTabData( const QString &p_qsLoginName, const QString &p_qsDisplayName, const QDateTime &p_qdtLastLogin )
{
    m_bDataChanged = true;

    if( p_qsLoginName.length() ) ledLoginName->setText( p_qsLoginName );
    if( p_qsDisplayName.length() ) ledDisplayName->setText( p_qsDisplayName );
    dtLastLogin->setDateTime( p_qdtLastLogin );

    m_bDataChanged = false;
}
//====================================================================================
QString cDlgPreferences::currentUserName() const
{
    CHAR    strName[256];
    DWORD   dwBuffer = 256;

    GetUserNameA(strName, &dwBuffer);
    QString qsUserName = QString( strName );

    return qsUserName;
}
//====================================================================================
void cDlgPreferences::on_ledDisplayName_textChanged(QString )
{
    if( m_bDataChanged ) return;

    m_bChangedGeneral = true;
    pbApplyGeneral->setEnabled( m_bChangedGeneral );
}
//====================================================================================
void cDlgPreferences::on_pbApplyGeneral_clicked()
{
    if( ledDisplayName->text().length() == 0 )
        ledDisplayName->setText( currentUserName() );

    g_poPrefs->setUserData( currentUserName(), ledDisplayName->text(), dtLastLogin->dateTime() );

    m_bChangedGeneral = false;
    pbApplyGeneral->setEnabled( m_bChangedGeneral );
}
//====================================================================================
void cDlgPreferences::on_chkLogToFile_clicked()
{
    if( m_bDataChanged ) return;

    m_bChangedLogging = true;
    pbApplyLogging->setEnabled( m_bChangedLogging );
}
//====================================================================================
void cDlgPreferences::on_checkBox_clicked()
{
    if( m_bDataChanged ) return;

    m_bChangedLogging = true;
    pbApplyLogging->setEnabled( m_bChangedLogging );
}
//====================================================================================
void cDlgPreferences::on_pbApplyLogging_clicked()
{
    if( !chkLogToFile->isChecked() && !chkDatabase->isChecked() )
    {
        QMessageBox::warning( this, tr("Attention"), "One of the logging mechanism has to be selected!" );
        return;
    }

    m_bChangedLogging = false;
    pbApplyLogging->setEnabled( m_bChangedLogging );
}
//====================================================================================

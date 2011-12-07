#include <QMessageBox>
#include <QPushButton>

#include "windows.h"

#include "dlgpreferences.h"

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
}

void cDlgPreferences::setIconToolTip( const QString &p_qsToolTip )
{
    m_poTrayIcon->setToolTip( p_qsToolTip );
}

void cDlgPreferences::accept()
{

    QDialog::accept();
}

QString cDlgPreferences::currentUserName() const
{
    CHAR    strName[256];
    DWORD   dwBuffer = 256;

    GetUserNameA(strName, &dwBuffer);
    QString qsUserName = QString( strName );

    return qsUserName;
}

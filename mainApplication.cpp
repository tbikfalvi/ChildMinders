
#include <QString>

#include "childminders.h"
#include "mainApplication.h"
#include "preferences.h"

cMainApplication::cMainApplication( int &argc, char **argv ) : QApplication( argc, argv )
{
    m_poMainDlg     = NULL;
    m_inTimerId     = 0;
    m_qsIniUserName = "";

    connect( this, SIGNAL( aboutToQuit() ), this, SLOT( endSession() ) );
}

cMainApplication::~cMainApplication()
{
}

void cMainApplication::startSession( cDlgPreferences *p_poMainDlg ) throw()
{
    m_poMainDlg = p_poMainDlg;
    m_qsIniUserName = g_poPrefs->getCurrentUser();
    g_obLog->storeApplicationStarted();

    m_inTimerId = startTimer( 1000 );
}

void cMainApplication::endSession() throw()
{
    killTimer( m_inTimerId );
    g_obLog->storeApplicationHalted( m_qsIniUserName );
}

void cMainApplication::timerEvent ( QTimerEvent * )
{
    // Checking current user
    // If user provided by windows is not the same
    // that stored in ini file then save windows user
    // and log current user's login
    QString qsWinUserName = m_poMainDlg->currentUserName();

    if( m_qsIniUserName.compare( qsWinUserName ) )
    {
        g_poPrefs->setCurrentUser( qsWinUserName, true );
        m_qsIniUserName = qsWinUserName;
        g_obLog->storeUserLogin( m_qsIniUserName );
    }
}


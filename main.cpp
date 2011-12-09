
#include <QtGui>
#include <QApplication>
#include <QString>
#include <QMessageBox>

//====================================================================================

#include "windows.h"

#include "childminders.h"
#include "preferences.h"
#include "mainApplication.h"
#include "dlgPreferences.h"
#include "clogger.h"

//====================================================================================

using namespace std;

//====================================================================================

cPreferences            *g_poPrefs;
cLogger                 *g_obLog;

//====================================================================================
int main(int argc, char *argv[])
{
    int  inRetVal = 1;

    cMainApplication    apMainApp( argc, argv );

    g_poPrefs  = new cPreferences( QString::fromAscii( "./childminders.ini" ) );
    g_obLog = new cLogger();

    try
    {
        bool          boSysTrayFound = false;
        unsigned int  uiCheckCounter = 0;

        while( !boSysTrayFound && uiCheckCounter++ < 20 )
        {
            boSysTrayFound = QSystemTrayIcon::isSystemTrayAvailable();
            if( !boSysTrayFound ) Sleep( 5 );
        }
        if( !boSysTrayFound )
        {
//            throw cSevException( cSeverity::ERROR, "Couldn't detect any system tray on this system." );
        }

        cMainApplication::setQuitOnLastWindowClosed( false );

        cDlgPreferences  obMainWindow;

        apMainApp.startSession( &obMainWindow );
        inRetVal = apMainApp.exec();
    }
    catch(std::exception &e)
    {
        inRetVal = 999;
    }

    return inRetVal;
}
//====================================================================================

#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QtGui/QApplication>
#include "dlgPreferences.h"

class cMainApplication : public QApplication
{
    Q_OBJECT
public:
    cMainApplication( int &argc, char **argv );
    ~cMainApplication();

    void            startSession( cDlgPreferences *p_poMainDlg )   throw();

public slots:
    void endSession()     throw();

protected:
    void timerEvent ( QTimerEvent *p_poEvent );

private:
    cDlgPreferences *m_poMainDlg;
    int              m_inTimerId;
    QString          m_qsIniUserName;
    QString          m_qsFileName;
};

#endif // MAINWINDOW_H

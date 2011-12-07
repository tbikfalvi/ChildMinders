#ifndef CLOGGER_H
#define CLOGGER_H

#include <QString>

class cLogger
{
public:
    cLogger();
    ~cLogger();

    void    storeUserLogin( const QString &p_qsUserName );
    void    storeApplicationStarted( const QString &p_qsUserName );
    void    storeApplicationHalted( const QString &p_qsUserName );

private:
    QString     m_qsFileName;

    void        _writeToLog( const QString &p_qsMessage );
};

#endif // CLOGGER_H

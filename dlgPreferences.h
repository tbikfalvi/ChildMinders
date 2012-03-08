#ifndef DLGPREFERENCES_H
#define DLGPREFERENCES_H

#include <QAction>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QCheckBox>
#include <vector>

#include "../ChildMinders-build-desktop/ui_dlgpreferences.h"

class cDlgPreferences : public QDialog, private Ui::dlgPreferences
{
    Q_OBJECT

public:
    cDlgPreferences( QWidget *p_poParent = 0 );

    void                    setIconToolTip( const QString &p_qsToolTip );
    QString                 currentUserName() const;

    void                    setGeneralTabData( const QString &p_qsLoginName, const QString &p_qsDisplayName, const QDateTime &p_qdtLastLogin );

public slots:
    virtual void accept();

private:
    QAction                 *m_poPreferencesAction;
    QAction                 *m_poTasksAction;
    QAction                 *m_poQuitAction;

    QSystemTrayIcon         *m_poTrayIcon;
    QMenu                   *m_poTrayIconMenu;

    QString                  m_qsUserName;

    bool                     m_bDataChanged;

    bool                     m_bChangedGeneral;
    bool                     m_bChangedLogging;

    std::vector<QCheckBox*> *m_vCheckUsers;

private slots:
    void on_pbApplyLogging_clicked();
    void on_pbApplyGeneral_clicked();
    void on_checkBox_clicked();
    void on_chkLogToFile_clicked();
    void on_ledDisplayName_textChanged(QString );
    void showEvent(QShowEvent *event);

};

#endif

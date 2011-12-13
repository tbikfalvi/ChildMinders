#====================================================================================
#
# Child Minders alkalmazas (c) Pagony Multimedia Studio Bt - 2011
#
#====================================================================================
#
# Filename    : childminders.pro
# AppVersion  : 1.0
# FileVersion : 1.0
# Author      : Bikfalvi Tamas
#
#====================================================================================
# Project file for childminders application
#====================================================================================

TEMPLATE = app
QT      += core gui
TARGET   = ChildMinders
#====================================================================================
SOURCES += \
    main.cpp \
    mainApplication.cpp \
    dlgPreferences.cpp \
    preferences.cpp \
    clogger.cpp
#====================================================================================
HEADERS += \
    childminders.h \
    mainApplication.h \
    dlgPreferences.h \
    preferences.h \
    clogger.h
#====================================================================================
FORMS += \
    dlgpreferences.ui
#====================================================================================
RESOURCES  += \
    childminders.qrc
#====================================================================================
RC_FILE = childminders.rc
#====================================================================================


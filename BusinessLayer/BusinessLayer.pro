TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
   error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
   BusinessContainer.h \
   CommunicationsMonitoringService/CommunicationsMonitoringService.h \
   CommunicationsMonitoringService/I_CommunicationsMonitoringService.h \
   LoggerService/LoggerService.h \

SOURCES += \
   BusinessContainer.cpp \
   CommunicationsMonitoringService/CommunicationsMonitoringService.cpp \
   LoggerService/LoggerService.cpp \

#pragma once

#include <QScopedPointer>

class DataContainer;
class CommunicationContainerPrivate;
class ConnectionController;

class I_PacketSynchronizer;
class I_PacketDecoder;
class I_PacketChecksumChecker;
class I_DataInjectionService;
class RadioConnectionService;
class UdpConnectionService;
class UdpMessageForwarder;

class CommunicationContainer
{
public:
   explicit CommunicationContainer(DataContainer& dataContainer);
   ~CommunicationContainer();

   I_PacketSynchronizer& packetSynchronizer();
   I_PacketDecoder& packetDecoder();
   I_PacketChecksumChecker& packetChecksumChecker();
   I_DataInjectionService& dataInjectionService();
   ConnectionController& connectionController();
   RadioConnectionService& radioConnectionService();
   UdpConnectionService& udpConnectionService();
   UdpMessageForwarder& messageForwarder();

private:
   // This is using the PIMPL design pattern, refer to http://c2.com/cgi/wiki?PimplIdiom
   QScopedPointer<CommunicationContainerPrivate> impl_;
};

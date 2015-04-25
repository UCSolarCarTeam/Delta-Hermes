#pragma once

#include <QIODevice>
#include "I_PacketSynchronizer.h"
class I_ConnectionService;

class PacketSynchronizer : public I_PacketSynchronizer
{
   Q_OBJECT
public:
   PacketSynchronizer(QIODevice& inputDevice,
      I_ConnectionService& connectionService);
   virtual ~PacketSynchronizer();

private slots:
   void handleConnectionCreated();
   void handleIncommingSerialData();

private:
   bool alignStartOfPacketToBeginningOfBuffer();
   bool extractPacketIfIsComplete();

private:
   QIODevice& inputDevice_;
   QByteArray buffer_;
};

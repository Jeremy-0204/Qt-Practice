#include "superlumbs840vm.h"
MGEN_NAMESPACE_START

SuperlumBS840VM :: SuperlumBS840VM(QObject *parent) : mSuperlumBS840()
{}

SuperlumBS840VM :: ~SuperlumBS840VM()
{}

bool SuperlumBS840VM :: onClickedConnect(const QString &portName, int baudRate, const QString &flowControl, const QString &parity, const QString &dataBits, const QString &stopBits)
{
    mSuperlumBS840.connectPort(portName, baudRate, flowControl, parity, dataBits, stopBits);
}

bool SuperlumBS840VM :: onClickedClose()
{
    mSuperlumBS840.close();
}





MGEN_NAMESPACE_END

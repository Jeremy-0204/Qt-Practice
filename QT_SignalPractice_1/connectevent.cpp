#include "connectevent.hpp"

//ConnectEvent::ConnectEvent(QObject *parent)
//    : QObject{parent}
//{

//}

ConnectEvent :: ConnectEvent()
{}

ConnectEvent :: ~ConnectEvent()
{}

void ConnectEvent :: CppSignalToQmlSlot()
{
    QObject :: connect(this, SIGNAL(CppSignalTestData(QVariant)), mMainView, SLOT(qmlSlotTestData(QVariant))); // 시그널과 슬롯의 connection

    emit CppSignalTestData(3);
    emit CppSignalTestData(4);
    emit CppSignalTestData(5);
    emit CppSignalTestData(6);
}

void ConnectEvent ::SetWindow(QQuickWindow* Window)
{
    mMainView = Window;

    CppSignalToQmlSlot();
}

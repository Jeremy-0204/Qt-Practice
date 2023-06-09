#include "connectevent.h"
#include "qquickitem.h"
#include <iostream>
#include <windows.h>
using namespace std;

ConnectEvent :: ConnectEvent()
{}

ConnectEvent :: ~ConnectEvent()
{}

void ConnectEvent :: CppSignalToQmlSlot()
{
    QObject :: connect(this, SIGNAL(CppSignalFunction(QVariant)), mMainView, SLOT(qmlSlotFunction(QVariant)));
    QObject :: connect(mMainView, SIGNAL(qmlSignalString(QVariant)), this, SLOT(CppSlotStringData(QVariant)));
    QObject :: connect(mMainView, SIGNAL(qmlSignalInt(QVariant)), this, SLOT(CppSlotIntdata(QVariant)));

    Sleep(2000);
    emit CppSignalFunction("I am signal sent from CPP");
}

void ConnectEvent :: SetWindow(QQuickWindow* Window)
{
    mMainView = Window;

    CppSignalToQmlSlot();

    //CppSignalToQmlSlot(Window);
}
void ConnectEvent::CppSlotStringData(QVariant StringData)
{
    cout << "CppSlotStringData called" << endl;
    string data_str = StringData.toString().toStdString();

//    if (mMainView)
//    {
//        QQuickItem *signalresponse = mMainView->findChild<QQuickItem*>("signalresponse");
//        if (signalresponse)
//        {
//            signalresponse->setProperty("text", StringData.toString());
//        }
//    }

    if (mMainView)
    {
        QMetaObject::invokeMethod(mMainView, "updateSignalResponse", Q_ARG(QVariant, StringData));
        QMetaObject::invokeMethod(mMainView, "openDialog", Q_ARG(QVariant, StringData));
    }

    cout << "Received: " + data_str << endl;
}



void ConnectEvent :: CppSlotIntdata(QVariant IntData)
{
    cout << "CppSlotIntData called" << endl;
    int data_int = IntData.toInt();

    if (mMainView)
    {
        QMetaObject::invokeMethod(mMainView, "updateSignalResponse", Q_ARG(QVariant, IntData));
        QMetaObject::invokeMethod(mMainView, "openDialog", Q_ARG(QVariant, IntData));
    }
    cout << "Received : " << data_int << endl;
}

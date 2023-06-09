#ifndef CONNECTEVENT_H
#define CONNECTEVENT_H

#include <QObject>
#include <QQuickView>

class ConnectEvent : public QObject
{
    Q_OBJECT
public:
    ConnectEvent();
    ~ConnectEvent();

    void CppSignalToQmlSlot();
    void SetWindow(QQuickWindow* Window);

private:
    QQuickWindow* mMainView;


signals:
    void CppSignalFunction(QVariant);

public slots:
    void CppSlotStringData(QVariant StringData);
    void CppSlotIntdata(QVariant IntData);
};

#endif // CONNECTEVENT_H

#ifndef CONNECTEVENT_HPP
#define CONNECTEVENT_HPP

#include <QQuickView>
#include <QObject>

class ConnectEvent : public QObject
{
    Q_OBJECT
public:
    //explicit ConnectEvent(QObject *parent = nullptr);
    ConnectEvent();
    ~ConnectEvent();

    void CppSignalToQmlSlot();
    void SetWindow(QQuickWindow* Window);

private:
    QQuickWindow* mMainView;

signals:
    void CppSignalTestData(QVariant);
};

#endif // CONNECTEVENT_HPP

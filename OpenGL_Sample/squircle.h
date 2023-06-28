#ifndef SQUIRCLE_H
#define SQUIRCLE_H
#include <QQuickItem>
#include <QRunnable>
#include <QQuickWindow>
#include <squirclerenderer.h>

class Squircle : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(qreal t READ t WRITE setT NOTIFY tChanged)
    QML_ELEMENT

public:
    Squircle();

    qreal t() const { return m_t; }
    void setT(qreal t);

signals:
    void tChanged();

public slots:
    void sync();
    void cleanup();

private slots:
    void handleWindowChanged(QQuickWindow *win);

private:
    void releaseResources() override;

    qreal m_t;
    SquircleRenderer *m_renderer;
};

#endif // SQUIRCLE_H

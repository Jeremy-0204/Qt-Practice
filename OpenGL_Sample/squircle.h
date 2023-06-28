//#ifndef SQUIRCLE_H
//#define SQUIRCLE_H
//#include <QQuickItem>
//#include <QRunnable>
//#include <QQuickWindow>
//#include <squirclerenderer.h>

//class Squircle : public QQuickItem
//{
//    Q_OBJECT
//    Q_PROPERTY(qreal t READ t WRITE setT NOTIFY tChanged)
//    QML_ELEMENT

//public:
//    Squircle();

//    qreal t() const { return m_t; }
//    void setT(qreal t);

//signals:
//    void tChanged();

//public slots:
//    void sync();
//    void cleanup();

//private slots:
//    void handleWindowChanged(QQuickWindow *win);

//private:
//    void releaseResources() override;

//    qreal m_t;
//    SquircleRenderer *m_renderer;
//};

//#endif // SQUIRCLE_H


#ifndef SQUIRCLE_H
#define SQUIRCLE_H

#include <QtQuick/QQuickItem>
#include <QOpenGLShaderProgram>
#include <QtGui/QOpenGLFunctions>



//! [1]
class SquircleRenderer : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    SquircleRenderer() : m_t(0), m_program(0) { }
    ~SquircleRenderer();

    void setT(qreal t) { m_t = t; }
    void setViewportSize(const QSize &size) { m_viewportSize = size; }
    void setWindow(QQuickWindow *window) { m_window = window; }

public slots:
    void init();
    void paint();

private:
    QSize m_viewportSize;
    qreal m_t;
    QOpenGLShaderProgram *m_program;
    QQuickWindow *m_window;
};
//! [1]

//! [2]
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
//! [2]

#endif // SQUIRCLE_H

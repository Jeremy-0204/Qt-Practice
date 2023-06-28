#ifndef SQUIRCLERENDERER_H
#define SQUIRCLERENDERER_H

#include <QQuickItem>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QSGRendererInterface>
#include <QQuickWindow>

class SquircleRenderer : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    ~SquircleRenderer();

    void setT(qreal t) { m_t = t; }
    void setViewportSize(const QSize &size) { m_viewportSize = size; }
    void setWindow(QQuickWindow *window) { m_window = window; }

public slots:
    void init();
    void paint();

private:
    QSize m_viewportSize;
    qreal m_t = 0.0;
    QOpenGLShaderProgram *m_program = nullptr;
    QQuickWindow *m_window = nullptr;
};

#endif // SQUIRCLERENDERER_H

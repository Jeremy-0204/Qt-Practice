#ifndef OPENGLTRIANGLEITEM_H
#define OPENGLTRIANGLEITEM_H

#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

class OpenGLTriangleItem : public QQuickFramebufferObject, public QQuickFramebufferObject::Renderer//, protected QOpenGLFunctions
{
public:
    OpenGLTriangleItem();
    ~OpenGLTriangleItem();

    virtual QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;

    virtual void render() override;

    void initializeOpenGL();

protected:
    QOpenGLFunctions mGLFunc;
};

#endif // OPENGLTRIANGLEITEM_H

#ifndef OPENGLTRIANGLEITEM_H
#define OPENGLTRIANGLEITEM_H

#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

class OpenGLTriangleItem : public QQuickFramebufferObject, protected QOpenGLFunctions
{
public:
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size);
    void render();

protected:
    void initializeOpenGL();
};

#endif // OPENGLTRIANGLEITEM_H

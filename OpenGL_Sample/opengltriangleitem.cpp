#include "opengltriangleitem.h"
#include <QOpenGLFramebufferObject>
#include <QOpenGLShaderProgram>

QOpenGLFramebufferObject *OpenGLTriangleItem::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    return new QOpenGLFramebufferObject(size, format);
}

void OpenGLTriangleItem::initializeOpenGL()
{
    initializeOpenGLFunctions();
}

void OpenGLTriangleItem::render()
{
    // Set up the OpenGL rendering

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glViewport(0, 0, width(), height());

    // Notify QML that the frame is ready to be displayed

    update();
}

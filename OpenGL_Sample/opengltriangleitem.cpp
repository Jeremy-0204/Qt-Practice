#include "opengltriangleitem.h"
#include <QOpenGLFramebufferObject>
#include <QOpenGLShaderProgram>
#include <QDebug>

OpenGLTriangleItem::OpenGLTriangleItem()
{

}

OpenGLTriangleItem::~OpenGLTriangleItem()
{

}

QOpenGLFramebufferObject *OpenGLTriangleItem::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    return new QOpenGLFramebufferObject(size, format);
}

void OpenGLTriangleItem::initializeOpenGL()
{
    mGLFunc.initializeOpenGLFunctions();
    qDebug() << "INITIALIZED CALLED";
}

void OpenGLTriangleItem::render()
{
    // Set up the OpenGL rendering
    qDebug() << "RENDER CALLED";

    mGLFunc.glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    mGLFunc.glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    mGLFunc.glBindFramebuffer(GL_FRAMEBUFFER, 0);
    mGLFunc.glBindTexture(GL_TEXTURE_2D, 0);
    mGLFunc.glViewport(0, 0, width(), height());

    // Notify QML that the frame is ready to be displayed

    QQuickFramebufferObject::update();
}

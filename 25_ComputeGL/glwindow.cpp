#include "glwindow.h"
#include <QtCore>
#include <QDebug>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLExtraFunctions>
#include <QOpenGLTexture>

GLWindow::GLWindow()
    :m_isCoreHasCompute(false),
     m_isAnimationForward(true),
     m_blurCur(0.0f),
     m_blurMin(0.0f),
     m_blurMax(1.0f),
     m_blurStep(0.01f),
     m_fpsCounter(0)
{
    m_Timer = new QTimer(this);
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(updateFPS()));
    m_Timer->start(1000);
}

GLWindow::~GLWindow()
{
    m_Timer->stop();
}
void
GLWindow::updateFPS()
{
    qInfo() << "FPS:" << m_fpsCounter;
    m_fpsCounter = 0;
}
void
GLWindow::initializeGL(){
    QOpenGLContext* ctx = QOpenGLContext::currentContext();
    if (ctx->isValid()){
        if ((ctx->format().majorVersion() == 4) & (ctx->format().minorVersion()==2)){
            if (!ctx->hasExtension("GL_ARB_compute_shader")){
                qErrnoWarning("Desktop GL 4.2 don't support Compute functionality, exiting..");
                return;
            } else {
                qInfo("Our last chance - GL_ARB_compute_shader on GL 4.2");
                m_isCoreHasCompute = true;
            }
        } else {
            qInfo("GL with Compute functionality granted");
        }
    }
    connect(this,&QOpenGLWindow::frameSwapped,
            this, QOverload<>::of(&QOpenGLWindow::update));

    QImage img(":/res/512x512.png");
    if (img.isNull()){
        qErrnoWarning("test image missed, exiting..");
        return;
    } else {
        qInfo() << "test image " << img.width() <<"x" << img.height();
    }
    m_textImageInput = new QOpenGLTexture(img.convertToFormat(QImage::Format_RGBA8888).mirrored());
}


void
GLWindow::paintGL(){
    QOpenGLExtraFunctions *f = QOpenGLContext::currentContext()->extraFunctions();

    f->glClearColor(0, m_blurCur, 0, 1);
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //f->glDispatchCompute(8,8,1); //no ARB prefix required fof ARB_compute_shader
    updateAnimParams();
}


void
GLWindow::updateAnimParams()
{
    if(m_isAnimationForward){
        m_blurCur += m_blurStep;
        if (m_blurCur>m_blurMax){
            m_isAnimationForward=false;
        }
    } else {
        m_blurCur -= m_blurStep;
        if (m_blurCur<(m_blurMin+m_blurStep)){
            m_isAnimationForward=true;
        }
    }
    m_fpsCounter++;
}


void
GLWindow::resizeGL(int w, int h){

}

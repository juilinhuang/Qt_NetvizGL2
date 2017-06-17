#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include "inc/Graphs/Graph.h"
#include "inc/Command/glwindow.h"
#include "inc/Command/Command.h"
#include "testthread.h"

class GLWidget : public QOpenGLWidget, GLWindow
{
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    void test(QString filePath);

    void terminateThread();

    Graph *getGraph() override;
    char *getPath() override;
    void setGraph(Graph *g) override;
    void setPath(char *p) override;

    void degreeC();
    void distanceC();
    void betweennessC();

private:
    QTimer *timer;
    TestThread *t;
    Algorithm *algorithm;
    char* path;

    Command *c;

    double pitch, yaw, bank;
    double translateX, translateY, translateZ;
    double mouseX, mouseY, mouseDiffX, mouseDiffY;
    bool isMouseLeftDown, isMouseMiddleDown, isMouseRightDown;

    Graph *graph;


//    GLfloat vertex[9] = {+0.0, +0.0, +0.0,
//                         -0.5, -0.5, +0.0,
//                         +0.1, +0.1, +0.0};


};

#endif // GLWIDGET_H

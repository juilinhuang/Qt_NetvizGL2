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

    void changeAlgorithm(char a);
    void terminateThread();
    void setSelectedVertexColour(int r, int g, int b);

    Graph *getGraph() override;
    char *getPath() override;
    void setGraph(Graph *g) override;
    void setPath(char *p) override;
    int getWidth() override;
    int getHeight() override;
    double getMouseX() override;
    double getMouseY() override;
    void setSelectedNode(Vertex *v) override;
    Vertex *getSelectedNode() override;
    GLdouble getMouseDiffX() const override;
    GLdouble getMouseDiffY() const override;
    GLdouble getTranslateZ() const override;
    int getSelectedVertexNumber() const override;
    void setSelectedVertexNumber(int value) override;

    void loadGraph(char *p);

    void degreeC();
    void distanceC();
    void betweennessC();

    void saveScreenshot();
    void saveFile();



private:
    QTimer *timer;
    TestThread *t;
    char algorithm;
    char* path;

//    Command *c;
//    Command *sv;

//    GLdouble pitch, yaw, bank;
//    GLdouble translateX, translateY, translateZ;
//    GLdouble mouseX, mouseY, mouseDiffX, mouseDiffY;
//    bool isMouseLeftDown, isMouseMiddleDown, isMouseRightDown;
//    bool isKeyCtrlDown;


//    Graph *graph;
//    Vertex *selectedNode;

    QPixmap originalPixmap;


//    GLfloat vertex[9] = {+0.0, +0.0, +0.0,
//                         -0.5, -0.5, +0.0,
//                         +0.1, +0.1, +0.0};


};

#endif // GLWIDGET_H

#include "glwidget.h"
#include <QDebug>
#include <GL/glu.h>
#include <QTimer>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QCloseEvent>
#include "inc/Graphs/EdgeGraph.h"
#include "inc/Graphs/AdjacencyGraph.h"
#include "inc/Graphs/MatrixMarketGraph.h"
#include "inc/Algorithms/Algorithm.h"
#include "inc/Algorithms/FruchtermanReingold.h"
#include "inc/Algorithms/SimpleForceDirected.h"
#include "inc/Algorithms/MultiForce.h"
#include "inc/Command/LoadGraph.h"
#include "inc/Command/SelectVertex.h"
#include "inc/Centrality/DegreeCentrality.h"
#include "inc/Centrality/DistanceCentrality.h"
#include "inc/Centrality/Betweenness.h"
#include "testthread.h"


GLWidget::GLWidget(QWidget *parent):QOpenGLWidget(parent)
{
    setFocus();

    translateX = 0;
    translateY = 0;
    translateZ = 1.8;
    isMouseLeftDown = false;
    isMouseMiddleDown = false;
    isMouseRightDown = false;
    isKeyCtrlDown = false;

    c = new LoadGraph(this);
    sv = new SelectVertex(this);

    t = NULL;
    graph = NULL;
    selectedNode = NULL;
    changeAlgorithm("1");

    // update timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(20);
}

GLWidget::~GLWidget()
{
    delete timer;
    delete t;
//    delete algorithm;
    delete graph;
}

void GLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearColor(1, 1 ,1 ,1);
}

void GLWidget::paintGL()
{
    /*
     * ---draw here---
     */

    glViewport(0, 0, width(), height());

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluPerspective(45, (double)width()/(double)height(), 0.01, 10);
    glTranslatef(translateX, translateY, -translateZ);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

/*
//    glEnable(GL_LINE_SMOOTH);

//    glPointSize(30/(translateZ+0.84));
//    glLineWidth(1);

//    glVertexPointer(3, GL_FLOAT, 0, vertex);
//    glDrawArrays(GL_POINTS, 0, 1);
//    glDrawArrays(GL_LINE_LOOP, 0, 3);
*/

    /*
     * draw graph
     */
    if(graph!=NULL){
        graph->update();
        graph->draw();
    }

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    /*
     * ---end of drawing---
     */
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    mouseX = event->pos().x();
    mouseY = event->pos().y();
    if(event->button() & Qt::LeftButton){
        isMouseLeftDown = true;
    }
    if(event->button() & Qt::MiddleButton){
        isMouseMiddleDown = true;
    }
    if(event->button() & Qt::RightButton){
        glLoadIdentity();
        gluPerspective(45, (double)width()/(double)height(), 0.01, 10);
        glTranslatef(translateX, translateY, -translateZ);
        glViewport(0, 0, width(), height());
        sv->execute();

        isMouseRightDown = true;
    }
    update();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton){
        isMouseLeftDown = false;
    }
    if(event->button() & Qt::MiddleButton){
        isMouseMiddleDown = false;
    }
    if(event->button() & Qt::RightButton){
        isMouseRightDown = false;
    }

    mouseX = event->pos().x();
    mouseY = event->pos().y();
    t->resume();
    update();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    mouseDiffX = mouseX - event->pos().x();
    mouseDiffY = mouseY - event->pos().y();
/*
//    if (wind->mouseMIDDLE) {
//        wind->yaw += (xpos - wind->mouseX) / 8;
//        wind->pitch += (ypos - wind->mouseY) / 8;
//        wind->mouseX = xpos;
//        wind->mouseY = ypos;
//    }
*/
    if (isMouseLeftDown && !isKeyCtrlDown) {
        translateX += (((double)event->pos().x() - mouseX) / (double)height()) * 0.82 * translateZ;
        translateY += ((mouseY - (double)event->pos().y()) / (double)height()) * 0.82 * translateZ;
    }
    if (isMouseLeftDown && isKeyCtrlDown) {
        t->pause();
        selectedNode->posX -= mouseDiffX * 0.145 * translateZ;
        selectedNode->posY += mouseDiffY * 0.145 * translateZ;
    }

    mouseX = event->pos().x();
    mouseY = event->pos().y();
    update();
}

void GLWidget::wheelEvent(QWheelEvent *event)
{
    translateZ += ((double)event->delta() / 20 /120) * translateZ;
    if (translateZ < 0.16) {
        translateZ = 0.16;
    }
    if(translateZ > 10){
        translateZ = 10;
    }
    update();
}

void GLWidget:: keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){

    }
    if(event->key() == Qt::Key_Escape){
//        terminateThread();
//        if(graph!=NULL){
//            delete graph;
//            graph = NULL;
//            qDebug() << graph;
//        }
        translateX = 0;
        translateY = 0;
    }
//    if (selectedNode != NULL){
//        if(event->key() == Qt::Key_Left){
//            selectedNode->posX -= 100;
//        }
//        if(event->key() == Qt::Key_Right){
//            selectedNode->posX += 100;
//        }
//    }
    if (event->key() == Qt::Key_Control){
        isKeyCtrlDown = true;
    }
    update();
}

void GLWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){

    }
    if (event->key() == Qt::Key_Control){
        isKeyCtrlDown = false;
    }
    update();
}

void GLWidget::changeAlgorithm(QString a)
{
    terminateThread();

    if (graph != NULL){
        t = new TestThread(this);
        if(a == '1')
            t->addAlgorithm(new SimpleForceDirected(graph));
        if(a == '2')
            t->addAlgorithm(new FruchtermanReingold(graph));
        if(a == '3')
            t->addAlgorithm(new MultiForce(graph));
        t->start();
    }
    setFocus();
}

void GLWidget::terminateThread()
{
    if(t!=NULL){
        t->terminate();
        t->wait();
        delete t;
        t = NULL;
    }
}

void GLWidget::setSelectedVertexColour(int r, int g, int b)
{
    GLdouble red = (GLdouble)r / 255;
    GLdouble green = (GLdouble)g / 255;
    GLdouble blue = (GLdouble)b / 255;
    if(selectedNode)
        selectedNode->setColour(red, green, blue);
}

Graph *GLWidget::getGraph()
{
    return graph;
}

char *GLWidget::getPath()
{
    return path;
}

void GLWidget::setGraph(Graph *g)
{
    graph = g;
}

void GLWidget::setPath(char *p)
{
    path = p;
}

int GLWidget::getWidth()
{
    return width();
}

int GLWidget::getHeight()
{
    return height();
}

double GLWidget::getMouseX()
{
    return mouseX;
}

double GLWidget::getMouseY()
{
    return mouseY;
}

void GLWidget::setSelectedNode(Vertex *v)
{
    selectedNode = v;
}

Vertex *GLWidget::getSelectedNode()
{
    return selectedNode;
}

void GLWidget::loadGraph(char *p)
{
    terminateThread();
    path = p;
    c->execute();
    changeAlgorithm("1");
}

void GLWidget::degreeC()
{
    DegreeCentrality cc;
    if (graph != NULL)
        cc.calcApply(graph);
    setFocus();
}

void GLWidget::distanceC()
{
    DistanceCentrality cc;
    if (graph != NULL)
        cc.calcApply(graph);
    setFocus();
}

void GLWidget::betweennessC()
{
    Betweenness cc;
    if (graph != NULL)
        cc.calcApply(graph);
    setFocus();
}

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
#include "inc/Centrality/DegreeCentrality.h"
#include "inc/Centrality/DistanceCentrality.h"
#include "inc/Centrality/Betweenness.h"
#include "testthread.h"


GLWidget::GLWidget(QWidget *parent):QOpenGLWidget(parent)
{
    setFocus();
    /*
     * update timer
     */


    path = "D:/Qt_project/NetvizGL2/Graphs/EdgeLinks/graph.txt";
//    graph = new MatrixMarketGraph("D:/Qt_project/NetvizGL2/Graphs/MatrixMarket/ash85.mtx");
//    graph = new AdjacencyGraph("D:/Qt_project/NetvizGL2/Graphs/Adjacency/sirpenski5.txt");
    graph = new EdgeGraph("D:/Qt_project/NetvizGL2/Graphs/EdgeLinks/graph.txt");
    c = new LoadGraph(this);
    translateX = 0;
    translateY = 0;
    translateZ = 1;
    isMouseLeftDown = false;
    isMouseMiddleDown = false;
    isMouseRightDown = false;

//    graph->vertices[0]->setColour(1,0,0);

//    algorithm = new SimpleForceDirected(graph);
//    t = new TestThread(this);
//    t->addAlgorithm(algorithm);
//    t->start();
    t = NULL;
    test("1");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(20);
}

GLWidget::~GLWidget()
{
    delete timer;
    delete t;
    delete algorithm;
    delete graph;
}

void GLWidget::initializeGL()
{
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
    gluPerspective(90, (double)width()/(double)height(), 0.01, 10);
    glTranslatef(translateX, translateY, -translateZ);

    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_LINE_SMOOTH);

    glPointSize(30/(translateZ+0.84));
    glLineWidth(1);

    //    glVertexPointer(3, GL_FLOAT, 0, vertex);
    //    glDrawArrays(GL_POINTS, 0, 1);
    //    glDrawArrays(GL_LINE_LOOP, 0, 3);

    /*
     * draw graph
     */
    if(graph!=NULL){
        graph->update();
        graph->draw();
    }
    /*
     * end of drawing
     */

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_LINE_SMOOTH);

//    qDebug() << "yoyo";
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton){
        isMouseLeftDown = true;
//        double xx = (double)(event->pos().x() * 2 - width()) / (double)width();
//        double yy = (double)(event->pos().y() * 2 - height()) / (double)height();
//        qDebug() << "left ( " << xx << ", " << yy << " )";
//        qDebug() << "left ( " << event->pos().x() << ", " << event->pos().y() << " )";
    }
    if(event->button() & Qt::MiddleButton){
        isMouseMiddleDown = true;
//        qDebug() << "middle";
    }
    if(event->button() & Qt::RightButton){
        isMouseRightDown = true;
//        qDebug() << "right";
    }
//    qDebug() << "( " << (double)event->pos().x() - (double)width() / 2<< ", " << (double)event->pos().y() - (double)height() / 2 << " )";
    qDebug() << "( " << graph->vertices[0]->posX << ", " << graph->vertices[0]->posY << " )";
    update();
    mouseX = event->pos().x();
    mouseY = event->pos().y();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton){
        isMouseLeftDown = false;
//        qDebug() << "left";
    }
    if(event->button() & Qt::MiddleButton){
        isMouseMiddleDown = false;
//        qDebug() << "middle";
    }
    if(event->button() & Qt::RightButton){
        isMouseRightDown = false;
//        qDebug() << "right";
    }
//    qDebug() << "(" << event->pos().x() << ", " << event->pos().y() << ")";
    mouseX = event->pos().x();
    mouseY = event->pos().y();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
//    if(isMouseLeftDown){
//        qDebug() << "(" << event->x() << ", " << event->y() << ")";
//    }
    mouseDiffX = mouseX - event->pos().x();
    mouseDiffY = mouseY - event->pos().y();
//    if (wind->mouseMIDDLE) {
//        wind->yaw += (xpos - wind->mouseX) / 8;
//        wind->pitch += (ypos - wind->mouseY) / 8;
//        wind->mouseX = xpos;
//        wind->mouseY = ypos;
//    }
    if (isMouseLeftDown) {
        translateX += (((double)event->pos().x() - mouseX) / (double)height()) * 2.0 * translateZ;
        translateY += ((mouseY - (double)event->pos().y()) / (double)height()) * 2.0 * translateZ;
//        qDebug() << "(" << translateX << ", " << translateY << ")";
        mouseX = event->pos().x();
        mouseY = event->pos().y();
    }
    mouseX = event->pos().x();
    mouseY = event->pos().y();
//    if (wind->mouseLEFT && wind->keyCTRL) {
//        wind->dragNode->execute();
//    }
//    qDebug() << "(" << translateX << ", " << translateY << ")";
}

void GLWidget::wheelEvent(QWheelEvent *event)
{
    translateZ += ((double)event->delta() / 20 /120) * translateZ;
    if (translateZ < 0.16) {
        translateZ = 0.16;
    }
    if(translateZ > 3){
        translateZ = 3;
    }
    update();
}

void GLWidget:: keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
        qDebug() << "A";
        if (graph != NULL){
            terminateThread();
            t = new TestThread(this);
            t->addAlgorithm(new MultiForce(graph));
            t->start();
        }
    }
    if(event->key() == Qt::Key_Escape){
        terminateThread();
        if(graph!=NULL){
            delete graph;
            graph = NULL;
            qDebug() << graph;
        }
    }
    if(event->key() == Qt::Key_Left){
//        qDebug() << "<<";
        graph->vertices[0]->posX -= 100;
    }
    if(event->key() == Qt::Key_Right){
//        qDebug() << ">>";
        graph->vertices[0]->posX += 100;
    }
}

void GLWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
//        qDebug() << "A";
    }
}

void GLWidget::test(QString filePath)
{
    qDebug() << "123456";
    terminateThread();

    if (graph != NULL){
        t = new TestThread(this);
        if(filePath == '1')
            t->addAlgorithm(new SimpleForceDirected(graph));
        if(filePath == '2')
            t->addAlgorithm(new FruchtermanReingold(graph));
        if(filePath == '3')
            t->addAlgorithm(new MultiForce(graph));
        t->start();
        qDebug() << t;
    }
    setFocus();
//    qDebug() << filePath;
}

void GLWidget::terminateThread()
{
    if(t!=NULL){
        t->terminate();
        t->wait();
        delete t;
        t = NULL;
        qDebug() << t;
    }
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
    c->execute();
}

void GLWidget::degreeC()
{
    DegreeCentrality cc;
    cc.calcApply(graph);
    setFocus();
}

void GLWidget::distanceC()
{
    DistanceCentrality cc;
    cc.calcApply(graph);
    setFocus();
}

void GLWidget::betweennessC()
{
    Betweenness cc;
    cc.calcApply(graph);
    setFocus();
}

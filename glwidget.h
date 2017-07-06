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

    int getWidth() override;
    int getHeight() override;

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
    QPixmap originalPixmap;

};

#endif // GLWIDGET_H

#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "../Graphs/Graph.h"
#include "Command.h"

class GLWindow{

public:
    virtual Graph *getGraph() = 0;
    virtual char* getPath() = 0;
    virtual void setGraph(Graph *g) = 0;
    virtual void setPath(char *p) = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual double getMouseX() = 0;
    virtual double getMouseY() = 0;
    virtual void setSelectedNode(Vertex *v) = 0;
    virtual Vertex *getSelectedNode() = 0;
    virtual GLdouble getMouseDiffX() const = 0;
    virtual GLdouble getMouseDiffY() const = 0;
    virtual GLdouble getTranslateZ() const = 0;
    virtual int getSelectedVertexNumber() const = 0;
    virtual void setSelectedVertexNumber(int value) = 0;

protected:
    Command *c;
    Command *sv;
    Command *dragv;
    Command *deletev;

    GLdouble pitch, yaw, bank;
    GLdouble translateX, translateY, translateZ;
    GLdouble mouseX;
    GLdouble mouseY;
    GLdouble mouseDiffX;
    GLdouble mouseDiffY;
    bool isMouseLeftDown, isMouseMiddleDown, isMouseRightDown;
    bool isKeyCtrlDown;


    Graph *graph;
    Vertex *selectedNode;
    int selectedVertexNumber;
};


#endif // GLWINDOW_H

#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "../Graphs/Graph.h"
#include "Command.h"

class GLWindow{

public:
//    Graph *getGraph();
//    char* getPath();
//    void setGraph(Graph *g);
//    void setPath(char *p);
//    double getMouseX();
//    double getMouseY();
//    void setSelectedNode(Vertex *v);
//    Vertex *getSelectedNode();
//    GLdouble getMouseDiffX() const;
//    GLdouble getMouseDiffY() const;
//    GLdouble getTranslateZ() const;
//    int getSelectedVertexNumber() const;
//    void setSelectedVertexNumber(int value);

    virtual int getWidth() = 0;
    virtual int getHeight() = 0;

    Graph *getGraph() const
    {
        return graph;
    }
    void setGraph(Graph *g)
    {
        graph = g;
    }
    char *getPath() const
    {
        return path;
    }
    void setPath(char *p)
    {
        path = p;
    }
    GLdouble getMouseX() const
    {
        return mouseX;
    }
    GLdouble getMouseY() const
    {
        return mouseY;
    }
    Vertex *getSelectedNode() const
    {
        return selectedNode;
    }
    void setSelectedNode(Vertex *v)
    {
        selectedNode = v;
    }
    GLdouble getMouseDiffX() const
    {
        return mouseDiffX;
    }
    GLdouble getMouseDiffY() const
    {
        return mouseDiffY;
    }
    GLdouble getTranslateZ() const
    {
        return translateZ;
    }
    int getSelectedVertexNumber() const
    {
        return selectedVertexNumber;
    }
    void setSelectedVertexNumber(int sv)
    {
        selectedVertexNumber = sv;
    }

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
    char* path;

};

#endif // GLWINDOW_H

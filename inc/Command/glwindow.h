#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "../Graphs/Graph.h"

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
};


#endif // GLWINDOW_H

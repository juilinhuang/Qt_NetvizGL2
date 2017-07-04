//
// Created by william on 20/02/17.
//

#ifndef NETVIZGL_UPDATEGRAPH_H
#define NETVIZGL_UPDATEGRAPH_H

#include "Command.h"
#include "../Graphs/EdgeGraph.h"
#include "glwindow.h"

class DeleteVertex : public Command {
private:
    GLWindow *window;
public:
    DeleteVertex(GLWindow *window, int deletedNode)
        : window(window), deleteNode(deletedNode) {};
    int deleteNode;

public:
    void execute() override {
        if (window->getGraph() && deleteNode >= 0 && deleteNode <= window->getGraph()->vertices.size()) {
            vector<int *> newEdgeList = window->getGraph()->edgeList;

            for (int i = 0; i < newEdgeList.size(); ++i) {
                if ((newEdgeList[i][0] == deleteNode ||
                     newEdgeList[i][1] == deleteNode)) {
                    newEdgeList.erase(newEdgeList.begin() + i);
                    i--;
                }
            }
            for (int i = 0; i < newEdgeList.size(); ++i) {
                if (newEdgeList[i][0] > deleteNode)
                    newEdgeList[i][0]--;
                if (newEdgeList[i][1] > deleteNode)
                    newEdgeList[i][1]--;
            }
            window->setGraph(new EdgeGraph(newEdgeList));
        }
    }
};

#endif //NETVIZGL_UPDATEGRAPH_H

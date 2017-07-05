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
        : window(window), deleteNode(deletedNode) {}
    ~DeleteVertex(){}
    int deleteNode;

public:
    void execute() override {
        if (window->getGraph() && deleteNode >= 0 && deleteNode <= window->getGraph()->vertices.size()) {
            vector<int *> newEdgeList = window->getGraph()->edgeList;

            window->getGraph()->set.erase(deleteNode);
            qDebug() << window->getGraph()->set.size();
            std::set<int>::iterator it;
            for(it = window->getGraph()->set.begin(); it != window->getGraph()->set.end(); it++){
                qDebug() << *it;
//                if(*it > deleteNode){
//                    it.operator--();
//                    qDebug() << *it;
//                }

            }

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

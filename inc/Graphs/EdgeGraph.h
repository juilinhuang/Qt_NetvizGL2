//
// Created by werl on 11/11/16.
//

#ifndef NETVIZGL_EDGEGRAPH_H
#define NETVIZGL_EDGEGRAPH_H

#include "Graph.h"
#include <QtCore>

class EdgeGraph : public Graph {
public:
    EdgeGraph(char *filePath);
//    EdgeGraph(char *filePath, vector<int *> newEdgeList);
//    EdgeGraph(vector<int *> newEdgeList);
    virtual ~EdgeGraph();

private:
    virtual void read(char *filePath) override;
    virtual int *split(string str) override;
    void createGraphData();
//    string *getEdgeList(string str);
};

#endif //NETVIZGL_EDGEGRAPH_H

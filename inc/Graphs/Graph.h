//
// Created by werl on 25/10/16.
//

#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <string>
#include "../vertex.h"

#ifndef NETVIZGL_GRAPH_H
#define NETVIZGL_GRAPH_H

class Algorithm;

using namespace std;

class Graph {
public:
    Graph(char *filePath);
    virtual ~Graph();
    Algorithm *algorithm;

    vector<Vertex *> vertices;
    vector<Edge *> edges;
    unsigned long numVertices;
    unsigned long numEdges;
    vector<vector<int>> adjacencyMatrix;
    vector<int *> edgeList;

    void draw();
    void update();

    virtual int *split(string x);
    static unsigned int hash3(unsigned int h1, unsigned int h2, unsigned int h3);
private:
    virtual void read(char *filePath) = 0;
};

#endif //NETVIZGL_GRAPHREADER_H

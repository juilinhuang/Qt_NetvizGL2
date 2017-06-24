//
// Created by werl on 25/10/16.
//

#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>
#include "../vertex.h"
#include "../Edge.h"

#ifndef NETVIZGL_GRAPH_H
#define NETVIZGL_GRAPH_H

using namespace std;

class Graph {
public:
    Graph(char *filePath);
    virtual ~Graph();

    vector<Vertex *> vertices;
    vector<Edge *> edges;
    unsigned long numVertices;
    unsigned long numEdges;
    vector<vector<int>> adjacencyMatrix;
    vector<int *> edgeList;

    set<string> set;

    void draw();
    void update();


    static unsigned int hash3(unsigned int h1, unsigned int h2, unsigned int h3);
private:
    virtual void read(char *filePath) = 0;
    virtual int *split(string str) = 0;
};

#endif //NETVIZGL_GRAPHREADER_H

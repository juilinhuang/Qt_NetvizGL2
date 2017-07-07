//
// Created by werl on 11/11/16.
//

#include <sys/time.h>
#include <cstdlib>
#include <zconf.h>
#include <fstream>
#include "../../inc/Graphs/AdjacencyGraph.h"
#include <QDebug>

AdjacencyGraph::AdjacencyGraph(char *filePath) {
    read(filePath);
}

void AdjacencyGraph::read(char *filePath) {
    string inString;
    ifstream inFile;

    inFile.open(filePath);
    if (inFile.is_open()) {
//        fprintf(stderr, "Open %s \n", filePath);
    } else {
//        fprintf(stderr, "Failed to open %s \n", filePath);
        exit(0);
    }

    while (!inFile.eof()) {
        getline(inFile, inString);
        if (inString.size() > 1)
            edgeList.push_back(split(inString));
    }
    inFile.close();

    numVertices = static_cast<unsigned long>( edgeList.size() );

    initialiseAdjacencyMatrix();

    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            adjacencyMatrix[i][j] = edgeList[i][j];
        }
    }

    edgeList.clear();
    getEdgeListFromAdjacencyMatrix();

    for (int j = 0; j < numVertices; ++j) {
        vertices.push_back(new Vertex(0, 0, 0));
        vertices[j]->setColour(0, 0, 0);
    }

    for (int i = 0; i < numVertices; ++i) {
        for (int j = i; j < numVertices; ++j) {
            if(j == i) continue;
            if (adjacencyMatrix[i][j] == 1) {
                edges.push_back(new Edge(vertices[i], vertices[j]));
//                vertices[i]->attachPoint(vertices[j]);
                vertices[i]->degree++;
                vertices[j]->degree++;
            }
        }
    }

    numEdges = edgeList.size();
    setRandomColour();
}

int *AdjacencyGraph::split(string str)
{
    std::istringstream buf(str);
    std::istream_iterator<std::string> beg(buf), end;

    std::vector<std::string> tokens(beg, end);

    int *ret = new int[tokens.size()];
    for (int i = 0; i < tokens.size(); ++i)
        ret[i] = atoi(tokens[i].c_str());

    return ret;
}

AdjacencyGraph::~AdjacencyGraph() {

}

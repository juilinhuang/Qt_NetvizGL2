//
// Created by werl on 11/11/16.
//

#include <cstdlib>
#include <fstream>
#include "../../inc/Graphs/EdgeGraph.h"
#include <QDebug>
#include <QSet>

EdgeGraph::EdgeGraph(char *filePath){
    read(filePath);
    createGraphData();
    setRandomColour();
}

EdgeGraph::EdgeGraph(vector<int *> newEdgeList) {
    edgeList = newEdgeList;
    createGraphData();
}

EdgeGraph::~EdgeGraph() {

}

void EdgeGraph::read(char *filePath) {
    string inString;
    ifstream inFile;
    inFile.open(filePath);
    if (inFile.is_open()) {

    }
    else {
        exit(0);
    }
    while (!inFile.eof()) {
        getline(inFile, inString);
        if (inString.size() > 1){
            edgeList.push_back(split(inString));
        }
    }
    inFile.close();
}

int *EdgeGraph::split(string str) {
    std::istringstream buf(str);
    std::istream_iterator<std::string> beg(buf), end;
    std::vector<std::string> tokens(beg, end);

    int *ret = new int[tokens.size()];
    for (int i = 0; i < tokens.size(); ++i){
        ret[i] = atoi(tokens[i].c_str());
    }
    return ret;
}

void EdgeGraph::createGraphData()
{
    set.clear();
    for (int i = 0; i < edgeList.size(); ++i) {
        set.insert(edgeList[i][0]);
        set.insert(edgeList[i][1]);
    }
    numVertices = set.size();

    adjacencyMatrix.clear();
    initialiseAdjacencyMatrix();
    getAdjacencyMatrixFromEdgeList();
    edgeList.clear();
    getEdgeListFromAdjacencyMatrix();
    vertices.clear();
    createVertices();
    edges.clear();
    createEdges();
    numEdges = edges.size();
}

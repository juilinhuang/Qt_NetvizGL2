//
// Created by werl on 11/11/16.
//

#include <cstdlib>
#include <fstream>
#include "../../inc/Graphs/EdgeGraph.h"
#include <QDebug>
#include <QSet>

EdgeGraph::EdgeGraph(char *filePath) {
    read(filePath);
}

EdgeGraph::EdgeGraph(vector<int *> newEdgeList) {
    edgeList = newEdgeList;
    set.clear();
    for (int i = 0; i < edgeList.size(); ++i) {
        set.insert(edgeList[i][0]);
        set.insert(edgeList[i][1]);
    }
    numVertices = set.size();
    createGraphData();
    numEdges = edgeList.size();
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

    numVertices = set.size();
    createGraphData();
    numEdges = edges.size();
}

int *EdgeGraph::split(string str) {
    std::istringstream buf(str);
    std::istream_iterator<std::string> beg(buf), end;
    std::vector<std::string> tokens(beg, end);

    int *ret = new int[tokens.size()];
    for (int i = 0; i < tokens.size(); ++i){
        ret[i] = atoi(tokens[i].c_str());
        set.insert(ret[i]);
    }
    return ret;
}

void EdgeGraph::createGraphData()
{
    adjacencyMatrix.clear();
    initialiseAdjacencyMatrix();
    for (int k = 0; k < edgeList.size(); ++k) {
        adjacencyMatrix[edgeList[k][0]][edgeList[k][1]] = 1;
        adjacencyMatrix[edgeList[k][1]][edgeList[k][0]] = 1;
    }
    edgeList.clear();
    getEdgeListFromAdjacencyMatrix();
    vertices.clear();
    for (int j = 0; j < set.size(); ++j) {
        vertices.push_back(new Vertex(0, 0, 0));
        vertices[j]->setColour(0, 0, 0);
    }
    for (int k = 0; k < edgeList.size(); ++k) {
        edges.push_back(new Edge(vertices[edgeList[k][0]], vertices[edgeList[k][1]]));
        vertices[edgeList[k][0]]->degree++;
        vertices[edgeList[k][1]]->degree++;
    }
    setRandomColour();
}

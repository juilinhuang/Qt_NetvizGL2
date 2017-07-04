//
// Created by werl on 25/10/16.
//

#include "../../inc/Graphs/Graph.h"
#include <QDebug>

Graph::Graph() {
    numVertices = 0;
}

Graph::~Graph() {
    //    fprintf(stderr, "Deleting Graph\n");
    vertices.clear();
    adjacencyMatrix.clear();
}

void Graph::initialiseAdjacencyMatrix()
{
    for (int i = 0; i < numVertices; ++i) {
        vector<int> row;
        adjacencyMatrix.push_back(row);
        for (int j = 0; j < numVertices; ++j) {
            adjacencyMatrix[i].push_back(0);
        }
    }
}

vector<vector<int> > Graph::getAdjacencyMatrix() const
{
    return adjacencyMatrix;
}

void Graph::update() {
    for (int i = 0; i < vertices.size(); ++i) {
        vertices[i]->update();
    }
    for (int i = 0; i < edges.size(); ++i) {
        edges[i]->update();
    }
}

void Graph::draw() {
    for (int i = 0; i < vertices.size(); ++i) {
        vertices[i]->draw();
    }
    for (int i = 0; i < vertices.size(); ++i) {
        vertices[i]->drawText();
    }
    for (int i = 0; i < edges.size(); ++i) {
        edges[i]->draw();
    }
    for (int i = 0; i < edges.size(); ++i) {
        edges[i]->drawText();
    }
}

unsigned int Graph::hash3(unsigned int h1, unsigned int h2, unsigned int h3) {
    return ((h1 * 2654435789U) + h2) * 2654435789U + h3;
}

//int *Graph::split(string str) {
//    std::istringstream buf(str);
//    std::istream_iterator<std::string> beg(buf), end;

//    std::vector<std::string> tokens(beg, end);

////    vector<string>::iterator it;
////    for(it=tokens.begin();it!=tokens.end();it++)
////        set.insert(*it);

//    qDebug() << "tokens.size() = " << tokens.size();

//    int *ret = new int[tokens.size()];
//    for (int i = 0; i < tokens.size(); ++i)
//        ret[i] = atoi(tokens[i].c_str());

//    return ret;
//}

void Graph::setRandomColour(){
    struct timeval time;
    gettimeofday(&time, NULL);
    srand(Graph::hash3(time.tv_sec, time.tv_usec, getpid()));
    for (int j = 0; j < vertices.size(); ++j) {
        vertices[j]->setColour(((double) rand() / (RAND_MAX)),
                               ((double) rand() / (RAND_MAX)),
                               ((double) rand() / (RAND_MAX)));
    }
}

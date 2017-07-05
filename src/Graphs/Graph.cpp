//
// Created by werl on 25/10/16.
//

#include "../../inc/Graphs/Graph.h"
#include <QDebug>

Graph::Graph() {
    numVertices = 0;
}

Graph::~Graph() {
    vertices.clear();
    adjacencyMatrix.clear();
    edgeList.clear();
    edges.clear();
    set.clear();
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

void Graph::getEdgeListFromAdjacencyMatrix()
{
    int *temp = new int[2];
    for (int i = 0; i < numVertices; ++i) {
        for (int j = i; j < numVertices; ++j) {
            if (adjacencyMatrix[i][j] == 1 && i != j) {
                temp[0] = i;
                temp[1] = j;
                edgeList.push_back(temp);
                temp = new int[2];
            }
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

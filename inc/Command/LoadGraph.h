//
// Created by werl on 12/01/17.
//

#ifndef NETVIZGL_LOADGRAPHCOMMAND_H
#define NETVIZGL_LOADGRAPHCOMMAND_H

#include "Command.h"
#include "glwindow.h"
#include "../Graphs/EdgeGraph.h"
#include "../Graphs/MatrixMarketGraph.h"
#include "../Graphs/AdjacencyGraph.h"
#include <sys/time.h>
#include <fstream>

class LoadGraph : public Command {
private:
    GLWindow *window;
public:
    LoadGraph(GLWindow *window) : window(window) {
//        fprintf(stdout, "%s\n", window->getPath());
    }
    ~LoadGraph(){
        delete window;
    }

public:
    void execute() override {
        std::ifstream infile;
        infile.open(window->getPath());
        std::string sLine;
        getline(infile, sLine);
        infile.close();

        if (window->getGraph()) {
            window->getGraph()->numVertices = 0;
        }
        Graph *temp = window->getGraph();

        if (sLine.length() <= 4) {
            window->setGraph(new EdgeGraph(window->getPath()));
//            fprintf(stdout, "Loading EdgeList:%s\n", window->getPath());
        } else if (strcmp("%%MatrixMarket", sLine.substr(0, 14).c_str()) == 0) /*%%MatrixMarket 14 chars*/{
            window->setGraph(new MatrixMarketGraph(window->getPath()));
//            fprintf(stdout, "Loading MatrixMarketGraph:%s\n", window->getPath());
        } else if (sLine.length() > 3 && (strcmp("0", sLine.substr(0, 1).c_str()) == 0)
                   || strcmp("1", sLine.substr(0, 1).c_str()) == 0) {
            window->setGraph(new AdjacencyGraph(window->getPath()));
//            fprintf(stdout, "Loading AdjacencyGraph:%s\n", window->getPath());
        } else {
//            fprintf(stderr, "Error file type not supported?");
            return;
        }

        char *digit = new char[64];
        struct timeval time;
        gettimeofday(&time, NULL);
        srand(Graph::hash3(time.tv_sec, time.tv_usec, getpid()));
        for (int j = 0; j < window->getGraph()->numVertices; ++j) {
//            sprintf(digit, "%d", j);
            //GLWindow::Ins()->graph->vertices[j]->setText(digit);
            window->getGraph()->vertices[j]->setColour(((double) rand() / (RAND_MAX)),
                                                       ((double) rand() / (RAND_MAX)),
                                                       ((double) rand() / (RAND_MAX)));
        }
        delete (digit);

        if (temp) {
            delete (temp);
        }
    }
};

#endif //NETVIZGL_LOADGRAPHCOMMAND_H

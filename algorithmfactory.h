#ifndef ALGORITHMFACTORY_H
#define ALGORITHMFACTORY_H

#include "inc/Algorithms/SimpleForceDirected.h"
#include "inc/Algorithms/FruchtermanReingold.h"
#include "inc/Algorithms/MultiForce.h"

class AlgorithmFactory
{
public:
    AlgorithmFactory();
    static Algorithm *getAlgorithm(char a, Graph *g);
};

#endif // ALGORITHMFACTORY_H

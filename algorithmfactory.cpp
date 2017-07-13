#include "algorithmfactory.h"

AlgorithmFactory::AlgorithmFactory()
{

}

Algorithm *AlgorithmFactory::getAlgorithm(char a, Graph *g)
{
    if(a == '1')
        return new SimpleForceDirected(g);
    if(a == '2')
        return new FruchtermanReingold(g);
    if(a == '3')
        return new MultiForce(g);
    return NULL;
}

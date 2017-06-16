#include "testthread.h"
#include <QDebug>

TestThread::TestThread(QObject *p) : QThread(p)
{

}

void TestThread::run()
{
    while(1){
        if(a!=NULL)
            a->apply();
//        usleep(5000);
    }
}

void TestThread::addAlgorithm(Algorithm *a)
{
    this->a = a;
}

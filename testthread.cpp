#include "testthread.h"
#include <QDebug>

TestThread::TestThread(QObject *p) : QThread(p)
{
    isPaused = false;
}

void TestThread::run()
{
    while(1){
        sync.lock();
        if(isPaused)
            pauseCond.wait(&sync); // in this place, your thread will stop to execute until someone calls resume
        sync.unlock();
        if(a!=NULL)
            a->apply();
        //        usleep(5000);
    }
}

void TestThread::addAlgorithm(Algorithm *a)
{
    this->a = a;
}

void TestThread::resume()
{
    sync.lock();
    isPaused = false;
    sync.unlock();
    pauseCond.wakeAll();
}

void TestThread::pause()
{
    sync.lock();
    isPaused = true;
    sync.unlock();
}

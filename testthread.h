#ifndef TESTTHREAD_H
#define TESTTHREAD_H
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include "inc/Algorithms/Algorithm.h"
#include "inc/Graphs/Graph.h"

class TestThread : public QThread
{
    Q_OBJECT
public:
    explicit TestThread(QObject *p = 0);
    ~TestThread();
    void run();
//    static Algorithm *getAlgorithm(char a, Graph *g);
    void resume();
    void pause();

    void setAlgorithm(Algorithm *a);

signals:

public slots:

private:
    Algorithm *algorithm;
    Graph *graph;
    QMutex sync;
    QWaitCondition pauseCond;
    bool isPaused;

};

#endif // TESTTHREAD_H

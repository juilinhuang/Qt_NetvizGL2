#ifndef TESTTHREAD_H
#define TESTTHREAD_H
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include "inc/Algorithms/Algorithm.h"

class TestThread : public QThread
{
    Q_OBJECT
public:
    explicit TestThread(QObject * p = 0);
    void run();
    void addAlgorithm(Algorithm *a);
    void resume();
    void pause();

signals:

public slots:

private:
    Algorithm *a;
    QMutex sync;
    QWaitCondition pauseCond;
    bool isPaused;

};

#endif // TESTTHREAD_H

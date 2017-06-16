#ifndef TESTTHREAD_H
#define TESTTHREAD_H
#include <QThread>
#include "inc/Algorithms/Algorithm.h"

class TestThread : public QThread
{
    Q_OBJECT
public:
    explicit TestThread(QObject * p = 0);
    void run();
    void addAlgorithm(Algorithm *a);

signals:

public slots:

private:
    Algorithm *a;

};

#endif // TESTTHREAD_H

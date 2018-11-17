#ifndef TIMEWORK_H
#define TIMEWORK_H

#include <QThread>
#include <QMutex>

class TimeWork : public QThread
{
    Q_OBJECT
public:
    TimeWork();
    ~TimeWork();
    void pause(bool flag);

protected:
    virtual void run();

signals:
    void countChanged(int count);

public slots:
    void changeFinishedFlag(bool finishedFlag);        //更改结束标志位

private:
    int mCount;          //计时器次数
    bool mFinishedFlag;       //线程结束标志位

    QMutex mutex;           //线程锁
    QMutex mutexPause;           //线程暂停

};

#endif // TIMEWORK_H

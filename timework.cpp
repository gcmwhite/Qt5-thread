#include "timework.h"
#include <QDebug>
#include <QMutexLocker>

TimeWork::TimeWork()
{
    this->mCount = 0;
    this->mFinishedFlag = false;
}

void TimeWork::run()
{
    qDebug() << "子线程：" << this->currentThread();
    while (!this->mFinishedFlag)
    {
        this->mCount++;
        emit countChanged(this->mCount);
        this->msleep(100);
        QMutexLocker locker(&mutexPause);
    }
}

void TimeWork::changeFinishedFlag(bool finishedFlag)
{
    qDebug() << "changeFinishedFlag：" << this->currentThread();
    QMutexLocker locker(&mutex);            //创建线程锁
    this->mFinishedFlag = finishedFlag;
}

TimeWork::~TimeWork()
{
    qDebug() << "调用析构函数！" << this->currentThread();
}

void TimeWork::pause(bool flag)
{
    if (flag)
        mutexPause.lock();
    else
        mutexPause.unlock();
}

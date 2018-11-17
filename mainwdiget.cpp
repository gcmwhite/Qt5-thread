#include "mainwdiget.h"
#include "ui_mainwdiget.h"
#include <QDebug>

MainWdiget::MainWdiget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWdiget)
{
    ui->setupUi(this);

    qDebug() << "主线程开始：" << QThread::currentThread();

    ui->pauseBtn->setEnabled(false);
    ui->stopBtn->setEnabled(false);
    threadPauseFlag = false;

    //开始计时
    this->connect(ui->startBtn,&QPushButton::clicked,this,[=](){
        timeWork = new TimeWork;
        timeWork->start();
        this->connect(timeWork,&TimeWork::finished,timeWork,&TimeWork::deleteLater);

        //计时器显示
        this->connect(timeWork,&TimeWork::countChanged,this,[=](int count){
            ui->lcdNumber->display(count);
        });
        ui->startBtn->setEnabled(false);
        ui->pauseBtn->setEnabled(true);
        ui->stopBtn->setEnabled(true);
    });

    //暂停计时
    connect(ui->pauseBtn,&QPushButton::clicked,this,[=]() /*mutable*/{
        threadPauseFlag = !threadPauseFlag;
        timeWork->pause(threadPauseFlag);
        if (threadPauseFlag)
            ui->pauseBtn->setText("开始计时");
        else
            ui->pauseBtn->setText("暂停计时");
    });

    //结束计时
    this->connect(ui->stopBtn,&QPushButton::clicked,this,[=](){
        timeWork->changeFinishedFlag(true);
        if (threadPauseFlag)
        {
            threadPauseFlag = false;
            timeWork->pause(threadPauseFlag);
        }
        ui->startBtn->setEnabled(true);
        ui->pauseBtn->setEnabled(false);
        ui->stopBtn->setEnabled(false);
        ui->pauseBtn->setText("暂停计时");
        ui->lcdNumber->display(0);
    });

}

MainWdiget::~MainWdiget()
{
    delete ui;
}

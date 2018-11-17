#ifndef MAINWDIGET_H
#define MAINWDIGET_H

#include <QWidget>
#include <timework.h>

namespace Ui {
class MainWdiget;
}

class MainWdiget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWdiget(QWidget *parent = 0);
    ~MainWdiget();

private:
    Ui::MainWdiget *ui;
    TimeWork *timeWork;

    bool threadPauseFlag;
};

#endif // MAINWDIGET_H

#include <QApplication>
#include <mainwdiget.h>

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    MainWdiget mainWidget;
    mainWidget.show();

    return app.exec();
}

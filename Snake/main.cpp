#include "mainmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainMenu StartWindow;//first window to show is mainmenu
    StartWindow.show();
    return a.exec();
}

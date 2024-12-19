#include "mainmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainMenu StartWindow;
    StartWindow.show();
    return a.exec();
}

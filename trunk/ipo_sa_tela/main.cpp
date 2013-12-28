#include "MainWindow.h"
#include <QApplication>

#define TESTES

#ifdef TESTES
#include <srcTest/tests.h>
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef TESTES
    mainTestes();
#endif

    MainWindow w;
    w.show();
    
    return a.exec();
}

#ifdef TESTES


#endif

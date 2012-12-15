#include <QApplication>
#include "include/note.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Note w;

    w.show();

    return a.exec();
}

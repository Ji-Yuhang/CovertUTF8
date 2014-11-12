#include "widget.hxx"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.showNormal();
    
    return a.exec();
}

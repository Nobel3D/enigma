#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    char s[26];
    for(int i = 0; i < 26; i++)
        s[i] = 'A' + i;
    qDebug(s);
    MainWindow w;
    w.show();

    return a.exec();
}

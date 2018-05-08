#include <QCoreApplication>
#include "enigma.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char* rot1 = "ZBCDEFIHGJKLMNOSQRUTPVWXYA";
    char* rot2 = "JBCDEFGIHKALMNOPQRSTUVWXYZ";
    char* rot3 = "ABCZERGHIJKLMNOPQFTUVWXYDS";
    Enigma e;

    char start = 'A' - 1;
    char ris, end;
    for(int i=0; i < 100; i++)
    {
        if(start++ >= 'Z')
            start = 'A';
        ris = e.cifra(start, false);
        end = e.cifra(ris, false);
        qDebug() << start << ris << end << (start == end ? "VERO" : "FALSO");
    }

    return a.exec();
}

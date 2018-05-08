#ifndef ROTORE_H
#define ROTORE_H

#include "def.h"

class Rotore
{
public:
    Rotore();
    Rotore(const char *lettere);
    Rotore(const Rotore &cp);

    void rotore(const char *lettere);
    char* rotore();

    char posizione();

    char cambioLettera(char lettera);
    char cambioIndice(char lettera);

    void avanza();
    void avanza(byte a);
private:
    char* rot;
};

#endif // ROTORE_H

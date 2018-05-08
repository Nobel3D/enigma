#include "rotore.h"
#include <string.h>
#include <stdlib.h>

Rotore::Rotore()
{
    rot = new char[26];
}

Rotore::Rotore(const char *lettere)
{
    rot = new char[26];
    rotore(lettere);
}

Rotore::Rotore(const Rotore &cp)
{
    rot = new char[26];
    memcpy(rot, cp.rot, 26);
}

void Rotore::rotore(const char *lettere)
{
    if(strlen(lettere) != 26)
        return;
    memcpy(rot, lettere, 26);
}
char* Rotore::rotore()
{
    return rot;
}

char Rotore::posizione()
{
    return rot[0];
}


char Rotore::cambioLettera(char lettera)
{
    return rot[lettera] - 'A';
}

char Rotore::cambioIndice(char lettera)
{
    for(int i=0; i < 26; i++)
        if((rot[i] - 'A') == lettera)
            return i;
}

void Rotore::avanza()
{
    char primo = rot[0];
    memcpy(rot, rot + 1, 25);
    rot[25] = primo;
}

void Rotore::avanza(byte a)
{
    if(a > 25 || a == 0 || a < -25)
        return;

    void* pData = nullptr;

    if(a > 0)
    {
        pData = malloc(a);
        memcpy(pData,rot, a);
        memcpy(rot, rot + a, 26 - a);
        memcpy(rot + (26 - a), pData, a);

    }
    else
    {
        a = -a;
        pData = malloc(a);
        memcpy(pData,rot + (26 - a), a);
        memcpy(rot + a, rot, 26 - a);
        memcpy(rot, pData, a);
    }

    delete[] pData;
}

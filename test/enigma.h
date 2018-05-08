#ifndef ENIGMA_H
#define ENIGMA_H

#include "def.h"
#include "rotore.h"

class Enigma
{
public:
    Enigma();
    Enigma(const Rotore& rot1, const Rotore& rot2, const Rotore& rot3);

    Rotore* rotore(int i)
    {
        return &rot[i];
    }

    char* cifra(const char* testo);
    char cifra(char c, bool avanza = true);

    char reflettore(char letter, Rotore *lastRotor);

    void scambio(const char *lettere);
    char scambio(char lettera);

    void posizione(byte a, byte b, byte c);

private:
    Rotore* rot;

    char sca[10] = "ABCD";

    static const char ref[];
    static const char notch[];
    bool fine = false;

};

#endif // ENIGMA_H

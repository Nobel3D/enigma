#include "enigma.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>


const char Enigma::ref[27]="YRUHQSLDPXNGOKMIEBFZCWVJAT";

const char Enigma::notch[6]="QEVJZ";


Enigma::Enigma()
{
    rot = new Rotore[3];
    for(int i = 0; i < 3; i++)
    {
        rot[i] = Rotore(genRotore());
        sleep(1);
    }
}

Enigma::Enigma(const Rotore& rot1, const Rotore& rot2, const Rotore &rot3)
{
    rot = new Rotore[3];
    rot[0] = Rotore(rot1);
    rot[1] = Rotore(rot2);
    rot[2] = Rotore(rot3);
}

char Enigma::cifra(char c, bool avanza)
{
    if(c == ' ')
        return c;
    if (!isalpha(c))
        return -1;

    c = toupper(c) - 'A';

    /* Primo giro dei rotori 0-3 */
    for(int i = 0; i < 3; i++)
    {
        c = rot[i].cambioLettera(c);
        if(c > 25)
            c = c % 26;
    }


    /* Processo del Reflettore */
    c=ref[c];
    c -= 'A';

    /* Secondo giro dei rotori 3-0 */
    for (int i = 2; i >= 0; i--)
    {
        c = rot[i].cambioIndice(c);
        if(c > 25)
            c = c % 26;
    }

    if(avanza)
    {
        /* Avanzare il primo rotore */
        rot[0].avanza();

        /* Controlla se deve avanzare il secondo e il terzo rotore */
        if (fine)
        {
            /* Controlla se deve avanzare il secondo rotore */
            rot[1].avanza();
            rot[2].avanza();
            /* $fine=true se anche il terzo rotore verrà avanzato */
            fine=false;
        }

        /*  Step up second rotor if first rotor reached notch */
        if (rot[0].posizione()== notch[0])
        {
            rot[1].avanza();
            /* Set flag if second rotor reached notch */
            if (rot[1].posizione()==notch[1])
                fine=true;
        }
    }
    return c + 'A';
}

char* Enigma::cifra(const char *testo)
{
    int len = strlen(testo);

    char* offset = new char[len + 1];
    char buffer;
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        buffer = cifra(testo[i]);
        if(buffer > 0)
            offset[j++] = buffer;
    }
    offset[len] = '\0';
    return offset;

}

char Enigma::reflettore(char letter, Rotore *lastRotor){

    //Reflector A : ??? / ????
    char reflectorarray[13][2] = {{'A', 'E'},{'B', 'J'},{'C', 'M'},{'D', 'Z'},{'F', 'L'},{'G', 'Y'},{'H', 'X'},{'I', 'V'},{'K', 'W'},{'N','R'},{'O','Q'},{'P','U'},{'S','T'}};

    char *key = lastRotor->rotore();
    char mapto = 'A';
    for(int j = 0; j < 13; j++){                    //Find Desired Map
        if(reflectorarray[j][0] == letter){
            mapto = reflectorarray[j][1];
            break;
        }else if(reflectorarray[j][1] == letter){
            mapto = reflectorarray[j][0];
            break;
        }
    }


    for(int i=0; i < 26; i++){
        if(key[i] == mapto){
            return i + 'A';
        }
    }

    return 'A';
}

void Enigma::scambio(const char *lettere)
{
    int len = strlen(lettere);
    if(len > 11)
        return;

    for(int i = 0; i < len; i++)
        sca[i] = toupper(lettere[i]);
    sca[len] = '\0';

}

char Enigma::scambio(char lettera)
{
    /* Scambio le lettere definite in $sca = "AB"
     * con la prima lettera e la seconda.
     * Esempio: $lettera=A -> $lettera=B*/
    for (int i=0; sca[i]; i+=2)
    {
        if (lettera==sca[i])
            lettera=sca[i+1];
        else if (lettera==sca[i+1])
            lettera=sca[i];
    }
    return lettera;
}

void Enigma::posizione(byte a, byte b, byte c)
{

    rot[0].avanza(a);
    rot[1].avanza(b);
    rot[2].avanza(c);
}

/*
int Enigma::rotore(const char *lettere)
{
    for(int i = 0; i < 3; i++)
        if(strncmp(rot[i], lettere, 26) == 0)
            return i;
}
*/

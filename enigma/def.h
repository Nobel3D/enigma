#ifndef DEF_H
#define DEF_H

#include <cstdint>
#include <time.h>
#include <stdlib.h>

typedef int8_t byte;

inline char* genRotoreFull()
{
    srand (time(NULL));
    int count = 0;
    char* offset = new char[27];
    bool skip = false;
    for(int i = 0; i < 26; i)
    {

        byte b = (rand() % 26) + 'A';
        for(int j = 0; j < i; j++)
            if(offset[j] == b)
            {
                count++; /* $count = 56 */
                skip = true;
                break;
            }
        if(!skip)
            offset[i++] = b;
        else
            skip = false;
    }
    offset[26] = '\0';
    return offset;
}

inline char* genRotore()
{
    srand (time(NULL));
    char* offset = new char[27];
    char alfa[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 25; i >= 0; i--)
    {
        byte b = rand() % (i + 1);
        offset[i] = alfa[b];
        int j = 0;
        while(j < i)
            alfa[j++] = (alfa[j] != alfa[b] ? alfa[j] : alfa[++b]);
    }
    offset[26] = '\0';
    return offset;
}

#endif // DEF_H

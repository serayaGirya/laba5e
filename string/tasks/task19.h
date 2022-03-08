//
// Created by serge on 08.03.2022.
//

#ifndef LABORATORY5E_TASK19_H
#define LABORATORY5E_TASK19_H
#include "../string_.h"

char f(char *string, char *word) {
    static char arrayOfSymbolIndexes[255];

    if (*word == '\0' || *string == '\0')
        return false;

    while (*string != '\0') {
        arrayOfSymbolIndexes[*string] = 1;
        string++;
    }
    while (*word != '\0') {
        if (!arrayOfSymbolIndexes[*word])
            return false;
        word++;
    }

    return true;
}

#endif //LABORATORY5E_TASK19_H

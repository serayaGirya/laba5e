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


void test_f_hasEqualLetters() {
    char s[MAX_STRING_SIZE] = "abcde";
    char word[MAX_STRING_SIZE] = "de";

    assert(f(s, word) == true);
}

void test_f_hasNoEqualLetters() {
    char s[MAX_STRING_SIZE] = "abcde";
    char word[MAX_STRING_SIZE] = "def";

    assert(f(s, word) == false);
}

void test_f_spacesInString() {
    char s[MAX_STRING_SIZE] = "a b c d e f g t y u";
    char word[MAX_STRING_SIZE] = "abc";

    assert(f(s, word) == true);
}

void test_f_wordIsEmpty() {
    char s[MAX_STRING_SIZE] = "abc";
    char word[MAX_STRING_SIZE] = "";

    assert(f(s, word) == false);
}

void test_f_spaces() {
    char s[MAX_STRING_SIZE] = "abc";
    char word[MAX_STRING_SIZE] = "ab c";

    assert(f(s, word) == true);
}

void test_f() {
    test_f_hasEqualLetters();
    test_f_hasNoEqualLetters();
    test_f_wordIsEmpty();
    test_f_spacesInString();
    test_f_spaces();
}
#endif //LABORATORY5E_TASK19_H

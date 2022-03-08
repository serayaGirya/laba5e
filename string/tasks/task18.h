//
// Created by serge on 08.03.2022.
//

#ifndef LABORATORY5E_TASK18_H
#define LABORATORY5E_TASK18_H
#include "../string_.h"

void atLastWords(char *string1, char *string2, int n1, int n2) {
    WordDescriptor word;
    bool isEqualStrings = n2 == n1;
    char *s1End = getEndOfString(string1);
    char *s2End = getEndOfString(string2) - 1;

    while (!isEqualStrings) {
        char *testVariable = findSpaceReverse(s2End, string2);
        getWordReverse(s2End,string2, &word);
        *s1End++ = ' ';
        while (word.begin != word.end) {
            *s1End++ = *word.begin++;
        }
        s2End = testVariable - 1;
        n1++;
        isEqualStrings = n2 == n1;
    }
}


void addMissingWords(char *string1, char *string2, int n1, int n2) {
    if (n2 > n1)
        atLastWords(string1, string2, n1, n2);
    else if (n1 > n2)
        atLastWords(string2, string1, n2, n1);
}

void test_addMissingWords_firstStringMoreSecond() {
    char s1[MAX_STRING_SIZE] = "aaaa bbbb cccc dddd";
    char s2[MAX_STRING_SIZE] = "aaaa bbbb";

    addMissingWords(s1, s2, 4, 2);

    ASSERT_STRING("aaaa bbbb dddd cccc", s2);
}

void test_addMissingWords_oneWordInFirst() {
    char s1[MAX_STRING_SIZE] = "aaaa";
    char s2[MAX_STRING_SIZE] = "aaaa bbbb";

    addMissingWords(s1, s2, 1, 2);

    ASSERT_STRING("aaaa bbbb", s1);
}

void test_addMissingWords_oneWordInStrings() {
    char s1[MAX_STRING_SIZE] = "aaaa";
    char s2[MAX_STRING_SIZE] = "";

    addMissingWords(s1, s2, 1, 0);

    ASSERT_STRING("aaaa", s1);
}

void test_addMissingWords_emptyStrings() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";

    addMissingWords(s1, s2, 0, 0);

    ASSERT_STRING("", s1);
    ASSERT_STRING("", s2);
}

void test_addMissingWords() {
    test_addMissingWords_firstStringMoreSecond();
    test_addMissingWords_oneWordInFirst();
    test_addMissingWords_oneWordInStrings();
    test_addMissingWords_emptyStrings();
}


#endif //LABORATORY5E_TASK18_H

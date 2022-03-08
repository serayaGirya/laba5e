//
// Created by serge on 08.03.2022.
//

#ifndef LABORATORY5E_TASK16_H
#define LABORATORY5E_TASK16_H
#include "../string_.h"

void wordDescriptorToString_task16(WordDescriptor word, char *destination) {
    *copy(word.begin, word.end, destination) = '\0';
}

WordDescriptor lastWordInFirstStringIsInSecondString_task16_16(char *string1, char *string2) {
    getBagOfWords(&_bag,string1);
    getBagOfWords(&_bag,string2);
    for(int i = _bag.size - 1; i >= 0; i++) {
        for (int j = 0; j < _bag2.size; ++j) {
            if (areWordsEqual(_bag.words[i], _bag2.words[j]))
                return _bag.words[i];
        }
    }
    WordDescriptor word = {NULL, NULL};
    return word;
}

void test_lastWordInFirstStringIsInSecondString_task16_StringsIsEmpty() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(lastWordInFirstStringIsInSecondString_task16_16(s1, s2), s3);
    ASSERT_STRING("", s3);
}

void test_lastWordInFirstStringIsInSecondString_task16_WordIsFound() {
    char s1[MAX_STRING_SIZE] = "touch in the night";
    char s2[MAX_STRING_SIZE] = "bla b night";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(lastWordInFirstStringIsInSecondString_task16_16(s1, s2), s3);
    ASSERT_STRING("night", s3);
}

void test_lastWordInFirstStringIsInSecondString_task16_WordIsNotFound() {
    char s1[MAX_STRING_SIZE] = "touch in the night";
    char s2[MAX_STRING_SIZE] = "bla b b";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(lastWordInFirstStringIsInSecondString_task16_16(s1, s2), s3);
    ASSERT_STRING("\0", s3);
}
void test_lastWordInFirstStringIsInSecondString_task16_firstFromTheEndIsFound() {
    char s1[MAX_STRING_SIZE] = "love in the night";
    char s2[MAX_STRING_SIZE] = "love b night";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(lastWordInFirstStringIsInSecondString_task16_16(s1, s2), s3);
    ASSERT_STRING("night", s3);
}

void test_lastWordInFirstStringIsInSecondString_task16_16() {
    test_lastWordInFirstStringIsInSecondString_task16_StringsIsEmpty();
    test_lastWordInFirstStringIsInSecondString_task16_WordIsFound();
    test_lastWordInFirstStringIsInSecondString_task16_WordIsNotFound();
    test_lastWordInFirstStringIsInSecondString_task16_firstFromTheEndIsFound();
}

#endif //LABORATORY5E_TASK16_H

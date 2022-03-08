//
// Created by serge on 08.03.2022.
//

#ifndef LABORATORY5E_TASK15_H
#define LABORATORY5E_TASK15_H
#include "../string_.h"

void lineWithWordsOtherThanLast(char *string) {
    WordDescriptor lastWord;
    getWordReverse(getEndOfString(string), string - 1, &lastWord);

    char *copy2 = string;
    char *copy1 = string;
    WordDescriptor now;
    while (getWord(copy2, &now)) {
        if (areWordsEqual(now, lastWord) != 0) {
            string = copy(now.begin, now.end, string);
            *string++ = ' ';
        }
        copy2 = now.end;
    }
    if (string != copy1)
        --string;
    *string = '\0';
}


void test_lineWithWordsOtherThanLast_someLastWords() {
    char s[MAX_STRING_SIZE] = "aaaa bbbb aaaa aaaa cccc aaaa";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("bbbb cccc", s);
}

void test_deleteSameWordsAsLastWord_equalWords() {
    char s[MAX_STRING_SIZE] = "aaaa aaaa";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("", s);
}

void test_lineWithWordsOtherThanLast_oneWord() {
    char s[MAX_STRING_SIZE] = "aaaa";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("", s);
}

void test_lineWithWordsOtherThanLast_empty() {
    char s[MAX_STRING_SIZE] = "";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("", s);
}

void test_lineWithWordsOtherThanLast_15() {
    test_lineWithWordsOtherThanLast_empty();
    test_lineWithWordsOtherThanLast_oneWord();
    test_lineWithWordsOtherThanLast_someLastWords();
    test_deleteSameWordsAsLastWord_equalWords();
}

#endif //LABORATORY5E_TASK15_H

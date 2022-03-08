//
// Created by serge on 08.03.2022.
//

#ifndef LABORATORY5E_TASK17_H
#define LABORATORY5E_TASK17_H
#include "../string_.h"

void lineWithWordsOtherThanLast_task17(char *string) {
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


void test_lineWithWordsOtherThanLast_task17_someLastWords() {
    char s[MAX_STRING_SIZE] = "aaaa bbbb aaaa aaaa cccc aaaa";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("bbbb cccc", s);
}

void test_deleteSameWordsAsLastWord_task17_equalWords() {
    char s[MAX_STRING_SIZE] = "aaaa aaaa";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("", s);
}

void test_lineWithWordsOtherThanLast_task17_oneWord() {
    char s[MAX_STRING_SIZE] = "aaaa";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("", s);
}

void test_lineWithWordsOtherThanLast_task17_empty() {
    char s[MAX_STRING_SIZE] = "";
    lineWithWordsOtherThanLast(s);
    ASSERT_STRING("", s);
}

void test_lineWithWordsOtherThanLast_task17_17() {
    test_lineWithWordsOtherThanLast_task17_empty();
    test_lineWithWordsOtherThanLast_task17_oneWord();
    test_lineWithWordsOtherThanLast_task17_someLastWords();
    test_deleteSameWordsAsLastWord_task17_equalWords();
}

#endif //LABORATORY5E_TASK17_H

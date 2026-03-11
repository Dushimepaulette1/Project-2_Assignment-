#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct wordStat {
    char name[40];
    int count;
};

void count_words(struct wordStat* statsArray, int uniqueCount) {
    int total = 0;
    struct wordStat* ptr = statsArray;
    for (int i = 0; i < uniqueCount; i++) {
        total += ptr->count;
        ptr++;
    }
    printf("Total words analyzed: %d\n", total);
}

void longest_word(struct wordStat* statsArray, int uniqueCount) {
    if (uniqueCount == 0) return;
    struct wordStat* longest = statsArray;
    struct wordStat* ptr = statsArray;
    for (int i = 0; i < uniqueCount; i++) {
        if (strlen(ptr->name) > strlen(longest->name)) {
            longest = ptr;
        }
        ptr++;
    }
    printf("Longest word: %s\n", longest->name);
}

void most_frequent(struct wordStat* statsArray, int uniqueCount) {
    if (uniqueCount == 0) return;
    struct wordStat* frequent = statsArray;
    struct wordStat* ptr = statsArray;
    for (int i = 0; i < uniqueCount; i++) {
        if (ptr->count > frequent->count) {
            frequent = ptr;
        }
        ptr++;
    }
    printf("Most frequent word: %s (used %d times)\n", frequent->name, frequent->count);
}

void average_word_length(struct wordStat* statsArray, int uniqueCount) {
    if (uniqueCount == 0) return;
    int totalCharacters = 0;
    int totalWords = 0;
    struct wordStat* ptr = statsArray;
    for (int i = 0; i < uniqueCount; i++) {
        totalCharacters += strlen(ptr->name) * ptr->count;
        totalWords += ptr->count;
        ptr++;
    }
    if (totalWords > 0) {
        printf("Average word length: %.2f characters\n", (float)totalCharacters / totalWords);
    }
}

int main() {
    char* textBuffer = (char*)malloc(2000 * sizeof(char));
    struct wordStat* dictionaryArray = (struct wordStat*)malloc(200 * sizeof(struct wordStat));
    int uniqueWords = 0;

    printf("Enter a paragraph from a book or article to analyze:\n");
    scanf(" %[^\n]", textBuffer);

    printf("\nText Buffer stored at memory address: %p\n", (void*)textBuffer);
    printf("Dictionary Array stored at memory address: %p\n\n", (void*)dictionaryArray);

    char* textPointer = textBuffer;
    char currentWord[40];
    int letterIndex = 0;

    while (*textPointer != '\0') {
        if (isalpha(*textPointer)) {
            currentWord[letterIndex] = tolower(*textPointer);
            letterIndex++;
        } else if (letterIndex > 0) {
            currentWord[letterIndex] = '\0';
            
            int found = 0;
            struct wordStat* searchPointer = dictionaryArray;
            for (int i = 0; i < uniqueWords; i++) {
                if (strcmp(searchPointer->name, currentWord) == 0) {
                    searchPointer->count++;
                    found = 1;
                    break;
                }
                searchPointer++;
            }
            
            if (found == 0) {
                struct wordStat* newEntry = dictionaryArray + uniqueWords;
                strcpy(newEntry->name, currentWord);
                newEntry->count = 1;
                uniqueWords++;
            }
            letterIndex = 0;
        }
        textPointer++;
    }

    if (letterIndex > 0) {
        currentWord[letterIndex] = '\0';
        struct wordStat* searchPointer = dictionaryArray;
        int found = 0;
        for (int i = 0; i < uniqueWords; i++) {
            if (strcmp(searchPointer->name, currentWord) == 0) {
                searchPointer->count++;
                found = 1;
                break;
            }
            searchPointer++;
        }
        if (found == 0) {
            struct wordStat* newEntry = dictionaryArray + uniqueWords;
            strcpy(newEntry->name, currentWord);
            newEntry->count = 1;
            uniqueWords++;
        }
    }

    void (*analysisPointers[4])(struct wordStat*, int) = {
        count_words,
        longest_word,
        most_frequent,
        average_word_length
    };

    for (int i = 0; i < 4; i++) {
        analysisPointers[i](dictionaryArray, uniqueWords);
    }

    free(textBuffer);
    free(dictionaryArray);
    return 0;
}

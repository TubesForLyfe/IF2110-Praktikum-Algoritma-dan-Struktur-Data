#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"

int main()
{
    /* KAMUS */
    int geser;
    int i;
    int j;
    char huruf[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    /* ALGORITMA */
    startWord();
    geser = currentWord.length;
    while (!endWord) {
        for (i=0; i<currentWord.length; i++) {
            j = 0;
            while (huruf[j] != currentWord.contents[i]) {
                j++;
            }
            j = (j + geser) % 26;
            printf("%c", huruf[j]);
        }
        advWord();
        if (!endWord) {
            printf(" ");
        }
    }
    printf("%c\n", MARK);
    return 0;
}

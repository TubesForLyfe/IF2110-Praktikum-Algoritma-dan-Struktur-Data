#include <stdio.h>
#include "tokenmachine.h"

boolean endToken;
Token currentToken;

void ignoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    /* ALGORITMA */
    while (currentChar == BLANK) {
        adv();
   }
}

void startToken() {
/* I.S. : currentChar sembarang
   F.S. : endToken = true, dan currentChar = MARK;
          atau endToken = false, currentToken adalah Token yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir Token */
    /* ALGORITMA */
    start();
    ignoreBlank();
    if (currentChar == MARK) {
        endToken = true;
    } else {
        endToken = false;
        salinToken();
    }
}

void advToken() {
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentToken adalah Token terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, maka endToken = true
   Proses : Akuisisi kata menggunakan procedure salinToken */
    /* ALGORITMA */
    ignoreBlank();
    if (currentChar == MARK) {
        endToken = true;
    } else {
        salinToken();
    }
}

void salinToken() {
/* Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
   I.S. : currentChar adalah karakter pertama dari Token
   F.S. : currentToken berisi Token yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata "dipotong" */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    i = 0;
    currentToken.val = 0;
    while ((currentChar != MARK) && (currentChar != BLANK)) {
        if (currentChar != '+' && currentChar != '-' && currentChar != '*' && currentChar != '/' && currentChar != '^') {
            currentToken.tkn = 'b';
            if (i < CAPACITY) {
                currentToken.val *= 10;
                currentToken.val += currentChar-'0';
                i++;
            }
        } else {
            currentToken.tkn = currentChar;
            currentToken.val = -1;
        }
        adv();
    }
}

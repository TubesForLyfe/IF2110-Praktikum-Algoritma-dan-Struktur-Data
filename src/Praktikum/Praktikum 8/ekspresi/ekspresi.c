#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tokenmachine.h"

int main()
{
    /* KAMUS */
    Stack s;
    int i;
    int val1, val2, val;
    /* ALGORITMA */
    CreateStack(&s);
    startToken();
    if (endToken) {
        printf("Ekspresi kosong\n");
    }
    else {
        while (!endToken) {
            if (currentToken.val != -1) {
                printf("%d\n", currentToken.val);
                push(&s,currentToken.val);
            } else {
                pop(&s,&val2);
                pop(&s,&val1);
                if (currentToken.tkn == '+') {
                    printf("%d + %d\n", val1, val2);
                    val = val1 + val2;
                } else if (currentToken.tkn == '-') {
                    printf("%d - %d\n", val1, val2);
                    val = val1 - val2;
                } else if (currentToken.tkn == '*') {
                    printf("%d * %d\n", val1, val2);
                    val = val1 * val2;
                } else if (currentToken.tkn == '/') {
                    printf("%d / %d\n", val1, val2);
                    val = val1 / val2;
                } else if (currentToken.tkn == '^') {
                    printf("%d ^ %d\n", val1, val2);
                    val = 1;
                    for (i=0; i<val2; i++) {
                        val *= val1;
                    }
                }
                printf("%d\n", val);
                push(&s,val);
            }
            advToken();
        }
        pop(&s,&val);
        printf("Hasil=%d\n", val);
    }
    return 0;
}


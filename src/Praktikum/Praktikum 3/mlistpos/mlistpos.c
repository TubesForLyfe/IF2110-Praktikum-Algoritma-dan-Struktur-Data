#include <stdio.h>
#include <stdlib.h>
#include "listpos.h"

int main()
{
    /* KAMUS */
    ListPos L;
    int X;
    /* ALGORITMA */
    CreateListPos(&L);
    readList(&L);
    scanf("%d", &X);
    displayList(L);
    printf("\n");
    if(indexOf(L,X) == IDX_UNDEF) {
        printf("%d tidak ada\n", X);
    } else {
        printf("%d\n", indexOf(L,X));
        sort(&L,true);
        if(X == ELMT(L,length(L)-1)) {
            printf("maksimum\n");
        }
        if(X == ELMT(L,0)) {
            printf("minimum\n");
        }
        if(length(L) % 2 == 0) {
            if(X == ELMT(L,(length(L)/2) -1)) {
                printf("median\n");
            }
        } else {
            if(X == ELMT(L,length(L)/2)) {
                printf("median\n");
            }
        }
    }
    return 0;
}

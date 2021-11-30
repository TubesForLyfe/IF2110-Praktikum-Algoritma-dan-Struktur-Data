#include <stdio.h>
#include <stdlib.h>
#include "list_linked.h"

int main()
{
    /* KAMUS */
    int N, Q, i, j, k, idx, val;
    List L;
    /* ALGORITMA */
    CreateList(&L);
    scanf("%d", &N);
    i = 1;
    while (i < N+1) {
        insertLast(&L,i);
        i++;
    }
    scanf("%d", &Q);
    for (j=0; j<Q; j++) {
        scanf("%d", &k);
        idx = indexOf(L,k);
        if (idx == IDX_UNDEF) {
            printf("miss ");
            deleteLast(&L,&val);
            insertFirst(&L,k);
            displayList(L);
            printf("\n");
        } else {
            printf("hit ");
            deleteAt(&L,idx,&val);
            insertFirst(&L,val);
            displayList(L);
            printf("\n");
        }
    }
    return 0;
}


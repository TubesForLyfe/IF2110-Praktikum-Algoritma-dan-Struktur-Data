#include <stdio.h>
#include <stdlib.h>
#include "listpos.h"

int main ()
{
    /* KAMUS */
    ListPos l1, l2;
    int i, val, max, min;
    /* ALGORITMA */
    CreateListPos(&l1);
    CreateListPos(&l2);
    readList(&l1);
    displayList(l1);
    printf("\n");
    readList(&l2);
    displayList(l2);
    printf("\n");
    printf("length l1, l2: %d, %d\n", length(l1), length(l2));
    scanf("%d", &i);
    if (isIdxValid(l1,i)) {
        printf("i Valid\n");
    } else {
        printf("i tidak Valid\n");
    }

    if (isIdxEff(l1,i)) {
        printf("i Eff\n");
    } else {
        printf("i tidak Eff\n");
    }

    if (isEmpty(l1)) {
        printf("l1 kosong\n");
    }
    if (isFull(l1)) {
        printf("l1 penuh\n");
    }

    if (isListEqual(l1,l2)) {
        printf("l1, l2 sama\n");
    }

    scanf("%d", &val);
    printf("%d\n", indexOf(l1,val));

    extremes(l1,&max,&min);
    printf("max: %d, min: %d\n", max, min);

    if(isAllEven(l1)) {
        printf("l1 semuanya genap\n");
    } else {
        printf("l1 tidak semuanya genap\n");
    }

    sort(&l2,true);
    displayList(l2);

    deleteLast(&l1,&val);
    displayList(l1);
    insertLast(&l2, val);
    displayList(l2);
    return 0;
}

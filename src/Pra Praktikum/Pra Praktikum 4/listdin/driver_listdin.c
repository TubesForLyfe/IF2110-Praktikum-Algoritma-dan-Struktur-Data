#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int main ()
{
    /* KAMUS */
    ListDin l1, l2;
    int i, val, max, min;
    /* ALGORITMA */
    CreateListDin(&l1,10);
    readList(&l1);
    displayList(l1);
    printf("\n%d\n", length(l1));
    copyList(l1,&l2);
    displayList(l2);
    printf("\n%d\n", getLastIdx(l1));
    scanf("%d", &i);
    if (isIdxValid(l1,i)) {
        printf("i Valid\n");
    }
    if (isIdxEff(l1,i)) {
        printf("i Eff\n");
    }
    if (isEmpty(l1)) {
        printf("l1 kosong\n");
    }
    if (isFull(l1)) {
        printf("l1 penuh\n");
    }
    displayList(plusMinusList(l1,l2,true));
    displayList(plusMinusList(l1,l2,false));
    printf("\n");
    readList(&l2);
    displayList(l2);
    if (isListEqual(l1,l2)) {
        printf("\nl1, l2 sama\n");
    }
    if (!isListEqual(l1,l2)) {
        printf("\nl1, l2 tidak sama\n");
    }
    scanf("%d", &val);
    printf("%d\n", indexOf(l1,val));
    extremes(l1,&max,&min);
    printf("%d %d\n%d %d\n", max, min, sumList(l1), countVal(l1,val));
    if (isAllEven(l1)) {
        printf("l1 genap\n");
    }
    sort(&l1,true);
    sort(&l2,false);
    displayList(l1);
    displayList(l2);
    deleteLast(&l1,&val);
    insertLast(&l2,val);
    printf("\n");
    displayList(l1);
    displayList(l2);
    printf("\n");
    growList(&l1,5);
    displayList(l1);
    printf("%d\n", CAPACITY(l1));
    shrinkList(&l2,5);
    displayList(l2);
    printf("%d\n", CAPACITY(l2));
    compactList(&l1);
    displayList(l1);
    printf("%d\n", CAPACITY(l1));
    dealocate(&l1);
    dealocate(&l2);
    return 0;
}

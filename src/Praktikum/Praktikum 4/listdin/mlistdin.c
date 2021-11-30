#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

int main()
{
    /* KAMUS */
    ListDin l;
    int Capacity, Q, op, num, i, j, del;
    /* ALGORITMA */
    scanf("%d", &Capacity);
    CreateListDin(&l,Capacity);
    readList(&l);
    scanf("%d", &Q);
    for (i=0;i<Q;i++) {
        scanf("%d", &op);
        if (op == 1 || op == 2 || op == 3) {
            scanf("%d", &num);
            if (op == 1) {
                if (NEFF(l) == CAPACITY (l)) {
                    printf("list sudah penuh\n");
                } else {
                    insertLast(&l,num);
                    printf("%d", CAPACITY(l));
                    displayList(l);
                    printf("\n");
                }
            } else if (op == 2) {
                growList(&l,num);
                printf("%d", CAPACITY(l));
                displayList(l);
                printf("\n");
            } else if (op == 3) {
                if (num <= CAPACITY(l)) {
                    shrinkList(&l,num);
                    if (CAPACITY(l) < NEFF(l)) {
                        for (j=CAPACITY(l);j<NEFF(l);j++) {
                            deleteLast(&l,&del);
                        }
                        NEFF(l) = CAPACITY(l);
                    }
                    printf("%d", CAPACITY(l));
                    displayList(l);
                    printf("\n");
                } else {
                    printf("list terlalu kecil\n");
                }
            }
        } else if (op == 4) {
            compactList(&l);
            printf("%d", CAPACITY(l));
            displayList(l);
            printf("\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main()
{
    /* KAMUS */
    BinTree b1, b2, b, p;
    int N, i, j, M, val;
    /* ALGORITMA */
    scanf("%d", &N);
    Address L[N];
    M = N;
    while (M % 2 == 0) {
        M = M/2;
    }
    if (M == 1) {
        for (i=0; i<N; i++) {
            scanf("%d", &val);
            b = newTreeNode(val);
            L[i] = b;
        }
        while (N != 1) {
            j = 0;
            for (i=0; i<N; i++) {
                if (i % 2 == 0) {
                    b1 = L[i];
                } else {
                    b2 = L[i];
                    CreateTree(ROOT(b1)+ROOT(b2),b1,b2,&b);
                    L[j] = b;
                    j++;
                }
            }
            N = N/2;
        }
        printTree(L[0],2);
    } else {
        printf("Jumlah masukan tidak sesuai\n");
    }
    return 0;
}


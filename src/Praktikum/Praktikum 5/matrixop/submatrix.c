#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    /* KAMUS */
    int TC;
    int t;
    int N, M;
    int i, j;
    int k, l;
    int x, y;
    int sum;
    int max;
    Matrix m, m2;
    /* ALGORITMA */
    scanf("%d", &TC);
    for (t=0; t<TC; t++) {
        max = 0;
        scanf("%d", &N);
        readMatrix(&m,N,N);
        scanf("%d", &M);
        CreateMatrix(M,M,&m2);
        if (M <= N) {
            for (i=0; i<=(ROWS(m)-M); i++) {
                for (j=0; j<=(COLS(m)-M); j++) {
                    k = i;
                    for (x=0; x<ROWS(m2); x++) {
                        l = j;
                        for (y=0; y<COLS(m2); y++) {
                            ELMT(m2,x,y) = ELMT(m,k,l);
                            l++;
                        }
                        k++;
                    }

                    sum = 0;
                    for (x=0; x<ROWS(m2); x++) {
                        for (y=0; y<COLS(m2); y++) {
                            sum += ELMT(m2,x,y);
                        }
                    }
                    if (sum > max) {
                        max = sum;
                    }
                }
            }
            printf("%d\n", max);
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main ()
{
    /* KAMUS */
    int N;
    TIME t1,t2,tMin,tMax;
    int i;
    /* ALGORITMA */
    /* Iniasiasi jam terkecil dan terbesar */
    Hour(tMin) = 23;
    Minute(tMin) = 59;
    Second(tMin) = 59;
    Hour(tMax) = 0;
    Hour(tMax) = 0;
    Hour(tMax) = 0;
    scanf("%d", &N);
    for (i=1; i<=N; i++) {
        printf("[%d]\n", i);
        BacaTIME(&t1);
        /* Mencari nilai terkecil tMin */
        if (TLT(t1,tMin)) {
            tMin = t1;
        }
        /* Mencari nilai terbesar tMax */
        if (TGT(t1,tMax)) {
            tMax = t1;
        }
        BacaTIME(&t2);
        /* Mencari nilai terkecil tMin */
        if (TLT(t2,tMin)) {
            tMin = t2;
        }
        /* Mencari nilai terbesar tMax */
        if (TGT(t2,tMax)) {
            tMax = t2;
        }
        /* Mencari durasi antara 2 waktu */
        if (TLT(t1,t2)) {
            printf("%d\n", Durasi(t1,t2));
        }
        if (TGT(t1,t2)) {
            printf("%d\n", Durasi(t2,t1));
        }
    }
    TulisTIME(tMin);
    printf("\n");
    TulisTIME(tMax);
    printf("\n");
    return 0;
}

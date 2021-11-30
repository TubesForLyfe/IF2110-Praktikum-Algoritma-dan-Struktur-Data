#include <stdio.h>
#include <stdlib.h>
#include "garis.h"

int main()
{
    /* KAMUS */
    GARIS L1, L2;
    /* ALGORITMA */
    BacaGARIS(&L1);
    BacaGARIS(&L2);
    TulisGARIS(L1);
    TulisGARIS(L2);
    printf("\n%.2f\n", PanjangGARIS(L1));
    printf("%.2f\n", Gradien(L2));
    GeserGARIS(&L2, 3, 3);
    TulisGARIS(L2);

    if (IsTegakLurus(L1,L2)) {
        printf("\nL1 dan L2 tegak lurus");
    }
    if (IsSejajar(L1,L2)) {
        printf("\nL1 dan L2 sejajar");
    }
    return 0;
}


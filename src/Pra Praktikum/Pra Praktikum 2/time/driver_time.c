#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
    /* KAMUS */
    TIME t1, t2;
    int N;
    /* ALGORITMA */
    /* Test Baca/Tulis */
    printf("Masukkan jam menit detik waktu pertama: ");
    BacaTIME(&t1);
    printf("Masukkan jam menit detik waktu kedua: ");
    BacaTIME(&t2);
    printf("Waktu t1 adalah ");
    TulisTIME(t1);
    printf(" dan t2 adalah ");
    TulisTIME(t2);

    /* Test Konversi */
    printf("\n\nKonversi t1 ke detik adalah %d\n", TIMEToDetik(t1));
    printf("t1 dikonversikan kembali ke waktu: ");
    DetikToTIME(TIMEToDetik(t1));
    printf("\n\n");

    /* Test Relational */
    if (TEQ(t1,t2)) {
        printf("t1 sama dengan t2\n");
    }
    if (TNEQ(t1,t2)) {
        printf("t1 tidak sama dengan t2\n");
    }
    if (TLT(t1,t2)) {
        printf("t1 lebih kecil dari t2\n\n");
    }
    if (TGT(t1,t2)) {
        printf("t1 lebih besar dari t2\n\n");
    }

    /* Test operasi aritmatika */
    printf("1 detik setelah t2: ");
    NextDetik(t2);
    printf("\nMasukan N: ");
    scanf("%d", &N);
    printf("N detik setelah t2: ");
    NextNDetik(t2,N);
    printf("\n1 detik sebelum t2: ");
    PrevDetik(t2);
    printf("\nMasukan N: ");
    scanf("%d", &N);
    printf("N detik sebelum t2: ");
    PrevNDetik(t2,N);

    /* Test Durasi */
    printf("\n\nDurasi antara t1 dan t2 adalah %d", Durasi(t1,t2));
    return 0;
}

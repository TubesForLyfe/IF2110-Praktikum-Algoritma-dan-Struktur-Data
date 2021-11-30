#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main()
{
    /* KAMUS */
    POINT p1, p2;
    float sudut;
    /* ALGORITMA */
    /* Test Baca dan Tulis */
    printf("Masukkan nilai absis dan ordinat titik pertama: ");
    BacaPOINT(&p1);
    printf("Masukkan nilai absis dan ordinat titik kedua: ");
    BacaPOINT(&p2);
    printf("p1 = ");
    TulisPOINT(p1);
    printf(" dan p2 = ");
    TulisPOINT(p2);
    printf("\n\n");

    /* Test Kesamaan */
    if (EQ(p1,p2)) {
        printf("p1 dan p2 sama\n");
    }
    if (NEQ(p1,p2)) {
        printf("p1 dan p2 berbeda\n");
    }

    /* Test Keberadaan Titik p1 */
    if (IsOrigin(p1)) {
        printf("p1 adalah titik origin\n");
    } else {
        printf("p1 bukan titik origin\n");
    }
    if (IsOnSbX(p1)) {
        printf("p1 berada di sumbu x\n");
    } else {
        printf("p1 tidak berada di sumbu x\n");
    }
    if (IsOnSbY(p1)) {
        printf("p1 berada di sumbu y\n");
    } else {
        printf("p1 tidak berada di sumbu y\n");
    }
    if (!IsOrigin(p1) && !IsOnSbX(p1) && !IsOnSbY(p1)){
        printf("Maka, p1 berada di kuadran %d\n\n", Kuadran(p1));
    }

    /* Operasi terhadap p2 */
    printf("Apabila Absis p2 ditambah 1 menjadi ");
    NextX(p2);
    printf("\nApabila Ordinat p2 ditambah 1 menjadi ");
    NextY(p2);
    printf("\nApabila dijumlahkan dengan p1 menjadi ");
    PlusDelta(p2,Absis(p1),Ordinat(p1));
    printf("\nCerminan p2 terhadap sumbu X adalah ");
    MirrorOf(p2,true);
    printf("\nCerminan p2 terhadap sumbu Y adalah ");
    MirrorOf(p2,false);
    printf("\nJarak p2 terhadap (0,0) adalah %.2f\n", Jarak0(p2));
    printf("Panjang garis antara p2 dan p1 adalah %.2f\n\n", Panjang(p1,p2));

    /* Perubahan nilai pada p2 */
    printf("Menggeser p2 sejauh p1 maka menjadi ");
    Geser(&p2,Absis(p1),Ordinat(p1));
    TulisPOINT(p2);
    printf("\nKemudian p2 digeser ke sumbu x menjadi ");
    GeserKeSbX(&p2);
    TulisPOINT(p2);
    printf("\nKemudian p2 digeser lagi ke sumbu y menjadi ");
    GeserKeSbY(&p2);
    TulisPOINT(p2);

    /* Perubahan pencerminan pada p1 */
    printf("\n\nMencerminkan p1 terhadap sumbu x menjadi ");
    Mirror(&p1,true);
    TulisPOINT(p1);
    printf("\nLalu, p1 dicerminkan kembali terhadap sumbu y menjadi ");
    Mirror(&p1,false);
    TulisPOINT(p1);

    /* Putar p1 dengan sudut tertentu */
    printf("\n\nMasukan sudut untuk memutar p1: ");
    scanf("%f", &sudut);
    printf("Titik p1 menjadi ");
    Putar(&p1,sudut);
    TulisPOINT(p1);
    return 0;
}


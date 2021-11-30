#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    /* KAMUS */
    Matrix M1, M2;
    int i,j;
    /* ALGORITMA */
    readMatrix(&M1,3,3);
    displayMatrix(M1);
    scanf("\n%d %d", &i, &j);
    if (isIdxValid(i,j)) {
        printf("Index valid\n");
    }
    printf("%d %d %d\n", getLastIdxRow(M1), getLastIdxRow(M1), getElmtDiagonal(M1,i));
    if (isIdxEff(M1,i,j)) {
        printf("Index efektif\n");
    }
    copyMatrix(M1,&M2);
    displayMatrix(addMatrix(M1,M2));
    printf("\n\n");
    displayMatrix(subtractMatrix(M1,M2));
    printf("\n\n");
    displayMatrix(multiplyMatrix(M1,M2));
    printf("\n\n");
    displayMatrix(multiplyConst(M1,i));
    printf("\n\n");
    if (isEqual(M1,M2)) {
        printf("M1 M2 sama\n");
    }
    pMultiplyConst(&M2,i);
    if (isNotEqual(M1,M2)) {
        printf("M1 M2 tidak sama\n");
    }
    if (isSizeEqual(M1,M2)) {
        printf("Ukuran M1 M2 sama\n");
    }
    printf("%d\n", count(M1));
    if (isSquare(M1)) {
        printf("M1 persegi\n");
    }
    if (isSymmetric(M1)) {
        printf("M1 simetrik\n");
    }
    if (isIdentity(M1)) {
        printf("M1 identitas\n");
    }
    if (isSparse(M1)) {
        printf("M1 sparse\n");
    }
    displayMatrix(inverse1(M1));
    pInverse1(&M2);
    printf("\n%d\n", determinant(M1));
    displayMatrix(M2);
    transpose(&M2);
    printf("\n\n");
    displayMatrix(M2);
    return 0;
}


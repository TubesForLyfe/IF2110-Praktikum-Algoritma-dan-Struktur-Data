#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    /* KAMUS */
    VECTOR v1, v2, v3;
    float s;
    /* ALGORITMA */
    v1 = MakeVector(2,3);
    v2 = MakeVector(3,4);
    TulisVector(v1);
    TulisVector(v2);
    printf("\n\n%.2f\n", Magnitude(v2));
    v3 = Add(v1,v2);
    TulisVector(v3);
    printf("\n");
    v3 = Substract(v2,v1);
    TulisVector(v3);
    printf("\n%.2f\n", Dot(v1,v2));
    scanf("%f", &s);
    v3 = Multiply(v1,s);
    TulisVector(v3);
    return 0;
}

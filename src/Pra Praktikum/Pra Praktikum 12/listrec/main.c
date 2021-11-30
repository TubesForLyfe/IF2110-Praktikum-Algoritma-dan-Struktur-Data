#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

int main()
{
    /* KAMUS */
    List l1, l2;
    /* ALGORITMA */
    l2 = konso(l1,5);
    displayList(l2);
    printf("\n");
    l2 = konso(l1,2);
    displayList(l2);
    printf("\n");

    return 0;
}

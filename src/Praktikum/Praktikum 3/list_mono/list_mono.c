#include <stdio.h>
#include <stdlib.h>
#include "listpos.h"

int main()
{
    /* KAMUS */
    ListPos L;
    boolean asc = true;
    boolean dsc = true;
    boolean stc = true;
    int i = 0;
    /* ALGORITMA */
    CreateListPos(&L);
    readList(&L);
    while((asc) && (i < length(L)-1)) {
        if (ELMT(L,i) > ELMT(L,i+1)) {
            asc = false;
        }
        i++;
    }
    i = 0;
    while((dsc) && (i < length(L)-1)) {
        if (ELMT(L,i) < ELMT(L,i+1)) {
            dsc = false;
        }
        i++;
    }
    i = 0;
    while((stc) && (i < length(L)-1)) {
        if (ELMT(L,i) != ELMT(L,i+1)) {
            stc = false;
        }
        i++;
    }

    if(stc) {
        asc = false;
        dsc = false;
        printf("Static Monotonic List\n");
    }
    if(asc) {
        printf("Non-descending Monotonic List\n");
    }
    if(dsc) {
        printf("Non-ascending Monotonic List\n");
    }
    if(!asc && !dsc && !stc) {
        printf("Non-monotonic List\n");
    }
    return 0;
}

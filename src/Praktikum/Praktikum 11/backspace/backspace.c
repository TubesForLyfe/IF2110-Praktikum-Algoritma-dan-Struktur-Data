#include <stdio.h>
#include <stdlib.h>
#include "stack_linked.h"

int main()
{
    /* KAMUS */
    Stack s1, s2;
    int A, B, val, i;
    boolean flag;
    /* ALGORITMA */
    scanf("%d %d", &A, &B);
    CreateStack(&s1);
    CreateStack(&s2);
    for (i=0; i<A; i++) {
        scanf("%d", &val);
        if (val == 0 && !isEmpty(s1)) {
            pop(&s1,&val);
        } else if (val != 0) {
            push(&s1,val);
        }
    }
    for (i=0; i<B; i++) {
        scanf("%d", &val);
        if (val == 0 && !isEmpty(s2)) {
            pop(&s2,&val);
        } else if (val != 0) {
            push(&s2,val);
        }
    }

    flag = true;
    while(flag && !isEmpty(s1) && !isEmpty(s2)) {
        if (TOP(s1) != TOP(s2)) {
            flag = false;
        } else {
            pop(&s1,&val);
            pop(&s2,&val);
        }
    }
    if (isEmpty(s1) && isEmpty(s2)) {
        printf("Sama\n");
    } else {
        printf("Tidak sama\n");
    }
    return 0;
}

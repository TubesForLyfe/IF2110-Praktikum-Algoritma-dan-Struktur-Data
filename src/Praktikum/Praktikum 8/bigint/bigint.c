#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    /* KAMUS */
    Stack S1, S2, SPlus;
    char str[100];
    int i, val1, val2, val, sum;
    /* ALGORITMA */
    CreateStack(&S1);
    CreateStack(&S2);
    CreateStack(&SPlus);
    scanf("%s", str);
    i = 0;
    while (str[i] != '#') {
        push(&S1, str[i]-'0');
        i++;
    }

    scanf("%s", str);
    i = 0;
    while (str[i] != '#') {
        push(&S2, str[i]-'0');
        i++;
    }

    while(!isEmpty(S1) && !isEmpty(S2)) {
        pop(&S1,&val1);
        pop(&S2,&val2);
        push(&SPlus, (val1+val2));
    }
    while(!isEmpty(S1)) {
        pop(&S1,&val1);
        push(&SPlus,val1);
    }
    while(!isEmpty(S2)) {
        pop(&S2,&val2);
        push(&SPlus,val2);
    }

    sum = 0;
    while(!isEmpty(SPlus)) {
        pop(&SPlus,&val);
        sum *= 10;
        sum += val;
    }

    printf("%d\n", sum);
    return 0;
}


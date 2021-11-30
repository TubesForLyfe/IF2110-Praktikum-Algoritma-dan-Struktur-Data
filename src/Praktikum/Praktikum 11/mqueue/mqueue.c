#include <stdio.h>
#include <stdlib.h>
#include "queue_linked.h"

int main()
{
    /* KAMUS */
    Queue q;
    int n, i, time, val;
    /* ALGORITMA */
    scanf("%d", &n);
    CreateQueue(&q);
    for (i=0; i<n; i++) {
        scanf("%d", &time);
        enqueue(&q,time);
        while (time-HEAD(q) > 300) {
            dequeue(&q,&val);
        }
        printf("%d\n", length(q));
    }
    return 0;
}

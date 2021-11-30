#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

float avgElmt (Queue Q) {
/* Menghasilkan rata-rata elemen dalam queue Q yang tidak kosong */
    /* KAMUS */
    int i;
    float sum;
    /* ALGORITMA */
    for (i=IDX_HEAD(Q); i<=IDX_TAIL(Q); i++) {
        sum += Q.buffer[i];
    }
    return (sum/length(Q));
}

int main()
{
    /* KAMUS */
    Queue Q;
    int kode, waktu;
    /* ALGORITMA */
    CreateQueue(&Q);
    scanf("%d", &kode);
    while (kode != 0) {
        if (kode == 1) {
            scanf("%d", &waktu);
            if (isFull(Q)) {
                printf("Queue penuh\n");
            } else {
                enqueue(&Q,waktu);
            }
            scanf("%d", &kode);
        } else if (kode == 2) {
            if (isEmpty(Q)) {
                printf("Queue kosong\n");
            } else {
                dequeue(&Q,&waktu);
            }
            scanf("%d", &kode);
        }
    }

    printf("%d\n", length(Q));
    if (length(Q) == 0) {
        printf("Tidak bisa dihitung\n");
    } else {
        printf("%.2f\n", avgElmt(Q));
    }
    return 0;
}

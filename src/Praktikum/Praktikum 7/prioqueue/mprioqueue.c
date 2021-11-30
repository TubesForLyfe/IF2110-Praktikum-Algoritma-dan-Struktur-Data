#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

int main()
{
    /* KAMUS */
    int N, T, I, M, D;
    int i,j,k;
    ElType L;
    int sum = 0;
    PrioQueue Q;
    /* ALGORITMA */
    scanf("%d", &N);
    if (N == 0) {
        printf("Tidak ada layanan\n");
    } else {
        CreatePrioQueue(&Q);
        for (i=0; i<N; i++) {
            scanf("%d %d %d %d", &T, &I, &M, &D);
            L.id = I;
            L.tArrival = T;
            L.score = M;
            L.dService = D;
            enqueue(&Q,L);
        }

        i = 0;
        while (i<N) {
            if (sum < Q.buffer[i].tArrival) {
                sum = (Q.buffer[i].tArrival + Q.buffer[i].dService);
            } else {
                sum += Q.buffer[i].dService;
            }
            j = i+1;
            while (Q.buffer[j].tArrival < sum && j < N) {
                k = j;
                while (k-1 != i) {
                    if (Q.buffer[k].score > Q.buffer[k-1].score) {
                        L = Q.buffer[k];
                        Q.buffer[k] = Q.buffer[k-1];
                        Q.buffer[k-1] = L;
                    k--;
                    }
                }
                j++;
            }
            i++;
        }

        for (i=0; i<N; i++) {
            if (i == 0) {
                printf("%d %d 0\n", Q.buffer[i].tArrival, Q.buffer[i].id);
                sum = (Q.buffer[i].tArrival + Q.buffer[i].dService);
            } else {
                if (sum > Q.buffer[i].tArrival) {
                    printf("%d %d %d\n", sum, Q.buffer[i].id, (sum - Q.buffer[i].tArrival));
                    sum += Q.buffer[i].dService;
                } else {
                    printf("%d %d 0\n", Q.buffer[i].tArrival, Q.buffer[i].id);
                    sum = (Q.buffer[i].tArrival + Q.buffer[i].dService);
                }
            }
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

void deleteRR (List *l, ElType tQ) {
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
- jika INFO(last)>tQ, maka last "diantrikan" kembali sebagai first elemen dengan INFO(last)=INFO(last)-tQ
- jika INFO(last)<=tQ, maka deleteLast(l,x) dan menampilkan x ke layar */
/* Jika l kosong, cetak "List kosong" */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai aturan round-robin.
l mungkin menjadi kosong. */
    /* KAMUS */
    Address p;
    int x;
    /* ALGORITMA */
    if (isEmpty(*l)) {
        printf("List kosong");
    } else {
        p = FIRST(*l);
        while (NEXT(p) != FIRST(*l)) {
            p = NEXT(p);
        }
        if (INFO(p) > tQ) {
            INFO(p) -= tQ;
            printf("%d", tQ);
            FIRST(*l) = p;
        } else {
            deleteLast(l,&x);
            printf("%d", x);
        }
    }
}

float average (List l) {
/* Menghasilkan nilai rata-rata elemen l. l tidak kosong. */
    /* KAMUS */
    Address p;
    float sum, count;
    /* ALGORITMA */
    sum = 0;
    count = 0;
    p = FIRST(l);
    while (NEXT(p) != FIRST(l)) {
        sum += INFO(p);
        count += 1;
        p = NEXT(p);
    }
    sum += INFO(p);
    count += 1;
    return (sum/count);
}

int main()
{
    /* KAMUS */
    int TQ, val;
    List L;
    char c;
    /* ALGORITMA */
    CreateList(&L);
    scanf("%d", &TQ);
    while (TQ <= 0) {
        scanf("%d", &TQ);
    }
    scanf(" %c", &c);
    while (c != 'F') {
        if (c == 'A') {
            scanf("%d", &val);
            insertFirst(&L,val);
        } else if (c == 'D') {
            deleteRR(&L,TQ);
            printf("\n");
        } else{
            printf("Kode salah\n");
        }
        scanf(" %c", &c);
    }
    if (isEmpty(L)) {
        printf("Proses selesai\n");
    } else {
        printf("%.2f\n", average(L));
    }
    return 0;
}

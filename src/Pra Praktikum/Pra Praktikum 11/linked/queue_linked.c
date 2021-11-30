#include <stdio.h>
#include "queue_linked.h"

/* Prototype manajemen memori */
Address newNode(ElType x) {
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x,
   atau NULL jika alokasi gagal */
   /* KAMUS */
   Address p;
   /* ALGORITMA */
   p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}
boolean isEmpty(Queue q) {
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
    /* ALGORITMA */
    return (ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
}
int length(Queue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
    /* KAMUS */
    int count;
    Address p;
    /* ALGORITMA */
    count = 0;
    if (!isEmpty(q)) {
        p = ADDR_HEAD(q);
        while (p != ADDR_TAIL(q)) {
            p = NEXT(p);
            count++;
        }
        count++;
    }
    return count;
}

/*** Kreator ***/
void CreateQueue(Queue *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
    /* ALGORITMA */
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x) {
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = newNode(x);
    if (p != NULL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}
void dequeue(Queue *q, ElType *x) {
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = ADDR_HEAD(*q);
    *x = HEAD(*q);
    if (ADDR_HEAD(*q) == ADDR_TAIL(*q)) {
        ADDR_HEAD(*q) = NULL;
        ADDR_TAIL(*q) = NULL;
    } else {
        ADDR_HEAD(*q) = NEXT(p);
        NEXT(p) = NULL;
    }
    free(p);
}

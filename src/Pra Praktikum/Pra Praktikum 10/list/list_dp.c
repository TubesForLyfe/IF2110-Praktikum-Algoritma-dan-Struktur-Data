#include <stdio.h>
#include "list_dp.h"

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    /* ALGORITMA */
    return (FIRST(l) == NULL && LAST(l) == NULL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
/* I.S. l sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    /* ALGORITMA */
    FIRST(*l) = NULL;
    LAST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL. */
/* Misalnya: menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL, PREV(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL. */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
        PREV(p) = NULL;
    }
    return p;
}
void deallocate (Address p) {
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
    /* ALGORITMA */
    free(p);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val) {
/* Mencari apakah ada elemen list dengan INFO(P)=val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = FIRST(l);
    while (p != NULL && INFO(p) != val) {
        p = NEXT(p);
    }
    return p;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = allocate(val);
    if (p != NULL) {
        if (isEmpty(*l)) {
            LAST(*l) = p;
        } else {
            NEXT(p) = FIRST(*l);
            PREV(FIRST(*l)) = p;
        }
        FIRST(*l) = p;
    }
}
void insertLast(List *l, ElType val) {
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = allocate(val);
    if (p != NULL) {
        if (isEmpty(*l)) {
            FIRST(*l) = p;
        } else {
            PREV(p) = LAST(*l);
            NEXT(LAST(*l)) = p;
        }
        LAST(*l) = p;
    }
}
void insertAfter(List *L, Address p, Address pRec) {
/* I.S. pRec pasti elemen list; p sudah dialokasi */
/* F.S. Insert p sebagai elemen sesudah elemen beralamat pRec */
    /* KAMUS */
    Address loc;
    /* ALGORITMA */
    if (pRec == LAST(*L)) {
        NEXT(p) = NULL;
        PREV(p) = LAST(*L);
        NEXT(LAST(*L)) = p;
        LAST(*L) = p;
    } else {
        loc = FIRST(*L);
        while (loc != pRec) {
            loc = NEXT(loc);
        }
        NEXT(p) = NEXT(loc);
        PREV(p) = loc;
        PREV(NEXT(loc)) = p;
        NEXT(loc) = p;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);
    if (LAST(*l) == FIRST(*l)) {
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
    } else {
        FIRST(*l) = NEXT(p);
        PREV(FIRST(*l)) = NULL;
        NEXT(p) = NULL;
    }
    deallocate(p);
}
void deleteLast(List *l, ElType *val) {
/* I.S. list l tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = LAST(*l);
    *val = INFO(p);
    if (LAST(*l) == FIRST(*l)) {
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
    } else {
        LAST(*l) = PREV(p);
        NEXT(LAST(*l)) = NULL;
        PREV(p) = NULL;
    }
    deallocate(p);
}
void deleteAfter(List *l, Address *pDel, Address pRec) {
/* I.S. List tidak kosong. pRec adalah anggota list.
        NEXT(pRec)!=NULL */
/* F.S. Menghapus NEXT(pRec): */
    /* KAMUS */
    Address loc;
    /* ALGORITMA */
    if (pRec == PREV(LAST(*l))) {
        loc = LAST(*l);
        LAST(*l) = PREV(LAST(*l));
        NEXT(LAST(*l)) = NULL;
    } else {
        loc = FIRST(*l);
        while (PREV(loc) != pRec) {
            loc = NEXT(loc);
        }
        NEXT(PREV(loc)) = NEXT(loc);
        PREV(NEXT(loc)) = PREV(loc);
        NEXT(loc) = NULL;
    }
    PREV(loc) = NULL;
    *pDel = loc;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = FIRST(l);
    printf("[");
    while (p != NULL) {
        if (p != LAST(l)) {
            printf("%d,", INFO(p));
        } else {
            printf("%d", INFO(p));
        }
        p = NEXT(p);
    }
    printf("]");
}
void displayListBackwards(List l) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = LAST(l);
    printf("[");
    while (p != NULL) {
        if (p != FIRST(l)) {
            printf("%d,", INFO(p));
        } else {
            printf("%d", INFO(p));
        }
        p = PREV(p);
    }
    printf("]");
}

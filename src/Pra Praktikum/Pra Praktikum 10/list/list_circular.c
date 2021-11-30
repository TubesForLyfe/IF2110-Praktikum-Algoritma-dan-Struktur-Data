#include <stdio.h>
#include "list_circular.h"

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    /* ALGORITMA */
    return (FIRST(l) == NULL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    /* ALGORITMA */
    FIRST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val) {
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = (Address) malloc(sizeof(ElmtList));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
void deallocate(Address P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
    /* ALGORITMA */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val) {
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    if (isEmpty(l)) {
        return NULL;
    } else {
        p = FIRST(l);
        while (NEXT(p) != FIRST(l) && INFO(p) != val) {
            p = NEXT(p);
        }
        if (INFO(p) == val) {
            return p;
        } else {
            return NULL;
        }
    }
}

boolean addrSearch(List l, Address p) {
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */
    /* KAMUS */
    Address loc;
    /* ALGORITMA */
    loc = FIRST(l);
    if (!isEmpty(l)) {
        while (NEXT(loc) != FIRST(l) && p != loc) {
            loc = NEXT(loc);
        }
    }
    return (p == loc);
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
/* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */
    /* KAMUS */
    Address p, loc;
    /* ALGORITMA */
    p = allocate(val);
    if (p != NULL) {
        if (isEmpty(*l)) {
            NEXT(p) = p;
        } else {
            loc = FIRST(*l);
            while (NEXT(loc) != FIRST(*l)) {
                loc = NEXT(loc);
            }
            NEXT(p) = FIRST(*l);
            NEXT(loc) = p;
        }
        FIRST(*l) = p;
    }
}
void insertLast(List *l, ElType val) {
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */
    /* KAMUS */
    Address p, loc;
    /* ALGORITMA */
    p = allocate(val);
    if (p != NULL) {
        if (isEmpty(*l)) {
            NEXT(p) = p;
            FIRST(*l) = p;
        } else {
            loc = FIRST(*l);
            while (NEXT(loc) != FIRST(*l)) {
                loc = NEXT(loc);
            }
            NEXT(p) = FIRST(*l);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val) {
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama List l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen pertama list lama di-dealokasi */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);
    if (NEXT(p) == FIRST(*l)) {
        FIRST(*l) = NULL;
    } else {
        while (NEXT(p) != FIRST(*l)) {
            p = NEXT(p);
        }
        NEXT(p) = NEXT(FIRST(*l));
        p = FIRST(*l);
        FIRST(*l) = NEXT(p);
        NEXT(p) = NULL;
    }
    deallocate(p);
}
void deleteLast(List *l, ElType * val) {
/* I.S. List l tidak kosong */
/* F.S. val adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
/*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen terakhir list lama di-dealokasi */
    /* KAMUS */
    Address p, loc;
    /* ALGORITMA */
    p = FIRST(*l);
    if (NEXT(p) == FIRST(*l)) {
        FIRST(*l) = NULL;
    } else {
        while (NEXT(NEXT(p)) != FIRST(*l)) {
            p = NEXT(p);
        }
        loc = p;
        p = NEXT(p);
        NEXT(loc) = FIRST(*l);
        NEXT(p) = NULL;
    }
    *val = INFO(p);
    deallocate(p);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    printf("[");
    p = FIRST(l);
    while (p != NULL && NEXT(p) != FIRST(l)) {
        printf("%d,", INFO(p));
        p = NEXT(p);
    }
    if (!isEmpty(l)) {
        printf("%d", INFO(p));
    }
    printf("]");
}

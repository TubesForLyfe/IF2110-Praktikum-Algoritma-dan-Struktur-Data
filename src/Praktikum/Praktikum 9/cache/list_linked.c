#include <stdio.h>
#include "list_linked.h"

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    /* ALGORITMA */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
/* Mengirim true jika list kosong */
    /* ALGORITMA */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    /* KAMUS */
    int ctr;
    Address p;
    /* ALGORITMA */
    ctr = 0;
    p = l;
    while (ctr < idx) {
        ctr++;
        p = NEXT(p);
    }
    return (INFO(p));
}

void setElmt(List *l, int idx, ElType val) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    /* KAMUS */
    int ctr;
    Address p;
    /* ALGORITMA */
    ctr = 0;
    p = *l;
    while (ctr < idx) {
        ctr++;
        p = NEXT(p);
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val) {
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    /* KAMUS */
    boolean found;
    Address p;
    int idx;
    /* ALGORITMA */
    found = false;
    idx = 0;
    p = l;
    while (p != NULL && !found) {
        if (INFO(p) == val) {
            found = true;
        } else {
            idx++;
            p = NEXT(p);
        }
    }

    if (found) {
        return idx;
    } else {
        return IDX_UNDEF;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = newNode(val);
    if (p != NULL) {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    Address p, last;
    /* ALGORITMA */
    if (isEmpty(*l)) {
        insertFirst(l,val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            last = *l;
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    Address p, loc;
    int ctr;
    /* ALGORITMA */
    if (idx == 0) {
        insertFirst(l,val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            ctr = 0;
            loc = *l;
            while (ctr < idx - 1) {
                ctr++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}
void deleteLast(List *l, ElType *val) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS */
    Address p, loc;
    /* ALGORITMA */
    p = *l;
    loc = NULL;
    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL) {
        *l = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val) {
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    /* KAMUS */
    Address p, loc;
    int ctr;
    /* ALGORITMA */
    if (idx == 0) {
        deleteFirst(l,val);
    } else {
        ctr = 0;
        loc = *l;
        while (ctr < idx - 1) {
            ctr++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* KAMUS */
    Address p;
    /* ALGORITMA */
    p = l;
    printf("[");
    while (p != NULL) {
        if (NEXT(p) == NULL) {
            printf("%d", INFO(p));
        } else {
            printf("%d,", INFO(p));
        }
        p = NEXT(p);
    }
    printf("]");
}

int length(List l) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    /* KAMUS */
    int count;
    Address p;
    /* ALGORITMA */
    count = 0;
    p = l;
    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P) {
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
    /* KAMUS */
    Address loc;
    boolean flag;
    /* ALGORITMA */
    flag = false;
    loc = L;
    while (loc != NULL && !flag) {
        if (loc == P){
            flag = true;
        } else {
            loc = NEXT(loc);
        }
    }
    return flag;
}
Address searchPrec(List L, ElType X) {
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
    /* KAMUS */
    Address loc;
    /* ALGORITMA */
    loc = L;
    if (INFO(loc) == X || INFO(loc) == NULL) {
        return NULL;
    } else {
        while (NEXT(loc) != X && loc != NULL) {
            loc = NEXT(loc);
        }
        if (loc != NULL) {
            return loc;
        } else {
            return NULL;
        }
    }
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
ElType max(List L) {
/* Mengirimkan nilai info(P) yang maksimum */
    /* KAMUS */
    Address p;
    int max;
    /* ALGORITMA */
    p = L;
    max = INFO(p);
    while (p != NULL) {
        if (INFO(p) > max) {
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return max;
}
Address adrMax(List L) {
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    /* KAMUS */
    Address p;
    Address max;
    /* ALGORITMA */
    p = L;
    max = p;
    while (p != NULL) {
        if (INFO(p) > INFO(max)) {
            max = p;
        }
        p = NEXT(p);
    }
    return max;
}
ElType min(List L) {
/* Mengirimkan nilai info(P) yang minimum */
    /* KAMUS */
    Address p;
    int min;
    /* ALGORITMA */
    p = L;
    min = INFO(p);
    while (p != NULL) {
        if (INFO(p) < min) {
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return min;
}
Address adrMin(List L) {
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    /* KAMUS */
    Address p;
    Address min;
    /* ALGORITMA */
    p = L;
    min = p;
    while (p != NULL) {
        if (INFO(p) < INFO(min)) {
            min = p;
        }
        p = NEXT(p);
    }
    return min;
}
float average(List L) {
/* Mengirimkan nilai rata-rata info(P) */
    /* KAMUS */
    Address p;
    float sum, count;
    /* ALGORITMA */
    sum = 0;
    count = 0;
    p = L;
    while (p != NULL) {
        sum += INFO(p);
        count++;
        p = NEXT(p);
    }
    return (sum/count);
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    /* KAMUS */
    Address p;
    List l3;
    /* ALGORITMA */
    CreateList(&l3);
    p = l1;
    while (p != NULL) {
        insertLast(&l3,INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p != NULL) {
        insertLast(&l3,INFO(p));
        p = NEXT(p);
    }
    return l3;
}

void delAll(List *L) {
/* Delete semua elemen list dan alamat elemen di-dealokasi */
    /* KAMUS */
    int val;
    /* ALGORITMA */
    while (*L != NULL) {
        deleteLast(L, &val);
    }
}

void inverseList(List *L) {
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    /* KAMUS */
    int i, val;
    /* ALGORITMA */
    i = length(*L)-1;
    while (i != 0) {
        i--;
        deleteAt(L,i,&val);
        insertLast(L,val);
    }
}

List fInverseList(List L) {
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
    /* KAMUS */
    int i;
    List L2;
    /* ALGORITMA */
    i = 0;
    while (i != length(L)) {
        insertFirst(&L2,getElmt(L,i));
        i++;
    }
    return L2;
}

void copyList(List *L1, List *L2) {
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
    /* ALGORITMA */
    *L2 = *L1;
}

List fCopyList(List L) {
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
    /* ALGORITMA */
    List L2;
    /* ALGORITMA */
    CreateList(&L2);
    copyList(&L,&L2);
    return L2;
}

void cpAllocList(List Lin, List *Lout) {
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
    /* KAMUS */
    boolean flag;
    Address p, loc;
    int val;
    /* ALGORITMA */
    flag = true;
    CreateList(Lout);
    while (Lin != NULL ) {
        p = newNode(INFO(Lin));
        if (p != NULL) {
            if (isEmpty(*Lout)) {
                *Lout = p;
            } else {
                NEXT(loc) = p;
            }
            loc = p;
            Lin = NEXT(Lin);
        } else {
            flag = false;
        }
    }

    if (!flag) {
        while (*Lout != NULL) {
            deleteLast(Lout,&val);
        }
    }
}

void splitList(List *L1, List *L2, List L) {
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */
    /* ALGORITMA */
    int i, val;
    List Lcopy;
    /* ALGORITMA */
    Lcopy = fCopyList(L);
    i = 0;
    CreateList(L1);
    CreateList(L2);
    while (i < length(L)/2) {
        deleteFirst(&Lcopy, &val);
        insertLast(L1, val);
        i++;
    }
    while (Lcopy != NULL) {
        deleteFirst(&Lcopy, &val);
        insertLast(L2, val);
    }
}

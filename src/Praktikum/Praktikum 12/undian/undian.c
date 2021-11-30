#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

List splitOddIndex(List l) {
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
ganjil pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
    /* ALGORITMA */
    if (isEmpty(l)) {
        return NULL;
    } else if (tail(l) == NULL) {
        return l;
    } else {
        return konso(splitOddIndex(tail(tail(l))),head(l));
    }
}

List splitEvenIndex(List l) {
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
genap pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
    /* ALGORITMA */
    if (isEmpty(l)) {
        return NULL;
    } else if (tail(l) == NULL) {
        return NULL;
    } else {
        return konso(splitEvenIndex(tail(tail(l))),head(tail(l)));
    }
}

List splitBeforeX(List l, ElType x) {
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen di depan elemen
dengan nilai x pada list l, sesuai dengan urutannya. Jika x tidak ada pada list, maka
kembalikan list l.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
    /* ALGORITMA */
    if (isEmpty(l)) {
        return NULL;
    } else if (head(l) == x) {
        return NULL;
    } else {
        return konso(splitBeforeX(tail(l),x),head(l));
    }
}

List reverseList(List l) {
/* Mengembalikan sebuah list baru yang urutannya merupakan kebalikan dari list l.
Jika l kosong, kembalikan list kosong. */
    /* ALGORITMA */
    if (isEmpty(l)) {
        return NULL;
    } else {
        return konsb(reverseList(tail(l)),head(l));
    }
}

int main()
{
    /* KAMUS */
    List l;
    char x;
    int n;
    /* ALGORITMA */
    l = NULL;
    scanf("%c", &x);
    while (x != 'X') {
        if (x == 'F') {
            scanf("%d", &n);
            l = konso(l,n);
        } else if (x == 'B') {
            scanf("%d", &n);
            l = konsb(l,n);
        } else if (x == 'O') {
            l = splitOddIndex(l);
        } else if (x == 'E') {
            l = splitEvenIndex(l);
        } else if (x == 'R') {
            l = reverseList(l);
        } else if (x == 'P') {
            scanf("%d", &n);
            l = splitBeforeX(l,n);
        }
        scanf("%c", &x);
    }
    if (isEmpty(l)) {
        printf("Semua gugur\n");
    } else {
        displayList(l);
        printf("\n");
    }
    return 0;
}


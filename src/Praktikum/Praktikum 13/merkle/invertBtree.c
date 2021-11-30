#include <stdio.h>
#include "bintree.h"

void invertBtree(BinTree *p) {
/* I.S. Pohon p terdefinisi */
/* F.S. Pohon p diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */
    /* KAMUS */
    BinTree b;
    /* ALGORITMA */
    if (!isTreeEmpty(*p) && !isOneElmt(*p)) {
        b = newTreeNode(ROOT(*p));
        b = LEFT(*p);
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = b;
        invertBtree(&(LEFT(*p)));
        invertBtree(&(RIGHT(*p)));
    }
}

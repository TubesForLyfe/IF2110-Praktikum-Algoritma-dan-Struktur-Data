#include <stdio.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m) {
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    /* ALGORITMA */
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j) {
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
    /* ALGORITMA */
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m) {
/* Mengirimkan Index baris terbesar m */
    /* ALGORITMA */
    return (ROWS(m)-1);
}
Index getLastIdxCol(Matrix m) {
/* Mengirimkan Index kolom terbesar m */
    /* ALGORITMA */
    return (COLS(m)-1);
}
boolean isIdxEff(Matrix m, Index i, Index j) {
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
    /* ALGORITMA */
    return (i >= 0 && i < ROWS(m) && j >= 0 && j < COLS(m));
}
ElType getElmtDiagonal(Matrix m, Index i) {
/* Mengirimkan elemen m(i,i) */
    /* ALGORITMA */
    return (ELMT(m,i,i));
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes) {
/* Melakukan assignment MRes = MIn */
    /* ALGORITMA */
    *mRes = mIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    CreateMatrix(nRow, nCol, m);
    for (i=0; i<ROWS(*m); i++) {
        for (j=0; j<COLS(*m); j++) {
            scanf("%d", &ELMT(*m,i,j));
        }
    }
}
void displayMatrix(Matrix m) {
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    for (i=0; i<ROWS(m); i++) {
        for (j=0; j<COLS(m); j++) {
            if (j == COLS(m)-1) {
                printf("%d", ELMT(m,i,j));
            } else {
                printf("%d ", ELMT(m,i,j));
            }
        }
        if (i != ROWS(m)-1) {
            printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
    /* KAMUS */
    Matrix m3;
    int i, j;
    /* ALGORITMA */
    ROWS(m3) = ROWS(m1);
    COLS(m3) = COLS(m1);
    for (i=0; i<ROWS(m1); i++) {
        for (j=0; j<COLS(m1); j++) {
            ELMT(m3,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
        }
    }
    return m3;
}
Matrix subtractMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    /* KAMUS */
    Matrix m3;
    int i, j;
    /* ALGORITMA */
    ROWS(m3) = ROWS(m1);
    COLS(m3) = COLS(m1);
    for (i=0; i<ROWS(m1); i++) {
        for (j=0; j<COLS(m1); j++) {
            ELMT(m3,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
        }
    }
    return m3;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2) {
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    /* KAMUS */
    Matrix m3;
    int i, j, k;
    /* ALGORITMA */
    ROWS(m3) = ROWS(m1);
    COLS(m3) = COLS(m2);
    for (i=0; i<ROWS(m3); i++){
        for (j=0; j<COLS(m3); j++) {
            ELMT(m3,i,j) = 0;
        }
    }

    for (i=0; i<ROWS(m1); i++) {
        for (j=0; j<COLS(m2); j++) {
            for (k=0; k<ROWS(m2); k++) {
                ELMT(m3,i,j) += ELMT(m1,i,k) * ELMT(m2,k,j);
            }
        }
    }
    return m3;

}
Matrix multiplyConst(Matrix m, ElType x) {
/* Mengirim hasil perkalian setiap elemen m dengan x */
    /* KAMUS */
    Matrix m2;
    int i, j;
    /* ALGORITMA */
    ROWS(m2) = ROWS(m);
    COLS(m2) = COLS(m);
    for (i=0; i<ROWS(m2); i++){
        for (j=0; j<COLS(m2); j++) {
            ELMT(m2,i,j) = ELMT(m,i,j) * x;
        }
    }
    return m2;
}
void pMultiplyConst(Matrix *m, ElType k) {
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    for (i=0; i<ROWS(*m); i++) {
        for (j=0; j<COLS(*m); j++) {
            ELMT(*m,i,j) *= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    /* KAMUS */
    boolean flag = true;
    int i = 0;
    int j;
    /* ALGORITMA */
    if (ROWS(m1) == ROWS(m2) && COLS(m1) == COLS(m2)) {
        while (i<ROWS(m1) && flag) {
            j = 0;
            while (j<COLS(m1) && flag) {
                if (ELMT(m1,i,j) != ELMT(m2,i,j)) {
                    flag = false;
                } else {
                    j++;
                }
            }
            i++;
        }
    } else {
        flag = false;
    }
    return flag;
}
boolean isNotEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika m1 tidak sama dengan m2 */
    /* ALGORITMA */
    /* KAMUS */
    boolean flag = false;
    int i = 0;
    int j;
    /* ALGORITMA */
    if (ROWS(m1) == ROWS(m2) && COLS(m1) == COLS(m2)) {
        while (i<ROWS(m1) && !flag) {
            j = 0;
            while (j<COLS(m1) && !flag) {
                if (ELMT(m1,i,j) != ELMT(m2,i,j)) {
                    flag = true;
                } else {
                    j++;
                }
            }
            i++;
        }
    } else {
        flag = true;
    }
    return flag;
}
boolean isSizeEqual(Matrix m1, Matrix m2) {
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    /* ALGORITMA */
    return(ROWS(m1) == ROWS(m2) && COLS(m1) == COLS(m2));
}

/* ********** Operasi lain ********** */
int count(Matrix m) {
/* Mengirimkan banyaknya elemen m */
    /* ALGORITMA */
    return (ROWS(m)*COLS(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    /* ALGORITMA */
    return (ROWS(m) == COLS(m));
}
boolean isSymmetric(Matrix m) {
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
    /* KAMUS */
    int i = 0;
    int j;
    boolean flag = true;
    /* ALGORITMA */
    if (isSquare(m)) {
        while (i<ROWS(m) && flag) {
            j = 0;
            while (j<COLS(m) && flag) {
                if (ELMT(m,i,j) != ELMT(m,j,i)) {
                    flag = false;
                } else {
                    j++;
                }
            }
            i++;
        }
    } else {
        flag = false;
    }
    return flag;
}
boolean isIdentity(Matrix m) {
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    /* KAMUS */
    int i = 0;
    int j;
    boolean flag = true;
    /* ALGORITMA */
    if (isSquare(m)) {
        while (i<ROWS(m) && flag) {
            j = 0;
            while (j<COLS(m) && flag) {
                if (i != j){
                    if (ELMT(m,i,j) != 0) {
                        flag = false;
                    }
                } else {
                    if (ELMT(m,i,j) != 1) {
                        flag = false;
                    }
                }
                j++;
            }
            i++;
        }
    } else {
        flag = false;
    }
    return flag;
}
boolean isSparse(Matrix m) {
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    /* KAMUS */
    int i, j;
    int count = 0;
    double percent;
    /* ALGORITMA */
    for (i=0; i<ROWS(m); i++) {
        for (j=0; j<COLS(m); j++) {
            if (ELMT(m,i,j) != 0) {
                count++;
            }
        }
    }
    percent = (count*100)/(ROWS(m)*COLS(m));
    return (percent <= 5);
}
Matrix inverse1(Matrix m) {
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    /* KAMUS */
    Matrix m2;
    int i, j;
    /* ALGORITMA */
    ROWS(m2) = ROWS(m);
    COLS(m2) = COLS(m);
    for (i=0; i<ROWS(m2); i++){
        for (j=0; j<COLS(m2); j++) {
            ELMT(m2,i,j) = ELMT(m,i,j) * (-1);
        }
    }
    return m2;
}
void pInverse1(Matrix *m) {
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    /* KAMUS */
    int i, j;
    /* ALGORITMA */
    for (i=0; i<ROWS(*m); i++) {
        for (j=0; j<COLS(*m); j++) {
            ELMT(*m,i,j) *= (-1);
        }
    }
}
float determinant(Matrix m) {
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
    /* KAMUS */
    int det=0;
    int i,j,k,x,y;;
    Matrix mr;

    /* ALGORITMA */
    CreateMatrix(ROWS(m)-1,COLS(m)-1,&mr);
    if (ROWS(m)==2 && COLS(m)==2) {
        det = (ELMT(m,0,0)*ELMT(m,1,1)) - (ELMT(m,0,1)*ELMT(m,1,0));
    } else { // Rekurens
        for (i = 0; i < COLS(m) ; i++) {
            if (ELMT(m,0,i) != 0) {
                y = 0;
                for (j = 0; j < ROWS(m) ; j++) {
                    x = 0;
                    for (k = 0; k < COLS(m) ; k++) {
                        if (k != i) { // Membentuk kofaktor matriks
                            ELMT(mr,y,x) = ELMT(m,j,k);
                            x++;
                        }
                    }
                    if (j != 0) {
                        y++;
                    }
                }
                if (i % 2 == 0) { // Menentukan tanda + dan - pada koefisien pengali kofaktor
                    det += ELMT(m,0,i) * determinant(mr);
                } else {
                    det -= ELMT(m,0,i) * determinant(mr);
                }
            }
        }
    }
    return det;
}
void transpose(Matrix *m) {
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    /* KAMUS */
    Matrix m2;
    int i, j;
    /* ALGORITMA */
    ROWS(m2) = ROWS(*m);
    COLS(m2) = COLS(*m);
    for (i=0; i<ROWS(m2); i++){
        for (j=0; j<COLS(m2); j++) {
            ELMT(m2,i,j) = ELMT(*m,j,i);
        }
    }
    *m = m2;
}

float rowMean (Matrix m, Index i) {
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
    /* KAMUS */
    int j;
    float sum = 0;
    /* ALGORITMA */
    for(j=0; j<COLS(m); j++) {
        sum += ELMT(m,i,j);
    }
    return (sum/COLS(m));
}
float colMean (Matrix m, Index j) {
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
    /* KAMUS */
    int i;
    float sum = 0;
    /* ALGORITMA */
    for(i=0; i<ROWS(m); i++) {
        sum += ELMT(m,i,j);
    }
    return (sum/ROWS(m));
}
void rowExtremes (Matrix m, Index i, ElType * max, ElType * min) {
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
    /* KAMUS */
    int j;
    /* ALGORITMA */
    *max = ELMT(m,i,0);
    *min = ELMT(m,i,0);
    for (j=1; j<COLS(m); j++) {
        if(ELMT(m,i,j) < *min) {
            *min = ELMT(m,i,j);
        }
        if(ELMT(m,i,j) > *max) {
            *max = ELMT(m,i,j);
        }
    }
}
void colExtremes (Matrix m, Index j, ElType * max, ElType * min) {
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    *max = ELMT(m,0,j);
    *min = ELMT(m,0,j);
    for (i=1; i<ROWS(m); i++) {
        if(ELMT(m,i,j) < *min) {
            *min = ELMT(m,i,j);
        }
        if(ELMT(m,i,j) > *max) {
            *max = ELMT(m,i,j);
        }
    }
}
int countValOnRow (Matrix m, Index i, ElType val) {
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
    /* KAMUS */
    int j;
    int count = 0;
    /* ALGORITMA */
    for (j=0; j<COLS(m); j++) {
        if(ELMT(m,i,j) == val) {
            count++;
        }
    }
    return count;
}
int countValOnCol (Matrix m, Index j, ElType val) {
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
    /* KAMUS */
    int i;
    int count = 0;
    /* ALGORITMA */
    for (i=0; i<ROWS(m); i++) {
        if(ELMT(m,i,j) == val) {
            count++;
        }
    }
    return count;
}

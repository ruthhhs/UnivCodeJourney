// ======================================================
// Nama Program: matriks.c
// Deskripsi   : file body ADT matriks integer
// NIM/Nama    : 24060124120024/Ruth Septriana Sipangkar
// Tanggal     : 18 Sept 2025
// ======================================================
#include <stdio.h>
#include "matriks.h" 
#include "boolean.h"
#include <stdlib.h>
#include <time.h>

/* KONSTRUKTOR */
void initMatriks(Matriks *M){
    for(int i=0; i<10; i++){
        for(int j=0;j<10; j++){
            M->cell[i][j] = -999;
        }
    }
    M->nbaris = 0;
    M->nkolom = 0;
}

/* SELEKTOR */
int getNBaris(Matriks M){
    return M.nbaris;
}

int getNKolom(Matriks M){
    return M.nkolom;
}

/* PREDIKAT */
boolean isEmptyMatriks(Matriks M){
    return M.nbaris==0 && M.nkolom==0;
}

boolean isFullMatriks(Matriks M){
    return M.nbaris==10 && M.nkolom==10;
}

/* MUTATOR */
void addX (Matriks *M, int X, int row, int col){
    if(!isFullMatriks(*M)){
        M->cell[row][col] = X;

        if(M->nbaris < row+1){
            M->nbaris = row+1;
        }
        if(M->nkolom < col+1){
            M->nkolom = col+1;
        }
    }
}

void delX (Matriks *M, int X){
    for(int i=0; i<M->nbaris; i++){
        for(int j=0;j<M->nkolom; j++){
            if(M->cell[i][j] == X){
                M->cell[i][j] = -999;

                int row = 0;
                for(int k=0; k<M->nbaris; k++){
                    if(M->cell[k][j] != -999){
                        row = 1;
                        break;
                    }
                }
                int col = 0;
                for(int k=0; k<M->nkolom; k++){
                    if(M->cell[i][k] != -999){
                        col = 1;
                        break;
                    }
                }
                if (row==0){
                    M->nkolom -= 1;
                }
                if (col==0){
                    M->nbaris -= 1;
                }
            }
            break;
        }
    }
}

void isiMatriksRandom(Matriks *M, int x, int y){
    M->nbaris = x;
    M->nkolom = y;
    for(int i=0; i<M->nbaris; i++){
        for(int j=0;j<M->nkolom; j++){
            M->cell[i][j] = rand() % 100;
        }
    }
}

void isiMatriksIdentitas(Matriks *M, int n){
    M->nbaris = n;
    M->nkolom = n;
    for(int i=0; i<M->nbaris; i++){
        for(int j=0;j<M->nkolom; j++){
            if(i==j){
                M->cell[i][j] = 1;
            }
            else{
                M->cell[i][j] = 0;
            }
        }
    }
}

/* OPERASI BACA/TULIS */
void populateMatriks(Matriks *M, int x, int y){
    initMatriks(M);
    M->nbaris = x;
    M->nkolom = y;
    for(int i=0; i<M->nbaris; i++){
        for(int j=0;j<M->nkolom; j++){
            scanf("%d", &M->cell[i][j]);
        }
    }
}

void printMatriks(Matriks M){
    printf("=== Print Matriks ===\n");
    for(int i=0; i<10; i++){
        printf("| ");
        for(int j=0;j<10; j++){
            printf("%d ", M.cell[i][j]);
        }
        printf("|\n");
    }
}

void viewMatriks (Matriks M){
    printf("=== View Matriks ===\n");
    if(isEmptyMatriks(M)){
        printf("|  |\n");
    } else {
        for(int i=0; i<M.nbaris; i++){
            printf("| ");
            for(int j=0;j<M.nkolom; j++){
                printf("%d ", M.cell[i][j]);
            }
            printf("|\n");
        }
    }
}

/* OPERASI ARITMATIKA */
Matriks addMatriks(Matriks M1, Matriks M2){
    if(M1.nbaris==M2.nbaris && M1.nkolom==M2.nkolom){
        Matriks Ma;
        initMatriks(&Ma);
        Ma.nbaris = M1.nbaris;
        Ma.nkolom = M1.nkolom;

        for(int i=0; i<Ma.nbaris; i++){
            for(int j=0;j<Ma.nkolom; j++){
                Ma.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
            }
        }
        return Ma;
    }
}

Matriks subMatriks(Matriks M1, Matriks M2){
    if(M1.nbaris==M2.nbaris && M1.nkolom==M2.nkolom){
        Matriks Ma;
        initMatriks(&Ma);
        Ma.nbaris = M1.nbaris;
        Ma.nkolom = M1.nkolom;

        for(int i=0; i<Ma.nbaris; i++){
            for(int j=0;j<Ma.nkolom; j++){
                Ma.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
            }
        }
        return Ma;
    }
}

Matriks kaliMatriks(Matriks M1, Matriks M2){
    if(M1.nkolom==M2.nbaris){
        Matriks Ma;
        initMatriks(&Ma);
        Ma.nbaris = M1.nbaris;
        Ma.nkolom = M2.nkolom;

        for(int i=0; i<Ma.nbaris; i++){
            for(int k=0;k<Ma.nkolom; k++){
                Ma.cell[i][k] = 0;
                for(int j=0; j<M1.nkolom; j++){
                    Ma.cell[i][k] += M1.cell[i][j] * M2.cell[j][k];
                }
            }
        }
        return Ma;
    }
}

Matriks kaliSkalarMatriks(Matriks M, int x){
    Matriks Ma;
    initMatriks(&Ma);
    Ma.nbaris = M.nbaris;
    Ma.nkolom = M.nkolom;
    for(int i=0; i<Ma.nbaris; i++){
        for(int j=0;j<Ma.nkolom; j++){
            Ma.cell[i][j] = M.cell[i][j]*x;
        }
    }
    return Ma;
}

/* OPERASI LAINNYA */
void transposeMatriks(Matriks *M);

Matriks getTransposeMatriks(Matriks M);

Matriks addPadding(Matriks M, int n);

Matriks maxPooling(Matriks M, int size);

Matriks avgPooling(Matriks M, int size);

Matriks conv(Matriks M, Matriks K);

/* OPERASI PENCARIAN*/
void searchX(Matriks M, int X, int *row, int *col){
    *row = -999;
    *col = -999;
    for(int i=0; i<M.nbaris; i++){
        for(int j=0; j<M.nkolom; j++){
            if(M.cell[i][j] == X){
                *row = i;
                *col = j;
            }
        }
    }
}

int countX (Matriks M, int X){
    int count = 0;
    for(int i=0; i<M.nbaris; i++){
        for(int j=0; j<M.nkolom; j++){
            if(M.cell[i][j] == X){
                count += 1;
            }
        }
    }
    return count;
}
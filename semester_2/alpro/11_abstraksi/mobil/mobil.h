#ifndef MOBIL_H
#define MOBIL_H

typedef struct {
    char* namaMobil;
    int kecepatan;
} Mobil;

// Procdure inisialiasi nilai awal mobil
void initMobil(Mobil* M);

// Procedure yang membuat mobil berjalan dengan kecepatan 50
void mobilJalan(Mobil* M);

// Procedure yang membuat mobil berjalan dengan kecepatan 0
void mobilBerhenti(Mobil* M);

// Procedure yang membuat mobil berjalan dengan kecepatan berkurang n%
void mobilRem(Mobil* M, int n);

// Procedure yang membuat mobil berbelok ke kiri (l) atau ke kanan (r)
void mobilBelok(char* arah);

#endif
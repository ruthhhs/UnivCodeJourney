#include <stdio.h>
int main(){
    float r, phi, Vb, Vk;

    printf("Masukkan jari-jari :");
    scanf("%f", &r);
    phi = 3.1415;
    Vb = 4/3 * (phi * r *r *r);
    Vk = 0.5 * Vb;
    printf("Volume Bola  : %.2f", Vb);
    printf("\nVolume Kerucut : %.2f", Vk);

    return 0;
}
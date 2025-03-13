#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hasta bilgilerini tutacak yapý
typedef struct {
    int id;
    char isim[50];
    int yas;
    int oncelik; // 1: acil, 2: orta, 3: normal
} Hasta;

// Reçete numarasý üretimi için global sayaç
int recete_no = 1000;

// Hastalarýn kaydedileceði liste
Hasta hastalar[100];
int hastaSayisi = 0;

// Reçete numarasý üretme fonksiyonu
int receteNoUret() {
    return recete_no++;
}

// Yeni hasta kaydý ekleme fonksiyonu
void hastaKaydiEkle() {
    if (hastaSayisi >= 100) {
        printf("Hastalar listesi dolu!\n");
        return;
    }
    
    Hasta yeniHasta;
    printf("Hasta Ismi: ");
    scanf("%s", yeniHasta.isim);
    printf("Hasta Yas: ");
    scanf("%d", &yeniHasta.yas);
    printf("Oncelik (1: acil, 2: orta, 3: normal): ");
    scanf("%d", &yeniHasta.oncelik);
    
    yeniHasta.id = hastaSayisi + 1;
    hastalar[hastaSayisi++] = yeniHasta;
    printf("Hasta kaydedildi.\n");
}

// Hastalarýn önceliðine göre sýralanmasý
void siraliListele() {
	int i,j;
    for (i = 0; i < hastaSayisi - 1; i++) {
        for ( j = i + 1; j < hastaSayisi; j++) {
            if (hastalar[i].oncelik > hastalar[j].oncelik) {
                Hasta temp = hastalar[i];
                hastalar[i] = hastalar[j];
                hastalar[j] = temp;
            }
        }
    }
    
    printf("Hastalar oncelik siralarina gore listeleniyor...\n");
    for (i = 0; i < hastaSayisi; i++) {
        printf("ID: %d, Isim: %s, Yas: %d, Oncelik: %d\n", hastalar[i].id, hastalar[i].isim, hastalar[i].yas, hastalar[i].oncelik);
    }
}

// Ana menü
void menu() {
    int secim;
    do {
        printf("\nAcil Servis Sistemi\n");
        printf("1. Hasta Kaydi Ekle\n");
        printf("2. Hastalari Oncelik Sirasi Ile Listele\n");
        printf("3. Recete Numarasi Uret\n");
        printf("4. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);
        
        switch (secim) {
            case 1:
                hastaKaydiEkle();
                break;
            case 2:
                siraliListele();
                break;
            case 3:
                printf("Yeni Recete Numarasi: %d\n", receteNoUret());
                break;
            case 4:
                printf("Cikis yapiliyor...\n");
                break;
            default:
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
        }
    } while (secim != 4);
}

int main() {
    menu();
    return 0;
}

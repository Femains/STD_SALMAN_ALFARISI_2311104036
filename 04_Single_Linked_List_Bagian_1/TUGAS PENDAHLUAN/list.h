#include <iostream>
#define first(L) L.first  // Makro untuk memudahkan akses elemen pertama dari list
#define next(P) P->next   // Makro untuk memudahkan akses elemen berikutnya dari sebuah node
#define info(P) P->info   // Makro untuk memudahkan akses nilai info dari sebuah node
using namespace std;

typedef int infotype;  // Tipe data untuk informasi dalam node (di sini tipe int)
typedef struct elmlist *address;  // Pointer ke elemen list

// Struktur data node dalam list
struct elmlist {
    infotype info;  // Menyimpan data informasi
    address next;   // Pointer ke elemen berikutnya (untuk membentuk rantai)
};

// Struktur list yang menyimpan pointer ke elemen pertama
struct List {
    address first;  // Menunjuk ke elemen pertama dari list
};

// Deklarasi fungsi untuk mengelola list
void createList(List &L);          // Inisialisasi list kosong
address allocate(infotype x);      // Alokasi elemen baru dengan nilai x
void insertFirst(List &L, address P); // Masukkan elemen baru di awal list
void printInfo(List L);            // Cetak semua elemen dalam list

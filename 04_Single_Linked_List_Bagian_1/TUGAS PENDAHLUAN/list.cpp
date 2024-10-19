#include <iostream>
#include "list.h"  // Memuat deklarasi fungsi dan struktur data dari file header
using namespace std;

// Fungsi untuk menginisialisasi list kosong
void createList(List &L) {
    first(L) = nullptr;  // Mengatur elemen pertama list menjadi nullptr (list kosong)
}

// Fungsi untuk mengalokasikan elemen baru dengan nilai info
address allocate(infotype x) {
    address P = new elmlist;  // Alokasikan memori untuk node baru
    info(P) = x;              // Isi node dengan nilai info
    next(P) = nullptr;        // Set pointer next node sebagai nullptr (belum ada elemen berikutnya)
    return P;                 // Kembalikan pointer ke elemen yang baru dialokasikan
}

// Fungsi untuk memasukkan elemen baru di awal list
void insertFirst(List &L, address P) {
    next(P) = first(L);  // Hubungkan elemen baru ke elemen pertama yang lama
    first(L) = P;        // Set elemen baru sebagai elemen pertama
}

// Fungsi untuk mencetak semua elemen dalam list
void printInfo(List L) {
    address P = first(L);  // Mulai dari elemen pertama list
    while (P != nullptr) {  // Selama masih ada elemen dalam list (tidak nullptr)
        cout << info(P);    // Cetak nilai info dari elemen tersebut
        P = next(P);        // Pindah ke elemen berikutnya
    }
    cout << endl;           // Setelah selesai mencetak, buat baris baru
}

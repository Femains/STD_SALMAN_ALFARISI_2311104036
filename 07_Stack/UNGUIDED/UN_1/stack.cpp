#include "stack.h"
#include <iostream>
using namespace std;

// Fungsi untuk menginisialisasi stack
void createStack(Stack &S) {
    S.top = -1;  // Menandakan stack kosong
}

// Fungsi untuk menambahkan elemen ke dalam stack
void push(Stack &S, infotype x) {
    if (S.top < 19) {  // Cek apakah stack sudah penuh
        S.top++;
        S.array[S.top] = x;  // Tambahkan elemen ke stack
    } else {
        cout << "Stack sudah penuh" << endl;
    }
}

// Fungsi untuk mengeluarkan elemen teratas dari stack
infotype pop(Stack &S) {
    if (S.top >= 0) {  // Cek apakah stack tidak kosong
        infotype nilaiArray = S.array[S.top];
        S.top--; 
        return nilaiArray;  // Kembalikan elemen yang dikeluarkan
    } else {
        cout << "Stack Kosong" << endl;
        return -1;  // Menandakan tidak ada elemen untuk dikeluarkan
    }
}

// Fungsi untuk menambahkan elemen ke dalam stack dalam urutan ascending
void pushAscending(Stack &S, int x) {
    // Cek apakah stack sudah penuh
    if (S.top >= 20 - 1) {
        cout << "Stack sudah penuh" << endl;
        return;
    }

    // Temukan posisi untuk menyisipkan elemen x
    int position = 0;
    while (position <= S.top && S.array[position] < x) {
        position++;  // Maju ke elemen berikutnya
    }

    // Geser elemen yang lebih besar ke kanan
    for (int i = S.top; i >= position; i--) {
        S.array[i + 1] = S.array[i];  // Geser elemen ke kanan
    }

    // Sisipkan elemen x ke posisi yang ditemukan
    S.array[position] = x;
    S.top++;  // Naikkan indeks top
}

// Prosedur pengguna memasukkan angka
void getInputStream(Stack &S){
    int banyakBilangan; // menetukan panjang pada array
    int angka; // menyimpan angka setia for
    cout<<"Masukkan banyak bilangan"<<endl;
    cin>>banyakBilangan;

    if(banyakBilangan >21){ // ketika pengguna memasuukkan angka lebih dari panjang top yang telah ditentukan mangaka akan berhenti
        cout<<"banyak bilangan melebihi batas"<<endl;
    }else{
        for(int i = 0; i<banyakBilangan; i++){
        cout<<"Masukkan angka "<<i+1<<" = ";
        cin>>angka;                             // looping untuk memasukkan angka sesuai kemasukan pengguna 
        S.array[i] = angka;
        S.top++;
        }
    }
    
}

// Fungsi untuk mencetak isi stack
void printInfo(Stack &S) {
    if (S.top == -1) {
        cout << "Stack Kosong" << endl;
    } else {
        for (int i = S.top; i >= 0; i--) {
            cout << S.array[i] << " ";  // Cetak elemen dari atas ke bawah
        }
    }
    cout << endl;  // Pindah ke baris baru setelah mencetak
}

// Fungsi untuk mencetak isi stack dari bawah ke atas
void balikStack(Stack &S) {
    if (S.top == -1) {
        cout << "Stack Kosong" << endl;
    } else {
        for (int i = 0; i <= S.top; i++) {
            cout << S.array[i] << " ";  // Cetak elemen dari bawah ke atas
        }
    }
    cout << endl;  // Pindah ke baris baru setelah mencetak
}



#include <iostream>
#include "list.cpp"
using namespace std;


int main() {
    List L;  // Deklarasi list L
    createList(L);  // Inisialisasi list L sebagai list kosong

    infotype num;  // Variabel untuk menyimpan input digit NIM
    cout << "Masukkan NIM perdigit" << endl;

    // Loop untuk meminta input 10 digit NIM
    for (int i = 1; i <= 10; i++) {
        cout << "Digit " << i << " : ";
        cin >> num;  // Input digit dari pengguna
        address P = allocate(num);  // Alokasikan elemen baru dengan digit tersebut
        insertFirst(L, P);  // Masukkan elemen baru ke dalam list (di awal)
    }

    // Karena elemen dimasukkan dari awal, urutannya terbalik
    // Kita buat list L2 untuk membalik urutan elemen list L
    List L2;  // Deklarasi list baru L2
    createList(L2);  // Inisialisasi list L2 sebagai list kosong

    address P = first(L);  // Ambil elemen pertama dari list L
    while (P != nullptr) {  // Loop selama masih ada elemen
        address temp = allocate(info(P));  // Alokasikan elemen baru dengan nilai dari list L
        insertFirst(L2, temp);  // Masukkan elemen tersebut ke dalam list L2 (di awal)
        P = next(P);  // Pindah ke elemen berikutnya di list L
    }

    // Cetak isi list L2 yang sudah dibalik urutannya
    cout << "Isi list: ";
    printInfo(L2);  // Tampilkan semua elemen dalam list L2

    return 0;  // Program selesai
}

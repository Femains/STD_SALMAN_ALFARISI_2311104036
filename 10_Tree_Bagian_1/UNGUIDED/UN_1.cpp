#include <iostream>
using namespace std;

// Struktur Pohon untuk mendefinisikan node dalam pohon biner
struct Pohon {
    char data;          // Data yang disimpan dalam node
    Pohon *left, *right, *parent;  // Pointer ke anak kiri, anak kanan, dan parent

    // Konstruktor untuk menginisialisasi node pohon dengan data dan pointer ke anak serta parent
    Pohon(char d, Pohon *l = NULL, Pohon *r = NULL, Pohon *p = NULL) 
        : data(d), left(l), right(r), parent(p) {}
};

// Variabel global untuk menyimpan root pohon dan pointer node baru
Pohon *root, *baru;

// Fungsi untuk menginisialisasi pohon (set root ke NULL)
void init() {
    root = NULL;
}

// Fungsi untuk mengecek apakah pohon kosong (root adalah NULL)
bool isEmpty() {
    return root == NULL;
}

// Fungsi untuk membuat node root pohon jika pohon kosong
void buatNode(char data) {
    if(isEmpty()) {
        // Jika pohon kosong, buat node root baru
        root = new Pohon(data, NULL, NULL, NULL);
        cout << "\nNode " << data << " berhasil dibuat menjadi root\n";
    } else {
        // Jika pohon sudah ada, beri pesan bahwa root sudah ada
        cout << "\nPohon sudah dibuat.\n";
    }
}

// Fungsi untuk mencari node berdasarkan data di pohon secara rekursif
Pohon* cariNode(Pohon *node, char data) {
    if (!node) return NULL;  // Jika node NULL, kembalikan NULL
    if (node->data == data) return node;  // Jika node ditemukan, kembalikan node tersebut
    Pohon *leftResult = cariNode(node->left, data);  // Cari di subpohon kiri
    if (leftResult) return leftResult;  // Jika ditemukan di kiri, kembalikan hasilnya
    return cariNode(node->right, data);  // Jika tidak ditemukan di kiri, cari di subpohon kanan
}

// Fungsi untuk menambahkan node sebagai anak kiri dari node tertentu
Pohon *insertLeft(char data, Pohon *node) {
    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child di kiri.\n";
        return NULL;  // Jika sudah ada anak kiri, beri pesan error
    }
    baru = new Pohon(data, NULL, NULL, node);  // Buat node baru sebagai anak kiri
    node->left = baru;  // Hubungkan node baru ke anak kiri
    cout << "\nNode " << data << " berhasil ditambahkan di kiri " << node->data << ".\n";
    return baru;
}

// Fungsi untuk menambahkan node sebagai anak kanan dari node tertentu
Pohon *insertRight(char data, Pohon *node) {
    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child di kanan.\n";
        return NULL;  // Jika sudah ada anak kanan, beri pesan error
    }
    baru = new Pohon(data, NULL, NULL, node);  // Buat node baru sebagai anak kanan
    node->right = baru;  // Hubungkan node baru ke anak kanan
    cout << "\nNode " << data << " berhasil ditambahkan di kanan " << node->data << ".\n";
    return baru;
}

// Fungsi untuk menampilkan anak kiri dan kanan dari node tertentu
void tampilChild(Pohon *node) {
    if (!node) return;  // Jika node NULL, keluar dari fungsi
    cout << "\nNode: " << node->data << "\n";
    cout << "Child kiri: " << (node->left ? node->left->data : '-') << "\n";  // Tampilkan anak kiri, jika ada
    cout << "Child kanan: " << (node->right ? node->right->data : '-') << "\n";  // Tampilkan anak kanan, jika ada
}

// Fungsi untuk menampilkan semua keturunan (descendant) dari node tertentu
void tampilDescendant(Pohon *node) {
    if (!node) return;  // Jika node NULL, keluar dari fungsi
    if (node->left) {
        cout << node->left->data << " ";  // Tampilkan anak kiri jika ada
        tampilDescendant(node->left);  // Rekursi untuk anak kiri
    }
    if (node->right) {
        cout << node->right->data << " ";  // Tampilkan anak kanan jika ada
        tampilDescendant(node->right);  // Rekursi untuk anak kanan
    }
}

// Menu utama yang mengatur pilihan pengguna untuk operasi pada pohon
void menu() {
    int pilihan;
    char data, parent;
    do {
        // Menampilkan menu operasi pohon
        cout << "\n=== Menu Tree ===\n";
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Child Kiri\n";
        cout << "3. Tambah Child Kanan\n";
        cout << "4. Tampilkan Child\n";
        cout << "5. Tampilkan Descendant\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);  // Membuat node root baru
                break;
            case 2:
                cout << "Masukkan data parent: ";
                cin >> parent;
                cout << "Masukkan data child kiri: ";
                cin >> data;
                if (Pohon *p = cariNode(root, parent)) {
                    insertLeft(data, p);  // Menambahkan anak kiri pada parent yang ditemukan
                } else {
                    cout << "\nNode parent tidak ditemukan.\n";
                }
                break;
            case 3:
                cout << "Masukkan data parent: ";
                cin >> parent;
                cout << "Masukkan data child kanan: ";
                cin >> data;
                if (Pohon *p = cariNode(root, parent)) {
                    insertRight(data, p);  // Menambahkan anak kanan pada parent yang ditemukan
                } else {
                    cout << "\nNode parent tidak ditemukan.\n";
                }
                break;
            case 4:
                cout << "Masukkan node: ";
                cin >> data;
                if (Pohon *p = cariNode(root, data)) {
                    tampilChild(p);  // Menampilkan anak kiri dan kanan dari node yang ditemukan
                } else {
                    cout << "\nNode tidak ditemukan.\n";
                }
                break;
            case 5:
                cout << "Masukkan node: ";
                cin >> data;
                if (Pohon *p = cariNode(root, data)) {
                    cout << "\nDescendant dari node " << data << ": ";
                    tampilDescendant(p);  // Menampilkan semua keturunan dari node yang ditemukan
                    cout << "\n";
                } else {
                    cout << "\nNode tidak ditemukan.\n";
                }
                break;
            case 6:
                cout << "\nKeluar.\n";
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
        }
    } while (pilihan != 6);  // Ulangi menu sampai pengguna memilih untuk keluar
}

// Fungsi utama untuk menjalankan program
int main() {
    init();  // Menginisialisasi pohon (root = NULL)
    menu();  // Menampilkan menu utama
    return 0;
}

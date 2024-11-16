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
    if (isEmpty()) {
        // Jika pohon kosong, buat node root baru
        root = new Pohon(data, NULL, NULL, NULL);
        cout << "\nNode " << data << " berhasil dibuat menjadi root" << endl;
    } else {
        // Jika pohon sudah ada, beri pesan bahwa root sudah ada
        cout << "\nPohon sudah dibuat." << endl;
    }
}

// Fungsi untuk menambahkan node sebagai anak kiri dari node tertentu
Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        // Jika pohon kosong, beri pesan agar pohon dibuat terlebih dahulu
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->left != NULL) {
        // Jika sudah ada anak kiri, beri pesan error
        cout << "\nNode " << node->data << " sudah ada child di kiri!" << endl;
        return NULL;
    }
    // Buat node baru sebagai anak kiri dari node yang diberikan
    baru = new Pohon(data, NULL, NULL, node);
    node->left = baru;  // Hubungkan node baru ke anak kiri
    cout << "\nNode " << data << " berhasil ditambahkan di kiri " << node->data << endl;
    return baru;
}

// Fungsi untuk menambahkan node sebagai anak kanan dari node tertentu
Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        // Jika pohon kosong, beri pesan agar pohon dibuat terlebih dahulu
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->right != NULL) {
        // Jika sudah ada anak kanan, beri pesan error
        cout << "\nNode " << node->data << " sudah ada child di kanan!" << endl;
        return NULL;
    }
    // Buat node baru sebagai anak kanan dari node yang diberikan
    baru = new Pohon(data, NULL, NULL, node);
    node->right = baru;  // Hubungkan node baru ke anak kanan
    cout << "\nNode " << data << " berhasil ditambahkan di kanan " << node->data << endl;
    return baru;
}

// Fungsi untuk menghitung jumlah simpul daun dalam pohon
int cari_simpul_daun(Pohon *node) {
    // Jika node kosong, kembalikan 0
    if (!node) return 0;
    
    // Jika node adalah simpul daun (tidak memiliki anak kiri dan kanan)
    if (!node->left && !node->right) {
        return 1;  // Menghitung simpul daun
    }
    
    // Rekursif menghitung simpul daun di anak kiri dan kanan
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

int main() {
    init();  // Menginisialisasi pohon (root = NULL)
    buatNode('A');  // Membuat node root dengan data 'A'
    
    // Menambahkan node anak kiri dan kanan ke root
    Pohon *nodeB = insertLeft('B', root); 
    Pohon *nodeC = insertRight('C', root);
    
    // Menambahkan anak kiri dan kanan untuk node-node lainnya
    insertLeft('D', nodeB);
    insertRight('E', nodeC);
    insertLeft('F', nodeB);
    insertRight('G', nodeC);

    // Menghitung jumlah simpul daun
    int jumlahDaun = cari_simpul_daun(root);
    cout << "\nJumlah simpul daun dalam tree: " << jumlahDaun << endl;

    return 0;
}

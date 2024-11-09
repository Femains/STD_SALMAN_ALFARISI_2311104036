#include <iostream>
#include <string>
using namespace std;

// Definisi struktur Mahasiswa
struct Mahasiswa {
    string nama;
    string NIM;
    Mahasiswa* next;
};

// Pointer front dan back untuk menandai awal dan akhir antrian
Mahasiswa* front = nullptr;
Mahasiswa* back = nullptr;

// Fungsi untuk mengecek apakah antrian kosong
bool isEmpty() {
    return front == nullptr;
}

// Fungsi untuk menambahkan mahasiswa ke dalam antrian berdasarkan prioritas NIM
void enqueue(string nama, string NIM) {
    Mahasiswa* newMahasiswa = new Mahasiswa(); // Membuat node mahasiswa baru
    newMahasiswa->nama = nama;
    newMahasiswa->NIM = NIM;
    newMahasiswa->next = nullptr;

    // Jika antrian kosong, mahasiswa pertama menjadi front dan back
    if (isEmpty()) {
        front = newMahasiswa;
        back = newMahasiswa;
    } else {
        // Menyisipkan mahasiswa berdasarkan urutan NIM
        Mahasiswa* temp = front;
        Mahasiswa* prev = nullptr;

        // Mencari posisi yang tepat untuk mahasiswa berdasarkan NIM
        while (temp != nullptr && temp->NIM < NIM) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == nullptr) {
            // Jika mahasiswa baru harus menjadi front
            newMahasiswa->next = front;
            front = newMahasiswa;
        } else {
            // Menyisipkan mahasiswa baru di posisi yang sesuai
            prev->next = newMahasiswa;
            newMahasiswa->next = temp;
        }
    }
}

// Fungsi untuk menghapus mahasiswa dari bagian depan antrian
void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Mahasiswa* temp = front;  // Simpan elemen depan
        front = front->next; // Pindahkan front ke elemen berikutnya
        
        // Jika setelah menghapus, antrian menjadi kosong
        if (front == nullptr) {
            back = nullptr; // Atur back menjadi nullptr
        }

        delete temp; // Hapus elemen depan dari memori
    }
}

// Fungsi untuk menghitung banyaknya mahasiswa dalam antrian
int countQueue() {
    int count = 0;
    Mahasiswa* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi untuk menghapus semua mahasiswa dari antrian
void clearQueue() {
    while (!isEmpty()) {
        dequeue(); // Hapus elemen satu per satu
    }
}

// Fungsi untuk menampilkan semua mahasiswa dalam antrian
void printQueue() {
    Mahasiswa* temp = front;
    int pos = 1;
    cout << "Data Antrian Mahasiswa (Prioritas Berdasarkan NIM):" << endl;
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        while (temp != nullptr) {
            cout << pos << ". Nama: " << temp->nama << ", NIM: " << temp->NIM << endl;
            temp = temp->next;
            pos++;
        }
    }
}

int main() {
    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa yang ingin ditambahkan ke antrian: ";
    cin >> jumlahMahasiswa;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        string nama, NIM;
        cout << "Masukkan nama mahasiswa ke-" << (i + 1) << ": ";
        cin >> nama;
        cout << "Masukkan NIM mahasiswa ke-" << (i + 1) << ": ";
        cin >> NIM;

        enqueue(nama, NIM); // Menambahkan mahasiswa ke dalam antrian
    }

    printQueue(); // Menampilkan antrian
    cout << "Jumlah Antrian = " << countQueue() << endl;
    cout << endl;

    // Menghapus mahasiswa dari antrian
    dequeue();
    printQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    cout << endl;

    // Menghapus semua mahasiswa dari antrian
    clearQueue();
    printQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;

    return 0;
}

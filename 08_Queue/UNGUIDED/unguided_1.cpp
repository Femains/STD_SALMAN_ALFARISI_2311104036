#include <iostream>
using namespace std;

// mendefinisi struktur Node
struct Node {
    string data;
    Node* next;
};

// inisialisasi pointer front dan back untuk merepresentasikan awal dan akhir antrian
Node* front = nullptr;
Node* back = nullptr;

// Fungsi untuk mengecek apakah antrian kosong
bool isEmpty() {
    return front == nullptr;
}

// Fungsi untuk menambahkan elemen ke dalam antrian
void enqueue(string data) {
    Node* newNode = new Node(); // Membuat node baru
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty()) {
        // Jika antrian kosong, elemen baru menjadi front dan back
        front = newNode;
        back = newNode;
    } else {
        // Jika antrian tidak kosong, tambahkan di bagian akhir
        back->next = newNode;
        back = newNode;
    }
}

// Fungsi untuk menghapus elemen dari bagian depan antrian
void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;  // Simpan elemen depan
        front = front->next; // Pindahkan front ke elemen berikutnya
        
        // Jika setelah menghapus, antrian menjadi kosong
        if (front == nullptr) {
            back = nullptr; // Atur back menjadi nullptr
        }

        delete temp; // Hapus elemen depan dari memori
    }
}

// Fungsi untuk menghitung banyaknya elemen dalam antrian
int countQueue() {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi untuk menghapus semua elemen dalam antrian
void clearQueue() {
    while (!isEmpty()) {
        dequeue(); // Hapus elemen satu per satu
    }
}

// Fungsi untuk menampilkan semua elemen dalam antrian
void printQueue() {
    Node* temp = front;
    int pos = 1;
    cout << "Data Antrian:" << endl;
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        while (temp != nullptr) {
            cout << pos << ". " << temp->data << endl;
            temp = temp->next;
            pos++;
        }
    }
}

int main() {
    // Menambahkan elemen ke antrian
    enqueue("Satria");
    enqueue("Gilang");
    printQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    cout << endl;

    // Menghapus elemen dari antrian
    dequeue();
    printQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    cout << endl;

    // Menghapus semua elemen dari antrian
    clearQueue();
    printQueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;

    return 0;
}

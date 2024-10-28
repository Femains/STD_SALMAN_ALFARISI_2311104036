#include <iostream>
using namespace std;

class Node {
public:
    int id;
    string judul;
    string penulis;

    Node* prev;
    Node* next;

    Node(int value, string jdl, string pnls) {
        id = value;
        judul = jdl;
        penulis = pnls;
        prev = nullptr;
        next = nullptr;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;

    DLL() {
        head = nullptr;
        tail = nullptr;
    }

    void insertLast(int data, string jdl, string pnls) {
        Node* p = new Node(data, jdl, pnls);  // Alokasi node baru

        // Jika list kosong
        if (head == nullptr) {
            head = p;
            tail = p;
        } else {
            // Set pointer prev dari node baru ke tail
            p->prev = tail;

            // Set pointer next dari tail ke node baru
            tail->next = p;

            // Update tail ke node baru
            tail = p;
        }
    }

    void displayAwal() {
        Node* current = head;
        cout << "Data Buku :" << endl;
        int index = 1; // Untuk nomor urut buku
        while (current != nullptr) {
            // Menampilkan id, judul, dan penulis
            cout << index << ". ID: " << current->id << ", Judul: " << current->judul
                 << ", Penulis: " << current->penulis << endl;
            current = current->next;
            index++;
        }
        cout << endl;
    }

    void displayAkhir() {
        Node* current = tail;
        cout << "Data Buku :" << endl;
        int index = 1; // Untuk nomor urut buku
        while (current != nullptr) {
            // Menampilkan id, judul, dan penulis
            cout << index << ". ID: " << current->id << ", Judul: " << current->judul
                 << ", Penulis: " << current->penulis << endl;
            current = current->prev;
            index++;
        }
        cout << endl;
    }
};

int main() {
    DLL List;
    cout<<"Display Awal ke Akhir:"<<endl;
    List.insertLast(1, "Gilang Mencari Ayam", "Gilang");
    List.insertLast(2, "Belajar C++", "Andika");
    List.insertLast(3, "Pemrograman Dasar", "Salman");
    List.displayAwal();
    cout<<"Display Akhir ke Awal:"<<endl;
    List.displayAkhir();

    return 0;
}

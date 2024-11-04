#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;   
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

    void insertFirst_2311104036(int data) {
        Node* p = new Node(data);

        if (head == nullptr) {
            head = p;
            tail = p;
        } else {
            p->next = head;
            p->prev = nullptr;
            head->prev = p;
            head = p;
        }
    }

    void insertLast_2311104036(int data) {
        Node* p = new Node(data);  

        if (head == nullptr) {
            head = p;
            tail = p;
        } else {
            p->prev = tail;
            tail->next = p;
            tail = p;
        }
    }

    void inputFirstPengguna_2311104036() {
        int dataInputan;
        Node* current = head;
        for (int i = 0; i < 1; i++) {
            cout << "Masukkan data dipisahkan dengan spasi = ";
            for (int j = 0; j < 4; j++) {
                cin >> dataInputan;
                insertFirst_2311104036(dataInputan);
            }
        }
    }

    void deleteFirst_2311104036() {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {  // Cek untuk memastikan head tidak null
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteLast_2311104036() {
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {  // Cek untuk memastikan tail tidak null
            tail->next = nullptr;
        }
        delete temp;
    }

    void displayAwal_2311104036() {
        Node* current = head;
        cout << "Daftar elemen dari belakang ke depan: ";
        while (current != nullptr) {
            cout << current->data << "<->";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void displayAkhir_2311104036() {
        Node* current = tail;
        cout << "Daftar elemen dari depan ke belakang: ";
        while (current != nullptr) {
            cout << current->data << "<->";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DLL dll;
    
    dll.inputFirstPengguna_2311104036();
    dll.displayAwal_2311104036();
    dll.displayAkhir_2311104036();

    return 0;
}

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

    void inputanPengguna_2311104036() {
        int dataInputan;
        Node* current = head;

        for (int i = 0; i < 1; i++) {
            cout << "Masukkan data yang ingin dimasukkan di awal = ";
            cin >> dataInputan;
            insertFirst_2311104036(dataInputan);
        }
        
        for (int i = 0; i < 1; i++) {
            cout << "Masukkan data yang ingin dimasukkan di akhir = ";
            cin >> dataInputan;
            insertLast_2311104036(dataInputan);
        }
    }

    void deleteFirst_2311104036() {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    void deleteLast_2311104036() {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    void display_2311104036() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << "<->";
            current = current->next;
        }
        
        cout << "NULL" << endl;
    }
};

int main() {
    DLL dll;

    dll.insertFirst_2311104036(10);
    dll.display_2311104036();
    dll.inputanPengguna_2311104036();
    dll.display_2311104036();
    

    return 0;
}

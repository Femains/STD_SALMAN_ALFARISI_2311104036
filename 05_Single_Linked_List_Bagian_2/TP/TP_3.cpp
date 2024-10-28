#include <iostream>
using namespace std;

struct Elemen {
    int data;
    Elemen* next;
};

struct List {
    Elemen* first;
};

void createList_2311104036(List &L) {
    L.first = NULL;
}

Elemen* alokasi_2311104036(int x) {
    Elemen* P = new Elemen;
    if (P != NULL) {
        P->data = x;
        P->next = NULL;
    }
    return P;
}

void insertSorted2311104036(List &L, Elemen* P) {
    Elemen* Q = L.first;
    Elemen* Prev = NULL;

    while (Q != NULL && Q->data < P->data) {
        Prev = Q;
        Q = Q->next;
    }

    if (Prev == NULL) {
        P->next = L.first;
        L.first = P;
    } else {
        Prev->next = P;
        P->next = Q;
    }
}

void tambahkanAngka_2311104036(List& L) {
    int inputan;
    Elemen* P_inputan;
    cout << "Masukkan 5 angka" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Angka ke " << i + 1 << " = ";
        cin >> inputan;
        P_inputan = alokasi_2311104036(inputan);
        insertSorted2311104036(L, P_inputan);
    }
}

void tambahAngkaTambahan_2311104036(List& L) {
    int value;
    cout << "Masukkan Angka Tambahan: ";
    cin >> value;
    Elemen* newElemen = alokasi_2311104036(value);
    insertSorted2311104036(L, newElemen);
}

void printInfo_2311104036(List L) {
    Elemen* P = L.first;
    while (P != NULL) {
        cout << P->data << " -> ";
        P = P->next;
    }
    cout << "NULL" << endl;
}

int main() {
    List L;
    createList_2311104036(L);
    tambahkanAngka_2311104036(L);
    printInfo_2311104036(L); 
    tambahAngkaTambahan_2311104036(L);
    printInfo_2311104036(L); 
    return 0;
}

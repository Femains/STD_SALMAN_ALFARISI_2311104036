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

void insertFirst_2311104036(List& L, Elemen* P) {
    P->next = L.first;
    L.first = P;
}

void tambahkanAngka_2311104036(List& L) {
    int inputan;
    Elemen* P_inputan;
    cout << "Masukkan 6 angka" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Angka ke " << i + 1 << " = ";
        cin >> inputan;
        P_inputan = alokasi_2311104036(inputan);
        insertFirst_2311104036(L, P_inputan);
    }
}

void printInfo_2311104036(List L) {
    Elemen* P = L.first;
    while (P != NULL) {
        cout << P->data << " -> ";
        P = P->next;
    }
    cout << "NULL" << endl;
}

Elemen* findElm_2311104036(List L, int x, int &posisi) {
    Elemen* P = L.first;
    posisi =1;
    while (P != NULL) {
        if (P->data == x) {
            return P;
        }
        P = P->next;
        posisi++;
    }
    return NULL;
}

int main() {
    int inputan_user;
    int posisi;
    List L;
    createList_2311104036(L);
    tambahkanAngka_2311104036(L);
    printInfo_2311104036(L);

    cout << "Masukkan data yang ingin dicari = ";
    cin >> inputan_user;
    Elemen* found = findElm_2311104036(L, inputan_user, posisi);
    
    if (found != NULL) {
        cout << found->data << " ditemukan pada ururtan ke-" << posisi<<endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }

    return 0;
}

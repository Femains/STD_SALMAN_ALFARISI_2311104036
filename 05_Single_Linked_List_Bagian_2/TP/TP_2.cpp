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
    cout << "Masukkan 5 angka" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Angka ke " << i + 1 << " = ";
        cin >> inputan;
        P_inputan = alokasi_2311104036(inputan);
        insertFirst_2311104036(L, P_inputan);
    }
}

void bubbleShort_2311104036(List& L) {
    int n = 0;
    Elemen* current = L.first;
    while (current != NULL) {
        n++;
        current = current->next;
    }

    for (int i = 1; i < n; i++) {
        current = L.first;
        Elemen* prev = NULL;

        for (int j = n - 1; j >= i; j--) {
            Elemen* next = current->next;
            if (next != NULL && current->data > next->data) {
                int t = current->data;
                current->data = next->data;
                next->data = t;
            }
            prev = current;
            current = next;
        }
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


int main(){
    List L;
    createList_2311104036(L);
    tambahkanAngka_2311104036(L);
    cout<<"Sebelum di sorting: "<<endl;
    printInfo_2311104036(L);
    cout<<endl;
    cout<<"Sesudah di sorting: "<<endl;
    bubbleShort_2311104036(L);
    printInfo_2311104036(L);

}
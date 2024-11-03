// main.cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    createStack(S);
    cout<<endl;
    cout<<"Huruf Tidak Terbalik"<<endl;
    // Menambahkan karakter ke dalam stack
    char elements[MAX] = {'I', 'F', 'L', 'A', 'B', 'J', 'A', 'Y', 'A'};
    for (int i = 0; i < 9; i++) {
        push(S, elements[i]);
    }

    // Menampilkan isi stack pertama kali
    printInfo(S);

    // Mengosongkan stack
    while (!isEmpty(S)) {
        pop(S);
    }

    // Menambahkan kembali elemen-elemen tertentu
    push(S, 'J');
    push(S, 'A');
    push(S, 'Y');
    push(S, 'A');

    // Menampilkan isi stack akhir
    printInfo(S);
    while (!isEmpty(S)) {
        pop(S);
    }
    cout<<endl<<"Huruf Terbalik"<<endl;
    // membuat huruf terbalik
    char kebalik[MAX] = {'I', 'F', 'L', 'A', 'B', 'J', 'A', 'Y', 'A'};
    for (int i = 0; i < 9; i++) {
        push(S, kebalik[i]);
    }

    for (int i = S.Top; i>-1; i--){
        cout<<S.info[i]<<" ";
    }

    while (!isEmpty(S)) {
        pop(S);
    }
    
    push(S, 'J');
    push(S, 'A');
    push(S, 'Y');
    push(S, 'A');
    cout<<endl;

    for (int i = S.Top; i>-1; i--){
        cout<<S.info[i]<<" ";
    }
    return 0;
}

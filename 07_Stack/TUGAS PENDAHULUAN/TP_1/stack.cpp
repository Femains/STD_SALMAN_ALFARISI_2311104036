#include "stack.h"
#include <iostream>
using namespace std;
void createStack(Stack &S) {
    S.Top = -1;
}

bool isEmpty(Stack S) {
    return S.Top == -1;
}

bool isFull(Stack S) {
    return S.Top == MAX - 1;
}

void push(Stack &S, char element) {
    if (!isFull(S)) {
        S.Top++;
        S.info[S.Top] = element;
    }
}

char pop(Stack &S) {
    if (!isEmpty(S)) {
        char element = S.info[S.Top];
        S.Top--;
        return element;
    }
    return '\0'; // Mengembalikan karakter kosong jika stack kosong
}

void printInfo(Stack S) {
    for (int i = 0; i <= S.Top; i++) {
        cout << S.info[i] << " ";
    }
    cout << std::endl;
}

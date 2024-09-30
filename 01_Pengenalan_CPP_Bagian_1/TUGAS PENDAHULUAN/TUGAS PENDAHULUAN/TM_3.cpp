#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "MASUKKAN BILANGAN = ";
    cin >> angka;
    for (int i = angka; i >= 1; i--) {
        for (int jarak = 0; jarak < (angka - i); jarak++) {
            cout << "  "; 
        }
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "* ";
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl; 
    }
    for (int jarak = 0; jarak < angka; jarak++) {
        cout << "  ";
    }
    cout << "*";
    
    return 0;
}

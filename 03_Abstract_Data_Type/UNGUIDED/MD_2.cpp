#include <iostream>
#include <conio.h>
#include "pelajaran.cpp"
using namespace std;

int main(){
    string namapel,kodepel;
    cout << "Masukkan nama mapel = ";
    getline(cin, namapel);
    cout << "Masukkan kode mapel = ";
    cin >> kodepel;
    pelajaran pel = create_pelajaran(namapel,kodepel);
    cout << "" << endl;
    tampil_pelajaran(pel);
    return 0;
}
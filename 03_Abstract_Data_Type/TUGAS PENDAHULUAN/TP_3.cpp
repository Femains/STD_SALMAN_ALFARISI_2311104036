#include <iostream>
using namespace std;

/*Bagaimana cara menggunakan pointer dalam program C++? Berikan contoh cara 
menampilkan nilai yang tersimpan pada suata alamat melalui pointer!*/

int main(){
    // Terdapat variabel x yang bertipe int
    int x = 10;
    int *ptrx = &x;

    cout << "Ini adalah Nilai dari x    = " << x << endl;
    cout << "Ini adalah alamat dari x   = " << &x << endl;
    cout << "Ini adalah nilai dari ptrx = " << ptrx << endl;
    return 0;

}



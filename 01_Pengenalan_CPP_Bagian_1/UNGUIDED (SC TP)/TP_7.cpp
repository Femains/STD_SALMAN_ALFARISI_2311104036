#include <iostream>
using namespace std;

int main(){
    cout << "SOAL NO 7" << endl;
    int bilangan_s7, asli_s7, jumlah_s7;
    cout << "Masukkan bilangan asli: ";
    cin >> asli_s7;

    bilangan_s7 = 1;
    jumlah_s7 = 0;
    while (bilangan_s7 <= asli_s7) {
        if (bilangan_s7 % 2 == 0) {
            jumlah_s7 += bilangan_s7;
            }
        bilangan_s7++;
        }
    cout << "Jumlah bilangan genap: " << jumlah_s7 << endl;
    cout << "" << endl;
    return 0;
}
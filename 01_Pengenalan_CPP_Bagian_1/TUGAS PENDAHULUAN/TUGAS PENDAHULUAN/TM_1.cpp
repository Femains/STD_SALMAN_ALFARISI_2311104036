#include <iostream>
using namespace std;
int main(){
    float angka_1, angka_2, penjumlahan, pengurangan, pembagian, perkalian;
    cout << "MASUKKAN ANGKA 1 :"<<endl;
    cin >> angka_1;
    cout << "MASUKKAN ANGKA 2 :" << endl;
    cin >> angka_2;
    penjumlahan = angka_1 + angka_2;
    pengurangan = angka_1 - angka_2;
    pembagian = angka_1 / angka_2;
    perkalian = angka_1 * angka_2;
    cout << "HASIL PENJUMLAHAN " << penjumlahan << endl;
    cout << "HASIL PENGURANGAN " << pengurangan << endl;
    cout << "HASIL PERKALIAN " << perkalian << endl;
    cout << "HASIL PEMBAGIAN " << pembagian << endl;
    return 0;

}
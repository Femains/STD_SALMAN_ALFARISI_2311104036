#include <iostream>
using namespace std;

int main(){
    cout << "SOAL NO 4" << endl;
    int bil1_S4 = 2, bil2_S4 = 3, hasil_S4;
    hasil_S4 = bil1_S4 <= bil2_S4 && bil1_S4 < bil2_S4;
    cout << hasil_S4 << endl;
    hasil_S4 = bil1_S4 >= bil2_S4 || bil1_S4 < bil2_S4;
    cout << hasil_S4 << endl;
    hasil_S4 = !(bil1_S4 >= bil2_S4) || bil1_S4 < bil2_S4;
    cout << hasil_S4 << endl;
    cout << "" << endl;
    return 0;
}
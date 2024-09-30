#include <iostream>
using namespace std;

int main(){
    string satuan[] = {"","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan","sepuluh", "sebelas"};
    string belasan[] ={"belas"};
    string puluhan[] = {"puluh"};
    int inputan_angka,i;
    cout << "masukkan angka = " <<endl;
    cin >> inputan_angka;
    if (inputan_angka<0 || inputan_angka>100){
        cout <<"angka di luar jangkauan"<<endl;
    }
    else if (inputan_angka<=11){
        cout << satuan[inputan_angka]<<endl;}
    else if (inputan_angka<=19){
        cout << satuan[inputan_angka-10] <<" "<< belasan[0] <<endl;}
        
    else if (inputan_angka%10==0&& inputan_angka!=100){
        cout << satuan[inputan_angka/10]<<" "<<puluhan[0]<<endl;
    }
    else if (inputan_angka<100 && inputan_angka%10!=0){
        cout <<satuan[inputan_angka/10]<< " "<<puluhan[0]<<" "<<satuan[inputan_angka%10]<<endl;
    }
    else if (inputan_angka==100){
        cout << "seratus"<<endl;
    }
    
    return 0;
}
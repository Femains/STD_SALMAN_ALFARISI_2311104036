#include <iostream>
using namespace std;

int main()
{   
    // Program 1: Menampilkan teks "Hello" 
    cout << "Hello" << endl;     

    // Program 2: Input dan Output sederhana 
    int inp;     
    cin >> inp;  
    cout << "nilai = " << inp << endl;

    // Program 3: Operasi Aritmatika 
    float W, X, Y; 
    float Z;    
    X = 7; 
    Y = 3; 
    W = 1;    
    Z = (X + Y) / (Y + W);    
    cout << "nilai Z = " << Z << endl; 

    int a = 10;
    int b = 20;
    cout <<""<<endl;
    //PERCABANGAN
    if (a == 15){
        cout <<"nilai a adalah 15"<<endl;
    }
    else {
        cout <<"nilai a bukanlah 15"<<endl;
    }
    // Latihan Percabangan
    double tot_pembelian, diskon;
    cout <<"total pembelian, RP "; cin>>tot_pembelian;
    diskon =0;
    if (tot_pembelian >= 100000){
        diskon = 0.05 * tot_pembelian;
    }
    else {
        diskon = 0;
    }
    cout << "besar diskon = RP "<<diskon;

    cout <<""<<endl;

    //Latihan Perulangan
    int i =1;
    int jum;
    cin>> jum;
    do{
        cout<<"baris ke-"<<i+1<<endl;
        i++;
    }
    while (i<jum);
    getchar();

    cout<<""<<endl;

    // Program 5: Program untuk memilih hari 
    int kode_hari;    
    puts("Tentuin hari\n");    
    puts("");  

    // Bikin Kode Sendiri
    int angka_ulang= 1;
    do {
        cout<<"baris ke-"<<angka_ulang<<endl;
        angka_ulang++;
    }
    while (angka_ulang<10);
    return 0;
}



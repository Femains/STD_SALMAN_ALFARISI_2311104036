#include <iostream>
using namespace std;

float hasilAkhir(float uts, float uas, float tugas){
    int hasil;
    hasil = (0.3*uts)+(0.4*uas)+(0.3*tugas);
    return hasil;
}

void tampilkan_hasil(float uts, float uas, float tugas){
    cout <<hasilAkhir(uts, uas, tugas)<<endl;
}
struct dataMahasiswa{
    string nama,nim;
    float uts,uas,tugas;
};

int main(){
    int jumlahMHS;
    cout << "Masukkan Jumlah Mahasiswa = ";
    cin >> jumlahMHS;
    dataMahasiswa mahasiswa[jumlahMHS];
    if (jumlahMHS > 10){
        cout << "JUMLAH MELEBIHI BATAS"<<endl;
    }

    for (int i = 0; i<jumlahMHS; i++){
        cout << "Masukkan Data Mahasiswa ke " << i+1<<endl;
        cout <<"Masukkan Nama = ";
        cin >> mahasiswa[i].nama;
        cout <<"Masukkan NIM = ";
        cin >> mahasiswa[i].nim;
        cout <<"Masukkan NIlai UTS = ";
        cin >> mahasiswa[i].uts;
        cout <<"Masukkan Nilai UAS = ";
        cin>> mahasiswa[i].uas;
        cout <<"Masukkan Niali Tugas = ";
        cin >> mahasiswa[i].tugas;
        cout << "Mahasiswa dengan nama "<<mahasiswa[i].nama<<" mendapatkan nilai akhir = ";
        tampilkan_hasil(mahasiswa[i].uts,mahasiswa[i].uas,mahasiswa[i].tugas);
        cout<<""<<endl;

    }
    return 0;
}
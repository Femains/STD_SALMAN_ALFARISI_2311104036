#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    int nim;
    mahasiswa* next;
};

struct List{
    mahasiswa*first;
};

void createMahasiswa(List& L){
    L.first = NULL;
}

mahasiswa* alokasiMahasiswa(string nama, int nim){
    mahasiswa* m = new mahasiswa;
    if(m != NULL){
        m->nama = nama;
        m->nim = nim;
        m->next = NULL;
    }
    return m;
}

void inputanPertama(List& L, mahasiswa* m ){
    m->next = L.first;
    L.first = m;
}

mahasiswa* findMahasiswa(List L, int nim ){
    mahasiswa* m = L.first;
    while (m != NULL){
        if (m->nim == nim){
            return m;
        }
        m =m->next;
    }
    return NULL;
}

void printMahasiswa(List L){
    mahasiswa* m = L.first;
    while(m != NULL){
        cout<<m->nama<<" "<<m->nim <<" -> ";
        m = m->next;
    }
    cout<<"NULL"<<endl;
    cout <<endl;
}

int main(){
    List L;
    mahasiswa*M1,*M2,*M3,*M4;
    int inputan;
    createMahasiswa(L);

    M1 = alokasiMahasiswa("Salman", 23111040);
    inputanPertama(L, M1);
    printMahasiswa(L);

    M2 = alokasiMahasiswa("Gilang", 23111041);
    inputanPertama(L, M2);
    printMahasiswa(L);
    
    cout << "Cari NIM Mahasiswa = ";
    cin >> inputan;
    mahasiswa * ketemu = findMahasiswa(L, inputan);
    if(ketemu != NULL){
            cout<<"Nama Dengan NIM " << inputan << " adalah = "<<ketemu->nama<<endl;
        }else{
            cout<<"Mahasiswa dengan NIM "<<inputan<<" tidak ditemukan"<<endl;
        }
        
    
    return 0;    
}





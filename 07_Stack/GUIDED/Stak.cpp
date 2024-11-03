#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal =5, top =0;

bool isFUll(){
    return top == maksimal;
}

bool isEmpty(){
    return top == 0;
}

void pushArrayBuku(string buku){
    if (isFUll()){
        cout << "Data telah penuh"<< endl;
    }else{
        arrayBuku[top] = buku ;
        top++;
    }
}

void popArrayBuku(){
    if(isEmpty()){
        cout<<"tidak ada data yang dihapus"<<endl;
    }else{
        arrayBuku[top -1] = "";
        top--;
    }
}
void peekArrayBuku(int posisi){
    if(isEmpty()){
        cout<<"tidak ada data yang bisa dilihat"<<endl;
    }else{
        int index = top -posisi;
        if (index >=0 && index <top){
            cout<<"Posisi ke "<<posisi<<"adalah"<<arrayBuku[index];
        }else{
            cout<<"posisi di luar jangkauan"<<endl;
        }
    }
}
int countStack(){
    return top;
}

void changeArrayBuku(int posisi, string data){
    int index = top - posisi;
    if (index >= 0 && index <top){
        arrayBuku[index] = data;
    }else{
        cout<<"posisi melebihi data yang ada"<<endl;
    }
}

void destroyArrayBuku(){
    for (int i =top-1; i>=0; i--){
        arrayBuku[i] ="";
    }
    top =0;
}

void printArrayBuku(){
    if(isEmpty()){
        cout<<"Tidak ada data yang dicetak"<<endl;
    }else{
        for(int i=top-1; i>=0; i--){
            cout<<arrayBuku[i]<<endl;
        }
    }
}
int main(){
    pushArrayBuku("KALKULUS");
    pushArrayBuku("STRUKTUR DATA");
    pushArrayBuku("MATEMATIKA DISKRIT");
    pushArrayBuku("DASAR MULTIMEDIA");
    pushArrayBuku("INGGRIS");

    printArrayBuku();
    cout<<"\n"<<endl;

    cout<<"apakah data stack penuh? "<<(isFUll()? "Ya" : "tidak")<<endl;
    cout<<"apakah data stack kosong? "<<(isEmpty()? "Ya" : "tidak")<<endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout<<"Banyak data = "<<countStack()<<endl;

    changeArrayBuku(2, "bahasa jermand");
    printArrayBuku();
    cout<<"\n"<<endl;

    destroyArrayBuku();
    cout<<"top setelah destroy:"<<top<<endl;

    printArrayBuku();



    return 0;
}
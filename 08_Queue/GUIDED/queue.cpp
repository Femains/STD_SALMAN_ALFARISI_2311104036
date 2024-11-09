#include <iostream>
using namespace std;


const int maksimalQueue =5; // maksimal antiran(queue)
int front =0; // awal
int back = 0; // akhir

string queueTeller[5]; // fungsi pengecekan

bool isFull(){
    // pengecakan antrian penuh atau tidak
    if(back == maksimalQueue){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(){
    // pengecekan antrian kosong atau tidak
    if(back == 0){
        return true;
    }else{
        return false;
    }
}

void enqueueAntrian(string data){
    // fungsi penambahan data ke antrian
    if(isFull()){
        cout<<"queue penuh"<<endl;
    }else{
        if(isEmpty()){
            //saat antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        }else{
            queueTeller[back] = data;
            back++;
        }
    }
}

void denqueueAntrian(){
    // fungsi mengurangi antrian
    if(isEmpty()){
        cout<<"Antiran Kosong"<<endl;
    }else{
        for(int i=0; i<back; i++){ //pindahkan elemn ke depan
            queueTeller[i] = queueTeller[i+1];
        }
        queueTeller[back-1] =""; // kosongkan elemen terakhir
        back--;
    }
}

int countQueue(){
    //fungsi menghitung banyak antrian
    return back;
}

void clearQueue(){ //fungsi menghapus semua antrian
    if(isEmpty()){
        cout<<"Antrian kosong"<<endl;
    }else{
        for(int i =0; i<back;i++){
            queueTeller[i] ="";
        }
        back = 0;
        front = 0;
    }
}

void printQueue(){
    //fungsi menampilkan queue
    cout<<"data Antrian"<<endl;
    for(int i = 0; i<maksimalQueue; i++){
        if(queueTeller[i] != ""){
            cout<<i+1<<". " << queueTeller[i] << endl;
        }else{
            cout<<i + 1 << ". (kosong)" << endl;
        }
    }
}

int main(){
    enqueueAntrian("Satria");
    enqueueAntrian("Gilang");
    printQueue();
    cout<<"jumlah Antrian = "<< countQueue() << endl;
    cout<<endl;
    denqueueAntrian();
    printQueue();
    cout<< "jumlah Antrian = " << countQueue() << endl;
    cout<<endl;
    clearQueue();
    printQueue();
    cout<< "jumlah Antrian = " << countQueue() << endl;

    return 0;
}
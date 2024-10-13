#include <iostream>
using namespace std;
struct kerucut{
    float pi = 22.0/7;
    float Volume(float t, float r){
        float hasil;
        hasil = 1.0/3 *pi * r*r * t;
        cout <<hasil<<endl;
        return hasil;
    }
    float luasAlas (float r){
        float hasil;
        hasil = pi *r*r;
        return hasil;
    }    
    float luasSelimut(float r, float s){
        float hasil;
        hasil = pi *r *s;
        return hasil;
    }
};

int main(){
    kerucut jawaban;
    float volume = jawaban.Volume(15,7);
    cout << volume<<endl;
    float luasAlas = jawaban.luasAlas(7);
    cout<<luasAlas<<endl;
    float luasSelimut = jawaban.luasSelimut(8,9);
    cout<<luasSelimut<<endl;
    return 0;
}
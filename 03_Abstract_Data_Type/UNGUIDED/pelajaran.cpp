#include <iostream>
using namespace std;

struct pelajaran{
    string namamapel;
    string kodemapel;
};

pelajaran create_pelajaran(string namapel, string kodepel){
    pelajaran inputpelajaran;
    inputpelajaran.namamapel = namapel;
    inputpelajaran.kodemapel = kodepel;
    return inputpelajaran;
}
void tampil_pelajaran(pelajaran pel){
    cout << "nama pelajaran = " << pel.namamapel << endl;
    cout << "kode pelajaran = " << pel.kodemapel << endl;

}


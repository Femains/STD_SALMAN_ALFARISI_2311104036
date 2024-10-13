#include <iostream>
using namespace std;

void tampilkanArray(int array[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray (int array1[3][3], int array2[3][3], int baris,  int kolom){
    int temp = array1[baris][kolom];
    array1[baris][kolom] = array2[baris][kolom];
    array2[baris][kolom] = temp;
}

void tukarpointer(int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main(){
    int array1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int array2[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int *ptr1 = &array1[0][0];
    int *ptr2 = &array2[0][0];

    cout<<"Array 1 sebelum ditukar = " <<endl;
    tampilkanArray(array1);
    cout << "Array 2 sebelum ditukar = "<<endl;
    tampilkanArray(array2);

    //menukar nilai array pada baris ke 2 kolom ke 2
    tukarArray(array1, array2, 1, 1);
    
    cout <<"Array 1 Setelah ditukar = "<<endl;
    tampilkanArray(array1);
    cout << "Array 2 setelah ditukar = "<<endl;
    tampilkanArray(array2);

    tukarpointer(ptr1, ptr2);
    cout <<"Array 1 Setelah ditukar  melalui pointer = "<<endl;
    tampilkanArray(array1);
    cout << "Array 2 setelah ditukar melalui pointer = "<<endl;
    tampilkanArray(array2);
    cout << "Nilai yang ditunjuk pointer 1 = "<< *ptr1<<endl;
    cout << "Nilai yang ditunjuk pointer 2 = "<< *ptr2<<endl;

    return 0;
}
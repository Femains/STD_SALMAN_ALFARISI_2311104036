#include <iostream>
using namespace std;


struct Node{
        int info;
        Node* next;
};

Node* alokasi(int x){
    Node* newNode = new Node();
    newNode->info = x;
    newNode->next = nullptr;
    return newNode;
}
void insertFirst(Node** first, int X) {
    Node* P = alokasi(X);  
    P->next = *first;
    *first = P;
}


void insertLast(Node** first, int X) {
    Node* P = alokasi(X); 
    if (*first == nullptr) {
        *first = P;
    } else {
        Node* Q = *first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

bool searchNode(Node* first, int value) {
    Node* current = first;
    while (current != nullptr) {
        if (current->info == value) {
            return true;  
        }
        current = current->next;  
    }
    return false;  
}
int countLength(Node* first) {
    int count = 0;
    Node* current = first;
    while (current != nullptr) {
        count++;  
        current = current->next;  
    }
    return count;  
}


int main(){
    Node * first = nullptr;
    insertFirst(&first,10 );
    insertLast(&first,20);
    insertFirst(&first, 5);



    int nilaiDicari = 20;
    if (searchNode(first, nilaiDicari)) {
        std::cout << "Node dengan nilai "<< nilaiDicari <<" ditemukan" << endl;
    } else {
        std::cout << "Node dengan nilai " << nilaiDicari << " tidak ditemukan." << std::endl;
    }
    int length = countLength(first);
    cout<<"Panjang Linked List = "<<countLength(first);

    return 0;
}
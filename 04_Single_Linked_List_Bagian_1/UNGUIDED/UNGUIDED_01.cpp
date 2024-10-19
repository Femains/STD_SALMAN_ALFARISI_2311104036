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


int main(){
    Node * first = nullptr;
    insertFirst(&first,10 );
    insertLast(&first,20 );
    insertFirst(&first, 5);

    Node* temp = first;
    while (temp != nullptr) {
        std::cout << temp->info;
        if (temp->next != nullptr) {
            std::cout << "->";
        }
        temp = temp->next;
    }

    return 0;
}
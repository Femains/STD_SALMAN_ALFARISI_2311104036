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


bool deleteNode(Node** first, int value) {
    if (*first == nullptr) {
        return false;
    }
    Node* current = *first;
    Node* previous = nullptr;

    while (current != nullptr && current->info != value) {
        previous = current;
        current = current->next;
    }
    if (current == nullptr) {
        return false;
    }
    if (previous == nullptr) {
        *first = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    return true;
}



int main(){
    Node * first = nullptr;
    insertFirst(&first,10 );
    insertLast(&first,20 );
    insertFirst(&first, 5);
    deleteNode(&first, 10);

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
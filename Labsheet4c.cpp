#include <iostream>
#include "Program3.hpp"

SinglyLinkedList<int> reverse_k_nodes(int k, SinglyLinkedList<int> iList, int size){
    SinglyLinkedList<int> newList;
    if(k<size){
        return iList;
    }
    for (int i = 0; i < k; i++){
        newList.insertEnd(iList.nthNodeFromEnd(size-i)->dataItem);
        newList.reverse();
    }
}

int main(){
    int numberOfElements, k;
    SinglyLinkedList<int>* list;
    cout << "ENTER THE NUMBER OF ELEMENTS IN LINKED LIST" << endl;
    cin >> numberOfElements;
    cout << "ENTER THE ELEMENTS" << endl;
    for (int i = 0; i<numberOfElements; i++){
        int data;
        cin >> data;
        list->insertEnd(data);
    }
    cout << endl << "ENTER THE VALUE OF K";
    cin >> k;
    
}
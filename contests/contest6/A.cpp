/**
 * A program for combining two sorted linked lists.
 */

#include <iostream>

class node{
 public:
    int data;
    node* next;
};

class linkedList{
 public:
    node* head;
    node* last;

    void append(int number){
        node* n = new node();

        n->data = number;
        n->next = nullptr;

        if(head == nullptr){
            head = n;
        }

        while(last->next != nullptr){
            last = last->next;
        }

        last->next = n;
    }

    /**
     * Prints out all elements of the current linked list.
     */
    void print(){

    }
};

linkedList combine(linkedList* l1, linkedList* l2){
    return;
}

int main() {
    int n, m;

    std::cin >> n >> m;

    linkedList l1, l2;

    for (int i = 0 ; i < n ; ++i) {
        int newElement;
        std::cin >> newElement;
        l1.append(newElement);
    }

    for (int i = 0 ; i < m ; ++i) {
        int newElement;
        std::cin >> newElement;
        l2.append(newElement);
    }


    return 0;
}

/**
 * A program for inverting a linked list.
 */

#include <iostream>

class Node {
public:
    int data_;
    Node *next_;
};

class LinkedList {
public:
    Node *head_ = nullptr;

    /**
     * Add an integer to the linked list.
     * @param number The integer to be added to the end of the linked list.
     */
    void append(int number) {
        Node *n = new Node();
        n->data_ = number;
        n->next_ = nullptr;

        if (head_ == nullptr) {
            // This is the first element of the array.
            head_ = n;
            return;
        }

        Node *temp = head_;
        while (temp->next_ != nullptr) {
            temp = temp->next_;
        }

        temp->next_ = n;
    }

    /**
     * Prints out all elements of the current linked list.
     */
    void print() {
        Node *temp = head_;
        while (temp != nullptr) {
            std::cout << temp->data_ << " ";
            temp = temp->next_;
        }
        // Memory cleanup.
        delete temp;
    }

    /**
     * Memory cleanup of the linked list.
     * @param n The head node.
     */
    void clean(Node *n) {
        if (n == nullptr) {
            return;
        }

        clean(n->next_);
        n->next_ = nullptr;
        delete n;
    }

    /**
     * Inverts the linked list.
     */
    void invert() {
        // Initialize temp variables.
        Node *curr = head_;
        Node *prev = nullptr, *next = nullptr;

        while (curr != nullptr) {
            next = curr->next_;
            curr->next_ = prev;
            prev = curr;
            curr = next;
        }

        head_ = prev;

        delete curr;
        delete next;
    }
};

int main() {
    int n;

    std::cin >> n;

    auto l1 = new LinkedList;

    for (int i = 0; i < n; ++i) {
        int new_element;
        std::cin >> new_element;
        l1->append(new_element);
    }

    l1->invert();
    l1->print();
    l1->clean(l1->head_);
    delete l1;

    return 0;
}

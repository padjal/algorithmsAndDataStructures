/**
 * A program for combining two sorted linked lists.
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
};

LinkedList *combine(LinkedList *l1, LinkedList *l2) {
    auto result = new LinkedList();
    Node *n1 = l1->head_;
    Node *n2 = l2->head_;

    while (n1 != nullptr || n2 != nullptr) {
        if (n1 == nullptr) {
            result->append(n2->data_);
            n2 = n2->next_;
            continue;
        } else if (n2 == nullptr) {
            result->append(n1->data_);
            n1 = n1->next_;
            continue;
        }

        if (n1->data_ <= n2->data_) {
            result->append(n1->data_);
            n1 = n1->next_;
        } else {
            result->append(n2->data_);
            n2 = n2->next_;
        }
    }

    return result;
}

int main() {
    int n, m;

    std::cin >> n >> m;

    auto l1 = new LinkedList;
    auto l2 = new LinkedList;

    for (int i = 0; i < n; ++i) {
        int new_element;
        std::cin >> new_element;
        l1->append(new_element);
    }

    for (int i = 0; i < m; ++i) {
        int new_element;
        std::cin >> new_element;
        l2->append(new_element);
    }

    LinkedList *result = combine(l1, l2);
    result->print();

    l1->clean(l1->head_);
    l2->clean(l2->head_);
    result->clean(result->head_);
    delete l1;
    delete l2;
    delete result;

    return 0;
}

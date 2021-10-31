/**
 * A program for inserting and deletion of elements in a custom implementation of a linked list.
 */

#include <iostream>
#include <string>

class Node {
public:
    int data_;
    Node *next_;

    Node() {
        next_ = nullptr;
    }
};

class DoubleLinkedList {
public:
    Node *head_;
    int size_;

    DoubleLinkedList() {
        size_ = 0;
        head_ = nullptr;
    }

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
            size_++;
            return;
        }

        Node *temp = head_;
        while (temp->next_ != nullptr) {
            temp = temp->next_;
        }

        temp->next_ = n;
        size_++;
    }

    /**
     * Inserts an element after a given index.
     * @param val The integer to be stored in that Node.
     * @param pos The position at which the element is added.
     * Constraints: >= 0 and <= list_size-1.
     */
    void insert(int val, int pos) {
        if (pos < 0 || pos > size_ - 1) {
            // Position index is outside list scope.
            return;
        }
        int count = 0;

        Node *new_node = new Node();
        new_node->data_ = val;

        if (head_ == nullptr) {
            head_ = new_node;
            size_++;
            return;
        }

        Node *prev = head_;
        while (count != pos) {
            count++;
            prev = prev->next_;
        }

        new_node->next_ = prev->next_;
        prev->next_ = new_node;
        size_++;
    }

    /**
     * Removes an element after the specified index.
     * @param pos The index of the removed element.
     * Constraints: pos should be >= 0 and <= list_size-1.
     */
    void remove(int pos) {
        if (pos < 0 || pos > size_ - 1) {
            // Position index is outside list scope.
            return;
        }

        if (pos == 0) {
            Node *temp = head_->next_;
            head_->next_ = head_->next_->next_;
            delete temp;
            return;
        }

        int count = 0;
        Node *temp = head_;
        while (count != pos) {
            temp = temp->next_;
            count++;
        }

        if (pos == size_) {
            // It's the last element.
            delete temp->next_;
            return;
        }

        temp->next_ = temp->next_->next_;
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

        std::cout << std::endl;
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

int main() {
    int n_elements;
    int cmds;

    std::cin >> n_elements >> cmds;

    auto l = new DoubleLinkedList();

    for (int i = 0; i < n_elements; ++i) {
        int new_element;
        std::cin >> new_element;
        l->append(new_element);
    }

    std::string command;
    for (int i = 0; i < cmds; ++i) {
        std::cin >> command;
        if (command == "insert") {
            int n, p;
            std::cin >> n >> p;
            l->insert(n, p);
        } else if (command == "remove") {
            int n;
            std::cin >> n;
            l->remove(n);
        }
    }

    l->print();
    // Memory cleanup.
    l->clean(l->head_);
    delete l;

    return 0;
}

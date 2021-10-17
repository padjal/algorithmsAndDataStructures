/**
 * An implementation of a double linked list.
 */

#include <iostream>
#include <string>

class Node {
public:
    int data_;
    Node *next_;
    Node *previous_;

    Node() {
        next_ = nullptr;
        previous_ = nullptr;
    }
};

class DoubleLinkedList {
public:
    Node *head_;
    Node *tail_;
    int size_;

    DoubleLinkedList() {
        size_ = 0;
        head_ = nullptr;
        tail_ = nullptr;
    }

    /**
     * Add an element to the beginning of the linked list.
     * @param n The integer contained in that new element.
     */
    void pushFront(int n) {
        Node *new_node = new Node();
        new_node->data_ = n;

        if (head_ == nullptr) {
            tail_ = head_;
            tail_->previous_ = new_node;
            new_node->next_ = tail_;
            head_ = new_node;
        }

        new_node->next_ = head_;
        head_->previous_ = new_node;
        head_ = new_node;
        size_++;
    }

    /**
     * Add an element to the tail of the linked list.
     * @param n The integer to be stored in that last Node.
     */
    void pushBack(int n) {
        Node *new_node = new Node();
        new_node->data_ = n;

        if (head_ == nullptr) {
            // This is the first or second element.
            head_ = new_node;
            size_++;
            return;
        } else if (tail_ == nullptr) {
            tail_ = new_node;
            tail_->previous_ = head_;
            head_->next_ = tail_;
            size_++;
            return;
        }

        new_node->previous_ = tail_;
        tail_->next_ = new_node;
        tail_ = new_node;
        size_++;
    }

    /**
     * Inserts an element at a given index.
     * @param val The integer value contain in that Node.
     * @param pos The position at which the element is added.
     * Constraints: >= 0 and <= list_size-2.
     */
    void insert(int val, int pos) {
        if (pos < 0 || pos > size_ - 1) {
            // Position index is outside list scope.
            return;
        }
        int count = 0;
        Node *prev = head_;
        while (prev != nullptr) {
            if (count == pos) {
                // Add element.
                Node *new_element = new Node();
                new_element->data_ = val;
                new_element->next_ = prev->next_;
                prev->next_->previous_ = new_element;
                prev->next_ = new_element;
                new_element->previous_ = prev;
                size_++;
                return;
            }
            prev = prev->next_;
            count++;
        }
    }

    /**
     * Removes an element at the specified index.
     * @param pos The index of the removed element.
     * Constraints: pos should be >= 0 and <= list_size-2.
     */
    void remove(int pos) {
        if (pos < 0 || pos > size_ - 2) {
            // Position index is outside list scope.
            return;
        }
        int count = 0;
        Node *temp = head_;
        while (count != pos + 1) {
            temp = temp->next_;
            count++;
        }

        if (temp->next_ == nullptr) {
            // It is the last element.
            temp->previous_->next_ = nullptr;
            tail_ = temp->previous_;
            delete temp;
            size_--;
            return;
        }

        temp->previous_->next_ = temp->next_;
        temp->next_->previous_ = temp->previous_;
        delete temp;
        size_--;
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
     * Prints out all elements of the current linked list.
     */
    void printReverse() {
        Node *temp = tail_;
        while (temp != nullptr) {
            std::cout << temp->data_ << " ";
            temp = temp->previous_;
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

int main() {
    int n_elements;
    int cmds;

    std::cin >> n_elements >> cmds;

    auto l = new DoubleLinkedList();

    for (int i = 0; i < n_elements; ++i) {
        int new_element;
        std::cin >> new_element;
        l->pushBack(new_element);
    }

    std::string command;
    for (int i = 0; i < cmds; ++i) {
        std::cin >> command;
        if (command == "push_front") {
            int n;
            std::cin >> n;
            l->pushFront(n);
        } else if (command == "push_back") {
            int n;
            std::cin >> n;
            l->pushBack(n);
        } else if (command == "insert") {
            int n, p;
            std::cin >> n >> p;
            l->insert(n, p);
        } else if (command == "remove") {
            int p;
            std::cin >> p;
            l->remove(p);
        }
    }

    l->print();
    l->printReverse();
    l->clean(l->head_);
    delete l;
    // Memory cleanup.

    return 0;
}

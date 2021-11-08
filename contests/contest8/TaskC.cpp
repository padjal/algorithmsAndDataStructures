#include <iostream>

class Node {
public:
    int data_;
    Node *left_ = nullptr;
    Node *right_ = nullptr;
    int times_added_;

    explicit Node(int value) {
        data_ = value;
        times_added_ = 1;
    }
};

class Tree {
private:
    Node *root_;

    void clearUtil(Node *node) {
        if (node == nullptr) {
            return;
        }

        clearUtil(node->left_);
        clearUtil(node->right_);

        delete node;
    }

public:
    /// Adds a node with the given value to the tree.
    /// \param value The value of the added node to the tree.
    void addNode(int value) {
        if (root_ == nullptr) {
            root_ = new Node(value);
            return;
        }

        Node *temp = root_;
        bool node_found = false;

        while (!node_found) {
            if (value < temp->data_) {
                if (temp->left_ == nullptr) {
                    node_found = true;
                } else {
                    temp = temp->left_;
                }
            } else if (value == temp->data_) {
                temp->times_added_++;
                return;
            } else {
                if (temp->right_ == nullptr) {
                    node_found = true;
                } else {
                    temp = temp->right_;
                }
            }
        }

        Node *new_node = new Node(value);

        if (value < temp->data_) {
            temp->left_ = new_node;
        } else {
            temp->right_ = new_node;
        }
    }

    void inOrder(Node *node) {
        if (node == nullptr) {
            return;
        }
        inOrder(node->left_);
        std::cout << node->data_ << " " << node->times_added_ << std::endl;
        inOrder(node->right_);
    }

    void display() {
        inOrder(root_);
    }

    void clear() {
        if (root_ == nullptr) {
            return;
        }

        clearUtil(root_);
    }
};

int main() {
    int number;
    std::cin >> number;

    Tree *tree = new Tree();

    while (number != 0) {
        tree->addNode(number);
        std::cin >> number;
    }

    tree->display();

    //  Cleanup
    tree->clear();
    delete tree;

    return 0;
}

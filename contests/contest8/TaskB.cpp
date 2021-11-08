#include <iostream>
#include <algorithm>

class Node {
public:
    int data_;
    Node *left_;
    Node *right_;

    explicit Node(int value) {
        data_ = value;
        left_ = nullptr;
        right_ = nullptr;
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

    int height(Node *node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(height(node->left_), height(node->right_));
    }

    bool isBalanced(Node *node) {
        if (node == nullptr) {
            return true;
        }

        int lh = height(node->left_);
        int rh = height(node->right_);

        if (abs(lh - rh) <= 1 && isBalanced(node->left_) && isBalanced(node->right_)) {
            return true;
        }
        return false;
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

    /// Clears all the memory of the current tree.
    void clear() {
        if (root_ == nullptr) {
            return;
        }

        clearUtil(root_);
    }

    /// Returns true if the current tree is AVL.
    bool isAVL() {
        if (root_ == nullptr) {
            return true;
        }

        return isBalanced(root_);
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

    tree->isAVL() ? std::cout << "YES" : std::cout << "NO";

    //  Cleanup
    tree->clear();
    delete tree;

    return 0;
}

#include <iostream>

class Node {
public:
    explicit Node(int n) {
        data_ = n;
        left_ = nullptr;
        right_ = nullptr;
    }

    int data_;
    Node *left_;
    Node *right_;
};

class Tree {
private:
    Node *getLargest(Node *node) {
        if (node->right_ != nullptr) {
            return getLargest(node->right_);
        }
        return node;
    }

public:
    Node *root_;

    explicit Tree(int root_value) {
        root_ = new Node(root_value);
    }

    void clear(Node *node) {
        if (node == nullptr) {
            return;
        }

        clear(node->left_);
        clear(node->right_);

        delete node;
    }

    void addNode(int value) {
        Node *temp = root_;
        int current_height = 1;

        while (true) {
            current_height++;
            if (value < temp->data_) {
                if (temp->left_ == nullptr) {
                    break;
                }
                temp = temp->left_;
            } else if (value == temp->data_) {
                return;
            } else {
                if (temp->right_ == nullptr) {
                    break;
                }
                temp = temp->right_;
            }
        }

        Node *new_node = new Node(value);

        if (value < temp->data_) {
            temp->left_ = new_node;
        } else {
            temp->right_ = new_node;
        }

        temp = nullptr;
        new_node = nullptr;
    }

    Node *getSecondLargest(Node *node) {
        if (node->right_ == nullptr && node->left_ != nullptr) {
            return getLargest(node->left_);
        }

        if (node->right_ != nullptr && node->right_->left_ == nullptr &&
            node->right_->right_ == nullptr) {
            return node;
        }

        return getSecondLargest(node->right_);
    }
};

int main() {
    int n;
    std::cin >> n;

    Tree *tree = new Tree(n);

    std::cin >> n;
    while (n != 0) {
        tree->addNode(n);
        std::cin >> n;
    }

    std::cout << tree->getSecondLargest(tree->root_)->data_;

    tree->clear(tree->root_);
    delete tree;

    return 0;
}

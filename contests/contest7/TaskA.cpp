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
    int max_height_ = 1;

public:
    Node *root_;

    explicit Tree(int root_value) {
        root_ = new Node(root_value);
    }

    void clear(Node *node) {
        // Memory cleanup
        if (node->left_ != nullptr) {
            clear(node->left_);
        }

        if (node->right_ != nullptr) {
            clear(node->right_);
        }

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

        if (current_height > max_height_) {
            max_height_ = current_height;
        }
    }

    int getHeight() {
        return max_height_;
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

    std::cout << tree->getHeight();

    tree->clear(tree->root_);
    delete tree;

    return 0;
}

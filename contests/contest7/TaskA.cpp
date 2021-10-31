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
    int maxDepth(Node *node) {
        if (node == nullptr) {
            return -1;
        } else {
            int left_depth = maxDepth(node->left_);
            int right_depth = maxDepth(node->right_);

            if (left_depth > right_depth) {
                return (left_depth + 1);
            } else {
                return (right_depth + 1);
            }
        }
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

        while (true) {
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

    int getHeight() {
        return maxDepth(root_) + 1;
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

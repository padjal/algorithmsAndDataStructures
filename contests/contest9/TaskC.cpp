/**
 * Ths program performs a SPLAY-based search on a binary tree.
 */

#include <iostream>
#include <algorithm>

class Node {
public:
    int key;
    Node *left_;
    Node *right_;
    Node *parent_;

    explicit Node(int value) {
        key = value;
        left_ = nullptr;
        right_ = nullptr;
        parent_ = nullptr;
    }
};

class SplayTree {
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

    int height(Node *node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(height(node->left_), height(node->right_));
    }

public:
    SplayTree() {
        root_ = nullptr;
    }

    ~SplayTree() {
        if (root_ == nullptr) {
            return;
        }

        clearUtil(root_);
    }

    /// Adds an element to the binary tree without balancing.
    /// If the element is already present, the method should return
    /// without modifying the collection.
    /// \param key The integer element to be added.
    void insert(int key) {
        if (root_ == nullptr) {
            root_ = new Node(key);
            return;
        }

        Node *current_node = root_;
        bool node_found = false;

        while (!node_found) {
            if (key < current_node->key) {
                if (current_node->left_ == nullptr) {
                    node_found = true;
                } else {
                    current_node = current_node->left_;
                }
            } else if (key == current_node->key) {
                return;
            } else {
                if (current_node->right_ == nullptr) {
                    node_found = true;
                } else {
                    current_node = current_node->right_;
                }
            }
        }

        Node *new_node = new Node(key);
        new_node->parent_ = current_node;

        if (key < current_node->key) {
            current_node->left_ = new_node;
        } else {
            current_node->right_ = new_node;
        }
    }

    /// Finds the node which contains the given key.
    /// \param key The searched key.
    /// \return A pointer to the node containing the given key.
    Node *find(int key) const {
        if (root_ == nullptr) {
            return nullptr;
        }

        Node *current_node = root_;
        while (current_node != nullptr) {
            if (key == current_node->key) {
                return current_node;
            }

            if (key < current_node->key) {
                current_node = current_node->left_;
            } else if (key > current_node->key) {
                current_node = current_node->right_;
            }
        }

        return nullptr;
    }

    /// Perfrm zig-zag operations to make the given node the root of the tree.
    /// \param node The pinter that should  become a root of the tree.
    /// \return The number of operations performed in order to set the new root.
    int splay(Node *node) {
        if (root_ == nullptr || node == root_) {
            return 0;
        }
    }

    /// Gets the maximum height of the tree.
    /// \return The maximum height of the tree.
    int getHeight() const {
        return height(root_) - 1;
    }
};

/*int main() {
    SplayTree *splayTree = new SplayTree();
    splayTree->insert(10);
    splayTree->insert(5);
    splayTree->insert(15);
    splayTree->insert(3);
    splayTree->insert(7);
    splayTree->insert(13);
    splayTree->insert(17);
    splayTree->insert(4);
    splayTree->insert(6);
    splayTree->insert(12);
    splayTree->insert(16);

    Node *node = splayTree->find(7);
    int height = splayTree->getHeight();


    return 0;
}*/

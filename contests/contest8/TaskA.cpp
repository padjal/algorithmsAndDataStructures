/*
 * Checking a binary tree for red-blackness.
 */

#include <iostream>
#include <string>
#include <climits>

enum Color { RED, BLACK };

class Node {
public:
    int key_;
    int left_;
    int right_;
    Color color_;

    Node() {
    }

    Node(int key, int left, int right, Color color) {
        key_ = key;
        left_ = left;
        right_ = right;
        color_ = color;
    }
};

bool isBSTUtil(Node *nodes, int current_node, int min, int max) {
    if (current_node == -1) {
        return true;
    }

    if (nodes[current_node].key_ < min || nodes[current_node].key_ > max) {
        return false;
    }

    return isBSTUtil(nodes, nodes[current_node].left_ - 1, min, nodes[current_node].key_ - 1) &&
           isBSTUtil(nodes, nodes[current_node].right_ - 1, nodes[current_node].key_ + 1, max);
}

bool isBST(Node *nodes, int root_number) {
    return isBSTUtil(nodes, root_number - 1, INT_MIN, INT_MAX);
}

bool check(Node *nodes, int root_number, int size) {
    if (!isBST(nodes, root_number)) {
        return false;
    }

    for (int current_node = 0; current_node < size; ++current_node) {
        if (nodes[current_node].left_ != 0 && nodes[current_node].right_ == 0 &&
            nodes[current_node].color_ == RED) {
            return false;
        }

        if (nodes[current_node].right_ != 0 && nodes[current_node].left_ == 0 &&
            nodes[current_node].color_ == RED) {
            return false;
        }

        if (nodes[root_number - 1].color_ == RED) {
            return false;
        }

        if (nodes[current_node].color_ == RED) {
            Node temp = nodes[root_number - 1];
            Node parent;

            while (temp.key_ != nodes[current_node].key_) {
                parent = temp;

                if (temp.key_ > nodes[current_node].key_) {
                    temp = nodes[temp.left_ - 1];
                } else {
                    temp = nodes[temp.right_ - 1];
                }
            }

            if (parent.key_ == RED) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int tree_size;
    int root;

    std::cin >> tree_size;
    std::cin >> root;

    if (tree_size <= 0 || root < 1 || root > tree_size) {
        std::cout << "YES";
        return 0;
    }

    Node *nodes = new Node[tree_size];

    for (int current_node = 0; current_node < tree_size; ++current_node) {
        int number;
        std::cin >> number;

        int key;
        std::cin >> key;

        int left;
        std::string left_string;
        std::cin >> left_string;
        if (left_string == "null") {
            left = 0;
        } else {
            left = std::stoi(left_string);
        }

        int right;
        std::string right_string;
        std::cin >> right_string;
        if (right_string == "null") {
            right = 0;
        } else {
            right = std::stoi(right_string);
        }

        char c;
        std::cin >> c;

        Color color;

        if (c == 'R') {
            color = RED;
        } else if (c == 'B') {
            color = BLACK;
        } else {
            return 0;
        }

        nodes[number - 1] = Node(key, left, right, color);
    }

    if (check(nodes, root, tree_size)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    //  Cleanup
    delete[] nodes;

    return 0;
}

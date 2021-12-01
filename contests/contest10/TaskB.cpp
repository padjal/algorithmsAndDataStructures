#include <iostream>

class IslandsAndBridges {
public:
    explicit IslandsAndBridges(int islands) {
        islands_size_ = islands;
        islands_ = new int[islands];
        min_bridges_ = 0;
        lengths_ = new int[islands];
        is_connected_ = false;
        for (int i = 0; i < islands_size_; ++i) {
            islands_[i] = i;
            lengths_[i] = 1;
        }
    }

    void unite(int first_island, int second_island) {
        if (is_connected_) {
            return;
        }
        int first_head = findHead(first_island);
        int second_head = findHead(second_island);
        min_bridges_++;

        if (first_head == second_head) {
            return;
        }

        islands_[second_head] = first_head;
        lengths_[first_head] += lengths_[second_head];
        lengths_[second_head] = 0;
        if (lengths_[first_head] == islands_size_) {
            is_connected_ = true;
        }
    }

    int getMinBridges() const {
        return min_bridges_;
    }

    void clear() {
        delete[] islands_;
        delete[] lengths_;
        islands_ = nullptr;
        lengths_ = nullptr;
    }

private:
    int islands_size_;
    int *islands_;
    int *lengths_;
    int min_bridges_;
    bool is_connected_;

    int findHead(int number) {
        if (islands_[number] == number) {
            return number;
        } else {
            return findHead(islands_[number]);
        }
    }
};

int main() {
    int islands, bridges;
    std::cin >> islands >> bridges;
    // Check input data
    if (islands < 1 || bridges < 1 || islands > 200000 || bridges > 200000) {
        return 0;
    }
    auto *world = new IslandsAndBridges(islands);
    for (int index = 0; index < bridges; ++index) {
        int bridge_one, bridge_two;
        std::cin >> bridge_one >> bridge_two;
        // Check islands
        if (bridge_one < 0 || bridge_two >= islands || bridge_one >= islands || bridge_two < 0) {
            return 0;
        }
        world->unite(bridge_one, bridge_two);
    }
    std::cout << world->getMinBridges();
    // Memory cleanup
    world->clear();
    delete world;
    return 0;
}

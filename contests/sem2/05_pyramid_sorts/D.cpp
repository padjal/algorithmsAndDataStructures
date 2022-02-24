/*
 * All n villages are in a straight line.
 * All m bomb shelters are located on the same road.
 */

#include <iostream>
#include <vector>
#include <utility>

class Heap {
private:
    std::vector<std::pair<int, int>> list_;

public:
    std::pair<int, int> getMax() {
        std::pair<int, int> result = list_[0];
        list_[0] = list_[getSize() - 1];
        list_.pop_back();
        return result;
    }

    int getSize() {
        return list_.size();
    }

    explicit Heap(std::vector<std::pair<int, int>> v) {
        list_ = v;
        for (int i = getSize() / 2; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    void heapifyDown(int i) {
        int left_child;
        int right_child;
        int largest_child;

        left_child = 2 * i + 1;
        right_child = 2 * i + 2;
        largest_child = i;

        if (left_child < getSize() && list_[left_child] > list_[largest_child]) {
            largest_child = left_child;
        }

        if (right_child < getSize() && list_[right_child] > list_[largest_child]) {
            largest_child = right_child;
        }

        if (largest_child != i) {
            std::pair<int, int> temp = list_[i];
            list_[i] = list_[largest_child];
            list_[largest_child] = temp;
            i = largest_child;

            heapifyDown(largest_child);
        }
    }
};

void heapSort(std::vector<std::pair<int, int>> *v) {
    Heap *heap = new Heap(*v);

    for (int i = v->size() - 1; i >= 0; --i) {
        v->at(i) = heap->getMax();
        heap->heapifyDown(0);
    }

    delete heap;
}

// The implementation of this method can be improved by using bubble sort
// to find the closest item in the list.
/*std::pair<int, int> findClosest(int value, std::vector<std::pair<int, int>> *list) {
    if (list->empty()) {
        return std::make_pair(-1, -1);
    } else if (list->size() == 1) {
        return list->at(0);
    }

    std::pair<int, int> closest = list->at(0);
    auto front_iter = list->begin();
    auto back_iter = --list->end();

    while (front_iter != back_iter) {
        auto check1 = std::abs(front_iter->first - value);
        auto check3 = back_iter->first;
        auto check2 = std::abs(back_iter->first - value);
        if (std::abs(front_iter->first - value) > std::abs(back_iter->first - value)) {
            front_iter++;
        } else {
            back_iter--;
        }
    }

    auto check4 = front_iter->first;
    return *front_iter;
}*/

std::pair<int, int> getClosest(std::pair<int, int> val1, std::pair<int, int> val2, int target) {
    if (target - val1.first >= val2.first - target) {
        return val2;
    } else {
        return val1;
    }
}

std::pair<int, int> findClosest(std::vector<std::pair<int, int>> arr, int target) {
    if (target <= arr[0].first) {
        return arr[0];
    }
    if (target >= arr[arr.size() - 1].first) {
        return arr[arr.size() - 1];
    }

    int i = 0, j = arr.size(), mid = 0;
    while (i < j) {
        mid = (i + j) / 2;

        if (arr[mid].first == target) {
            return arr[mid];
        }

        if (target < arr[mid].first) {
            if (mid > 0 && target > arr[mid - 1].first) {
                return getClosest(arr[mid - 1], arr[mid], target);
            }
            j = mid;
        } else {
            if (mid < static_cast<int>(arr.size()) - 1 && target < arr[mid + 1].first) {
                return getClosest(arr[mid], arr[mid + 1], target);
            }
            i = mid + 1;
        }
    }

    return arr[mid];
}

/*void printVector(std::vector<std::pair<int, int>> *v) {
    for (auto e: *v) {
        std::cout << e.first << " ";
    }
}*/

int main() {
    // Number of villages and bombshells respectively.
    int villages_size, bombshell_size, next_integer;
    // Locations from the beginning of the road.
    std::vector<int> villages_locations;
    // Storing vectors to keep track of initial index
    std::vector<std::pair<int, int>> bombshell_locations;

    std::cin >> villages_size;

    for (int i = 0; i < villages_size; ++i) {
        std::cin >> next_integer;
        villages_locations.push_back(next_integer);
    }

    std::cin >> bombshell_size;

    for (int i = 0; i < bombshell_size; ++i) {
        std::cin >> next_integer;
        bombshell_locations.emplace_back(next_integer, i);
    }

    // Sort bombshell
    heapSort(&bombshell_locations);

    // printVector(&bombshell_locations);

    for (int i = 0; i < villages_size; ++i) {
        std::cout << findClosest(bombshell_locations, villages_locations[i]).second + 1 << " ";
    }

    return 0;
}

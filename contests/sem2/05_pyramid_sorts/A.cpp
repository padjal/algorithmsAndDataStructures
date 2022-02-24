/*
 * max heap
 *
 * Problem: спращивают на каком эл-те (при проходе от
 * нулевого эл-та массиваа направо) условие кучи перестанет выполняться
 */

#include <iostream>
#include <vector>

int isHeap(std::vector<int> *nums) {
    if (nums->empty() || nums->size() == 1) {
        return 0;
    } else if (nums->size() == 2) {
        return nums->at(0) >= nums->at(1) ? 1 : 0;
    }

    for (int i = 0; i < (nums->size()) / 2; ++i) {
        if (2 * i + 1 <= nums->size() - 1 && nums->at(i) < nums->at(2 * i + 1)) {
            return 2 * i;
        }
        if (2 * i + 2 <= nums->size() - 1 && nums->at(i) < nums->at(2 * i + 2)) {
            return 2 * i + 1;
        }
    }

    return nums->size() - 1;
}

int main() {
    int n;

    std::cin >> n;

    std::vector<int> nums;

    int next_number;
    for (int i = 0; i < n; ++i) {
        std::cin >> next_number;
        nums.push_back(next_number);
    }

    std::cout << isHeap(&nums);

    return 0;
}

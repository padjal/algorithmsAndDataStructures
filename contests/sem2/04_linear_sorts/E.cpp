#include <iostream>
#include <vector>

int main() {
    int n, total_presses;
    std::vector<int> clicks_left, push_order;

    std::cin >> n;

    int next_number;
    for (int i = 0; i < n; ++i) {
        std::cin >> next_number;
        clicks_left.push_back(next_number);
    }

    std::cin >> total_presses;

    for (int i = 0; i < total_presses; ++i) {
        std::cin >> next_number;
        push_order.push_back(next_number);
    }

    for (int click: push_order) {
        clicks_left[click - 1]--;
    }

    for (int left_clicks: clicks_left) {
        if (left_clicks < 0) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }

    return 0;
}

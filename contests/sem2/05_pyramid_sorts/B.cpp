#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> list_;

public:
    void add(int value) {
        list_.push_back(value);
        int i = getSize() - 1;
        int parent = (i - 1) / 2;

        while (i > 0 && list_[parent] < list_[i]) {
            int temp = list_[i];
            list_[i] = list_[parent];
            list_[parent] = temp;

            i = parent;
            parent = (i - 1) / 2;
        }
    }

    int getMax() {
        int result = list_[0];
        list_[0] = list_[getSize() - 1];
        list_.pop_back();
        return result;
    }

    int getSize() {
        return list_.size();
    }

    explicit Heap(std::vector<int> v) {
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
            int temp = list_[i];
            list_[i] = list_[largest_child];
            list_[largest_child] = temp;
            i = largest_child;

            heapifyDown(largest_child);
        }
    }

    void remove() {
    }

    void print() {
        for (int e : list_) {
            std::cout << e << " ";
        }
    }
};

void heapSort(std::vector<int> *v) {
    Heap *heap = new Heap(*v);

    for (int i = v->size() - 1; i >= 0; --i) {
        v->at(i) = heap->getMax();
        heap->heapifyDown(0);
    }

    delete heap;
}

void printVector(std::vector<int> *v) {
    for (auto e : *v) {
        std::cout << e << " ";
    }
}

int main() {
    int n;

    std::cin >> n;

    std::vector<int> numbers;

    int next_number;
    for (int i = 0; i < n; ++i) {
        std::cin >> next_number;
        numbers.push_back(next_number);
    }

    heapSort(&numbers);

    printVector(&numbers);

    return 0;
}

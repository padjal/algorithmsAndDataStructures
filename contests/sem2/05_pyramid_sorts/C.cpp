/*
 * Full max heap implementation.
 */

#include <vector>
#include <utility>

template <class ValueType>
class Heap {
private:
    ValueType getMax() {
        ValueType result = list_[0];
        list_[0] = list_[size() - 1];
        list_.pop_back();
        return result;
    }

    std::vector<ValueType> list_;

    void heapifyDown(int i) {
        int left_child;
        int right_child;
        int largest_child;

        left_child = 2 * i + 1;
        right_child = 2 * i + 2;
        largest_child = i;

        if (left_child < size() && list_[left_child] > list_[largest_child]) {
            largest_child = left_child;
        }

        if (right_child < size() && list_[right_child] > list_[largest_child]) {
            largest_child = right_child;
        }

        if (largest_child != i) {
            std::swap(largest_child, list_[i]);

            heapifyDown(largest_child);
        }
    }

    void heapifyUp(int i) {
        int parent_index = (i - 1) / 2;

        if (list_[i] > list_[parent_index]) {
            std::swap(list_[i], list_[parent_index]);

            heapifyUp(parent_index);
        }
    }

public:
    Heap() = default;

    // Status: Works
    template <class Iterator>
    Heap(Iterator begin, Iterator end) {
        for (auto i = begin; i != end; ++i) {
            insert(*i);
        }
    }

    // Status:
    Heap(std::initializer_list<ValueType> initializer_list) {
        Heap(initializer_list.begin(), initializer_list.end() + 1);
    }

    // Status: Works
    // Copy constructor
    Heap(const Heap &other_heap) {
        list_ = other_heap.list_;
    }

    // Status: Works
    // Copy assignment
    Heap &operator=(const Heap &other_heap) {
        list_ = other_heap.list_;
        return *this;
    }

    // Status:
    // Move constructor
    Heap(Heap &&other_heap) {
        list_ = std::move(other_heap.list_);

        for (int i = 0; i < size() / 2; ++i) {
            heapifyDown(i);
        }
    }

    // Status
    // Move assignment
    Heap &operator=(Heap &&other_heap) {
        list_ = std::move(other_heap.list_);

        for (int i = 0; i < size() / 2; ++i) {
            heapifyDown(i);
        }

        return *this;
    }

    ~Heap() {
        list_.clear();
    }

    // Status: Works
    size_t size() {
        return list_.size();
    }

    // Status: Works
    bool empty() const {
        return list_.empty();
    }

    // Status: Works
    void insert(const ValueType &element) {
        list_.push_back(element);

        heapifyUp(size() - 1);
    }

    // Status:
    ValueType extract() {
        ValueType first_element = list_[0];

        list_[0] = list_[size() - 1];
        list_.pop_back();

        heapifyDown(0);

        return first_element;
    }
};

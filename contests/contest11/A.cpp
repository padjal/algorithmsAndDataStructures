/**
 * This program finds the minimum spanning tree.
 */

/**
 * Solving steps:
 *  1. Take edges
 *  2. Sort edges by weight with quicksort algorithm.
 *  3. Go through edges checking DSU by increase of weight.
 */

#include <iostream>

struct Edge {
public:
    int src_;
    int dest_;
    int weight_;

    Edge(int src, int dest, int weight) {
        src_ = src;
        dest_ = dest;
        weight_ = weight;
    }
};

class MinimumSpanningTree {
private:
    int vertices_;
    int edges_;

    void printEdges() {
        for (int i = 0; i < edges_; ++i) {
            std::cout << "Source: " << edgesContainer_[i]->src_;
            std::cout << " Dest: " << edgesContainer_[i]->dest_;
            std::cout << " Weight: " << edgesContainer_[i]->weight_ << std::endl;
        }
    }

    void initialize() {
        verticesContainer_ = new int[vertices_];
        edgesContainer_ = new Edge *[edges_];

        for (int i = 0; i < vertices_; ++i) {
            verticesContainer_[i] = i;
        }

        int src, dest, weight;

        for (int i = 0; i < edges_; ++i) {
            std::cin >> src >> dest >> weight;
            edgesContainer_[i] = new Edge(src, dest, weight);
        }

        // quickSortThree(edgesContainer_, 0, edges_ - 1);
        quickSortTwo(edgesContainer_, edges_);

        // printEdges();
    }

    /*void quickSortThree(Edge *arr[], int begin, int end) {
        if (begin < end) {
            int middle = partition(arr, begin, end);
            quickSortThree(arr, begin, middle - 1);
            quickSortThree(arr, middle + 1, end);
        }
    }

    int partition(Edge *array[], const int &begin, const int &end) {
        int index = begin - 1;
        for (int j = begin; j < end; ++j) {
            if (array[j]->weight_ < array[end]->weight_) {
                ++index;
                Edge *copy = array[index];
                array[index] = array[j];
                array[j] = copy;
            }
        }

        Edge *copy = array[end];
        array[end] = array[index + 1];
        array[index + 1] = copy;
        return (index + 1);
    }*/

    /*static void swapEdges(Edge *a, Edge *b) {
        Edge t = *a;
        *a = *b;
        *b = t;
    }

    static int partition(Edge *arr[], int low, int high) {
        int pivot = arr[high]->weight_;
        int index = (low - 1);

        for (int j = low; j <= high - 1; ++j) {
            if (arr[j]->weight_ < pivot) {
                index++;
                swapEdges(arr[index], arr[j]);
            }
        }
        swapEdges(arr[index + 1], arr[high]);
        return (index + 1);
    }

    void quickSort(Edge *arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSortThree(arr, pi + 1, high);
        }
    }*/

    void quickSortTwo(Edge *arr[], int size) {
        int min_index = 0;
        int max_index = size - 1;

        int mid = arr[size / 2]->weight_;

        do {
            while (arr[min_index]->weight_ < mid) {
                min_index++;
            }
            while (arr[max_index]->weight_ > mid) {
                max_index--;
            }

            // Swap
            if (min_index <= max_index) {
                Edge *tmp = arr[min_index];
                arr[min_index] = arr[max_index];
                arr[max_index] = tmp;

                min_index++;
                max_index--;
            }
        } while (min_index <= max_index);

        if (max_index > 0) {
            // Left
            quickSortTwo(arr, max_index + 1);
        }
        if (min_index < size) {
            // Right
            quickSortTwo(&arr[min_index], size - min_index);
        }
    }

    int find(int number) {
        if (verticesContainer_[number] == number) {
            return number;
        } else {
            return verticesContainer_[number] = find(verticesContainer_[number]);
        }
    }

public:
    int *verticesContainer_{};  // Containing sets information about the vertices
    Edge **edgesContainer_{};   // Contains all entered edges by the user.

    MinimumSpanningTree(int vertices, int edges) {
        edges_ = edges;
        vertices_ = vertices;
        initialize();
    }

    ~MinimumSpanningTree() {
        for (int i = 0; i < edges_; ++i) {
            delete edgesContainer_[i];
            edgesContainer_[i] = nullptr;
        }

        delete[] edgesContainer_;
        edgesContainer_ = nullptr;
        delete[] verticesContainer_;
        verticesContainer_ = nullptr;
    }

    int getMinWeight() {
        int min_weight = 0;

        for (int i = 0; i < edges_; ++i) {
            int first_set = find(edgesContainer_[i]->src_ - 1);
            int second_set = find(edgesContainer_[i]->dest_ - 1);

            if (first_set != second_set) {
                verticesContainer_[second_set] = first_set;
                min_weight += edgesContainer_[i]->weight_;
            }
        }

        return min_weight;
    }
};

int main() {
    // User input.
    int vertices, edges;
    std::cin >> vertices >> edges;
    // Check input.
    if (vertices < 2 || vertices > 20000 || edges < 1 || edges > 100000) {
        return 0;
    }

    auto m_s_tree = new MinimumSpanningTree(vertices, edges);

    std::cout << m_s_tree->getMinWeight();

    delete m_s_tree;

    return 0;
}

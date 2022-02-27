#include <vector>
#include <iostream>
#include <utility>
#include "student-ski.h"

void quickSort(std::vector<Student> *v, int low, int high) {
    int i = low, j = high;
    Student pivot = v->at((low + high) / 2);

    do {
        while (v->at(i).id < pivot.id) {
            i++;
        }
        while (v->at(j).id > pivot.id) {
            j--;
        }

        if (i <= j) {
            if (v->at(i).id > v->at(j).id) {
                std::swap(v->at(i), v->at(j));
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < high) {
        quickSort(v, i, high);
    }
    if (low < j) {
        quickSort(v, low, j);
    }
}

void findPairs(std::vector<Student> *students, std::vector<Ski> *skis) {
    // your code
    quickSort(students, 0, students->size() - 1);

    for (int i = 0; i < students->size(); ++i) {
        for (int j = 0; j < skis->size(); ++j) {
            if (compare(students->at(i), skis->at(j)) == 0) {
                skis->at(i) = skis->at(j);
            }
        }
    }

    for (int j = 0; j < skis->size(); ++j) {
        std::cout << j + 1 << " " << skis->at(j).id << "; ";
    }
}

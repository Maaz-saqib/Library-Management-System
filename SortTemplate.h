#ifndef SORTTEMPLATE_H
#define SORTTEMPLATE_H

#include <functional>
#include "Book.h"
#include "User.h"

using namespace std;

class SortTemplate {
public:
    // Insertion sort for Book arrays
    static void insertionSortBooks(Book arr[], int size, function<bool(const Book&, const Book&)> compare) {
        for (int i = 1; i < size; i++) {
            Book key = arr[i];
            int j = i - 1;

            while (j >= 0 && compare(key, arr[j])) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }

    // Insertion sort for User arrays
    static void insertionSortUsers(User arr[], int size, function<bool(const User&, const User&)> compare) {
        for (int i = 1; i < size; i++) {
            User key = arr[i];
            int j = i - 1;

            while (j >= 0 && compare(key, arr[j])) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }
};

#endif
#ifndef SEARCHTEMPLATE_H
#define SEARCHTEMPLATE_H

#include <functional>
#include "Book.h"
#include "User.h"

using namespace std;

class SearchTemplate {
public:
    // Binary search for Book with string key extractor
    static int binarySearchBooks(Book arr[], int size, const string& key, function<string(const Book&)> getKey) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            string midKey = getKey(arr[mid]);

            if (midKey == key) {
                return mid;
            } else if (midKey < key) {  
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // Not found
    }

    // Binary search for User with int key extractor (e.g., id)
    static int binarySearchUsersByIntKey(User arr[], int size, int key, function<int(const User&)> getKey) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midKey = getKey(arr[mid]);

            if (midKey == key) {
                return mid;
            } else if (midKey < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // Not found
    }

    // Binary search for User with string key extractor (e.g., name)
    static int binarySearchUsersByStringKey(User arr[], int size, const string& key, function<string(const User&)> getKey) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            string midKey = getKey(arr[mid]);

            if (midKey == key) {
                return mid;
            } else if (midKey < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // Not found
    }
};

#endif
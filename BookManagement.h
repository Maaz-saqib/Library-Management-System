#ifndef BOOKMANAGEMENT_H
#define BOOKMANAGEMENT_H

#include "Book.h"
#include "DoublyLinkedList.h"
#include "SearchTemplate.h"
#include "SortTemplate.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class BookManagement {
private:
    DoublyLinkedListBook books;
    string filename;

    void loadFromFile() {
        ifstream file(filename);
        if (!file) return;

        string title, author, isbn, availableStr;
        while (getline(file, title) && 
               getline(file, author) && 
               getline(file, isbn) && 
               getline(file, availableStr)) {
            Book book(title, author, isbn);
            book.setAvailable(availableStr == "1");
            books.add(book);
        }
        file.close();
    }

public:
    BookManagement(const string& file = "books.txt") : filename(file) {
        loadFromFile();
    }

    ~BookManagement() {
        saveToFile();
    }

    void saveToFile() {
        ofstream file(filename);
        NodeBook* current = books.getHead();
        while (current) {
            file << current->data.getTitle() << "\n"
                 << current->data.getAuthor() << "\n"
                 << current->data.getISBN() << "\n"
                 << (current->data.isAvailable() ? "1" : "0") << "\n";
            current = current->next;
        }
        file.close();
    }

    void addBook(const string& title, const string& author, const string& isbn) {
        Book book(title, author, isbn);
        books.add(book);
        saveToFile();
        cout << "Book added successfully!\n";
    }

    void displayAllBooks() const {
        if (books.getSize() == 0) {
            cout << "No books available.\n";
            return;
        }
        books.display();
    }

    Book* searchByTitle(const string& title) {
        int size = books.getSize();
        if (size == 0) return nullptr;

        Book* bookArray = books.toArray();
        
        // Sort by title for binary search
        SortTemplate::insertionSortBooks(bookArray, size, 
            [](const Book& a, const Book& b) { return a.getTitle() < b.getTitle(); });

        int index = SearchTemplate::binarySearchBooks(
            bookArray, size, title, 
            [](const Book& b) { return b.getTitle(); });

        Book* result = (index != -1) ? &bookArray[index] : nullptr;
        delete[] bookArray;
        return result;
    }

    Book* searchByAuthor(const string& author) {
        int size = books.getSize();
        if (size == 0) return nullptr;

        Book* bookArray = books.toArray();
        
        SortTemplate::insertionSortBooks(bookArray, size,
            [](const Book& a, const Book& b) { return a.getAuthor() < b.getAuthor(); });

        int index = SearchTemplate::binarySearchBooks(
            bookArray, size, author,
            [](const Book& b) { return b.getAuthor(); });

        Book* result = (index != -1) ? &bookArray[index] : nullptr;
        delete[] bookArray;
        return result;
    }

    Book* searchByISBN(const string& isbn) {
        int size = books.getSize();
        if (size == 0) return nullptr;

        Book* bookArray = books.toArray();
        
        SortTemplate::insertionSortBooks(bookArray, size,
            [](const Book& a, const Book& b) { return a.getISBN() < b.getISBN(); });

        int index = SearchTemplate::binarySearchBooks(
            bookArray, size, isbn,
            [](const Book& b) { return b.getISBN(); });

        Book* result = (index != -1) ? &bookArray[index] : nullptr;
        delete[] bookArray;
        return result;
    }

    bool borrowBookByISBN(const string& isbn) {
        NodeBook* current = books.getHead();
        while (current) {
            if (current->data.getISBN() == isbn) {
                if (current->data.isAvailable()) {
                    current->data.setAvailable(false);
                    saveToFile();
                    return true;
                }
                return false; // Book not available
            }
            current = current->next;
        }
        return false; // Book not found
    }

    bool returnBookByISBN(const string& isbn) {
        NodeBook* current = books.getHead();
        while (current) {
            if (current->data.getISBN() == isbn) {
                if (!current->data.isAvailable()) {
                    current->data.setAvailable(true);
                    saveToFile();
                    return true;
                }
                return false; // Book already available
            }
            current = current->next;
        }
        return false; // Book not found
    }

    
    void sortByTitle() {
        int size = books.getSize();
        if (size == 0) return;

        Book* bookArray = books.toArray();
        SortTemplate::insertionSortBooks(bookArray, size,
            [](const Book& a, const Book& b) { return a.getTitle() < b.getTitle(); });

        books.clear();
        for (int i = 0; i < size; i++) {
            books.add(bookArray[i]);
        }
        delete[] bookArray;
        cout << "Books sorted by title.\n";
    }

    void sortByAuthor() {
        int size = books.getSize();
        if (size == 0) return;

        Book* bookArray = books.toArray();
        SortTemplate::insertionSortBooks(bookArray, size,
            [](const Book& a, const Book& b) { return a.getAuthor() < b.getAuthor(); });

        books.clear();
        for (int i = 0; i < size; i++) {
            books.add(bookArray[i]);
        }
        delete[] bookArray;
        cout << "Books sorted by author.\n";
    }

    DoublyLinkedListBook& getBooks() { return books; }
};

#endif
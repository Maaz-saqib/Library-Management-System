#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

using namespace std;

class Book {
protected:
    string title;
    string author;
    string isbn;
    bool available;

public:
    Book() : available(true) {}
    Book(const string& t, const string& a, const string& i) 
        : title(t), author(a), isbn(i), available(true) {}

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    bool isAvailable() const { return available; }

    // Setters
    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setISBN(const string& i) { isbn = i; }
    void setAvailable(bool a) { available = a; }

    void display() const {
        cout << "Title: " << title << "\nAuthor: " << author 
             << "\nISBN: " << isbn << "\nAvailable: " << (available ? "Yes" : "No") << "\n\n";
    }

    // Comparison operators for searching and sorting
    bool operator==(const Book& other) const { return isbn == other.isbn; }
    bool operator<(const Book& other) const { return title < other.title; }
};

#endif
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "Book.h"
#include "User.h"

using namespace std;

// Node and list for Book
class NodeBook {
public:
    Book data;
    NodeBook* next;
    NodeBook* prev;

    NodeBook(const Book& value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedListBook {
private:
    NodeBook* head;
    NodeBook* tail;
    int size;

public:
    DoublyLinkedListBook() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedListBook() {
        clear();
    }

    void add(const Book& value) {
        NodeBook* newNode = new NodeBook(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    bool remove(const Book& value) {
        NodeBook* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
                if (current == head) head = current->next;
                if (current == tail) tail = current->prev;
                delete current;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() const {
        NodeBook* current = head;
        while (current) {
            current->data.display();
            current = current->next;
        }
    }

    int getSize() const { return size; }

    NodeBook* getHead() const { return head; }

    void clear() {
        NodeBook* current = head;
        while (current) {
            NodeBook* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }

    // Convert to array for searching and sorting
    Book* toArray() const {
        if (size == 0) return nullptr;
        Book* arr = new Book[size];
        NodeBook* current = head;
        for (int i = 0; i < size; i++) {
            arr[i] = current->data;
            current = current->next;
        }
        return arr;
    }
};

// Node and list for User
class NodeUser {
public:
    User data;
    NodeUser* next;
    NodeUser* prev;

    NodeUser(const User& value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedListUser {
private:
    NodeUser* head;
    NodeUser* tail;
    int size;

public:
    DoublyLinkedListUser() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedListUser() {
        clear();
    }

    void add(const User& value) {
        NodeUser* newNode = new NodeUser(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    bool remove(const User& value) {
        NodeUser* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
                if (current == head) head = current->next;
                if (current == tail) tail = current->prev;
                delete current;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() const {
        NodeUser* current = head;
        while (current) {
            current->data.display();
            current = current->next;
        }
    }

    int getSize() const { return size; }

    NodeUser* getHead() const { return head; }

    void clear() {
        NodeUser* current = head;
        while (current) {
            NodeUser* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }

    // Convert to array for searching and sorting
    User* toArray() const {
        if (size == 0) return nullptr;
        User* arr = new User[size];
        NodeUser* current = head;
        for (int i = 0; i < size; i++) {
            arr[i] = current->data;
            current = current->next;
        }
        return arr;
    }
};

#endif
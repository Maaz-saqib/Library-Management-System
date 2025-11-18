#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include "User.h"
#include "DoublyLinkedList.h"
#include "SearchTemplate.h"
#include "SortTemplate.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class UserManagement {
private:
    DoublyLinkedListUser users;
    string filename;

    void loadFromFile() {
        ifstream file(filename);
        if (!file) return;

        string idStr, name, contact;
        while (getline(file, idStr) && 
               getline(file, name) && 
               getline(file, contact)) {
            int id = stoi(idStr);
            User user(id, name, contact);
            users.add(user);
        }
        file.close();
    }

    void saveToFile() {
        ofstream file(filename);
        NodeUser* current = users.getHead();
        while (current) {
            file << current->data.getId() << "\n"
                 << current->data.getName() << "\n"
                 << current->data.getContact() << "\n";
            current = current->next;
        }
        file.close();
    }

public:
    UserManagement(const string& file = "users.txt") : filename(file) {
        loadFromFile();
    }

    ~UserManagement() {
        saveToFile();
    }

    void addUser(int id, const string& name, const string& contact) {
        User user(id, name, contact);
        users.add(user);
        saveToFile();
        cout << "User added successfully!\n";
    }

    void displayAllUsers() const {
        if (users.getSize() == 0) {
            cout << "No users available.\n";
            return;
        }
        users.display();
    }

    User* searchById(int id) {
        int size = users.getSize();
        if (size == 0) return nullptr;

        User* userArray = users.toArray();
        
        SortTemplate::insertionSortUsers(userArray, size,
            [](const User& a, const User& b) { return a.getId() < b.getId(); });

        int index = SearchTemplate::binarySearchUsersByIntKey(
            userArray, size, id,
            [](const User& u) { return u.getId(); });

        User* result = (index != -1) ? &userArray[index] : nullptr;
        delete[] userArray;
        return result;
    }

    User* searchByName(const string& name) {
        int size = users.getSize();
        if (size == 0) return nullptr;

        User* userArray = users.toArray();
        
        SortTemplate::insertionSortUsers(userArray, size,
            [](const User& a, const User& b) { return a.getName() < b.getName(); });

        int index = SearchTemplate::binarySearchUsersByStringKey(
            userArray, size, name,
            [](const User& u) { return u.getName(); });

        User* result = (index != -1) ? &userArray[index] : nullptr;
        delete[] userArray;
        return result;
    }

    DoublyLinkedListUser& getUsers() { return users; }
};

#endif
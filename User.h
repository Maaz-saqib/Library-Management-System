#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;

class User {
protected:
    int id;
    string name;
    string contact;

public:
    User() : id(0) {}
    User(int i, const string& n, const string& c) : id(i), name(n), contact(c) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getContact() const { return contact; }

    // Setters
    void setId(int i) { id = i; }
    void setName(const string& n) { name = n; }
    void setContact(const string& c) { contact = c; }

    void display() const {
        cout << "ID: " << id << "\nName: " << name << "\nContact: " << contact << "\n\n";
    }

    // Comparison operators
    bool operator==(const User& other) const { return id == other.id; }
    bool operator<(const User& other) const { return name < other.name; }
};

#endif
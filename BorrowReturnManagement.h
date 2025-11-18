#ifndef BORROWRETURNMANAGEMENT_H
#define BORROWRETURNMANAGEMENT_H

#include "Book.h"
#include "User.h"
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "BookManagement.h"
#include "UserManagement.h"

using namespace std;

class BorrowReturnManagement : public Book, public User {
private:
    string transactionFile;

    string getCurrentTimestamp() {
        time_t now = time(nullptr);
        tm* localTime = localtime(&now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
        return string(buffer);
    }

    void logTransaction(const string& type, int userId, const string& isbn) {
        ofstream file(transactionFile, ios::app);
        if (file) {
            file << type << " | User ID: " << userId << " | ISBN: " << isbn 
                 << " | Time: " << getCurrentTimestamp() << "\n";
            file.close();
        }
    }

public:
    BorrowReturnManagement(const string& file = "transactions.txt") {
        transactionFile = file;
    }
    
    bool borrowBook(BookManagement& bm, UserManagement& um, int userId, const string& isbn) {
        User* user = um.searchById(userId);
        Book* book = bm.searchByISBN(isbn);

        if (!user) {
            cout << "User not found!\n";
            return false;
        }

        if (!book) {
            cout << "Book not found!\n";
            return false;
        }

        // Use the new method that updates the actual linked list
        if (bm.borrowBookByISBN(isbn)) {
            logTransaction("BORROW", userId, isbn);
            cout << "Book borrowed successfully!\n";
            return true;
        } else {
            cout << "Book is not available for borrowing!\n";
            return false;
        }
    }

    bool returnBook(BookManagement& bm, UserManagement& um, int userId, const string& isbn) {
        User* user = um.searchById(userId);
        Book* book = bm.searchByISBN(isbn);

        if (!user) {
            cout << "User not found!\n";
            return false;
        }

        if (!book) {
            cout << "Book not found!\n";
            return false;
        }

        // Use the new method that updates the actual linked list
        if (bm.returnBookByISBN(isbn)) {
            logTransaction("RETURN", userId, isbn);
            cout << "Book returned successfully!\n";
            return true;
        } else {
            cout << "Book is already available!\n";
            return false;
        }
    }

    void displayTransactionHistory() {
        ifstream file(transactionFile);
        if (!file) {
            cout << "No transaction history available.\n";
            return;
        }

        string line;
        cout << "\n=== Transaction History ===\n";
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    }
};

#endif
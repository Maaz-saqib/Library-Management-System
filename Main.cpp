#include <iostream>
#include <string>
#include "BookManagement.h"
#include "UserManagement.h"
#include "BorrowReturnManagement.h"

using namespace std;

void displayMainMenu() {
    cout << "\n=== Library Management System ===\n";
    cout << "1. Book Management\n";
    cout << "2. User Management\n";
    cout << "3. Borrow/Return Books\n";
    cout << "4. Search\n";
    cout << "5. Sort Books\n";
    cout << "6. Transaction History\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}

void displayBookMenu() {
    cout << "\n=== Book Management ===\n";
    cout << "1. Add Book\n";
    cout << "2. Display All Books\n";
    cout << "3. Back to Main Menu\n";
    cout << "Choose an option: ";
}

void displayUserMenu() {
    cout << "\n=== User Management ===\n";
    cout << "1. Add User\n";
    cout << "2. Display All Users\n";
    cout << "3. Back to Main Menu\n";
    cout << "Choose an option: ";
}

void displayBorrowReturnMenu() {
    cout << "\n=== Borrow/Return Management ===\n";
    cout << "1. Borrow Book\n";
    cout << "2. Return Book\n";
    cout << "3. Back to Main Menu\n";
    cout << "Choose an option: ";
}

void displaySearchMenu() {
    cout << "\n=== Search ===\n";
    cout << "1. Search Book by Title\n";
    cout << "2. Search Book by Author\n";
    cout << "3. Search Book by ISBN\n";
    cout << "4. Search User by ID\n";
    cout << "5. Search User by Name\n";
    cout << "6. Back to Main Menu\n";
    cout << "Choose an option: ";
}

void displaySortMenu() {
    cout << "\n=== Sort Books ===\n";
    cout << "1. Sort by Title\n";
    cout << "2. Sort by Author\n";
    cout << "3. Back to Main Menu\n";
    cout << "Choose an option: ";
}

int main() {
    BookManagement bm;
    UserManagement um;
    BorrowReturnManagement brm;

    int choice;
    bool running = true;

    while (running) {
        displayMainMenu();
        cin >> choice;
        cin.ignore(); // Clear newline

        switch (choice) {
            case 1: { // Book Management
                int bookChoice;
                do {
                    displayBookMenu();
                    cin >> bookChoice;
                    cin.ignore();

                    switch (bookChoice) {
                        case 1: {
                            string title, author, isbn;
                            cout << "Enter title: ";
                            getline(cin, title);
                            cout << "Enter author: ";
                            getline(cin, author);
                            cout << "Enter ISBN: ";
                            getline(cin, isbn);
                            bm.addBook(title, author, isbn);
                            break;
                        }
                        case 2:
                            bm.displayAllBooks();
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Invalid option!\n";
                    }
                } while (bookChoice != 3);
                break;
            }

            case 2: { // User Management
                int userChoice;
                do {
                    displayUserMenu();
                    cin >> userChoice;
                    cin.ignore();

                    switch (userChoice) {
                        case 1: {
                            int id;
                            string name, contact;
                            cout << "Enter user ID: ";
                            cin >> id;
                            cin.ignore();
                            cout << "Enter name: ";
                            getline(cin, name);
                            cout << "Enter contact: ";
                            getline(cin, contact);
                            um.addUser(id, name, contact);
                            break;
                        }
                        case 2:
                            um.displayAllUsers();
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Invalid option!\n";
                    }
                } while (userChoice != 3);
                break;
            }

            case 3: { // Borrow/Return
                int brChoice;
                do {
                    displayBorrowReturnMenu();
                    cin >> brChoice;
                    cin.ignore();

                    switch (brChoice) {
                        case 1: {
                            int userId;
                            string isbn;
                            cout << "Enter user ID: ";
                            cin >> userId;
                            cin.ignore();
                            cout << "Enter book ISBN: ";
                            getline(cin, isbn);
                            brm.borrowBook(bm, um, userId, isbn);
                            break;
                        }
                        case 2: {
                            int userId;
                            string isbn;
                            cout << "Enter user ID: ";
                            cin >> userId;
                            cin.ignore();
                            cout << "Enter book ISBN: ";
                            getline(cin, isbn);
                            brm.returnBook(bm, um, userId, isbn);
                            break;
                        }
                        case 3:
                            break;
                        default:
                            cout << "Invalid option!\n";
                    }
                } while (brChoice != 3);
                break;
            }

            case 4: { // Search
                int searchChoice;
                do {
                    displaySearchMenu();
                    cin >> searchChoice;
                    cin.ignore();

                    switch (searchChoice) {
                        case 1: {
                            string title;
                            cout << "Enter title to search: ";
                            getline(cin, title);
                            Book* book = bm.searchByTitle(title);
                            if (book) {
                                cout << "Book found:\n";
                                book->display();
                            } else {
                                cout << "Book not found!\n";
                            }
                            break;
                        }
                        case 2: {
                            string author;
                            cout << "Enter author to search: ";
                            getline(cin, author);
                            Book* book = bm.searchByAuthor(author);
                            if (book) {
                                cout << "Book found:\n";
                                book->display();
                            } else {
                                cout << "Book not found!\n";
                            }
                            break;
                        }
                        case 3: {
                            string isbn;
                            cout << "Enter ISBN to search: ";
                            getline(cin, isbn);
                            Book* book = bm.searchByISBN(isbn);
                            if (book) {
                                cout << "Book found:\n";
                                book->display();
                            } else {
                                cout << "Book not found!\n";
                            }
                            break;
                        }
                        case 4: {
                            int id;
                            cout << "Enter user ID to search: ";
                            cin >> id;
                            cin.ignore();
                            User* user = um.searchById(id);
                            if (user) {
                                cout << "User found:\n";
                                user->display();
                            } else {
                                cout << "User not found!\n";
                            }
                            break;
                        }
                        case 5: {
                            string name;
                            cout << "Enter user name to search: ";
                            getline(cin, name);
                            User* user = um.searchByName(name);
                            if (user) {
                                cout << "User found:\n";
                                user->display();
                            } else {
                                cout << "User not found!\n";
                            }
                            break;
                        }
                        case 6:
                            break;
                        default:
                            cout << "Invalid option!\n";
                    }
                } while (searchChoice != 6);
                break;
            }

            case 5: { // Sort Books
                int sortChoice;
                do {
                    displaySortMenu();
                    cin >> sortChoice;
                    cin.ignore();

                    switch (sortChoice) {
                        case 1:
                            bm.sortByTitle();
                            bm.displayAllBooks();
                            break;
                        case 2:
                            bm.sortByAuthor();
                            bm.displayAllBooks();
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Invalid option!\n";
                    }
                } while (sortChoice != 3);
                break;
            }

            case 6: // Transaction History
                brm.displayTransactionHistory();
                break;

            case 7: // Exit
                running = false;
                cout << "Thank you for using Library Management System!\n";
                break;

            default:
                cout << "Invalid option! Please try again.\n";
        }
    }

    return 0;
}
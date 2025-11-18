# Library Management System

## Overview
The **Library Management System** is a console-based C++ application designed to manage books, users, and borrowing/returning of books efficiently. It uses **Doubly Linked Lists** for dynamic data storage and supports sorting and searching functionalities through **template classes**.

This project demonstrates **OOP, data structures, file handling**, and **template programming** in C++.

---

## Class and Module Structure

Main Program
│
├── BookManagement ────── DoublyLinkedList<Book>
│ ├── uses: SearchTemplate<Book>
│ └── uses: SortTemplate<Book>
│
├── UserManagement ────── DoublyLinkedList<User>
│ ├── uses: SearchTemplate<User>
│ └── uses: SortTemplate<User>
│
└── BorrowReturnManagement
├── inherits: Book
├── inherits: User
├── uses: BookManagement
└── uses: UserManagement


**Diagram:**  
See `Swark-output` folder for the class relationship diagram.

---

## File Structure

Library Management System/
│
├── Swark-output/ # Class Relationship diagram
├── Book.h # Book class definition
├── User.h # User class definition
├── DoublyLinkedList.h # Generic doubly linked list
├── SearchTemplate.h # Template for searching
├── SortTemplate.h # Template for sorting
├── BookManagement.h # Book management
├── UserManagement.h # User management
├── BorrowReturnManagement.h # Borrow/Return management
├── Main.cpp # Main program
├── books.txt # Stores book records
├── users.txt # Stores user records
└── transactions.txt # Auto-generated transaction file

## Features

- Add, delete, and manage books and users  
- Borrow and return books  
- Search and sort books and users using **templates**  
- Persistent storage via text files (`books.txt`, `users.txt`, `transactions.txt`)  
- Dynamic memory management with **Doubly Linked Lists**  
- Modular design for maintainability

---

## Sample Output

Welcome to Library Management System
Manage Books
Manage Users
Borrow/Return Book
Exit
Enter your choice: 1
Book Menu:
Add Book
Delete Book
Display Books
Enter your choice: 3

Book List:
ID: 101 | Title: C++ Basics | Author: Bjarne Stroustrup
ID: 102 | Title: Data Structures | Author: Mark Allen Weiss
...
> You can expand this section with **screenshots** of running the program in console if you like.

---

## How to Run

1. Clone the repository:

```bash
git clone https://github.com/Maaz_Saqib/Library-Management-System.git
Open the project in VS Code or any C++ IDE.

Compile Main.cpp along with all .h files.

Run the executable.

Ensure books.txt and users.txt are in the same directory as the executable.
transactions.txt will be automatically created when borrowing/returning books.

**Author**
Maaz Saqib
GitHub: Maaz-saqib

Email: maazsaqib601@gmail.com

**Notes**
Swark-output folder contains class diagrams.
This project is a good reference for OOP, templates, and file handling in C++.

#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string name;
    string author;
    bool isIssued;
};

int main() {
    Book library[100];
    int bookCount = 0;
    int choice;

    do {
        cout << "\n==== Library Management System ====\n";
        cout << "1. Add Book\n";
        cout << "2. Show All Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            // Add Book
            cout << "Enter Book ID: ";
            cin >> library[bookCount].id;
            cin.ignore();
            cout << "Enter Book Name: ";
            getline(cin, library[bookCount].name);
            cout << "Enter Author Name: ";
            getline(cin, library[bookCount].author);
            library[bookCount].isIssued = false;
            bookCount++;
            cout << "Book Added Successfully!\n";
        }
        else if(choice == 2) {
            // Show All Books
            cout << "\nAll Books in Library:\n";
            for(int i=0; i<bookCount; i++) {
                cout << "ID: " << library[i].id
                     << ", Name: " << library[i].name
                     << ", Author: " << library[i].author
                     << ", Status: " << (library[i].isIssued ? "Issued" : "Available")
                     << endl;
            }
        }
        else if(choice == 3) {
            // Issue Book
            int id;
            cout << "Enter Book ID to issue: ";
            cin >> id;
            bool found = false;
            for(int i=0; i<bookCount; i++) {
                if(library[i].id == id) {
                    found = true;
                    if(library[i].isIssued) {
                        cout << "Sorry, this book is already issued.\n";
                    } else {
                        library[i].isIssued = true;
                        cout << "Book issued successfully!\n";
                    }
                }
            }
            if(!found) cout << "Book not found!\n";
        }
        else if(choice == 4) {
            // Return Book
            int id;
            cout << "Enter Book ID to return: ";
            cin >> id;
            bool found = false;
            for(int i=0; i<bookCount; i++) {
                if(library[i].id == id) {
                    found = true;
                    if(library[i].isIssued) {
                        library[i].isIssued = false;
                        cout << "Book returned successfully!\n";
                    } else {
                        cout << "This book was not issued.\n";
                    }
                }
            }
            if(!found) cout << "Book not found!\n";
        }
        else if(choice == 5) {
            cout << "Exiting... Thank you!\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 5);

    return 0;
}

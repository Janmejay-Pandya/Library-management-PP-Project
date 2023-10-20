#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
protected:
    string title;
    int number_of_copies;

public:
    Book(string t, int noc) : title(t), number_of_copies(noc) {}

    virtual void display() {
        cout << "\nTitle: " << title << endl;
        cout << "Number of Copies: " << number_of_copies << endl;
    }

    bool isAvailable() {
        return number_of_copies > 0;
    }

    void checkoutBook() {
        if (isAvailable()) {
            cout << "Book '" << title << "' is checked out." << endl;
            number_of_copies--;
        } else {
            cout << "Book '" << title << "' is not available for checkout." << endl;
        }
    }

    string getTitle() {
        return title;
    }
};

class Teacher : public Book {
    string name;
    int Emp_id;

public:
    Teacher(string t, int noc, string n, int id)
        : Book(t, noc), name(n), Emp_id(id) {}

    void display() {
        cout << "\nName of teacher: " << name << endl;
        cout << "Employer ID: " << Emp_id << endl;
        Book::display();
    }
};

int main() {
    vector<Book*> books;
    vector<Teacher*> teachers;

    while (true) {
        int choice;
        cout << "\n1. Add a new book" << endl;
        cout << "2. Add a new teacher" << endl;
        cout << "3. Display all books" << endl;
        cout << "4. Display all teachers" << endl;
        cout << "5. Checkout a book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title;
                int noc;
                cout << "\nEnter Title: ";
                cin >> title;
                cout << "Enter Number of Copies: ";
                cin >> noc;
                books.push_back(new Book(title, noc));
                break;
            }

            case 2: {
                string title, name;
                int id, noc;
                cout << "\nEnter Teacher's Name: ";
                cin >> name;
                cout << "Enter Teacher's Employee ID: ";
                cin >> id;
                cout << "Enter Title: ";
                cin >> title;
                cout << "Enter Number of Copies: ";
                cin >> noc;
                teachers.push_back(new Teacher(title, noc, name, id));
                break;
            }

            case 3:
                cout << "Books:\n";
                for (Book* book : books) {
                    book->display();
                }
                break;

            case 4:
                cout << "Teachers:\n";
                for (Teacher* teacher : teachers) {
                    teacher->display();
                }
                break;
            case 5: {
                cout << "Enter the title of the book to check out: ";
                string checkoutTitle;
                cin >> checkoutTitle;

                for (Book* book : books) {
                    if (book->getTitle() == checkoutTitle) {
                        book->checkoutBook();
                        break;
                    }
                }
                break;
            }
            case 6:
                for (Book* book : books) {
                    delete book;
                }
                for (Teacher* teacher : teachers) {
                    delete teacher;
                }
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}
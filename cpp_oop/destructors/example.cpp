#include <iostream>

using namespace std;

class Book {
private:
    string title;
    string author;
    int* rates;
    int ratesCounter;
public:
    Book(string title, string author) {
        this->title = title;
        this->author = author;
        ratesCounter = 2;
        rates = new int[ratesCounter];
        rates[0] = 5;
        rates[1] = 4;
    }

    static Book createBook() {
        string title, author;
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);

        return Book(title, author);
    }

    friend ostream& operator<<(ostream& os, Book& book) {
        os << "Book: " << book.title << ", Author: " << book.author << endl;
        return os;
    }

    ~Book() {
        delete [] rates;
        rates = nullptr;
    }
};

int main() {
    Book b1 = Book("Los Muchachos", "Author 1");
    cout << b1;

    Book b2 = Book::createBook();
    cout << b2;

    return 0;
}
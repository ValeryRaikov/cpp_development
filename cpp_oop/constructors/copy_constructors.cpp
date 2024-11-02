#include <iostream>

using namespace std;

class Book {
private:
    string title;
    string author;
    float* rates;
    int ratesCounter;
public:
    Book(string title, string author) {
        this->title = title;
        this->author = author;
        ratesCounter = 2;
        rates = new float[ratesCounter];
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

    Book(const Book& original) {
        this->title = original.title;
        this->author = original.author;
        this->ratesCounter = original.ratesCounter;

        rates = new float[ratesCounter];
        for (int i = 0; i <ratesCounter; i++) {
            rates[i] = original.rates[i];
        }
    }

    friend void printBook(Book);
};

void printBook(Book book) {
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;

    float sum;
    for (int i = 0; i < book.ratesCounter; i++) {
        sum += book.rates[i];
    }

    cout << "Average rate: " << sum / book.ratesCounter << endl;
}

int main() {
    Book b1 = Book("Los Muchachos", "Author 1");
    cout << b1;

    // Book b2 = Book::createBook();
    // cout << b2;

    Book b3(b1); // Copy constructor invokation
    // Book b3 = b1;
    cout << b3;

    printBook(b1);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(): day(1), month(1), year(2000) {}
    Date(int day, int month, int year): day(day), month(month), year(year) {}

    int getDay() const { return day; }
    void setDay(int d) { day = d; }
    int getMonth() const { return month; }
    void setMonth(int m) { month = m; }
    int getYear() const { return year; }
    void setYear(int y) { year = y; }

    static Date getCurrentDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return Date(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
    }

    bool isValidDate() {
        if (year < 2000 || month < 1 || month > 12 || day < 1 || day > 31) return false;
        return true;
    }

    friend ostream &operator<<(ostream &os, const Date &date) {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }
};

class Book {
private:
    string title;
    string author;
    int isbn;
    Date publicationDate;
    bool isAvailable;
public:
    Book(string title, string author, int isbn, Date publicationDate, bool isAvailable = true):
        title(title), author(author), isbn(isbn), publicationDate(publicationDate), isAvailable(isAvailable) {}

    string getTitle() const { return title; }
    void setTitle(string t) { title = t; }
    string getAuthor() const { return author; }
    void setAuthor(string a) { author = a; }
    int getIsbn() const { return isbn; }
    void setIsbn(int i) { isbn = i; }
    Date getPublicationDate() const { return publicationDate; }
    void setPublicationDate(Date d) { publicationDate = d; }
    bool getIsAvailable() const { return isAvailable; }
    void setIsAvailable(bool b) { isAvailable = b; }

    void checkOut() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book checked out successfully!\n";
        } else {
            cout << "Book is already checked out!\n";
        }
    }

    void returnBook() {
        isAvailable = true;
        cout << "Book returned successfully!\n";
    }

    void displayDetails() const {
        cout << "Book:\n";
        cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << isbn
             << "\nPublication Date: " << publicationDate << "\nAvailable: " 
             << (isAvailable ? "Yes" : "No") << endl; 
    }
};

class Patron {
private:
    string name;
    int memberID;
    string address;
    string contactInfo;
    vector<Book*> borrowedBooks;
public:
    Patron(string name, int memberID, string address, string contactInfo): 
        name(name), memberID(memberID), address(address), contactInfo(contactInfo) {}

    string getName() const { return name; }
    void setName(string n) { name = n; } 
    int getMemberID() const { return memberID; }
    void setMemberID(int m) { memberID = m; }
    string getAddress() const { return address; }
    void setAddress(string a) { address = a; }
    string getContactInfo() const { return contactInfo; }
    void setContactInfo(string c) { contactInfo = c; }

    bool borrowBook(Book &book) {
        if (!book.getIsAvailable()) {
            cout << "Book \"" << book.getTitle() << "\" is currently not available.\n";
            return false;
        }

        book.setIsAvailable(false); 
        borrowedBooks.push_back(&book); 
        cout << name << " has successfully borrowed \"" << book.getTitle() << "\".\n";

        return true;
    }

    bool returnBook(Book &book) {
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), &book);

        if (it != borrowedBooks.end()) {
            book.setIsAvailable(true); 
            borrowedBooks.erase(it);
            cout << name << " has returned \"" << book.getTitle() << "\".\n";
            return true;
        } else {
            cout << "Book \"" << book.getTitle() << "\" not found in " << name << "'s borrowed list.\n";
            return false;
        }
    }

    void viewBorrowedBooks() const {
        if (borrowedBooks.empty()) {
            cout << "No books currently borrowed.\n";
            return;
        }

        cout << name << "'s Borrowed Books:\n";
        for (const auto &book : borrowedBooks) {
            book->displayDetails();
        }
    }
};

class Transaction {
private:
    int transactionID;
    Book &book;
    Patron &patron;
    Date dateBorrowed;
    bool isReturned;
    Date dateReturned;
public:
    Transaction(int transactionID, Book &book, Patron &patron, Date dateBorrowed): 
        transactionID(transactionID), book(book), patron(patron), dateBorrowed(dateBorrowed), isReturned(false) {}

    void setReturnDate(Date date) {
        dateReturned = date;
        isReturned = true;
    }

    void displayTransactionDetails() const {
        cout << "Transaction ID: " << transactionID << "\n"
             << "Book Title: " << book.getTitle() << "\n"
             << "Patron: " << patron.getName() << "\n"
             << "Date Borrowed: " << dateBorrowed << "\n"
             << "Date Returned: " << (isReturned ? to_string(dateReturned.getDay()) + "/" + to_string(dateReturned.getMonth()) + "/" + to_string(dateReturned.getYear()) : "Not returned yet") << "\n";
    }
};

int main() {
    Book book1("C++ Programming", "CodeCademy.org", 12345, Date(15, 5, 2000));
    Patron patron1("Ivan Petrov", 101, "Sofia, Mladost 4", "vaniopetrov.com");

    int transactionID = 1;

    if (patron1.borrowBook(book1)) {
        Date borrowDate = Date::getCurrentDate();
        Transaction transaction(transactionID++, book1, patron1, borrowDate);

        transaction.displayTransactionDetails();

        if (patron1.returnBook(book1)) {
            transaction.setReturnDate(Date::getCurrentDate());
            cout << "\nAfter returning the book:\n";
            transaction.displayTransactionDetails();
        }
    }

    return 0;
}

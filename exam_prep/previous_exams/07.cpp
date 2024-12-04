/*
да се проектира клас Читател с член-данни име и номер и клас Библиотека, наследник на класа Читател, с 
член-данни име на книга и статус <заета/свободна>, член функция за заемане на книга и член функция за проверка 
дали дадена книга е заета. Инициализирането на член данните и на двата класа става чрез конструктори с параметри.
Решението да включва и главна функция, в която да се дефинира масив от обекти и да се изведат книгите със статус <свободна>.
*/

#include <iostream>
#include <vector>

using namespace std;

class Reader {
protected:
	string name;
	int number;
public:
	Reader(string name, int number) {
		this->name = name;
		this->number = number;
	}

	string getName() { return name; }
	int getNumber() { return number; }
};

class Library : public Reader {
protected:
	string title;
	string status;
public:
	Library(string name, int number, string title, string status) : Reader(name, number) {
		this->title = title;
		this->status = status;
	}

	string getTitle() { return title; }
	string getStatus() { return status; }

	bool isAvailable() {
		return status == "free";
	}

	void takeBook() {
		if (status == "free") {
			status = "taken";
			cout << "Book is taken by reader " << getName() << endl;
			return;
		}

		cout << "Book is currently taken. You have to wait!\n";
	}

	void display() {
		cout << "Book: " << getTitle() << ", status: " << getStatus() << endl;
		cout << "Reader: " << getName() << ", number: " << getNumber() << endl;
	}
};

int main() {
	vector<Library> libraryBooks = {
		Library("Ivan Petrov", 101, "Voina i mir", "free"),
		Library("Maria Ivanova", 102, "Prestyplenie i nakazanie", "taken"),
		Library("Georgi Georgiev", 103, "Pod igoto", "free"),
		Library("Anna Dimitrova", 104, "Harry Potter", "taken"),
		Library("Petyr Stoqnov", 105, "Don Juan", "free"),
	};

	cout << "Books with status 'free':\n";
	for (auto& book : libraryBooks) {
		if (book.isAvailable()) {
			book.display();
		}
	}
	cout << endl;

	libraryBooks[0].takeBook();
	libraryBooks[1].takeBook();
	cout << endl;

	cout << "Books with status 'free' after some books are borrowed:\n";
	for (auto& book : libraryBooks) {
		if (book.isAvailable()) {
			book.display();
		}
	}

	return 0;
}
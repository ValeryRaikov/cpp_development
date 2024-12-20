#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

string usernameRegex = "^(?=.{8,20}$)(?!.*[_.]{2})[a-zA-Z0-9._]+(?<![_.])$";
string emailRegex = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}$";
string passwordRegex = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%^&*()\\-+])[A-Za-z\\d!@#$%^&*()\\-+]{8,}$";

bool validateInput(string data, string regexStr) {
	return regex_match(data, regex(regexStr));
}

class User {
private:
	string username;
	string email;
	string password;
public:
	User(string username, string email, string password) {
		setUsername(username);
		setEmail(email);
		setPassword(password);
	}

	string getUsername() const { return username; }
	string getEmail() const { return email; }
	string getPassword() const { return password; }

	void setUsername(string value) {
		if (!validateInput(value, usernameRegex)) {
			cout << "Invalid input. Try again...\n";
			return;
		}

		username = value;
	}
	void setEmail(string value) {
		if (!validateInput(value, emailRegex)) {
			cout << "Invalid input. Try again...\n";
			return;
		}

		email = value;
	}
	void setPassword(string value) {
		if (!validateInput(value, passwordRegex)) {
			cout << "Invalid input. Try again...\n";
			return;
		}

		password = value;
	}

	bool operator==(const string& input) const {
		return getUsername() == input || getEmail() == input;
	}

	void displayInfo() const {
		cout << getUsername() << " - " << getEmail() << endl;
	}
};

class UserManager {
private:
	vector<User> users;
public:
	UserManager() = default;

	vector<User> getUsers() const { return users; }

	void registerUser() {
		string username, email, password;
		cout << "Enter username: ";
		cin.ignore();
		getline(cin, username);
		cout << "Enter email: ";
		getline(cin, email);
		cout << "Enter password: ";
		getline(cin, password);

		User newUser(username, email, password);
		users.push_back(newUser);

		cout << "User registered successfully.\n";
	}

	void loginUser() {
		string username, password;
		cout << "Enter username: ";
		cin.ignore();
		getline(cin, username);
		cout << "Enter password: ";
		getline(cin, password);

		for (const auto& user : getUsers()) {
			if (user.getUsername() == username && user.getPassword() == password) {
				cout << "Logged in successfully.\n";
			}
		}

		cout << "Invalid username or password...\n";
	}

	void showUsers() const {
		if (getUsers().empty()) {
			cout << "No users registered yet.\n";
			return;
		}

		cout << "Registered users list:\n";
		for (const auto& user : getUsers()) {
			user.displayInfo();
		}
	}

	void searchUser() const {
		string inputField;
		cout << "Enter username or email to search user: ";
		cin.ignore();
		getline(cin, inputField);

		for (const auto& user : getUsers()) {
			if (user.getUsername() == inputField || user.getEmail() == inputField) {
				cout << "User found.\n";
				user.displayInfo();
			}
		}
	}

	void deleteUser() {
		string inputField;
		cout << "Enter username or email to search user: ";
		cin.ignore();
		getline(cin, inputField);

		auto it = find_if(users.begin(), users.end(), [&inputField](const User& user) {
			return user.getUsername() == inputField || user.getEmail() == inputField;
		});

		if (it != users.end()) {
			cout << "User found: " << it->getUsername() << " (" << it->getEmail() << ")" << endl;
			users.erase(it);
			cout << "User successfully removed.\n";
		}
		else {
			cout << "No user found with the given username or email.\n";
		}
	}
};

int main() {
	UserManager userManager;

	while (true) {
		cout << "Menu\n";
		cout << "\t1. Register user\n";
		cout << "\t2. Login\n";
		cout << "\t3. Show user list\n";
		cout << "\t4. Search user\n";
		cout << "\t5. Remove user\n";
		cout << "\t6. Exit\n";

		int choice;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			userManager.registerUser();
			break;
		case 2:
			userManager.loginUser();
			break;
		case 3:
			userManager.showUsers();
			break;
		case 4:
			userManager.searchUser();
			break;
		case 5:
			userManager.deleteUser();
			break;
		case 6:
			cout << "Goodbye!\n";
			break;
		default:
			cout << "Invalid input. Try again...\n";
			break;
		}
	}

	return 0;
}
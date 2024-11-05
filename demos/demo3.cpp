#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Todo {
private:
    string todoName;
    string todoPriority;
    int duration;
public:
    Todo() {}
    Todo(string todoName, string todoPriority, int duration)
        : todoName(todoName), todoPriority(todoPriority), duration(duration) {}

    string getTodoName() const { return todoName; }
    void setTodoName(string todoName) { this->todoName = todoName; }
    string getTodoPriority() const { return todoPriority; }
    void setTodoPriority(string todoPriority) { this->todoPriority = todoPriority; }
    int getDuration() const { return duration; }
    void setDuration(int duration) { this->duration = duration; }

    void display() const {
        cout << todoName << ", Priority: " << todoPriority << ", " << duration << "h\n";
    }
};

class TodoManager {
private:
    vector<Todo> todos;
public:
    Todo createTodo() {
        string name, priority;
        int duration;

        cout << "Enter todo name: ";
        getline(cin, name);
        cout << "Enter todo priority: ";
        getline(cin, priority);
        cout << "Enter todo duration: ";
        cin >> duration;

        Todo todo(name, priority, duration);
        todos.push_back(todo);

        return todo;
    }

    bool removeTodo(const string& name) {
        auto it = find_if(todos.begin(), todos.end(), [&](const Todo& todo) {
            return todo.getTodoName() == name;
        });

        if (it != todos.end()) {
            todos.erase(it);
            cout << "Todo \"" << name << "\" removed successfully.\n";
            return true;
        } else {
            cout << "Todo with name \"" << name << "\" not found.\n";
            return false;
        }
    }

    void displayTodos() const {
        if (todos.empty()) {
            cout << "No todos available.\n";
            return;
        }

        cout << "Todos: " << todos.size() << endl;
        for (const Todo& todo : todos) {
            todo.display();
        }
    }
};

int main() {
    TodoManager manager;

    manager.createTodo();
    manager.createTodo();

    manager.displayTodos();

    manager.removeTodo("study");

    manager.displayTodos();

    return 0;
}

#include <iostream>

int main() {
    using namespace std;

    string questions[] {
        "What year was C++ invented?",
        "Who invented C++?",
        "What is the predecessor of C++?",
        "For what is C++ used nowadays?"
    };

    string options[][4] = {
        {"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
        {"A. Guido Van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zuckerberg"},
        {"A. C" ,"B. C+", "C. C--", "D. C#"},
        {"A. Game development", "B. Web development", "C. Web scraping", "D. Machine learning"}
    };

    char answer_key[] = {'C', 'B', 'A', 'A'};

    int size = sizeof(questions) / sizeof(questions[0]);
    char guess;
    int score = 0;

    for (int i = 0; i < size; ++i) {
        cout << "*****************************" << endl;
        cout << questions[i] << endl;
        cout << "*****************************" << endl;
        for (int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); ++j) {
            cout << options[i][j] << endl;
        }

        cin >> guess;
        guess = toupper(guess);

        if (guess == answer_key[i]) {
            cout << "CORRECT!" << endl;
            score++;
        } else {
            cout << "WRONG!" << endl;
            cout << "Correct answer is: " << answer_key[i] << endl;
        }
    }

    cout << "*****************************" << endl;
    cout << "Score is: " << score << " out of " << size << endl;
    cout << "*****************************" << endl;

    double percentage = (score / double(size)) * 100;
    cout << "Result is: " << percentage << "%" << endl;

    return 0;
}
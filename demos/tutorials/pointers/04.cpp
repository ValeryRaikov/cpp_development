#include <iostream>

using namespace std;

int getMinNumber(int numbers[], int size) {
    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    return min;
}

int getMaxNumber(int numbers[], int size) {
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    return max;
}

void getMinAndMax(int numbers[], int size, int* min, int* max) {
    for (int i = 1; i < size; i++) {
        if (numbers[i] > *max) {
            *max = numbers[i];
        }
        if (numbers[i] < *min) {
            *min = numbers[i];
        }
    }
}

int main() {
    int numbers[5] = {5, 3, -2, 9, 15};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Min number is: " << getMinNumber(numbers, size) << endl;
    cout << "Max number is: " << getMaxNumber(numbers, size) << endl;

    int min = numbers[0];
    int max = numbers[0];

    getMinAndMax(numbers, size, &min, &max);

    cout << "Min is: " << min << endl;
    cout << "Max is: " << max << endl;

    return 0;
}
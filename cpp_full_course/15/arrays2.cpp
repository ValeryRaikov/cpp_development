#include <iostream>

using namespace std;

int search_array(int array[], int size, int element);

int main() {

    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int index, my_number;

    cout << "Enter element to search for: ";
    cin >> my_number;

    index = search_array(numbers, size, my_number);

    if (index != -1) {
        cout << "Your number is at index: " << index << endl;
    } else {
        cout << "Number is not found!" << endl;
    }

    return 0;
}

int search_array(int array[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element)
            return i;
    }

    return -1;
}
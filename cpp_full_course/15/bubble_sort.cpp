#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& array);

int main() {
    int size;
    cout << "Enter the length of your array: ";
    cin >> size;

    vector<int> numbers(size);
    for (int i = 0; i < size; i++) {
        cout << "Enter number #" << i + 1 << '\n';
        cin >> numbers[i];
    }

    cout << "This is the array you created:\n";

    for  (int i = 0; i < size; i++) {
        cout << numbers[i] << ", ";
    }
    cout << '\n';

    bubble_sort(numbers);

    cout << "Sorted array is:\n";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << ", ";
    }
    cout << '\n';

    return 0;
}

void bubble_sort(vector<int>& array) {
    int size = array.size();
    int temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
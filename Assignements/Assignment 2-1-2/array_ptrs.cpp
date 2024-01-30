#include <iostream>

using namespace std;

void bubbleSort(int* ptrs[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*ptrs[j] > *ptrs[j + 1]) {
                
                int* temp = ptrs[j];
                ptrs[j] = ptrs[j + 1];
                ptrs[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int size = 4;
    int my_ints[size];

    cout << "Enter " << size << " integers one by one:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i + 1 << " integer: ";
        cin >> my_ints[i];
    }

    int* my_ptrs[size];
    for (int i = 0; i < size; i++) {
        my_ptrs[i] = &my_ints[i];
    }

    bubbleSort(my_ptrs, size);

    cout << "Sorted values using pointers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << *my_ptrs[i] << " ";
    }
    cout << endl;

    cout << "Original values in my_ints array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << my_ints[i] << " ";
    }
    cout << endl;

    return 0;
}
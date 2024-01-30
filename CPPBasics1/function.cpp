// Creator: Ash Zahabiuon
// Date: 01/18/2024
// Group: Team 9

#include <iostream>
using namespace std;

void swapInts(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;
    cout << "Enter the first integer: ";
    cin >> num1;

    cout << "Enter the second integer: ";
    cin >> num2;

    swapInts(&num1, &num2);

    cout << "Swapped values: num1 = " << num1 << ", num2 = " << num2 << endl;
    return 0;
}
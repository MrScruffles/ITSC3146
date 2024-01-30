#include <iostream>
using namespace std;

int main() {
    int myInt = 15;
    int* myPointer = &myInt;

    cout << "Memory address of myInt: " << hex << &myInt << endl;
    cout << "Value pointed to by myPointer: " << dec << *myPointer << endl;

    // Change the value of myInt
    myInt = 10;

    cout << "Memory address of myInt after reassignment: " << hex << &myInt << endl;
    cout << "Value pointed to by myPointer after reassignment: " << dec << *myPointer << endl;

    return 0;
}

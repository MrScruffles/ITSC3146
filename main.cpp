#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    double y_double;
    int x, p;
    string s;
    stringstream ss("4.0fourtypoint0 45fortyfive");

    ss >> y_double;  // Attempt to read a double
    ss >> s;         // Attempt to read a string
    ss >> x; 
    ss >> p;        // Attempt to read an int

    cout << "Double: " << y_double << endl;
    cout << "String: " << s << endl;
    cout << "Int: " << x << endl;
    cout << "Int: " << p << endl;

    return 0;
}

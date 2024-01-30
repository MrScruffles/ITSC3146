// Creator: Ash Zahabiuon
// Date: 01/18/2024
// Group: Team 9

#include <iostream>
#include <cmath>
using namespace std;


struct CartesianCoordinate {
    double x;
    double y;
};

double calculateDistance(const CartesianCoordinate* p1, const CartesianCoordinate* p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    CartesianCoordinate p1, p2;

    cout << "Enter x-coordinate for p1: ";
    cin >> p1.x;
    cout << "Enter y-coordinate for p1: ";
    cin >> p1.y;

    cout << "Enter x-coordinate for p2: ";
    cin >> p2.x;
    cout << "Enter y-coordinate for p2: ";
    cin >> p2.y;

    double distance = calculateDistance(&p1, &p2);

    cout << "Distance between p1 and p2: " << distance << endl;

    return 0;
}

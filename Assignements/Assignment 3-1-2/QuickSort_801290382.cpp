//
//  QuickSort_Skeleton.cpp
//
//  Created by Bahamon, Julio on 6/25/19.
//  UNC Charlotte
//  Copyright © 2019 Bahamon, Julio. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//  Declaring a new struct to store patient data
struct patient
{
    int age;
    char name[20];
    float balance;
};

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY AGE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE AGE OF THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S AGE
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE

int comparePatientsByAge(const void *a, const void *b)
{
    struct patient *patientA = (struct patient *)a;
    struct patient *patientB = (struct patient *)b;

    if (patientA->age < patientB->age)
        return -1;
    if (patientA->age > patientB->age)
        return 1;
    return 0;
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY BALANCE DUE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE BALANCE FOR THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S BALANCE
//       0 IF THE BALANCES ARE EQUAL
//       1 OTHERWISE

int comparePatientsByBalance(const void *a, const void *b)
{
    struct patient *patientA = (struct patient *)a;
    struct patient *patientB = (struct patient *)b;

    if (patientA->balance < patientB->balance)
        return -1;
    if (patientA->balance > patientB->balance)
        return 1;
    return 0;
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY NAME

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE NAME OF THE FIRST PATIENT GOES BEFORE
//         THE SECOND PATIENT'S NAME
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE

int comparePatientsByName(const void *a, const void *b) {
    struct patient *patientA = (struct patient *)a;
    struct patient *patientB = (struct patient *)b;

    int result = strncmp(patientA->name, patientB->name, 20);

    if (result < 0) return -1;
    if (result > 0) return 1;
    return 0;
}

//
//  HINT: USE THE strncmp FUNCTION
//  (SEE http://www.cplusplus.com/reference/cstring/strncmp/)

// displayPatientList Funtion
void displayPatientList(struct patient *patient_list, int total_patients)
{
    for (int i = 0; i < total_patients; i++)
    {
        cout << patient_list[i].name << " " << patient_list[i].age << " " << patient_list[i].balance << endl;
    }
}

//  The main program
int main()
{
    int total_patients = 6;

    //  Storing some test data
    struct patient patient_list[6] = {
        {25, "Juan Valdez   ", 1250},
        {15, "James Morris  ", 2100},
        {32, "Tyra Banks    ", 750},
        {62, "Mario O'Donell", 375},
        {53, "Pablo Picasso ", 615},
        {0, "", 0}};

    cout << "Enter your last name: ";
    cin >> patient_list[5].name;

    cout << "Enter your age: ";
    cin >> patient_list[5].age;

    cout << "Enter your balance due: ";
    cin >> patient_list[5].balance;

    cout << "Hello " << patient_list[5].name << ", you are " << patient_list[5].age << " years old and your balance is $" << patient_list[5].balance << endl;

    cout << "Patient List: " << endl;

    //  TODO:
    //  IMPLEMENT THE CODE TO DISPLAY THE CONTENTS
    //  OF THE ARRAY BEFORE SORTING
    displayPatientList(patient_list, total_patients);

    cout << endl;

    cout << "Sorting..." << endl;

    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT AGE
    cout << "Patient List - Sorted by Age: " << endl;
    qsort(patient_list, total_patients, sizeof(struct patient), comparePatientsByAge);

    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY AGE

    displayPatientList(patient_list, total_patients);

    cout << endl;

    cout << "Sorting..." << endl;

    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT BALANCE
    qsort(patient_list, total_patients, sizeof(struct patient), comparePatientsByBalance);
    cout << "Patient List - Sorted by Balance Due: " << endl;

    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY BALANCE
    displayPatientList(patient_list, total_patients);

    cout << endl;

    cout << "Sorting..." << endl;

    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT NAME
    qsort(patient_list, total_patients, sizeof(struct patient), comparePatientsByName);
    cout << "Patient List - Sorted by Name: " << endl;

    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY NAME
    displayPatientList(patient_list, total_patients);

    cout << endl;

    return 0;
}
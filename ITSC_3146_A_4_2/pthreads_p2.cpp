#include <pthread.h>
#include <iostream>

using namespace std;

// This is the array that contains the integer values,
// that will be used fore the functions,
// countNegative, average, and reverse. 
int arr[10];

// This function is used to count negatives within the data array. 
// The function has a return type of void and the parameter is a void pointer. 
void *countNegatives(void *arg)
{ 
   int total = 0;

   for (int index = 0; index < 10; index++)
   {
      if (arr[index] < 0)
         total++;
   }
   
   cout << "Total negative numbers: "<< total << endl << endl;
   
   pthread_exit(0);
}

// This function is used to calculate the average value of the data array. 
// The function has a return type of void and the parameter is a void pointer. 
void *average(void *arg)
{
   double total = 0.0;
   
   for (int index = 0; index < 10; index++)
   {
      total += arr[index];
   }
   
   cout << "Average: "<< total / 10.0 << endl << endl;
   
   pthread_exit(0);
}

// This function is used to print the data array in reverse. 
// The function has a return type of void and the parameter is a void pointer.
void *reverse(void *arg)
{
   cout << "The numbers in reverse: " << endl;
   
   for (int index = 9; index >=0; index--)
   {
      cout << arr[index] << endl ;
   }
   
   pthread_exit(0);
}



int main()
{   
   // TODO:
   // Add necessary variable declarations. 
   pthread_t negativeID, averageID, reverseID;

   // TODO:
   // Add code to perform any needed initialization
   // or to process user input
      cout << "Enter 10 integers: ";
   for (int i = 0; i < 10; i++)
   {
      cin >> arr[i];
   }
   
   // TODO: Modify according to assignment requirements
   // Create thread(s) that will execute the functions of countNegative, average, and reverse
   // and check for the return values for errors. 

   pthread_create(&negativeID, NULL, countNegatives, (void*) &arr);
   for (int count = 0; count < 100000; count++); // Delay

   pthread_create(&averageID, NULL, average, (void*) &arr);
   for (int count = 0; count < 100000; count++); // Delay

   pthread_create(&reverseID, NULL, reverse, (void*) &arr);
   for (int count = 0; count < 100000; count++); // Delay 

   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}

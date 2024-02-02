/*
 @file: pthreads_skeleton.cpp
 
 @author: student name1, student2@uncc.edu
 @author: student name2, student2@uncc.edu
 @author: student name3, student3@uncc.edu
 
 @description: A program that demonstrates processes.
 
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>

using namespace std;

const char* my_messages[4] = 
{
   "Italian: Ciao!", 
   "English: Hello!", 
   "Hindi: Namaste!", 
   "Spanish: Hola!" 
}; 

// This function shows the skeleton that pthread 
// functions must adhere to. 
// Copy this skeleton for any pthread function 
// you need to define. 
// In the copy, modify the name of the function 
// and the function body as needed. 
void *printMessage(void *arg)
{
   int index = *((int*)arg);
   cout << my_messages[index] << endl;
   return 0;
}

int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   pthread_t ids[4];
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
   
   int indices[4] = {0, 1, 2, 3};

   for(int i = 0; i < 4; i++) {
       rc = pthread_create(&ids[i], NULL, printMessage, (void*)&indices[i]);
       if (rc) {
           cout << "Error: Unable to create thread," << rc << endl;
           exit(-1);
       }
   }

   for(int i = 0; i < 4; i++) {
       pthread_join(ids[i], NULL);
   }

   return 0;
}
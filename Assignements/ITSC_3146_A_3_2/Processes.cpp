//
//  Processes.cpp
//  ITSC 3146
//
//  Created by Bahamon, Julio on 1/12/17.
//

/*
 @file Processes.cpp
 @author student name, student@uncc.edu
 @author student name, student@uncc.edu
 @author student name, student@uncc.edu
 @description: <ADD DESCRIPTION>
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#ifndef Processes_cpp
#define Processes_cpp

#include "Processes.h"

using namespace std;

// Part 1: Working With Process IDs
pid_t getProcessID(void)
{
   // TODO: Add your code here

   pid_t processID = getpid();
   return processID;
}

// Part 2: Working With Multiple Processes
string createNewProcess(void)
{
   pid_t id = fork();

   // DO NOT CHANGE THIS LINE OF CODE
   process_id = id;

   if (id == -1)
   {
      return "Error creating process";
   }
   else if (id == 0)
   {
      // This is the child process
      cout << "I am a child process!" << endl;
      return "I am bored of my parent, switching programs now";
   }
   else
   {
      // This is the parent process
      cout << "I just became a parent!" << endl;
      wait(NULL);
      return "My child process just terminated!";
   }
}

// Part 3: Working With External Commands"
void replaceProcess(char *args[])
{
   // Spawn a process to execute the user's command.
   pid_t id = fork();

   // TODO: Add your code here
   if (id == -1)
   {
      // Handle error: The fork() function failed
      cout << "Error creating process" << endl;
   }
   else if (id == 0)
   {
      // This is the child process
      // Replace the current process image with a new process image
      execvp(args[0], args);

      // If execvp returns, it must have failed
      cout << "Error executing command" << endl;
   }
   else
   {
      // This is the parent process
      // Wait for the child process to terminate
      waitpid(id, NULL, 0);
   }
}

#endif /* TestProg_cpp */

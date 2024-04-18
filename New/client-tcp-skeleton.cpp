/************************* INCLUDES **************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>

using namespace std;


/************************* MACROS ****************************/
#define MAXBUF 1000000
#define FALSE 0
#define TRUE 1


/************************* VARIABLES ****************************/
struct sockaddr_in sockme;
int s;
int type;
int portnum;
char *hostnum;


char bufout[MAXBUF+1];
char bufin[MAXBUF+1];
char c, *cp;
char filename[100];

int result;
int n;


int main(int argc, char *argv[])
{
   
   // Get the port number and dotted decimal address of server
   // from the command-line arguments
   if (argc == 3)
   {
      hostnum = argv[1];
      portnum = atoi(argv[2]);
   }
   else
   {
      cout << "usage: client-tcp <hostnum> <portnum>" << endl;
      exit(-1);
   }
   
   
   
   // PASTE CODE FROM STEP #1 HERE
   
   
   
   
   // PASTE CODE FROM STEP #2 HERE
   
   
   
   
   //   Get message from user, send to server
   char message[100] = "";
   
   
   // Run indefinitely, until the user enters the /QUIT command
   while(true)
   {
      // PASTE CODE FROM STEP #3 HERE
      
      
      cout << "--------------------------------------" << endl;
      cout << "Connected to server at IP address = " << hostnum;
      cout << " and Port = " << portnum << endl;
      
      cout << "Input your request (99 characters max). Enter /QUIT when finished:" << endl;
      
      
      // Read a message from the standard input
      string msg;

      getline (cin, msg);
      
      
      
      if (msg == "/QUIT")
      {
         // Close the socket
         close(s);
         
         break;
      }

      
      // Send the message
      int total_characters = msg.length();
      
      cout << "Message: " << msg << endl;
      cout << "Message size: " << total_characters << endl;

      
      // PASTE CODE FROM STEP #4 HERE
      
      
      
      
      
      // Now half close the connection so the server knows
      // the request is complete
      result = shutdown(s, 1);
      
   
      
      // Read response from the server, send to standard output
      char *bp = bufin;
      int cnt = MAXBUF;
      
      
      // PASTE CODE FROM STEP #5 HERE
      
      
      
      
      if (n != -1)
      {
         *bp = '\0';
         cout << "Response was: " << bufin << endl;
      }
      else
      {
         perror("recv failed");
         exit(-1);
      }
      
      
      // Close the socket
      close(s);
      
   }
   
   

   return 0;
}

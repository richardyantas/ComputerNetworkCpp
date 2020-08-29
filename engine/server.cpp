#include <iostream>
#include "socket.h"
using namespace std;
#define MAX 80

void func(Socket &s) 
{
    char buff[MAX];
    int n;
    // infinite loop for chat
    for (;;)
    {           
        bzero(buff, MAX);
        printf("Enter the string : ");
        int n=0;
        while ((buff[n++] = getchar()) != '\n');    

        s.write(buff);
        bzero(buff, MAX);        
        s.read(buff);
        // if msg contains "Exit" then server exit and chat ended.
        /*
        if( (strncmp("exit", buff, 4)) == 0) {
            printf("Server Exit...\n"); 
            break;
        }
        */
    }
} 


int main()
{
    Socket s;
    
    s.create();
    bzero(&s.servaddr, sizeof(s.servaddr));
    // assign IP, PORT
    s.servaddr.sin_family = AF_INET;
    s.servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    s.servaddr.sin_port = htons( 8080 );
    
    s.bind();
    s.listen();
    
    s.accept();
    
    func(s);   
    s.close();
    return 0;
}


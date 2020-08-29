#include <iostream>
#include "socket.h"
using namespace std;

void func(Socket& s)
{
    char buff[MAX]; 
    int n;
    for (;;) {
        bzero(buff, sizeof(buff)); 
        printf("Enter the string: ");
        int n=0;
        // Aqui deberia de esperar a que yo tipee 
        while ((buff[n++] = getchar()) != '\n');
       
        s.write(buff);

        bzero(buff, sizeof(buff)); 
        s.read(buff);
        printf("From Server : %s", buff);
        /*
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client Exit...\n");
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
    s.servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    s.servaddr.sin_port = htons( 8080 );
    s.connect();
    func(s);
    s.close();
    return 0;
}


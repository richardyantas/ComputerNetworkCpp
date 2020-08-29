// g++ serverOnFile.cpp -I/usr/include/conn -o out -lmysqlcppconn
// #include <iostream.h>

#include <iostream>
#include <cstdio> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <stdlib.h> // ??
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/un.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

//using namespace std;
// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
    char buff[MAX]; 
    int n; 
    // infinite loop for chat 
    for (;;) { 
        bzero(buff, MAX); 
        //read the message from client and copy it in buffer 
        //read(sockfd, buff, sizeof(buff)); 
        //recv(sockfd, buff, sizeof(buff)); 
        int len = (int)strlen(buff);
        int a  = (int)recv(sockfd, buff, len-1, 0);        
        // print buffer which contains the client contents 
        printf("From client: %s\t To client : ", buff); 
        bzero(buff, MAX); 
        n = 0; 
        // copy server message in the buffer 
        while ((buff[n++] = getchar()) != '\n'); 
        int len2 = (int)strlen(buff);
        int status = (int)send(sockfd, buff, len2, 0);
        // if msg contains "Exit" then server exit and chat ended. 
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Server Exit...\n"); 
            break; 
        }
    } 
} 
  
// Driver function 
int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
    //printf("PORT: ", servaddr.sin_port);
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
    
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 

    socklen_t len3 = sizeof(cli); 
    /*
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    addr_size = sizeof their_addr;
    int newsock = ::accept(sock, (struct sockaddr *)&their_addr, &addr_size);
    if (newsock < 0) {
        //exit(1);
        cerr << "accept error: " << gai_strerror(errno) << endl;
    }
    */
    // Accept the data packet from client and verification 
    connfd = ::accept(sockfd, (SA*)&cli, &len3); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n");   
    // Function for chatting between client and server 
    func(connfd); 
    // After chatting close the socket 
    ::close(sockfd); 
    return 0;
} 

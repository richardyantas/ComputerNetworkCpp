#include <iostream>
#include <cstdio> 
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

//#define MAX 80 
//#define PORT 8080 
#define SA struct sockaddr 

//uint16_t port 8080;

class Socket
{
public:

    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
    Socket(){};
    void create(uint16_t port);
    void bind();
    void listen();
    void accept();   
    void close();
};

void Socket::create(uint16_t port)
{
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
    servaddr.sin_port = htons( port );
}

void Socket::bind()
{
    //printf("PORT: ", servaddr.sin_port);
    // Binding newly created socket to given IP and verification 
    //int u = (bind(sockfd, (SA*)&servaddr, sizeof(servaddr))); 
    if ((::bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
    
}


void Socket::listen()
{
    // Now server is ready to listen and verification 
    if ((::listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
}

void Socket::accept()
{
    socklen_t len3 = sizeof(cli); 
    // Accept the data packet from client and verification 
    connfd = ::accept(sockfd, (SA*)&cli, &len3); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n"); 
}


void Socket::close()
{
    ::close(sockfd);
}
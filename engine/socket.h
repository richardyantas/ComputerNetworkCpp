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

#define SA struct sockaddr 
#define MAX 80

using namespace std;

class Socket
{
public:
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
    Socket(){};
    void create(); // uint16_t port
    void bind();
    void listen();

    void read(char* buff);
    void write(char* buff);

    void connect();
    void accept();   
    void close();
};

void Socket::create()
{
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("Socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n");
    
    
}

void Socket::bind()
{
    //printf("PORT: ", servaddr.sin_port);
    // Binding newly created socket to given IP and verification 
    if ((::bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("Socket bind failed...\n"); 
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
    socklen_t len = sizeof(cli); 
    // Accept the data packet from client and verification 
    connfd = ::accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("Server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server acccept the client...\n"); 

    return;
}

void Socket::read(char* buff)
{
    int len = (int)strlen(buff);
    cout << "tamanio leido: " << len << endl;
    int a  = (int)recv(sockfd, buff, len-1, 0);
    if ( a != -1)
    {
        cout << "There is bytes" << endl;
    }
    else
    {
        cout << "Does not receive anything" << endl;
    }
    printf("From client: %s\t To client : ", buff); 
}

void Socket::write(char* buff)
{
    //cout << "socker data: " << buff << endl;
    int len = (int)strlen(buff);
    int status = (int)send(sockfd, buff, len, 0);
    if( status != -1)
    {
        cout << "Success sending "<< endl;
    }
    else
    {
        cout << "Failure sending " << endl;
    }
}

void Socket::connect()
{
    // connect the client socket to server socket 
    if (::connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("Connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("Connected to the server..\n"); 
}

void Socket::close()
{
    ::close(sockfd);
}
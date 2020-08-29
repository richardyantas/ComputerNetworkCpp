#include <iostream>
#include <gtest/gtest.h>
#include "../engine/socket.h"
using namespace std;

// c_str -> string -> const char * 


char* foo(char* c)
{
  char ans;
  int n = 0;

  //cout << "l: " << (int)strlen(c) << endl;
  //while ( putchar(*(c+n)) != '\n')n++;
  //cout << "Buff: " << c << endl;
  return "hola"; 
}

TEST(test_char, test1)
{
    char* out = "hola";
    char* in = "hola";
    //EXPECT_EQ(out, foo("hola"));
    ASSERT_EQ(out, foo(in));
}

/*
TEST()
{
    Socket s;   
    s.create();
    // assign IP, PORT
    s.servaddr.sin_family = AF_INET;
    s.servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    s.servaddr.sin_port = htons( 8080 );    
    s.bind();
    s.listen();    
    s.accept();    
    func(s);   
    s.close();
    EXPECT_EQ();
}
*/


void func(Socket &s) 
{
    char buff[MAX];
    int n;
    // infinite loop for chat
    for (;;)
    {   
        bzero(buff, MAX);        
        s.read(buff);
        cout << ":) " << endl;
        bzero(buff, MAX);
        s.write(buff);
        
        // if msg contains "Exit" then server exit and chat ended.
        /*
        if( (strncmp("exit", buff, 4)) == 0) {
            printf("Server Exit...\n"); 
            break;
        }
        */
    }
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
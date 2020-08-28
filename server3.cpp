#include <iostream>
#include "socket.h"
using namespace std;

int main()
{
    Socket s;
    s.create(8080);
    s.bind();
    s.listen();
    s.accept();
    s.close();

    return 0;
}
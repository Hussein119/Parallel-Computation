#include <cstdlib>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv)
{
    pid_t childID;
    childID = fork();

    if (childID == 0)
    {
        cout << "This is the child process\n";
    }
    else
    {
        cout << "This is the parent process\n";
    }
    return 0;
}
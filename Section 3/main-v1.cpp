#include <iostream>
#include <thread>

using namespace std;
using namespace std::this_thread;

int main(int argc, char **argv)
{

    thread t([]()
             { cout << "from " << get_id() << endl; });

    cout << "Main thread waiting\n";

    t.join(); // waits for the thread t to finish its execution before continuing with the main thread.

    return 0;
}

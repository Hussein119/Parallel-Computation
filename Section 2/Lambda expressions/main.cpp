#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// struct
// {
//     void operator()(int x)
//     {
//         cout << x << endl;
//     }
// } print;

// void print(int x)
// {
//     cout << x << endl;
// }

int main()
{
    vector<int> v{2, 5, 58, 54};
    // for_each(v.begin(), v.end(), print);
    // for_each(v.begin(), v.end(), [](int x)
    //          { cout << x << endl; });

    int d = 3;
    for_each(v.begin(), v.end(), [d](int x)
             { x % d == 0 && cout << x << " is devisable by " << d << endl; });

    return 0;
}
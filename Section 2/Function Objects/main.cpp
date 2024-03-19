#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct IsDivisible
{
    int divisor;

    IsDivisible(int newDivisor) : divisor(newDivisor) {}

    bool operator()(int dividend)
    {
        return dividend % divisor == 0;
    }
};

int main()
{
    IsDivisible isDivisibleBy10(10);
    vector<int> myVector = {41, 20, 30, 59, 58};
    auto itr = find_if(myVector.begin(), myVector.end(), isDivisibleBy10);
    if (itr != myVector.end())
    {
        cout << *itr << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    return 0;
}

#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

using namespace std;

// Define a struct to encapsulate a function object
struct functionObject
{
    vector<double>::iterator start; // Iterator pointing to the start of a range
    vector<double>::iterator end;   // Iterator pointing to the end of a range
    double res = 0;                 // Variable to store the result of summing elements in the range

    // Overloaded operator () to perform the sum operation on the range
    void operator()()
    {
        while (start < end)
        {
            res += *start; // Add the value pointed by the iterator to the result
            start++;       // Move the iterator to the next element in the range
        }
    }
};

int main()
{
    int vectorSize;
    cout << "Enter the size of the vector\n";
    cin >> vectorSize; // Input the size of the vector

    vector<double> v(vectorSize);
    iota(v.begin(), v.end(), 1); // Fill the vector with values from 1 to n

    int noThreads;
    cout << "Enter the number of threads to be used for parallel processing\n";
    cin >> noThreads; // Input the number of threads to be used for parallel processing

    vector<thread *> thr(noThreads);     // Vector to store pointers to threads
    vector<functionObject> f(noThreads); // Vector to store function objects
    int step = vectorSize / noThreads;   // Calculate the size of each sub-range

    auto localStart = v.begin(); // Iterator pointing to the beginning of the vector
    for (int i = 0; i < noThreads; i++)
    {
        f[i].start = localStart;        // Assign the start iterator of the range
        f[i].end = localStart + step;   // Assign the end iterator of the range
        thr[i] = new thread(ref(f[i])); // Create a new thread and store its pointer
        localStart += step;             // Move the iterator to the next sub-range
    }

    double total = 0; // Variable to store the total sum of all sub-ranges
    for (int i = 0; i < noThreads; i++)
    {
        thr[i]->join();    // Wait for the thread to finish execution
        total += f[i].res; // Accumulate the sum computed by each thread
        delete thr[i];     // Delete the thread object to free memory
    }

    cout << "The average of the sum is: " << total / vectorSize << endl; // Output the average of the sum
}

/*
The goal of this code is to demonstrate parallel computation of the sum of
    elements in a vector using multiple threads. By dividing the vector into smaller
    sub-ranges and assigning each sub-range to a separate thread,
    the code aims to exploit parallelism and utilize the processing power of
    multiple CPU cores to compute the sum more efficiently.
The end result is the average of the total sum computed by all threads,
    providing a demonstration of how parallel programming techniques can
    improve performance for certain types of computations.
*/
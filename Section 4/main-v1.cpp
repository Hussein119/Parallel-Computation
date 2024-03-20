#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

using namespace std;

struct functionObject
{
    vector<double>::iterator start;
    vector<double>::iterator end;
    double res = 0;

    void operator()()
    {
        while (start < end)
        {
            res += *start;
            start++;
        }
    }
};

class ThreadGuard
{
private:
    thread &th;

public:
    explicit ThreadGuard(thread &i) : th(i) {}

    ~ThreadGuard()
    {
        if (th.joinable())
            th.join();
    }

    ThreadGuard(const ThreadGuard &th) = delete;             // Copy constructor
    ThreadGuard &operator=(const ThreadGuard &rhs) = delete; // Copy operator
};

void process(vector<double> &v, vector<functionObject> &f, int step)
{
    int n = f.size();
    vector<unique_ptr<thread>> thr(n);
    vector<unique_ptr<ThreadGuard>> tg(n);
    auto localStart = v.begin();
    for (int i = 0; i < n; i++)
    {
        f[i].start = localStart;
        f[i].end = localStart + step;
        thr[i] = make_unique<thread>(ref(f[i]));
        tg[i] = make_unique<ThreadGuard>(*thr[i]);
        localStart += step;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " <vector_size> <num_threads>\n";
        return 1;
    }

    int vectorSize = atoi(argv[1]);
    int noThreads = atoi(argv[2]);

    if (vectorSize <= 0 || noThreads <= 0)
    {
        cerr << "Invalid input. Size of the vector and number of threads must be positive integers.\n";
        return 1;
    }

    vector<double> v(vectorSize);
    iota(v.begin(), v.end(), 1);

    vector<functionObject> f(noThreads);
    int step = vectorSize / noThreads;

    process(v, f, step);

    double total = 0;
    for (int i = 0; i < noThreads; i++)
    {
        total += f[i].res;
    }

    cout << "The average of the sum is: " << total / vectorSize << endl;
}

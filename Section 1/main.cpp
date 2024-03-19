#include <iostream>

using namespace std;

class Rect
{
private:
    int width;
    int *height;

public:
    Rect(int w, int h)
    {
        width = w;
        height = new int(h);
    }

    Rect(const Rect &rhs)
    {
        cout << "Copy constructor called " << endl;
        width = rhs.width;
        height = new int(*rhs.height);
    }

    Rect &operator=(const Rect &rhs)
    {
        cout << "Assignment operator called " << endl;
        if (this != &rhs) // Check for self-assignment
        {
            delete height;
            width = rhs.width;
            height = new int(*rhs.height);
        }
        return *this;
    }

    ~Rect()
    {
        delete height;
    }

    void setWidth(int w)
    {
        width = w;
    }

    int getWidth() const
    {
        return width;
    }

    void setHeight(int h)
    {
        *height = h;
    }

    int getHeight() const
    {
        return *height;
    }
};

int main()
{
    Rect a(5, 5);
    Rect b = a;
    b = a;

    a.setHeight(10);
    cout << b.getHeight() << endl;

    return 0;
}

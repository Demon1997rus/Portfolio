#include <iostream>

#include "library/uniqueptr.h"

using namespace std;
using namespace rdi;

class Base
{
public:
    Base() : m_i(0) { cout << __PRETTY_FUNCTION__ << endl; }
    Base(int i) : m_i(i) { cout << __PRETTY_FUNCTION__ << endl; }
    ~Base() { cout << __PRETTY_FUNCTION__ << endl; }

    friend ostream& operator<<(ostream& os, const Base& other)
    {
        os << other.m_i;
        return os;
    }

private:
    int m_i;
};

int main()
{
    UniquePointer<Base> ptr(new Base(1));
    cout << *ptr << endl;

    return 0;
}

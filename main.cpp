#include <iostream>
#include <chrono>

#include "library/list.h"
#include <list>

using namespace std;
using namespace Containers;

void print(const List<int>& container)
{
    for (int i = 0; i < container.count(); ++i)
    {
        cout << container.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    auto start = chrono::steady_clock::now();
    // testSpeed containers
    Containers::List<string> myList;
    std::list<string> stdList;
    // MyList vs StdList
    auto finish = chrono::steady_clock::now();
    auto duration = finish - start;
    auto total = chrono::duration_cast<chrono::milliseconds>(duration).count();
    cout << "Total milliseconds: " << total << endl;
    return 0;
}

#include <iostream>
#include <chrono>

#include "library/list.h"

using namespace std;
using namespace Containers;

int main()
{
    auto start = chrono::steady_clock::now();
    // testSpeed containers
    List<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.push_front(4);
    lst.push_front(5);
    for (int i = 0; i < lst.count(); ++i)
    {
        cout << lst.at(i) << endl;
    }

    cout << "size list-----> " << lst.count() << endl;
    auto finish = chrono::steady_clock::now();
    auto duration = finish - start;
    auto total = chrono::duration_cast<chrono::milliseconds>(duration).count();
    cout << "Total milliseconds: " << total << endl;
    return 0;
}

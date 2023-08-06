#include <iostream>
#include <chrono>

#include "library/list.h"

using namespace std;
using namespace Containers;

void printList(const List<int>& test)
{
    for (int i = 0; i < test.count(); ++i)
    {
        cout << test.at(i) << endl;
    }
    cout << endl;
}

int main()
{
    auto start = chrono::steady_clock::now();
    // testContainers
    auto finish = chrono::steady_clock::now();
    auto duration = finish - start;
    auto total = chrono::duration_cast<chrono::milliseconds>(duration).count();
    cout << "Total milliseconds: " << total << endl;
    return 0;
}

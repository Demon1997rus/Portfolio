#include <iostream>
#include <chrono>

#include "library/list.h"

using namespace std;
using namespace Containers;

int main()
{
    auto start = chrono::steady_clock::now();
    // testSpeed containers
    auto finish = chrono::steady_clock::now();
    auto duration = finish - start;
    auto total = chrono::duration_cast<chrono::milliseconds>(duration).count();
    cout << "Total milliseconds: " << total << endl;
    return 0;
}

#include <iostream>

#include "library/vector.h"

using namespace Containers;

int main()
{
    Vector<int> vec{ 1, 2, 3, 4, 5 };
    std::cout << vec << std::endl;
    return 0;
}

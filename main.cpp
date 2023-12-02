#include <iostream>

#include "library/functions.h"
#include "library/xmlparsetests.h"

using namespace std;
using namespace rdi;

int main()
{
    const std::string configPath = rdi::searchConfig("tests.xml");
    XmlParseTests xmlTests(configPath);
    XmlParseTests::Tests tests = xmlTests.leetCodeHard("1212");

    return 0;
}

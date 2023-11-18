#include <iostream>
#include <vector>

#include "library/nonbinarypolishrecord.h"

using namespace std;

int main()
{
    vector<string> tests{ "(*(+3 6)(*1 2 3))", "(+(*5 3)(*5 3))", "(+6 3)", "(-6 3)",
                          "(*(+(/6 3)(*2 8))(+2 4)(-4 2))" };

    for (const string& test : tests)
    {
        cout << "Результат " << test << " = " << rdi::nonbinarypolishrecord(test) << endl;
    }

    return 0;
}

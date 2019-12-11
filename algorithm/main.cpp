#include <iostream>
#include <vector>
#include "copy.h"
#include "find.h"
using namespace std;

int main(int, char **)
{
    vector<double> s;
    vector<double> des;
    for (int i = 0; i < 10; i++)
    {
        s.push_back(i);
    }
    cout << string(3, '=') + "copy test" + string(3, '=') << endl;
    testcopy(s, des);
    cout << string(3, '=') + "find test" + string(3, '=') << endl;
    testfind(s);
}

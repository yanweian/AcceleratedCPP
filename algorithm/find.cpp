#include "find.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<double>::const_iterator iter;
bool findcmp(double n)
{
    return n > 6;
}
void testfind(const vector<double> &s)
{
    cout << "find 4:" << endl;
    iter i = find(s.begin(), s.end(), 4);
    cout << *i << endl;
    cout << "find n>6:" << endl;
    i = find_if(s.begin(), s.end(), findcmp);
    cout << *i << endl;
    cout << "search 4 5:" << endl;
    vector<double> des;
    des.push_back(4);
    des.push_back(5);
    i = search(s.begin(), s.end(), des.begin(), des.end());
    cout << *i << endl;
    cout << "search 4 5 7:" << endl;
    des.push_back(7);
    i = search(s.begin(), s.end(), des.begin(), des.end());
    cout << *i << endl;
}
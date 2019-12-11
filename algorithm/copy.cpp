#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
#include "copy.h"
bool cmp(double n)
{
    return n > 6;
}
void testcopy(const vector<double> &s, vector<double> &des)
{
    cout << "copy" << endl;
    copy(s.begin(), s.end(), back_inserter(des));
    vector<double>::iterator iter = des.begin();
    vector<double>::const_iterator end = des.end();
    while (iter != end)
    {
        cout << *iter << " ";
        ++iter;
    }
    cout << endl;

    cout << "remove_copy" << endl;
    des.clear();
    remove_copy(s.begin(), s.end(), back_inserter(des), 1);
    iter = des.begin();
    end = des.end();
    while (iter != end)
    {
        cout << *iter << " ";
        ++iter;
    }
    cout << endl;

    cout << "remove_copy_if" << endl;
    des.clear();
    remove_copy_if(s.begin(), s.end(), back_inserter(des), cmp);
    iter = des.begin();
    end = des.end();
    while (iter != end)
    {
        cout << *iter << " ";
        ++iter;
    }
    cout << endl;
}
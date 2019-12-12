#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

bool not_space(char c)
{
    return !isspace(c);
}
// 由于isspace支持多种类型，所以我们需要指定一种类型，方便编译器识别
bool space(char c)
{
    return isspace(c);
}
template <class Out>
void split(const string &str, Out os)
{
    typedef string::const_iterator iter;
    iter i = str.begin();
    while (i != str.end())
    {
        i = find_if(i, str.end(), not_space);
        if (i != str.end())
        {
            iter j = find_if(i, str.end(), space);
            *os++ = string(i, j);
            i = j;
        }
    }
}

int main(int, char **)
{
    std::cout << "Hello, world!\n";
    cout << "test stream iterator." << endl;
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    for (vector<int>::const_iterator i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << "test template function." << endl;
    string str = "If you just want to read the latest version of the NVDLA documentation, go to http: //nvdla.org/.";
    split(str, ostream_iterator<string>(cout, " "));
}

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char **argv)
{
    std::cout << "Hello, world!\n";
    for (int i = 1; i < argc; i++)
    {
        ifstream in(argv[i]);
        // 如果文件可以访问
        if (in)
        {
            string tmp;
            while (getline(in, tmp))
            {
                cout << tmp << endl;
            }
        }
    }
}

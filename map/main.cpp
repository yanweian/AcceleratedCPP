#include <iostream>
#include <map>
using namespace std;
// 验证map的自动排序
int main(int, char **)
{
    std::cout << "Hello, world!\n";
    map<string, double> maps;
    maps["yanweian"] = 20;
    maps["chengjinfeng"] = 30;
    maps["aa"] = 30;
    for (map<string, double>::iterator iter = maps.begin(); iter != maps.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}

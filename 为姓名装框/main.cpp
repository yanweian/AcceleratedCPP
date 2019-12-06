#include <iostream>
#include <string>

using namespace std;
/**
 * 为姓名加上框，涉及 string 的一些使用
 * */
int main(int num,char** args){
    string name;
    cout << "Please enter your name:" << endl;
    cin >> name;
    const string greeting = "Hello " + name + " !";
    // string(int,char);构造一个由int个重复的char组成的字符串
    const string spaces(greeting.size(), ' ');
    const string second = "*" + spaces + "*";
    const string first(second.size(), '*');

    cout << first << endl;
    cout << second << endl;
    cout << "*" + greeting + "*" << endl;
    cout << second << endl;
    cout << first << endl;
    return 0;
}
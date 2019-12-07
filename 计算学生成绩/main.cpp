#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
/**
 * 计算学生成绩
 * */
int main(int num, char **args)
{
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
    cout << "Please enter your midterm and final exam grades:";
    double midterm, final;
    cin >> midterm >> final;
    // 两个以上字符串直接变量，使用空白符分隔可以自动连接
    cout << "Enter all your homework grades, "
            "followed by end-of-file:";
    int count = 0;
    // 编译器会将0转换为double类型对sum进行初始化
    double sum = 0;
    double x;
    while (cin >> x)
    {
        sum += x;
        count++;
    }
    streamsize prec = cout.precision();
    cout << "Your final grade is:"
         << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
         << setprecision(prec) << endl;
    return 0;
}
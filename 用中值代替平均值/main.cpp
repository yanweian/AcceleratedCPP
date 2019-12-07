#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
/**
 * 计算学生成绩，用中值代替平均值
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

    // 计算家庭作业的中值
    vector<double> homework;
    double x;
    while (cin >> x)
    {
        homework.push_back(x);
    }
    size_t vec_sz = homework.size();
    size_t vec_sz_mid = vec_sz / 2;
    // sort(n,m) 用来对[n,m)区间的元素排序
    // begin指向第一个元素的位置，end指向紧跟最后一个元素之后的位置
    sort(homework.begin(), homework.end());
    // 关系运算符 ? : 相当于 if then else
    double median = vec_sz % 2 != 0 ? homework[vec_sz_mid] : (homework[vec_sz_mid] + homework[vec_sz_mid - 1]) / 2;
    streamsize prec = cout.precision();
    cout << "Your final grade is:"
         << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prec) << endl;
    return 0;
}
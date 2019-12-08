#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include "../include/Student_info.h"
#include "../include/grade.h"
using namespace std;
/**
 * 计算学生成绩，用中值代替平均值
 * */
int main(int num, char **args)
{
    vector<Student_info> students;
    Student_info record;
    size_t maxlen = 0;
    while (read(cin, record))
    {
        // 寻找最长的姓名
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    sort(students.begin(), students.end(), compare);
    for (size_t i = 0; i < students.size(); i++)
    {
        // 输出姓名
        cout << setw(maxlen + 1) << students[i].name;
        // 计算并输出成绩
        try
        {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3)
                 << final_grade
                 << setprecision(prec);
        }
        catch (domain_error e)
        {
            e.what();
        }
        cout << endl;
    }
    return 0;
}
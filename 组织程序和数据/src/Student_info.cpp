#include "../include/Student_info.h"
using std::istream;
using std::vector;
bool compare(const Student_info &x, const Student_info &y)
{
    return x.name < y.name;
}
istream &read(istream &is, Student_info &s)
{
    // 读入学生的姓名，期中，期末成绩
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);
    return is;
}
istream &read_hw(istream &is, vector<double> &hw)
{
    if (is)
    {
        hw.clear();
        double x;
        while (is >> x)
        {
            hw.push_back(x);
        }
        // 清除所有错误信息，方便下次输入
        is.clear();
    }
    return is;
}
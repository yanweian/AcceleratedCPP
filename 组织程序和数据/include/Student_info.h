#ifndef __STUDENT_INFO_H__
#define __STUDENT_INFO_H__
#include <iostream>
#include <string>
#include <vector>
struct Student_info
{
    std::string name;
    double midterm;
    double final;
    std::vector<double> homework;
};

bool compare(const Student_info &, const Student_info &);
std::istream &read(std::istream &, Student_info &);
std::istream &read_hw(std::istream &, std::vector<double> &);
#endif
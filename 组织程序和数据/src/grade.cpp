#include "../include/grade.h"
#include <stdexcept>
using namespace std;
double grade(double midterm, double final, double median)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * median;
}
double grade(double midterm, double final, const std::vector<double> &hw)
{
    if (hw.size() == 0)
        throw domain_error("homework is necessary. Please try again.");
    return grade(midterm, final, median(hw));
}
double median(std::vector<double> hw)
{
    if (hw.size() == 0)
        throw domain_error("the size of homework must larger than 0.");
    sort(hw.begin(), hw.end());
    size_t vc_sz = hw.size();
    size_t vc_sz_half = vc_sz / 2;
    return vc_sz % 2 != 0 ? hw[vc_sz_half] : (hw[vc_sz_half] + hw[vc_sz_half - 1]) / 2;
}
double grade(Student_info &s)
{
    return grade(s.midterm, s.final, s.homework);
}

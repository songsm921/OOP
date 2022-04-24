#ifndef _4_H
#define _4_H

#include <istream>
#include <ostream>
#include <fstream>
#include <qstring.h>

// 학점관리
namespace Minho
{
    class Courses{
    public:
        Courses();
        void read_data(std::string id);
        void write_data(std::string id);
        void sort();
        int* sum_category();
        void get_requirements(int*, std::string&);
        int* cal_sub();
        std::string const get_inf(int s, int c, int e);
        void set_inf(const std::string& str, int s, int c, int e);
        std::string get_inf();
        void increment_size(int i);
        bool& get_dual_major();
        int get_dual_req(std::string&);
    private:
        std::string inf[8][10][4]; // [학기][과목][과목명, 단위, 학점, 계열]
        int size_per_semester[8]; // 8학기 기본으로
        int sum_per_category[8]; // 복전까지 8개
        bool dual_major;
    };
}

#endif

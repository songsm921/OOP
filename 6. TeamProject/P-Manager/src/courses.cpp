#include "courses.h"
#include"member.h"

namespace Minho
{
    Courses::Courses()
    {
        for(int i =0; i <8 ; i++)
            for(int j=0 ; j< 10; j++)
                for(int k=0; k< 4; k++)
                    inf[i][j][k] = "";
        for(int i =0; i < 8; i++)
            size_per_semester[i] = 0;
        for(int i = 0; i< 7; i++)
            sum_per_category[i]= 0;
        dual_major = 0;
    }

    void Courses::read_data(std::string id){
        std::string in_file_path = "courseslog";
        in_file_path.append("_"+id);
        in_file_path.append(".txt");
        std::ifstream fin(in_file_path);
        std::string sem;std::string course_name; std::string credit;std::string grade;std::string category;\
        while(std::getline(fin, sem))
        {
            if(sem == "dm")
            {
                dual_major = 1;
                continue;
            }
            std::getline(fin, course_name);std::getline(fin, credit);std::getline(fin, grade);std::getline(fin, category);
            int semester = std::atoi (sem.c_str());
            switch (semester) {
            case 0:
            {
                inf[semester][size_per_semester[0]][0] = course_name;
                inf[semester][size_per_semester[0]][1] = credit;
                inf[semester][size_per_semester[0]][2] = grade;
                inf[semester][size_per_semester[0]][3] = category;
                size_per_semester[0]++;
                break;
            }
            case 1:
            {
                inf[semester][size_per_semester[1]][0] = course_name;
                inf[semester][size_per_semester[1]][1] = credit;
                inf[semester][size_per_semester[1]][2] = grade;
                inf[semester][size_per_semester[1]][3] = category;
                size_per_semester[1]++;
                break;
            }
            case 2:
            {
                inf[semester][size_per_semester[2]][0] = course_name;
                inf[semester][size_per_semester[2]][1] = credit;
                inf[semester][size_per_semester[2]][2] = grade;
                inf[semester][size_per_semester[2]][3] = category;
                size_per_semester[2]++;
                break;
            }
            case 3:
            {
                inf[semester][size_per_semester[3]][0] = course_name;
                inf[semester][size_per_semester[3]][1] = credit;
                inf[semester][size_per_semester[3]][2] = grade;
                inf[semester][size_per_semester[3]][3] = category;
                size_per_semester[3]++;
                break;
            }
            case 4:
            {
                inf[semester][size_per_semester[4]][0] = course_name;
                inf[semester][size_per_semester[4]][1] = credit;
                inf[semester][size_per_semester[4]][2] = grade;
                inf[semester][size_per_semester[4]][3] = category;
                size_per_semester[4]++;
                break;
            }
            case 5:
            {
                inf[semester][size_per_semester[5]][0] = course_name;
                inf[semester][size_per_semester[5]][1] = credit;
                inf[semester][size_per_semester[5]][2] = grade;
                inf[semester][size_per_semester[5]][3] = category;
                size_per_semester[5]++;
                break;
            }
            case 6:
            {
                inf[semester][size_per_semester[6]][0] = course_name;
                inf[semester][size_per_semester[6]][1] = credit;
                inf[semester][size_per_semester[6]][2] = grade;
                inf[semester][size_per_semester[6]][3] = category;
                size_per_semester[6]++;
                break;
            }
            case 7:
            {
                inf[semester][size_per_semester[7]][0] = course_name;
                inf[semester][size_per_semester[7]][1] = credit;
                inf[semester][size_per_semester[7]][2] = grade;
                inf[semester][size_per_semester[7]][3] = category;
                size_per_semester[7]++;
                break;
            }
            }
        }
    }

    void Courses::write_data(std::string id){
        std::string out_file_path = "courseslog_";
        out_file_path.append(id);
        out_file_path.append(".txt");
        std::ofstream fout(out_file_path);
        if(dual_major == 1)
            fout << "dm\n";
        for(int sem = 0; sem < 8 ; sem++)
            for(int c=0; c<size_per_semester[sem]; c++)
                fout  << sem << "\n"<< inf[sem][c][0] << "\n"<< inf[sem][c][1] << "\n" << inf[sem][c][2] << "\n" << inf[sem][c][3]<< "\n";
    }

    void Courses::sort(){
        for(int i =0; i <8 ; i++)
            for(int j=0 ; j< 10; j++)
                for(int k=0; k< 4; k++)
                    inf[i][j][k] = "";
        for(int i =0; i < 8; i++)
            size_per_semester[i] = 0;
        for(int i = 0  ; i < 8; i++)
            sum_per_category[i] = 0;
    }

    int* Courses::sum_category(){
        for(int sem = 0; sem < 8 ; sem++)
            for(int c=0; c<size_per_semester[sem]; c++){
                if(inf[sem][c][3] == "교양필수" || inf[sem][c][3] == "교양 필수"|| inf[sem][c][3] == "교필"){
                    int credit = std::atoi (inf[sem][c][1].c_str());
                    sum_per_category[0] += credit;
                }
                else if(inf[sem][c][3] == "교양선택"|| inf[sem][c][3] == "교양 선택"|| inf[sem][c][3] == "교선"){
                    int credit = std::atoi (inf[sem][c][1].c_str());
                    sum_per_category[1] += credit;
                }
                else if(inf[sem][c][3] == "기초필수"|| inf[sem][c][3] == "기초 필수"|| inf[sem][c][3] == "기필"){
                    int credit = std::atoi (inf[sem][c][1].c_str());
                    sum_per_category[2] += credit;
                }
                else if(inf[sem][c][3] == "기초선택"|| inf[sem][c][3] == "기초 선택"|| inf[sem][c][3] == "기선"){
                    int credit = std::atoi (inf[sem][c][1].c_str());
                    sum_per_category[3] += credit;
                }
                else if(inf[sem][c][3] == "전공필수"|| inf[sem][c][3] == "전공 필수"|| inf[sem][c][3] == "전필"){
                    int credit = std::atoi (inf[sem][c][1].c_str());
                    sum_per_category[4] += credit;
                }
                else if(inf[sem][c][3] == "전공선택"|| inf[sem][c][3] == "전공 선택"|| inf[sem][c][3] == "전선"){
                    int credit = std::atoi (inf[sem][c][1].c_str());
                    sum_per_category[5] += credit;
                }
                else if(inf[sem][c][3] == "자유선택"|| inf[sem][c][3] == "자유 선택"|| inf[sem][c][3] == "자선"){
                    int credit = std::atoi (inf[sem][c][1].c_str());
                    sum_per_category[6] += credit;
                }
                else if(inf[sem][c][3] == "복수전공"|| inf[sem][c][3] == "복수 전공"|| inf[sem][c][3] == "복전"){
                    int credit = std::atoi (inf[sem][c][1].c_str());
                    sum_per_category[7] += credit;
                }
            }
        return sum_per_category;
    }

    void Courses::get_requirements(int* arr, string& dept_name){
                // {교필, 교선... , 복전}
                // 복전
                // 산경 = 43, 기계 = 37
                // 나머지 35
                if (mc.get_logged_in_member()->get_dept() == "기계"||mc.get_logged_in_member()->get_dept() == "기계과"||mc.get_logged_in_member()->get_dept() == "기계 공학과" || mc.get_logged_in_member()->get_dept() == "기계공학과"||mc.get_logged_in_member()->get_dept() == "기공") {
                    //{ 13,18,25,5,25 + 9,25,9,37 }; //기계 *9
                    arr[0]=13;
                    arr[1]=18;
                    arr[2]=25;
                    arr[3]=5;
                    arr[4]=34;
                    arr[5]=25;
                    arr[6]=9;
                    dept_name = "기계공학과";
                }
                else if (mc.get_logged_in_member()->get_dept() == "물리"||mc.get_logged_in_member()->get_dept() == "물리과"||mc.get_logged_in_member()->get_dept() == "물리 학과" || mc.get_logged_in_member()->get_dept() == "물리학과") {
                    //{ 13,18,25,5,24,30,15,35 };
                    arr[0]=13;
                    arr[1]=18;
                    arr[2]=25;
                    arr[3]=5;
                    arr[4]=24;
                    arr[5]=30;
                    arr[6]=15;
                    dept_name = "물리학과";
                }
                else if (mc.get_logged_in_member()->get_dept() == "산경"||mc.get_logged_in_member()->get_dept() == "산경과"||mc.get_logged_in_member()->get_dept() == "산업 경영 공학과" || mc.get_logged_in_member()->get_dept() == "산엄경영공학과") {
                    //{ 13,18,25,5,43,15,11,43 };//산경
                    arr[0]=13;
                    arr[1]=18;
                    arr[2]=25;
                    arr[3]=5;
                    arr[4]=43;
                    arr[5]=15;
                    arr[6]=11;
                    dept_name = "산업경영공학과";
                }
                else if (mc.get_logged_in_member()->get_dept() == "생명"||mc.get_logged_in_member()->get_dept() == "생명 공학과" || mc.get_logged_in_member()->get_dept() == "생명공학과"||mc.get_logged_in_member()->get_dept() == "생명과") {
                    //{ 13,18,25,5,25,27,11,35 };//생명
                    arr[0]=13;
                    arr[1]=18;
                    arr[2]=25;
                    arr[3]=5;
                    arr[4]=25;
                    arr[5]=27;
                    arr[6]=11;
                    dept_name = "생명공학과";
                }
                else if (mc.get_logged_in_member()->get_dept() == "수학과"||mc.get_logged_in_member()->get_dept() == "수학") {
                    //{ 13,18,25,5,3 + 12,33,16,35 };//수학 *12
                    arr[0]=13;
                    arr[1]=18;
                    arr[2]=25;
                    arr[3]=5;
                    arr[4]=15;
                    arr[5]=33;
                    arr[6]=16;
                    dept_name = "수학과";
                }
                else if (mc.get_logged_in_member()->get_dept() == "소재"||mc.get_logged_in_member()->get_dept() == "소재과"||mc.get_logged_in_member()->get_dept() == "신소재 공학과" || mc.get_logged_in_member()->get_dept() == "신소재공학과"||mc.get_logged_in_member()->get_dept() == "신소재"||mc.get_logged_in_member()->get_dept() == "신소재과") {
                    //{ 13,18,25,5,12 + 10,35,10,35 };//신소재 *10
                    arr[0]=13;
                    arr[1]=18;
                    arr[2]=25;
                    arr[3]=5;
                    arr[4]=22;
                    arr[5]=35;
                    arr[6]=10;
                    dept_name = "신소재공학과";
                }
                else if (mc.get_logged_in_member()->get_dept() == "전자"||mc.get_logged_in_member()->get_dept() == "전자과"||mc.get_logged_in_member()->get_dept() == "전자 공학과" || mc.get_logged_in_member()->get_dept() == "전자공학과") {
                    //{ 13,18,25,5,31,25,12,35 };//전자
                    arr[0]=13;
                    arr[1]=18;
                    arr[2]=25;
                    arr[3]=5;
                    arr[4]=31;
                    arr[5]=25;
                    arr[6]=12;
                    dept_name = "전자공학과";
                }
                else if (mc.get_logged_in_member()->get_dept() == "창공"||mc.get_logged_in_member()->get_dept() == "창의IT융합공학과" || mc.get_logged_in_member()->get_dept() == "창의it융합공학과"||mc.get_logged_in_member()->get_dept() == "창의IT공학과"||mc.get_logged_in_member()->get_dept() == "창의it공학과"||mc.get_logged_in_member()->get_dept() == "창공과") {
                    //{ 13,18,25,5,29,31,0,35 };//창공
                    arr[0]=13;
                    arr[1]=18;
                    arr[2]=25;
                    arr[3]=5;
                    arr[4]=29;
                    arr[5]=31;
                    arr[6]=0;
                    dept_name = "창의IT융합공학과";
                }
                else if (mc.get_logged_in_member()->get_dept() == "컴공"||mc.get_logged_in_member()->get_dept() == "컴공과"||mc.get_logged_in_member()->get_dept() == "컴퓨터 공학과" || mc.get_logged_in_member()->get_dept() == "컴퓨터공학과") {
                    arr[0]=13;
                    arr[1]=18;
                    arr[2]=25;
                    arr[3]=5;
                    arr[4]=31;
                    arr[5]=27;
                    arr[6]=9;
                    dept_name = "컴퓨터공학과";
                    //{ 13,18,25,5,31,27,9,35 };//컴공
                }
                else if (mc.get_logged_in_member()->get_dept() == "화학"|| mc.get_logged_in_member()->get_dept() == "화학과") {
                    //{ 13,18,25,5,34,15,15,35 };//화학
                    arr[0]=13;
                    arr[1]=18;
                    arr[2]=25;
                    arr[3]=5;
                    arr[4]=34;
                    arr[5]=15;
                    arr[6]=15;
                    dept_name = "화학과";
                }
                else if (mc.get_logged_in_member()->get_dept() =="화공"||mc.get_logged_in_member()->get_dept() == "화학 공학과" || mc.get_logged_in_member()->get_dept() == "화학공학과"|| mc.get_logged_in_member()->get_dept() == "화공과") {
                    // { 13,18,25,5,30,25,15,35 };//화공
                    arr[0]=13;
                    arr[1]=18;
                    arr[2]=25;
                    arr[3]=5;
                    arr[4]=30;
                    arr[5]=25;
                    arr[6]=15;
                    dept_name = "화학공학과";
                }
    }

    int* Courses::cal_sub(){
        int* sum = sum_category();
        std::string s;
        int* sum_; get_requirements(sum_, s);
        static int sub[7];
        for(int j=0; j<7; j++)
        {
            sub[j] = sum_[j] - sum[j];
        }
        return sub;
    }

    std::string const Courses::get_inf(int s, int c, int e){
        return inf[s][c][e];
    }

    void Courses::set_inf(const std::string& str, int s, int c, int e){
        inf[s][c][e] = str;
    }

    void Courses::increment_size(int i){
        size_per_semester[i]++;
    }

    bool& Courses::get_dual_major(){
        return dual_major;
    }


    int Courses::get_dual_req(std::string& d){
        if (d == "기계"||d == "기계 공학과" || d == "기계공학과"||d == "기공"||d == "기계과")
            return 37;
        else if (d == "산경"||d == "산업 경영 공학과" || d == "산엄경영공학과"|| d == "산경과")
            return 43;
        else
            return 35;
    }
}


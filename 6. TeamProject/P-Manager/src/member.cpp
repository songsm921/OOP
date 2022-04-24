#include "member.h"


namespace Minho
{
string& Member::get_id(){
    return ID;
}
string& Member::get_pw(){
    return Password;
}
string& Member::get_dept(){
    return department;
}
string& Member::get_dual_dept(){
    return dual_dept;
}
bool Member::information_check(string id, string password){
    if (!ID.compare(id) && !Password.compare(password))
        return true;
    return false;
}
Courses* Member::get_courses(){
    return courses;
}

MemberCollection::MemberCollection(){
    for(int i = 0; i < 20; i++)
        Members[i] = new Member;
    index_of_logged_in_member= 0;
    n_members = 0;
}

bool MemberCollection::Login(string id, string password){
    if (index_of_logged_in_member == 0)
    {
        index_of_logged_in_member = 1;
        if (0 == n_members){
            index_of_logged_in_member =0;
            return 0;
        }
        while (!Members[index_of_logged_in_member]->information_check(id, password))
        {
            if (index_of_logged_in_member == n_members + 1)
            {
                index_of_logged_in_member = 0;
                return 0;
            }
            index_of_logged_in_member++;
        }
        if (index_of_logged_in_member == n_members + 1)
        {
            index_of_logged_in_member = 0;
            return 0;
        }
        return 1;
    }
    else
        return 0;
}
bool MemberCollection::Logout(){
    if (index_of_logged_in_member == 0)
        return 0;
    index_of_logged_in_member = 0;
    return 1;
}
bool MemberCollection::is_logged_in(){
    if (index_of_logged_in_member == 0)
        return false; // no
    else
        return true; // yes
}
bool MemberCollection::Register(string id, string password, string dept, string dual_dept){
    if (index_of_logged_in_member == 0)
    {
        for (int j = 1; j < n_members + 1; j++)
        {
            if(Members[j]->information_check(id, password))
                return false;
        }
        Members[n_members + 1] = new Member;
        Members[n_members + 1]->get_id() = id;
        Members[n_members + 1]->get_pw() = password;
        Members[n_members + 1]->get_dept() = dept;
        Members[n_members + 1]->get_dual_dept() = dual_dept;
        n_members++;
        return true;
    }
    else
        return false;
}
bool MemberCollection::Unsubscribe(string id, string password){
    int j;
    if (0 == n_members)
        return false;
    for (j = 1; j < n_members + 1; j++)
    {
        if(Members[j]->information_check(id, password))
            break;
    }
    if (j == n_members + 1)
        return false;
    if (index_of_logged_in_member == j)
    {
        string id=Members[j]->get_id(), pw="", dept="";
        Members[j] = new Member(id,pw,dept);
        Members[j]->get_courses()->write_data(id);
        delete Members[j];
        for (j; 0 < j&& j < n_members; j++)
            Members[j] = Members[j + 1];
        index_of_logged_in_member=0;
        n_members--;
        return true;
    }
    return false;
}

Member* MemberCollection::get_logged_in_member(){
    return Members[index_of_logged_in_member];
}
void MemberCollection::write_log(){
    std::string out_file_path = "Members.txt";
    std::ofstream fout(out_file_path);
    for(int i = 1; i <= n_members; i++)
    {
        std::string dual_dept = Members[i]->get_dual_dept();
        std::string id = Members[i]->get_id();
        std::string pw = Members[i]->get_pw();
        std::string dept = Members[i]->get_dept();
        if(dual_dept != ""){
            fout << "dual dept" << std::endl;
        fout << dual_dept << std::endl<< id << std::endl <<pw<< std::endl<<dept<< std::endl;
        }
        else{
            fout << id << std::endl <<pw<< std::endl<<dept<< std::endl;
        }
    }
}
void MemberCollection::read_log(){
    std::string in_file_path = "Members.txt";
    std::ifstream fin(in_file_path);
    std::string id;std::string pw; std::string dept;std::string dual_dept;
    while(std::getline(fin, id))
    {
        if(id == "dual dept")
        {
            std::getline(fin, dual_dept);std::getline(fin, id);std::getline(fin, pw);std::getline(fin, dept);
            mc.Register(id,pw,dept,dual_dept);
        }
        else{
            std::getline(fin, pw);std::getline(fin, dept);
            mc.Register(id,pw,dept);
        }
    }
}
MemberCollection mc;
}



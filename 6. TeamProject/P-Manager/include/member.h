#ifndef _6_H
#define _6_H

#include <istream>
#include <ostream>
#include "courses.h"
#include "municipality.h"
#include "extra_widget.h"
#include "club.h"
#include "extra.h"
#include "portfolio.h"


namespace Minho
{
using namespace std;
    class Member{
    public:
        Member(string id,string pw,string dept){
            ID = id; Password=pw; department=dept; dual_dept ="";
            courses = new Courses;
      //      extra_widget = new Sumin::EXTRA(id);
            /*club = new Club; committee= new Committee; extramural_activity = Extramural_Activity;*/
     //       connect(this,SIGANL(login_success()), )

        }
        Member(string id,string pw,string dept, string _dual_dept){
            ID = id; Password=pw; department=dept; dual_dept = _dual_dept;
            courses = new Courses;
      //      extra_widget = new Sumin::EXTRA(id);
            /*club = new Club; committee= new Committee; extramural_activity = Extramural_Activity;*/
     //       connect(this,SIGANL(login_success()), )

        }
        Member():ID(""),Password(""),department(""){
            courses = new Courses;
            /*club = new Club; committee= new Committee; extramural_activity = Extramural_Activity;*/
        }
        string& get_id();
        string& get_pw();
        string& get_dept();
        string& get_dual_dept();
        bool information_check(string id, string password);
        Courses* get_courses();
 //       Sumin::EXTRA* get_extra_widget() {return extra_widget;}
        /*
        Junhyeong::Committee* get_committee() {return committee;}
        Sumin::ExtraCourse* get_municipality() {return municipality;}
        Sumin::ExtraCourse* get_extra() {return extra;}
        Sumin::ExtraCourse* get_club() {return club;}
        Sumin::Portfolio* get_portfolio() {return portfolio;}
        */
    private:
        string ID;
        string Password;
        string department;
        string dual_dept;
        Courses* courses;
        Sumin::ExtraCourse* municipality, *extra, *club;
        Sumin::Portfolio* portfolio;
    //    Sumin::EXTRA* extra_widget;

        /*Club* club;
        Committee* committee;
        Extramural_Activity* extramural_activity;*/
    };
    class MemberCollection{
    public:
        MemberCollection();
        bool Login(string id, string password);
        bool Logout();
        bool is_logged_in();
        bool Register(string id, string password, string dept, string dual_dept = "");
        bool Unsubscribe(string id, string password);
        Member* get_logged_in_member();
        void write_log();
        void read_log();
    private:
        Member* Members[20];
        int n_members;
        int index_of_logged_in_member;
    };
    extern MemberCollection mc;
}


#endif

#include "io/songio.h"
#include "string"
#include "sstream"
namespace as4::io
{
    namespace operators
    {
        /* Put your code here */
    std::ostream& operator<<(std::ostream& out,const as4::model::Song &save)
    {
        for(unsigned i=0;i<save.GetMelodySeq()->Getsize();i++)
        {
            out<<save.GetMelodySeq()->Enter1(i)<<" "<<save.GetMelodySeq()->Enter2(i)<<" "<<save.GetMelodySeq()->Enter3(i)<<" "<<save.GetMelodySeq()->Enter4(i)<<" "<<std::endl;
        }
        out<<"FIN"<<std::endl;
        for(unsigned i=0;i<save.GetDrumSeq()->Getsize();i++)
        {
            out<<save.GetDrumSeq()->Enter1(i)<<" "<<save.GetDrumSeq()->Enter2(i)<<" "<<save.GetDrumSeq()->Enter3(i)<<" "<<save.GetDrumSeq()->Enter4(i)<<" "<<std::endl;
        }
        return out;
    }//Drum과 Melody를 구별하기 위해 Melody의 입력이 끝나면 FIN을 입력하고 이를 기준으로 Drum과 나뉩니다.
     std::istream& operator>>(std::istream& in,as4::model::Song &make)
     {
         std::string tokens[4],line;
         std::stringstream stream;
         as4::model::Timestamp temp1;
         as4::model::TimeInterval temp2;
         int temp3,temp4;
         int check=1;
         int mode =1;//Melody Input = 1, Drum Input =2
         int nTokens=0;
         while(check)
         {
         getline(in,line);
         if(line=="FIN")
         {
             mode =2;
             continue;
         }//Fin을 getline하면 mode를 2로 바꾸어 Drum 입력으로 진입합니다.
         if(line=="")
         {
             if(in.eof())
             {
                 //in.close();
                 check =0;
             }
         }
         else if(mode==1)
         {
             stream.str(line);
             nTokens=0;
             while(stream>>tokens[nTokens])
                 nTokens++;
             stream.clear();
             temp1 = _atoi64(tokens[0].c_str());
             temp2 = _atoi64(tokens[1].c_str());
             temp3 = atoi(tokens[2].c_str());
             temp4 = atoi(tokens[3].c_str());
             make.GetMelodySeq()->Put({temp1,temp2,{temp3,temp4}});

         }
         else if(mode==2)
         {
             stream.str(line);
             nTokens=0;
             while(stream>>tokens[nTokens])
                 nTokens++;
             stream.clear();
             temp1 = _atoi64(tokens[0].c_str());
             temp2 = _atoi64(tokens[1].c_str());
             temp3 = atoi(tokens[2].c_str());
             temp4 = atoi(tokens[3].c_str());
             make.GetDrumSeq()->Put({temp1,temp2,{temp3,temp4}});

         }
         }
         return in;
     }
    }
}

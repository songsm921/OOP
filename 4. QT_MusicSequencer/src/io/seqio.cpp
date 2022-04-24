#include "io/seqio.h"
#include "string"
#include "sstream"
namespace as4::io
{
    namespace operators
    {
        /* Put your code here */
    std::ostream& operator<<(std::ostream& out,const as4::model::ISeq &save)
    {
        for(unsigned i=0;i<save.Getsize();i++)
        {
            out<<save.Enter1(i)<<" "<<save.Enter2(i)<<" "<<save.Enter3(i)<<" "<<save.Enter4(i)<<" "<<std::endl;
        }
        return out;
    }
    std::istream& operator>>(std::istream& in,as4::model::ISeq &make)
    {
        std::string tokens[4],line;
        std::stringstream stream;
        as4::model::Timestamp temp1;
        as4::model::TimeInterval temp2;
        int temp3,temp4;
        int check=1;
        int nTokens=0;
        while(check)
        {
        getline(in,line);
        if(line=="")
        {
            if(in.eof())
            {
                //in.close();
                check =0;
            }
        }
        else
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
            make.Put({temp1,temp2,{temp3,temp4}});

        }
        }
        return in;
    }
    }// Assignment 2,3의 파일 입출력을 기반으로 하여 작성하였습니다.
}

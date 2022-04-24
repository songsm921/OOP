#ifndef __AS4_SONGIO_H
#define __AS4_SONGIO_H

#include <istream>
#include <ostream>

#include "model/song.h"

namespace as4::io
{
    namespace operators
    {
        /* Put your code here */
    std::ostream& operator<<(std::ostream& out,const as4::model::Song &save);//<< Operator Overloading
    std::istream& operator>>(std::istream& in,as4::model::Song &make);//>> Operator Overloading
    }
}

#endif

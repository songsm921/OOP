#ifndef __AS4_IO_SEQ_H
#define __AS4_IO_SEQ_H

#include <istream>
#include <ostream>

#include "model/seq.h"

/**
 * Abstract)
 * IO functions for note seqences
 *
 * Notes)
 * These namespace specifications(as4::io) are not mendatory for our code 
 * to work. However, it helps the users of this code not to mix many 
 * function/classes with identical names.
 */
namespace as4::io
{
    namespace operators
    {

        /* Put your code here */
std::ostream& operator<<(std::ostream& out,const as4::model::ISeq &save);//<< Operator Overloading
std::istream& operator>>(std::istream& in,as4::model::ISeq &make);//>> Operator Overloading


    }
}

#endif

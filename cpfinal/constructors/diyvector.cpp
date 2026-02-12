// The contents of this file are for your information only.
// (like inspiration for particular syntax)
//
// This file MUST NOT be modified.
// Any modifications will be ignored by all tests.
// An original copy will always be used instead.
//

#include "diyvector.h"
#include <stdexcept>

int& DIYVector::at(int index)
{
    if ( (index<0) || (index>=dataSize) ){
        throw std::out_of_range("DIYVector.at()");
    }
    return data[index];
}

const int& DIYVector::at(int index) const
{
    if ( (index<0) || (index>=dataSize) ){
        throw std::out_of_range("DIYVector.at()");
    }
    return data[index];
}

void DIYVector::resize(int newSize)
{
    if ( newSize == dataSize ) return;

    if ( newSize < 0 ){
        throw std::out_of_range("DIYVector.resize()");
    }

    if ( newSize == 0 ){
        delete[] data;
        data = nullptr;
        dataSize = 0;
        return;
    }

    int* newData = new int[newSize];
    int upperBound = ( newSize < dataSize ) ? newSize : dataSize;
    for (int i=0; i<upperBound; i++){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    dataSize = newSize;
    return;
}

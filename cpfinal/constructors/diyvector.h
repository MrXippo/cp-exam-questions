// This file MUST NOT be modified.
// Any modifications will be ignored by all tests.
// An original copy will always be used instead.
//

#ifndef DIYVECTOR_H
#define DIYVECTOR_H

#include <cstddef>

class DIYVector{
    public:
        DIYVector() : data(nullptr), dataSize(0) {}
        ~DIYVector() { delete data; }
        DIYVector(const DIYVector& source);
        DIYVector& operator= (const DIYVector& source);
        int size() const{ return dataSize; }
        void resize(int newSize);
        int& at(int index);
        const int& at(int index) const;
    private:
        int* data;
        int dataSize;
};

#endif
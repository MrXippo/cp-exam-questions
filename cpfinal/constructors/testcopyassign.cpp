#include <iostream>
#include <cassert>
#include "diyvector.h"

bool sameSize(const DIYVector& a, const DIYVector& b)
{
    return ( a.size() == b.size() );
}

bool sameValues(const DIYVector& a, const DIYVector& b)
{
    for (int i = 0; i< a.size(); i++){
        if ( a.at(i) != b.at(i) ){
            return false;
        }
    }
    return true;
}

int main()
{
    DIYVector dv, dRef;
    dv.resize(42);
    dRef.resize(42);
    for (int i=-0; i< dv.size(); i++){
        dv.at(i) = 2 * i;
        dRef.at(i) = 2 * i;
    }

    DIYVector dv2;
    dv2 = dv;
    assert(sameSize(dv, dv2));
    assert(sameValues(dv, dv2));

    DIYVector dEmpty;
    DIYVector dE2;
    dE2 = dEmpty;
    assert(sameSize(dEmpty, dE2));
    assert(sameValues(dEmpty, dE2));

    for (int i=0; i<dv2.size(); i++){
        dv2.at(i) += 42;
    }
    assert(sameSize(dRef,dv2));
    assert(sameSize(dRef, dv));
    assert(sameValues(dRef,dv));
    assert(!sameValues(dRef,dv2));

    dv.resize(10);
    assert(!sameSize(dv,dv2));
    
    std::cout << "All tests passed!\n";
    return 0;
}
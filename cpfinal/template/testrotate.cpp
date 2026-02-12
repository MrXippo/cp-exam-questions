#include <iostream>
#include <cassert>

#include "templaterotate.h"

class Foo{
    public:
        Foo() {};
        Foo(int value) : v(value) {}
        bool operator<(const Foo& other) const
        {
            return v < other.v;
        }
        int v;
};

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int aO = a;
    int bO = b;
    int cO = c;
    

    std::cout << a << ' ' << b << ' ' << c << '\n';
    rotateRight(a,b,c);
    std::cout << a << ' ' << b << ' ' << c << '\n';
    rotateRight(a,b,c);
    std::cout << a << ' ' << b << ' ' << c << std::endl;
    assert ((c==aO) && (a==bO) && (b==cO) );

    srand(time(0));
    Foo fa(rand()%10);
    Foo fb(rand()%10);
    Foo fc(rand()%10);

    Foo faO = fa;
    Foo fbO = fb;
    Foo fcO = fc;

    std::cout << fa.v << ' ' << fb.v << ' ' << fc.v << '\n';
    rotateRight(fa,fb,fc);
    std::cout << fa.v << ' ' << fb.v << ' ' << fc.v << std::endl;
    assert ( (fb.v==faO.v) && (fc.v==fbO.v) && (fa.v==fcO.v) );


    return 0;
}
#include <iostream>
#include <cassert>

#include "templatemaxbroken.h"
#include "reference.h"

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
    int maximum;

    std::cout << a << ' ' << b << ' ' << c << '\n';

    maximum = max(a,b,c);
    std::cout << "max: " << maximum << "\n";
    assert ( maximum == referenceMax(a,b,c) );

    srand(time(0));
    Foo fa(rand()%10);
    Foo fb(rand()%10);
    Foo fc(rand()%10);

    std::cout << fa.v << ' ' << fb.v << ' ' << fc.v << '\n';

    maximum = max(fa,fb,fc).v;
    std::cout << "max: " << maximum << "\n";

    assert ( maximum == referenceMax(fa,fb,fc).v );

    return 0;
}



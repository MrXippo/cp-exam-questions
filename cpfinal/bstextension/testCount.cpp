#include <iostream>
#include <vector>
#include <cstdlib>
#include "bstCount.h"

void checkCount(BST& b, int shouldBe)
{
    int count  = b.count();
    if ( count != shouldBe ){
        throw std::runtime_error(
            "count is " + std::to_string(count) + " but should be " + std::to_string(shouldBe) + "\n"
        );
    }
}

int main()
{
    try{
        std::vector<int>keys = {8, -1, 5, -3, 7, 6, -5, 4};
        std::vector<std::string>values = {"a", "b", "c", "d", "e", "f", "g", "h"};

        BST b;
        checkCount(b, 0);
        for (int i=0; i<keys.size(); i++){
            std::cout << "insert " << keys.at(i) << "\n";
            b.insert(keys.at(i), values.at(i));
            checkCount(b, i+1);
        }
    }
    catch (std::runtime_error& e){
        std::cerr << e.what() << "\n";
        return 1;
    }
    catch(...){
        std::cerr << "unexpected exception. terminating\n";
        return 1;
    }

    std::cout << "Tests for count() passed successfully!\n";
    return 0;
}
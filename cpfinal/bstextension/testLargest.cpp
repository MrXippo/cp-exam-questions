#include <iostream>
#include <vector>
#include <cstdlib>
#include "bstLargest.h"

void checkLargest(BST& b, int shouldBe)
{
    int largest  = b.largestKey();
    if ( largest != shouldBe ){
        throw std::runtime_error(
            "largestKey is " + std::to_string(largest) + " but should be " + std::to_string(shouldBe) + "\n"
        );
    }
}

int main()
{
    try{
        std::vector<int>keys = {-1, 5, -3, 7, 6, -5, 4, 8};
        std::vector<std::string>values = {"a", "b", "c", "d", "e", "f", "g", "h"};
        std::vector<int>largest = {-1, 5, 5, 7, 7, 7, 7, 8};

        BST b;
        bool gotException = false;
        std::cout << "empty tree\n";
        try{
            int dummy = b.largestKey();
        }
        catch(std::out_of_range& e){
            gotException = true;
        }
        if ( !gotException ){
            throw std::runtime_error("trying to get the largest key of an empty BST did not throw an exception");
        }

        
        for (int i=0; i<keys.size(); i++){
            std::cout << "insert " << keys.at(i) << "\n";
            b.insert(keys.at(i), values.at(i));
            checkLargest(b, largest.at(i));
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

    std::cout << "Tests for largestKey() passed successfully!\n";
    return 0;
}
//
// For your information only
//
// Changes to this file will not affect the test outcomes upon hand-in
//

#include <iostream>
#include <vector>
#include <chrono>
#include <cassert>

#include "binarysearch.h"

class StopWatch{
    public:
        void start(){
            startTime = std::chrono::system_clock::now();
        }
        double elapsedTimeSinceStart(){
            endTime = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsedTime = endTime-startTime;
            return elapsedTime.count();
        }
    private:
        std::chrono::system_clock::time_point startTime, endTime;
};

std::vector<int> createVector(int size, int factor, int offset)
{
    std::vector<int> result(size);
    for ( int i=0; i <size; i++ ){
        result.at(i) = i*factor+offset;
    }
    return result; 
}

int linearSearch(const std::vector<int>& v, int minIndex, int maxIndex, int searchValue)
{
    for ( int i=minIndex; i<=maxIndex; i++){
        if ( v.at(i) == searchValue ) return i;
    }
    return -1;
}

void compareResults(const std::vector<int>& v)
{
    for (int i=0; i<v.size(); i++){
        assert ( linearSearch(v,0,v.size()-1,v.at(i)) == binarySearch(v,0,v.size()-1,v.at(i)) );
    }
    assert ( linearSearch(v,0,v.size()-1, -v.at(v.size()-1)) == binarySearch(v,0,v.size()-1, -v.at(v.size()-1)) );
    assert ( linearSearch(v,0,v.size()-1, 2*v.at(v.size()-1)) == binarySearch(v,0,v.size()-1, 2*v.at(v.size()-1)) );
}

double runtime(const std::vector<int>& v){
    StopWatch s;
    double result = 0.0;

    int minIndex = 0;
    int maxIndex = v.size()-1;
    int index;
    for (int i=0; i<v.size(); i++){
        s.start();
        index = binarySearch(v,minIndex,maxIndex,v.at(i));
        result += s.elapsedTimeSinceStart();
    }
    result /= v.size();
    return result;
}

bool runsFastEnough(double increase, double threshold)
{
    return increase < threshold;
}

int main()
{
    srand(time(0));
    int factor = rand() % 5 + 1;
    int offset = rand() % 3 + 1;
    std::vector<int> one = createVector(1000, factor, offset);
    std::vector<int> ten = createVector(10000, factor, offset);

    compareResults(one);
    compareResults(ten);

    double tOne = 0.0;
    double tTen =  0.0;
    for (int i = 0; i < 10; i++){
        tOne += runtime(one);
        tTen += runtime(ten);
    }
    tOne /= 10;
    tTen /= 10;
    double increase = tTen / tOne;

    std::cout << "runtime increase from 1000 to 10000 elements: " << increase << " times" << std::endl;

        assert( runsFastEnough(increase, 2.5) );

    std::cout << "The implementation of binarySearch() is actually using binary search!\n";

    return 0;
}

#include <iostream>
#include "Ptest.hpp"
#include "Ptest.cpp"
#include "time.h"
using namespace std;
int main(){
    unsigned long long n=210002977;
    Ptest test(n);
    clock_t start_time=clock();
    test.aksTest();
    clock_t end_time=clock();
    cout<<"AKS algorithm "<<(double)(end_time-start_time)/CLOCKS_PER_SEC*1000<<" ms "<<endl;
    start_time=clock();
    test.trivialTest();
    end_time=clock();
    cout<<"Trivial algorithm "<<(double)(end_time-start_time)/CLOCKS_PER_SEC*1000<<" ms "<<endl;
    return 0;
}
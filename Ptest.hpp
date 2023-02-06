#ifndef _PTEST_HPP
#define _PTEST_HPP
#include <cmath>
#include <vector>
using std::vector;
using std::ceil;
using std::floor;
using std::pow;
/*Pramlity Test function here and some basic functions in number theory*/
class Ptest
{
public:
    long long num;
    Ptest(/* args */) = default;
    ~Ptest() = default;
    Ptest(long long n){
        this->num=n;
    }
    void aksTest() const;
    void lucasTest() const;
    void trivialTest() const;
    void millerRabinTest() const;
    void pepinTest() const;
};
long long gcd(long long a,long long n) 
{
    long long small=std::min(a,n);
    long long large=std::max(a,n);
    long long b=large%small;
    while (b!=0)
    {
        large=small;
        small=b;
        b=large%small;
    }
    return small;
}
unsigned int euler(unsigned int r){
    unsigned int ans=0;
    for(unsigned int i=1;i<r;i++){
        if(gcd(i,r)==1){
            ans++;
        }
    }
    return ans;
}
unsigned int findr(long long n){
    bool next=true;
    unsigned int r=1;
    while (next)
    {
        r++;
        next=false;
        if(gcd(n,r)==1){
            long long temp=1;
            for(unsigned k=1; !next and k<=pow(std::log2(n),2);k++){
                temp=temp*n;
                temp=temp%r;
                if(temp==1){
                    next=true;
                }
            }
        }
    }
    return r;
}
bool Ispower(long long n){
    bool ans=false;
    for(unsigned int b=2;b<=std::log2(n);b++){
        double temp=(double)b;
        long double a =pow(n,1/temp);
        if (a-floor(a)<=0.00000001){
            ans=true;
            break;
        }
    }
    return ans;
}
vector<unsigned int> binaryForm(long long n)
{
unsigned int temp =floor(std::log2(n));
vector<unsigned int> bin(temp+1);
bin[temp]=1;
long long remainder=n-pow(2,temp);
while (remainder>0)
{
    temp=floor(std::log2(remainder));
    bin[temp]=1;
    remainder=remainder-pow(2,temp);
}
return bin;
}
#endif
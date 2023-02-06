#include <iostream>
#include "Ptest.hpp"
#include "polynomial.hpp"
#include <algorithm>
#include <cmath>
using std::cout;
using std::endl;
using std::vector;
using std::pow;
void Ptest::aksTest() const
{
    if(!Ispower(num)){
        unsigned int r=findr(num);
        bool step2=true;
        for(unsigned int a=r;a>1;a--){
            if(gcd(a,num)>1 and gcd(a,num)<num){
                cout<<"Composite"<<endl;
                step2=false;
                break;
            }
        }
        if(step2){
            if(r>=num){
                cout<<"Prime"<<endl;
            }else{
                bool step5=true;
                unsigned int phi=euler(r);
                unsigned int k=floor(pow(phi,0.5)*std::log2(num));
                for(unsigned i=1;i<=k;i++){
                    vector<long long> v1={i,1};
                    vector<long long> v2(num%r+1);
                    v2[0]=(long long)i%num;
                    v2[num%r]=1;
                    Polynomial P2(v2,num);
                    Polynomial temp(v1,num);
                    vector<unsigned int> bin=binaryForm(num);
                    vector<Polynomial> list;
                    if (bin[0]>0){
                        list.push_back(temp);
                    }
                    for(unsigned int j=1;j<bin.size();j++){
                        temp=temp*temp;
                        if(temp.Poly.size()>r){
                            temp.modr(r);
                        }
                        Polynomial temp2(temp.Poly,num);
                        if(bin[j]>0){
                            list.push_back(temp2);
                        }
                    }
                    Polynomial P1=list[0];
                    for(unsigned int j=1;j<list.size();j++){
                        P1=P1*list[j];
                        if(P1.Poly.size()>r){
                            P1.modr(r);
                        }
                    }
                    if(!P1.Isequal(P2)){
                        step5=false;
                        cout<<i<<endl;
                        break;
                    }
                }
                if(step5){
                    cout<<"Prime"<<endl;
                }else{
                    cout<<"Composite"<<endl;
                }
            }
        }
    }else{
        cout<<"Composite"<<endl;
    }
}
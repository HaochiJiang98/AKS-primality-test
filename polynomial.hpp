#ifndef _PLOYNOMIAL_HPP
#define _POLYNOMIAL_HPP
#include <vector>
#include <algorithm>
/*Here is a polynomial over ring Zn*/
class Polynomial
{   
public:
    unsigned long long n;
    std::vector<unsigned long long> Poly;
    Polynomial() = default;
    Polynomial(std::vector<unsigned long long> P, unsigned long long num){
        this->Poly=P;
        this->n=num;
    }
    ~Polynomial() = default;
    Polynomial(Polynomial const&) = default;
    Polynomial(Polynomial &&) = default;
    Polynomial& operator =(Polynomial const&) = default;
    Polynomial& operator =(Polynomial &&) = default;
    void modr(unsigned int const &r);
    bool Isequal(Polynomial const & Q) const;
};
Polynomial operator*(Polynomial const & P,Polynomial const & Q){
    unsigned int degree1=P.Poly.size()-1;
    unsigned int degree2=Q.Poly.size()-1;
    std::vector<unsigned long long> poly2;
    unsigned long long n=P.n;
    for (unsigned int i=0;i<=degree1+degree2;i++){
        unsigned long long temp=0;
        for(int j=std::max(0,(int)(i-degree2));j<=(int)std::min(i,degree1);j++){
            temp=temp+P.Poly[j]*Q.Poly[i-j];
            if(temp>=n){
                temp=temp%n;
            }
        }
        poly2.push_back(temp);
    }
    while (poly2[poly2.size()-1]==0)
    {
        if(poly2.size()>1){
            poly2.pop_back();
        }else{
            break;
        }
    }
    
    Polynomial PQ(poly2,n);
    return PQ;
}
void Polynomial::modr(unsigned int const & r) 
{
    std::vector<unsigned long long> temp;
    unsigned int degree =Poly.size()-1;
    for(unsigned i=0;i<=degree;i++){
        if(i<=r-1){
            temp.push_back(Poly[i]);
        }else{
           unsigned int j=i%r;
           temp[j]=temp[j]+Poly[i];
           if(temp[j]>=n){
            temp[j]=temp[j]%n;
           }
        }
    }
    while (temp[temp.size()-1]==0)
    {
        if(temp.size()>1){
            temp.pop_back();
        }else{
            break;
        }
    }
    this->Poly=temp;
}
bool Polynomial::Isequal(Polynomial const & Q) const
{
bool ans=true;
unsigned int degree1 = this->Poly.size()-1;
unsigned int degree2 = Q.Poly.size()-1;
if (degree1==degree2){
    for(unsigned int i=0;i<=degree1;i++){
        if(this->Poly[i]!=Q.Poly[i]){
            ans=false;
            break;
        }
    }
}else{
    ans=false;
}
return ans;
}
#endif
#include "polynomial.h"

polynomial firstDerivative(const polynomial &other)
{
    polynomial temp;
    term newTerm;
    for(unsigned int i = 0; i < other.poly.size(); ++i)
    {
        newTerm.setTerm(
            other[i].getCoeff()*other[i].getPower() ,
            other[i].getPower()-1
            );
        temp.poly.push_back(newTerm);
    }
    temp.sort();
    return temp;
}

std::string nthDerivative(const polynomial &other, int n)
{
    std::stringstream nthderivative;
    polynomial temp = other;

    while (n > 0){
        temp = firstDerivative(temp);
        n--;
    }
    nthderivative << temp;
    return nthderivative.str();
}

polynomial operator+(const polynomial &x, const polynomial &y)
{
    polynomial temp;
    for(unsigned int i = 0; i < x.poly.size(); ++i)
        temp.poly.push_back(x[i]);
    for(unsigned int i = 0; i < y.poly.size(); ++i)
        temp.poly.push_back(y[i]);
    temp.sort();
    temp.combineTerms();
    return temp;
}

polynomial operator-(const polynomial &x, const polynomial &y)
{
    polynomial temp = x + y;
    return temp;
}

polynomial operator*(const polynomial &x, const polynomial &y)
{
    polynomial temp;
    for(unsigned int i = 0; i < x.poly.size(); ++i)
        for(unsigned int j = 0; j < y.poly.size(); ++j)
            temp.poly.push_back(x[i] * y[j]);
    temp.sort();
    temp.combineTerms();
    return temp;
}

fraction evaluate(const fraction &frac, polynomial &y)
{
    fraction temp = 0;
    for(unsigned int i = 0; i < y.poly.size(); ++i)
    {
        temp += y.poly[i].evaluate(frac);
    }
    return temp;
}

//polynomial operator/(const polynomial &x, const polynomial &y)
//{
//    //do this with synthetic division.... hint...
//    //Also, does polynomial need to be changed to support division??
//}

std::ostream& operator<<(std::ostream& out, const polynomial &other)
{
    for(unsigned int i = 0; i < other.poly.size(); ++i)
    {
        out<<other[i] <<" ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, polynomial &p)
{
    std::stringstream aa;
    std::string possiblePoly;
    std::string possibleTerm;
    term temp;
    getline(in, possiblePoly);
    std::stringstream ss(possiblePoly);
    while(ss>>possibleTerm)
    {
        aa<<possibleTerm;
        aa>>temp;
        aa.clear();
        p.poly.push_back(temp);
    }
    p.sort();
    p.combineTerms();
    return in;
}

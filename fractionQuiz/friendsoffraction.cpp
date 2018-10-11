#include "fraction.h"

std::ostream& operator<<(std::ostream& out, const fraction &frac)
{
    out<<frac.num;
    if(frac.denom != 1)
         out<<"/"<<frac.denom;
    return out;
}

std::istream& operator>>(std::istream& in, fraction &frac)
{
    char junk;
    std::stringstream ss;
    std::string possibleFraction;
    std::cout<<"Starting operator>>"<<std::endl;
    if(&in == &std::cin) //This means that the program is reading from the console
    {
        if(in>>possibleFraction)
        {
            std::cout<<"You entered: "<<possibleFraction<<std::endl;
            ss<<possibleFraction;
            std::cout<<"the first thing in the stringstream is: "<<(char)ss.peek()<<std::endl;
            ss>>frac;
            std::cout<<"You got: "<<frac<<std::endl;
        }
    }
    else//Let's assume everything else is a file (for now)
    {
        std::cout<<"Reading from a stream other than cin"<<std::endl;
        if(in>>frac.num)
        {
            if(in.peek() == '/')
               in>>junk>>frac.denom;
            frac.reduce();
        }
        else
            std::cout<<"Hit End of File"<<std::endl;
    }
    return in;
}

fraction operator+(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom + y.num  * x.denom,
        denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator-(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom - y.num  * x.denom,
        denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator*(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.num,
        denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator/(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom,
        denom = x.denom * y.num;
    result.setValue(num,denom);
    return result;
}


bool operator==(const fraction &x,const fraction &y)
{
    return x.num * y.denom == y.num * x.denom;
}

bool operator>=(const fraction &x,const fraction &y)
{
    return x.num * y.denom >= y.num * x.denom;
}

bool operator<=(const fraction &x,const fraction &y)
{
    return x.num * y.denom <= y.num * x.denom;
}

bool operator!=(const fraction &x,const fraction &y)
{
    return x.num * y.denom != y.num * x.denom;
}

bool operator<(const fraction &x,const fraction &y)
{
    return x.num * y.denom < y.num * x.denom;
}

bool operator>(const fraction &x,const fraction &y)
{
    return x.num * y.denom > y.num * x.denom;
}

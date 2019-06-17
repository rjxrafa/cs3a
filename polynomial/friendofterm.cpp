#include "term.h"

term operator+(const term &x, const term &y)
{
    if(x.power == y.power)
    {
        term temp(x.coeff+y.coeff, x.power);
        return temp;
    }
    else
    {
        std::cout<< "Error" << std::endl;
        exit(1);
    }
}

term operator-(const term &x, const term &y)
{
    if(x.power == y.power)
    {
        term temp(x.coeff - y.coeff, x.power);
        return temp;
    }
    else
    {
        std::cout<< "Error" << std::endl;
        exit(1);
    }
}

term operator*(const term &x, const term &y)
{
    term temp(x.coeff*y.coeff, x.power + y.power);
    return temp;
}

term operator/(const term &x, const term &y)
{
    term temp(x.coeff/y.coeff, x.power - y.power);
    return temp;
}


bool operator==(const term &x, const term &y)
{
    return x.power == y.power && x.coeff == y.coeff;
}


bool operator!=(const term &x, const term &y)
{
    return x.power != y.power || x.coeff != y.coeff;
}

bool operator%=(const term &x, const term &y)
{
    return x.power == y.power;
}


bool operator>=(const term &x, const term &y)
{
    return !(x < y);
}


bool operator<=(const term &x, const term &y)
{
    return !(x > y);
}


bool operator>(const term &x, const term &y)
{
    if(x.power == y.power)
        return x.coeff > y.coeff;
    else
        return x.power > y.power;
}


bool operator<(const term &x, const term &y)
{
    if(x.power == y.power)
        return x.coeff < y.coeff;
    else
        return x.power < y.power;
}

std::ostream& operator<<(std::ostream& out, const term& t)
{
    if (t.coeff != 0)
    {
        if (t.coeff != 1) // prints out coeff
        {
            out << t.coeff;
        }

        if (t.coeff == 1 && t.power == 0) // '1X^0 = 1' prints out 1 by itself
            out << t.coeff;

        if (t.power != 0)
        {
            out << t.variable;
            if (t.power != 1)
                out << '^' << t.power;
        }

    }
    else
    {
        out << '0';
    }

    return out;
}


std::istream& operator>>(std::istream& in, term& t)
{

    char junk;
    std::stringstream ss;
    std::string possibleTerm;
    if(&in == &std::cin)
    {
        if(in>>possibleTerm)
        {
            ss<<possibleTerm;
            ss>>t;
        }
    }
    // this sets a flag for variable to know if there is a coefficient
    else
    {
        bool cinflag = true;

        if (in>>t.coeff)
            cinflag = false; // this sets a flag for variable to know if there is a coefficient

        t.power = 0;

        if(isalpha(in.peek())) //only execute when variable exists
        {
            in>>t.variable;
            t.coeff+=cinflag;
            t.power = 1;
        }

        if(in.peek() == '^') // only execute when carat exists
            in>>junk>>t.power;
//            std::cout<<"Hit End of File"<<std::endl;
    }
    return in;
}

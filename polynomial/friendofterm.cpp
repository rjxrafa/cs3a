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
//    std::cout << " t << was fired" << std::endl;


    out<<t.coeff<<t.variable<<'^'<<t.power;
//    if(t.power != 0)
//    {
//        if(t.coeff == 0)
//        {
//            out << t.coeff;
//        }
//        else if(t.coeff == 1)
//        {
//            out << t.variable;
//            if(t.power != 1)
//            {
//                out<< '^' << t.power;
//            }
//        }
//        else if(t.coeff != 0 || t.coeff != 1)
//        {
//            out << t.coeff << t.variable << '^' << t.power;
//        }
//    }
//    else
//    {
//        out << t.coeff;
//    }
    return out;

//    if (t.coeff == 0)
//           out << t.coeff;
//       else
//       {
//           if (t.coeff != 1)
//           { //print out only the variable
//               out << t.coeff;
//               if (t.power != 0)
//               { // print out variable only if power is not 0
//                   out<< t.variable;
//                   if(t.power != 1)
//                   {   // print out power only if it is not 1
//                       out << '^' << t.power;
//                   }
//               }
//           }
//           else
//           { // just print out 1
//               out << t.coeff;
//           }
//       }
//       return out;
}


std::istream& operator>>(std::istream& in, term& t)
{
//    std::cout << " t >> was fired" << std::endl;
//    std::cout << t << std::endl;
    char junk;
    std::stringstream ss;
    std::string possibleTerm;
    if(&in == &std::cin) //This means that the program is reading from the console
    {
        if(in>>possibleTerm)
        {
            ss<<possibleTerm;
//            std::cout << "This is the possible term: "<<possibleTerm << std::endl;
            ss>>t;
        }
    }
    else//Let's assume everything else is a file (for now)
    {
//        std::cout << " t2 >> was fired" << std::endl;
        if(in>>t.coeff)
        {
            if(in.peek() == 'X')
               in>>t.variable>>junk>>t.power;
//            std::cout << "This is t: "<< t << std::endl;
        }
        else
            std::cout<<"Hit End of File"<<std::endl;
    }
    return in;
}

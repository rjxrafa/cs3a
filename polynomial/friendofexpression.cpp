#include "expression.h"
#include <string>

std::ostream& operator<<(std::ostream& out, const expression &e)
{
    for(unsigned int i = 0; i < 26; ++i)
    {
        out<< char(i+65) << "=" << e.library[i] <<"\n";
    }
    return out;
}

std::istream& operator>>(std::istream& in, expression &e)
{
    std::string line, possiblyPoly;
    std::stringstream ss, ss_poly;
    polynomial poly_temp;
    char junk;
    char index;

    e.clearLibrary();
    for(unsigned int i = 0; i < 26; ++i)
    {
        //grabs a line
        getline(in, line);
        //puts in stream
        ss << line;
        //grabs index
        ss >> index;
        index = toupper(index);
        //throws away equals
        ss >> junk;
        //saves expresion as element of library(holds polynomials)
        ss >> e.library[int(index-65)];
        ss.clear();

    }


    return in;
}

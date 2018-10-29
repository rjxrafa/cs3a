#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "polynomial.h"
#include <map>

class expression
{

    enum UserChoice { LET,
                      EVAL,
                      PRINT,
                      LOAD,
                      SAVE };

    std::map<std::string, expression::UserChoice> map_StringValues;

    public:
        expression();
        ~expression();            
        void choice(const std::string &input, const std::string &argument); // this should access the private functions
        void setFunction(int index);
        polynomial getFunction(int index);

    private:
        polynomial library[26];
        void let(){std::cout << "LET EXECUTED";};
        void eval(){std::cout << "EVAL EXECUTED";};
        void print(){std::cout << "PRINT EXECUTED";};
        void load(){std::cout << "LOAD EXECUTED";};
        void save(const std::string arg);
        

};


#endif // EXPRESSION_H

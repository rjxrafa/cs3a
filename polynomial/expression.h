#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "polynomial.h"
#include <map>

class expression
{

    enum commands { ERROR, LET, EVAL, PRINT, LOAD, SAVE };
    std::map<std::string, expression::commands> commandMap;
    void initializeMap();

    public:
        expression();
        ~expression();            
        void choice(const std::string &input, const std::string &argument); // this should access the private functions
        void setFunction(int index);
        polynomial getFunction(int index);

    private:
        polynomial library[26];
        void let(const std::string &arg);
        void eval(){std::cout << "EVAL EXECUTED";};
        void print(const std::string &arg);
        void load(){std::cout << "LOAD EXECUTED";};
        void save(const std::string &arg);

};


#endif // EXPRESSION_H

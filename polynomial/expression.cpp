#include "expression.h"
#include "string.h"

expression::expression()
{ // constructor definition
    for (unsigned int i = 0; i < 26; ++i)
    {
        term a(0,0);                        
        polynomial b(a);
        library[i] = b;
    }

    map_StringValues["let"] = LET;
    map_StringValues["eval"] = EVAL;
    map_StringValues["print"] = PRINT;
    map_StringValues["load"] = LOAD;
    map_StringValues["save"] = SAVE;
}

expression::~expression()
{
    for (unsigned int i = 0; i < 26; ++i)
    {
        term a(0,0);
        polynomial b(a);
        library[i] = b;
    }
};

polynomial expression::getFunction(int index)
{
    std::cout << library[index];
}

void expression::setFunction(int index)
{ // set function
    term temp(0,0);
    polynomial a(temp);
    std::cin >> a;
    library[index] = a;
}

void expression::choice(const std::string &input,
                        const std::string &argument) {
    std:: string temp_str;

    for (unsigned int i = 0; i < input.length(); ++i)
    {
        temp_str += tolower(input[i]);
    }

    switch(map_StringValues[temp_str])
    {
        case LET:
            let();
            break;
            
        case EVAL:
            eval();
            break;

        case PRINT:
            break;

        case LOAD:
            break;

        case SAVE:
            break;

        default:
            exit(1); // replace with throw error
    }
}


void expression::save(const std::string arg) {
//    //open object with arg name
//
//    ostream output;
//
//    std::ostream << library[2];

}


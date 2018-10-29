#include "expression.h"

expression::expression()
{ // constructor definition
    for (unsigned int i = 0; i < 26; ++i)
    {
        term a(0,0);                        
        polynomial b(a);
        library[i] = b;
    }
    initializeMap();
    term a(3,3);
    library[0].addTerm(a);
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
                        const std::string &argument)
{
    std:: string temp_str;

    for (unsigned int i = 0; i < input.length(); ++i)
    {
        temp_str += tolower(input[i]);
    }

    switch(commandMap[temp_str])
    {
        case LET:
            let(argument);
            break;

        case EVAL:
            eval();
            break;

        case PRINT:
            print(argument);
            break;

        case LOAD:
            load();
            break;

        case SAVE:
//            save(argument);
            break;

        default:
            std::cout << "no argument found";
            exit(1); // replace with throw error
    }
}

//void expression::save(const std::string arg)
//{
////    //open object with arg name
////
////    ostream output;
////
////    std::ostream << library[2];
//
//}

void expression::initializeMap() {
    commandMap["let"] = LET;
    commandMap["eval"] = EVAL;
    commandMap["print"] = PRINT;
    commandMap["load"] = LOAD;
    commandMap["save"] = SAVE;
}

void expression::let(const std::string &arg) {
    std::stringstream temp;
    char index;
    temp >> index;
    std::cin >> library[index];
}

void expression::print(const std::string &arg) {
    // if arg is greater than one char, need to throw error
    std::cout << arg[0] << " = " << library[toupper(arg[0])-65];
}




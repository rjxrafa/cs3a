#include <iostream>
#include "mystack.h"
#include <string>

using namespace std;

string processLine(const string &line);
bool getInput(string &line);
bool palindrome(const string &line);

int main()
{
    string line, toCheck, isNot;
    try
    {
        while(getInput(line))
        {
            toCheck = processLine(line);
            isNot = line + " is"+ (palindrome(toCheck) ? " " : " not ") + "a palindrome";
            cout<<isNot<<endl;
        }
    }
    catch (MY_STACK_ERRORS e)
    {
        switch(e)
        {
            case STACK_EMPTY : cout<<"Stack empty error occurred"<<endl;
                               break;
           case STACK_FULL   : cout<<"Stack full error occurred"<<endl;
                               break;
         case STACK_BAD_SIZE : cout<<"Bad stack size error occurred"<<endl;
        }
    }
    return 0;
}


bool getInput(string &line)
{
    cout<<"Input: ";
    getline(cin, line);
    return !line.empty();
}


string processLine(const string &line)
{
    string result;
    for(unsigned int i = 0; i < line.size(); ++i)
        if(isalpha(line[i]) || isdigit(line[i]))
            result += toupper(line[i]);
    return result;
}


bool palindrome(const string &line)
{
    string reversed;
    myStack<char> toReverse;
    for(unsigned int i = 0; i < line.size(); ++i)
        toReverse.push(line[i]);
    while(!toReverse.empty())
    {
        reversed += toReverse.top();
        toReverse.pop();
    }
    return reversed == line;
}

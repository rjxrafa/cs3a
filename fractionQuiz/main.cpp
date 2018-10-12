#include <iostream>
#include "fraction.h"
#include "fractionQuiz.h"

using namespace std;

void getInput(string title, fraction &frac);
void output(fraction x, fraction y, char op);

int main()
{
    fractionQuiz a;

    return 0;
}


void getInput(string title, fraction &frac)
{
    cout<<title;
    cin>>frac;
    cout<<"You entered: "<<frac<<endl;
}

void output(fraction x, fraction y, char op)
{
    fraction z;
    switch(op)
    {
        case '+' : z = x + y;
                   break;
        case '-' : z = x - y;
                   break;
        case '*' : z = x * y;
                   break;
        case '/' : z = x / y;
    }
    cout<<x<<" "<<op<<" "<<y<<" = "<<z<<endl;
}

#include <iostream>
#include "fraction.h"

using namespace std;

void getInput(string title, fraction &frac);
void output(fraction x, fraction y, char op);

int main()
{
    fraction x, y;
    getInput("Please enter your first fraction: ", x);
    getInput("Please enter your second fraction: ", y);
    output(x,y,'+');
    output(x,y,'-');
    output(x,y,'*');
    output(x,y,'/');
    //And now for something completely different....
    output(3,y,'+');
    output(3,y,'-');
    output(3,y,'*');
    output(3,y,'/');
    output(x,2.8888888888,'+');
    output(x,2.8888888888,'-');
    output(x,2.8888888888,'*');
    output(x,2.8888888888,'/');
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

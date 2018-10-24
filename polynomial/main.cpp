#include <iostream>
#include <string>
#include "fraction.h"
#include "term.h"
#include "polynomial.h"

using namespace std;

void getFrac(string title, fraction &frac);
void output(fraction x, fraction y, char op);
void getTerm(string title, term &t);
void getPoly(string title, polynomial &p);
void evaluatePoly(string title, polynomial&p);
bool question(string title);

int main()
{
    do
    {
        polynomial c;
        getPoly("Please enter your first polynomial, term by term, (z to end): ", c);
        cout << "This is c: "<< c << endl;
        evaluatePoly("For which value would you like to evaluate poly: ", c);

//        cout << firstDerivative(c);
        cout << nthDerivative(c,4);

    }while(question("Do you want to do this again? "));


    return 0;
}

void getPoly(string title, polynomial &p)
{
    cout<<title;
    cin>>p;
    cout<<"You entered: "<<p<<endl;
}

void evaluatePoly(string title, polynomial &p)
{
    cout << title;
    fraction input;
    getFrac("",input);
    fraction temp;
    temp = evaluate(input, p);
    cout << "The final value is: "<< temp;
    cout << endl;

}

//void getTerm(string title, term &t)
//{
//    cout<<title;
//    cin>>t;
//    cout<<"You entered: "<<t<<endl;
//}

void getFrac(string title, fraction &frac)
{
    cout<<title;
    cin>>frac;
    cout<<"You entered: "<<frac<<endl;
}

//void output(fraction x, fraction y, char op)
//{
//    fraction z;
//    switch(op)
//    {
//        case '+' : z = x + y;
//                   break;
//        case '-' : z = x - y;
//                   break;
//        case '*' : z = x * y;
//                   break;
//        case '/' : z = x / y;
//    }
//    cout<<x<<" "<<op<<" "<<y<<" = "<<z<<endl;
//}

void newLine()
{
    char symbol;
    do
    {
        cin.get(symbol);
    } while (symbol != '\n');
}

bool question(string title)
{
    string border(50, '*');
    string line;
    cout<<title;
    cin >> line;
    newLine();
    cout << border << endl;
    return toupper(line[0]) == 'Y';
}

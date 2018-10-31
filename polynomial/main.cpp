/*Test #1. "Calculate", a command line Algebraic Expression calculator that will accept up to 26
 * arbitraily long algebraic expressions composed of terms
 *
 * Written By Edgar Flores and Rafael Betita
 * */

#include <iostream>
#include <fstream>
#include <sstream>
#include "fraction.h"
#include "term.h"
#include "polynomial.h"
#include "expression.h"

using namespace std;

void introduction();
//brief intro to the program

bool checkCL(int count);
//checks if there are any arguments in the command line, returns flag if true or false

void getInput(istream& in, expression&a, char *commands[],
              int count, bool record = false, bool execute = false);
//single input function for reading from file or terminal

void recordFile(std::string filename, string userInput);
//opens file, records given input, closes file

void executeFile(string filename, string &userInput, int&count);
//opens file, assigns command from file to userInput, closes file

void newLine();
//new line function

bool question(string title);
//ask a questions, returns a true or false answer


int main(int argc, char *argv[])
{
    introduction();
    bool CL = checkCL(argc);
    do
    {
        expression a;
        ifstream in;

        if(CL)
            getInput(in, a, argv, argc); //if parameters in command line, we're reading from a file
        else
            getInput(cin, a, argv, argc); //read straight from the terminal

    } while(question("Do you want to do this again? "));
    return 0;
}

void introduction()
{
    string border(80, '*');

    cout << border << endl;
    cout << "This Program is called Calculate and it is an polynomial\nCalculator that that will accept up to 26 algebraic polynomials." << endl;
    cout << border << endl;
}

bool checkCL(int count)
{
    //if command line containes 1 or 2 parameters (excluding the name of the program)
    if(count == 2 || count == 3)
    {
        return true;
    }
    //if command line contains more than 2 parameters, error out
    else if(count > 3)
    {
        cout << "Error, there are more than 2 parameters on the command line \n"
             << "The program will now exit \n";
        exit(1);
    }
    //if no command line arguments, return false
    return false;
}

void getInput(istream& in, expression& a, char *commands[], int count,
              const bool record, const bool execute)
{
    string userInput;
    string arg;

    int comCount=0;
    //reading from terminal
    if(&in == &cin)
    {
        while(1)
        {
            cout << "\nCOMMAND: ";

            //if execute was flagged
            if(execute)
            {
                //open file and reads from it, inputs line into userInput, closes file, this will be repeated
                //until the end.
                executeFile(commands[2], userInput, comCount);
            }
            else
                // Get user input from the command line
                getline(cin, userInput);

            stringstream user_ss(userInput);

            //if record was flagged, record every following input
            if(record)
            {
                recordFile(commands[2], userInput);
            }
            //if size of string is 0, (enter was pressed), terminate program
            if (userInput.size() == 0)
            {
                cout << "See ya!" << endl;
                exit(1);
            }

            //if second element of string is equals sign, go this path (ex. F=G+H, F=G'')
            if (userInput[1]=='=')
            {
                char index, b, c;
                int deriv_count(0);

                index = userInput[0]; // takes initial element as variable for poly a
                b = userInput[2]; // takes 3rd element as letter for poly b

                //for derivative calculator (ex F=G')
                if (userInput[3] == '\'')
                {
                    //adds 1 to deriv count for every '
                    for(unsigned int i = 3; i <= userInput.length() && userInput[i] == '\''; ++i)
                    {
                        deriv_count++;
                    }

                    //calculates nth deriv
                    a.nthDerivative(index-65, b-65, deriv_count);
                }
                //for expresison calculator (ex F=G+H)
                else
                {
                    c=userInput[4];

                    //switch that depends on operator
                    switch (userInput[3])
                    {
                    case '+':
                        a.add(index-65, b-65, c-65);
                        break;
                    case '-':
                        a.subtract(index-65, b-65, c-65);
                        break;
                    case '*':
                        a.multiply(index-65, b-65, c-65);
                        break;
                    case '/':
                        break;
                    default:
                        cout << "Error " << endl;
                        exit(1);
                    }
                }
            }
            //if a command preceeds the expression (ex. Let F=2X+4)
            else
            {
                //take command
                user_ss >> userInput;
                //take expression
                user_ss >> arg;
                //passes it to choice function
                a.choice(userInput, arg);
            }

        }
    }
    //if there are arguments in the command line
    else
    {
        string filename;

        //one argument after the name of the program
        if(count == 2)
        {
            cout << "There is one parameter in the command line" << endl;

            //load file associated with this parameter
            filename = commands[1];

            if(filename == "/h" || filename == "/?")
            {
                cout << "It seems that you need help, "
                        "you must include the name of the file that you wish to load" << endl;
                exit(1);
            }

            //load expressions from file chosen
            a.choice("load", filename);

            //goes back to reading user input from terminal after loading expressions
            getInput(cin, a, commands, count, false, false);

        }
        //two arguemnts after the name of the program
        else if(count == 3)
        {
            ifstream file;
            string EXorRE;

            cout <<"There are two parameters in the command line" << endl;

            //first argument is a command, either execute or record
            EXorRE = commands[1];

            for (unsigned int i = 0; i < EXorRE.length(); ++i) // converts to uppercase
                EXorRE[i] = toupper(EXorRE[i]);


            //second argument is a script file
            filename = commands[2];
            if (EXorRE == "EXECUTE")
            {
                cout << "Executing File" << endl;
                getInput(cin, a, commands, count, false, true);

            if (EXorRE == "EXECUTE")
            {
                cout << "Executing File" << endl;
                //activates execute flag, treats the file commands as if they were input by a user
                getInput(cin, a, commands, count, false, true);

            }
            else if (EXorRE == "RECORD")
            {
                cout << "Recording File" << endl;
                //activates record flag, records user input commands into the file given by the commandline
                getInput(cin, a, commands, count, true, false);
            }

        }
    }
}

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

void recordFile(std::string filename, string userInput)
{ // Saves current expression library to file while checking for existing file
    ofstream out;
    std::ifstream in;

    if(filename.find('.') > filename.size())
        filename += ".spt";

    out.open(filename,ios_base::app);

    out << userInput << endl;

    out.close();
}

void executeFile(string filename, string &userInput, int &count)
{
    //open input file, keep grabbing a line from the file
    ifstream in;
    string line;
    if(filename.find('.') > filename.size())
        filename += ".spt";

    in.open(filename);

    for(int i = 0; i < count; i++)
    {
        getline(in, line);
    }
    getline(in, userInput);
    count++;
    in.close();

}

/* Sample Program
********************************************************************************
This Program is called Calculate and it is an polynomial
Calculator that that will accept up to 26 algebraic polynomials.
********************************************************************************

COMMAND: display

A =
B =
C =
D =
E =
F =
G =
H =
I =
J =
K =
L =
M =
N =
O =
P =
Q =
R =
S =
T =
U =
V =
W =
X =
Y =
Z =


COMMAND: load expressions
The file "expressions.exp" was loaded!

COMMAND: display

A = 3X^3
B = 3X^4+2X+3
C = 3X^4+3X^3+2X+3
D = 2X
E = 10X^22
F = 8X^3+2X+7
G = -3X^3
H = -4X^4
I = 8X^22
J =
K = 9X^6+5X^4-3X^3+2X
L =
M =
N =
O = 3X^3
P = 9X^3
Q = 12X^3
R = 72X
S =
T =
U = 2X^2
V =
W =
X =
Y =
Z = 5X^4


COMMAND: L=I'

L=176X^21

COMMAND: display

A = 3X^3
B = 3X^4+2X+3
C = 3X^4+3X^3+2X+3
D = 2X
E = 10X^22
F = 8X^3+2X+7
G = -3X^3
H = -4X^4
I = 8X^22
J =
K = 9X^6+5X^4-3X^3+2X
L = 176X^21
M =
N =
O = 3X^3
P = 9X^3
Q = 12X^3
R = 72X
S =
T =
U = 2X^2
V =
W =
X =
Y =
Z = 5X^4


COMMAND: N=O+P

N=12X^3

COMMAND: display

A = 3X^3
B = 3X^4+2X+3
C = 3X^4+3X^3+2X+3
D = 2X
E = 10X^22
F = 8X^3+2X+7
G = -3X^3
H = -4X^4
I = 8X^22
J =
K = 9X^6+5X^4-3X^3+2X
L = 176X^21
M =
N = 12X^3
O = 3X^3
P = 9X^3
Q = 12X^3
R = 72X
S =
T =
U = 2X^2
V =
W =
X =
Y =
Z = 5X^4


COMMAND: save expressions
That file exists!!
Do you wish to overwrite it?
yes
Save successful.

COMMAND: print Z
Z = 5X^4

COMMAND:
See ya!
Press <RETURN> to close this window...

*/

/*
 * We, Edgar Flores and Rafael Betita do hereby certify that we have derived no assistance for this project or examination from any sources whatever, whether oral, written, or in print.
 * We also understand that if it is found that we have received unauthorized assistance, then we will receive a failing grade.

Definitions of plagiarism and cheating influenced in part by the academic honesty policies of Las Positas College (Livermore California), Ohlone College (Fremont California),
the California Maritime Academy (Vallejo California), the University of California at Los Angeles, the University of Virgina’s Student Honor System, and Hamilton College (Clinton New York); by "What is Plagiarism,"
Turnitin.com Oakland: iParadigms, 2003. 10 Feb. 2004 ; and by Robert A. Harris, The Plagiarism Handbook (Los Angeles: Pyrczak Publishing, 2001)
*/

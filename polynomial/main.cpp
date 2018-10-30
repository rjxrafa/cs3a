#include <iostream>
#include <fstream>
#include <sstream>
#include "fraction.h"
#include "term.h"
#include "polynomial.h"
#include "expression.h"

using namespace std;

void introduction();
bool checkCL(int count);
void getInput(istream& in, expression&a, char *commands[],
              int count, bool record = false, bool execute = false);
bool question(string title);
void introduction();
void recordFile(std::string filename, string userInput);
void executeFile(string filename, string &userInput, int&count);

int main(int argc, char *argv[])
{
    introduction();
    bool CL = checkCL(argc);
    vector<string> commandOutput;

    do
    {
        expression a;
        ifstream in;

        if(CL)
            getInput(in, a, argv, argc); //if parameters in command line, we're reading from a file
        else
            getInput(cin, a, argv, argc);//read straight from the terminal

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
    //if command line contains more than 2 parameters
    else if(count > 3)
    {
        cout << "Error, there are more than 2 parameters on the command line \n"
             << "The program will now exit \n";
        exit(1);
    }
    return false;
}

void getInput(istream& in, expression& a, char *commands[], int count,
              const bool record, const bool execute)
{
    string userInput;

    int count2=0;
    if(&in == &cin) //read from terminal, no parameters in command line
    {
        while(1)
        {
            cout << "\nCOMMAND: ";
            if(execute)
            {
                //open file and read from it, input line into userInput, repeat this until we reach the end.
                executeFile(commands[2], userInput, count2);
            }
            else
                getline(cin, userInput); // Get user input as one full string
            stringstream user_ss(userInput);
            string arg;
//            commandOutput.push

            if(record)
            {
                recordFile(commands[2], userInput);
            }

            //remove spaces

            if (userInput.size() == 0)
            {
                cout << "See ya!" << endl;
                exit(1);
            }
            if (userInput[1]=='=')
            {
                cout <<"op = fired" << endl;
                char index, b, c, op;
                int deriv_count(0);

                index = userInput[0]; // takes initial argument as a
                b = userInput[2]; // takes 2nd expression as b

                if (userInput[3] == '\'')
                {
                    for(unsigned int i = 3; i < userInput.length() && userInput[i] == '\''; ++i)
                    {
                        deriv_count++;
                    }

                    a.nthDerivative(index-65, b-65, deriv_count);
                }
                else
                {
                    c=userInput[4];

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
            else
            {
                user_ss >> userInput;
                // If temp has greater than 1 size, it is likely a command
                user_ss >> arg; // Proceed to take another argument
                a.choice(userInput, arg); // Pass both vars into choice menuF
            }

        }
    }
    else
    {
        string filename;

        //one parameter after the name of the program
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

            a.choice("load", filename);

            getInput(cin, a, commands, count, false, false);

        }
        else if(count == 3)
        {
            ifstream file;
            string EXorRE;

            cout <<"There are two parameters in the command line" << endl;

            //first argument is a command, either execute or record
            EXorRE = commands[1];

            for (unsigned int i = 0; i < EXorRE.length(); ++i) // converts to uppercase
                EXorRE[i] = toupper(EXorRE[i]);


            filename = commands[2];
            if (EXorRE == "EXECUTE")
            {
                cout << "Executing File" << endl;
                getInput(cin, a, commands, count, false, true);

            }
            else if (EXorRE == "RECORD")
            {
                cout << "Recording File" << endl;
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
    cout << "Write Fired" << endl;
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

*/

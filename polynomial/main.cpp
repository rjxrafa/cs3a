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
void getInput(istream& in, expression&a, char *commands[], int count);
bool question(string title);
void introduction();

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
            getInput(cin, a, argv, argc); //read from terminal

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

void getInput(istream& in, expression& a, char *commands[], int count) //expression will be in here as well
{
    ifstream file;
    stringstream ss;
    string line, filename, EXorRE, userInput;
    polynomial input;

    if(&in == &cin) //read from terminal, no parameters in command line
    {
        while(1)
        {
            cout << "\nCOMMAND: ";
            getline(cin, userInput); // Get user input as one full string
            stringstream user_ss(userInput);
            string temp, arg;

            user_ss >> temp; // Get first argument from the stringstream

            //remove spaces

            if (temp.size() > 1)
            { // If temp has greater than 1 size, it is likely a command
                user_ss >> arg; // Proceed to take another argument
                a.choice(temp, arg); // Pass both vars into choice menu
            }

            if (temp.size() == 1)
            {
                char a, b, c, op;
                int deriv_count(0);

                a = temp[0]; // takes initial argument as a
                user_ss >> op; // takes '=' as junk
                user_ss >> b; // takes 2nd expression as b


                if (user_ss.peek() == '\'')
                {
                    while (user_ss.peek() == '\'')
                    {
                        deriv_count++;
                        user_ss >> op;

                    }
                    cout <<deriv_count<< endl;
                }
                else
                {
                    user_ss >> op;
                    user_ss >> c;
                    cout <<  "a: " << a
                          << "\nb: " << b
                         << "\nop: " << op
                         << "\nc: " << c << endl;
                }
            }
//
//            if (temp.size() == 0)
//            {
//                cout << "See ya!" << endl;
//                exit(1);
//            }




            // If

            // If
//            cout << userInput;

//            string temp, arg;
//            cin >> temp;
//            cin >> arg;

        }

    }
    else
    {
        //one parameter after the name of the program
        if(count == 2)
        {
            cout << "There is one parameter in the command line" << endl;

            //load file associated with this parameter
            filename = commands[1];

            if(filename == "/h" || filename == "/?")
            {
                cout << "It seems that you need help, you must include the name of the file that you wish to load" << endl;
                exit(1);
            }

            a.choice("save", filename);


        }
        else if(count == 3)
        {
            cout <<"There are two parameters in the command line" << endl;

            //first argument is a command, either execute or record
            EXorRE = commands[1];

            //this is the name of a script file, which is composed of commands
            filename = commands[2];

            //add .spt to file name if not found
            if(filename.find('.') > filename.size())
                filename += ".spt";
            file.open(filename);
            if((in.fail()))
            {
                cout << "The input file does not exist" << endl;
                exit(1);
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

/* Sample Program



*/

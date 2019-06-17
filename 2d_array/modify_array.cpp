//
// Created by rafab on 6/16/2019.
//

/*
Title:
     Assignment II - Two Dimension Arrays of Variable Length (Pt.1)

Authors:
     Rafael Betita

Modified:
     September 12, 2018

Description:
     Fix the program, doubleDimensionArray, done in class  on 9/5/18 so that the
     program does not de-reference a null pointer as well as the other "errors"
     that are in the program.
*/

#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

int getInput(string title, int min = 1, int max = 32767);
bool load2Darray(int **&list, int *row, int *col);
bool create2Darray(int **&list, int row = 10, int col = 10);
void nuke2Darray(int **&list, int row = 10, int col = 10);
void randomize2Darray(int **list, int row, int col, int min, int max);
void display(ostream &where, int **list, int row, int col);
void writeToFile(int **list, int row, int col);
bool again(string title);
void editArray(int **&list, int row, int col);
void modifyCell(int **&list, int row, int col, int c, int r);

int main()
{

    int row, col;
    srand(time(NULL));
    do
    {
        int **list;
        load2Darray(list, &row, &col);
        display(cout,list, row, col);

        if (again("\nDo you want to edit the array?"))
            editArray(list,row,col);

        nuke2Darray(list,row,col);


    }while(again("\nWould you like to do this again? "));
    return 0;
}


int getInput(string title, int min, int max)
{
    bool repeat;
    int input;
    do
    {
        repeat = false;
        cout<<title;
        while (!(cin>>input))
        {
            cin.clear();
            cin.ignore(256,'\n');
            cout << "\nInvalid entry, try again: ";
        }

        if((repeat = input < min || input > max))
            cout<<"Your input of "<<input<<" is outside of"
                <<" the acceptable input range of "<<min<<" to "<<max
                <<endl<<"You will have to re-enter your input"<<endl;
    }while(repeat);
    return input;
}

bool create2Darray(int **&list, int row, int col)
{
    if(row < 1 || col < 1)
        return false;
    list = new int* [row];
    for(unsigned int i = 0; i < row; ++i) // THIS HAS TO BE ROW
        list[i] = new int[col];
    return true;
}

void nuke2Darray(int **&list, int row, int col)
{
    for(unsigned int r = 0; r < row; ++r)
    {
        for(unsigned int c = 0; c < col; ++c)
            list[r][c] = 0;
        delete [] list[r];
        list[r] = NULL;
    }
    delete [] list;
    list = NULL;
}

void randomize2Darray(int **list, int row, int col, int min, int max)
{
    for(unsigned int r = 0; r < row; ++r)
        for(unsigned int c = 0; c < col; ++c)
            *(*(list+r)+c) = (rand()%(max-min+1))+min;
//            list[r][c] = (rand()%(max-min+1))+min;

}

void display(ostream &where, int **list, int row, int col)
{
    int min = **list;
    int max = **list;
    for (unsigned int r = 0; r < row; ++r)
        for (unsigned int c = 0; c < col; ++c)
        {
            if (max < *(*(list+r)+c))
                max = *(*(list+r)+c);
            if (min > *(*(list+r)+c))
                min = *(*(list+r)+c);
        }

    int largest = abs(min) > abs(max) ? abs(min) : abs(max),
            neg = min < 0 || max < 0 ? 1 : 0,
            digits = log10(largest) + 3 + neg;

    if (min == 0 && max == 0)
        digits = 3;

    where<<"\nRows: "<<row<<endl
         <<"Cols: "<<col<<endl;

    for(unsigned int r = 0; r < row; ++r)
    {
//        cout << "Row " << r+1 << setw(digits);
        for(unsigned int c = 0; c < col; ++c)
            where<< setw(digits) << list[r][c];
        where<<endl;
    }
}

void writeToFile(int **list, int row, int col)
{
    ifstream in;
    ofstream out;
    string fileName;
    bool repeat;
    do {
        repeat = false;
        cout << "Name of file to write your data (enter means no file)? ";
        cin.ignore(256, '\n');
        getline(cin, fileName);

        if (fileName.empty())
            return;

        if (fileName.find('.') > fileName.size())
            fileName += ".data";

        in.open(fileName.c_str());
        in.close();

        if (in.fail() || again("\nThat file already exists. Do you want to overwrite it?")) {
            out.open(fileName.c_str());
            display(out, list, row, col);
            out.close();
        } else {
            repeat = true;
        }
    }while(repeat);
}

bool again(string title)
{
    string line;
    cout<< title;
    cin >> line;
    return toupper(line[0]) == 'Y';
}

bool load2Darray(int **&list, int *row, int *col)
{
    string fileName;
    ifstream in;

    do
    {
        if (in.fail())
            cout << "Error. File not found.\n";

        cout << "Enter a valid filename: ";
        cin >> fileName;

        if (fileName.find('.') > fileName.size())
            fileName += ".data";
        in.open(fileName);
    } while (in.fail());

    in.ignore(256, ' ');
    in >> *row;
    in.ignore(256, ' ');
    in >> *col;

    int temp;

    if (!create2Darray(list,*row,*col))
        return false;

    for (unsigned int r = 0; r < *row; ++r)
    {
        for (unsigned int c = 0; c < *col; ++c)
        {
            in >> temp;
            *(*(list+r)+c) = temp;
        }
    }

    return true;
}

void editArray(int **&list, int row, int col)
{
    while(1)
    {
        cout << "\n1: Display Array"
             << "\n2: Modify cell"
             << "\n3: Delete all"
             << "\n4: Randomize"
             << "\n5: Save changes and Exit"
             << "\nAny other key to exit.\n";

        char temp;
        cin >> temp;

        switch(temp)
        {
            case '1':
                display(cout, list, row, col);
                break;
            case '2':
                modifyCell(list,row,col, getInput("Col: ", 1, col), getInput("Row: ", 1, row));
                display(cout, list, row, col);
                break;
            case '3':
                randomize2Darray(list, row, col, 0, 0);
                display(cout, list, row, col);
                break;
            case '4':
                int min, max;
                min = getInput("Lowest value to place in the array? ", -32767);
                max = getInput("Highest value to place in the array? ", min+1);
                randomize2Darray(list, row, col, min, max);
                display(cout, list, row, col);
                break;
            case '5':
                writeToFile(list, row, col);
                return;
            default:
                cout << "\nExiting..";
                return;
        }
    }


}

void modifyCell(int **&list, int row, int col, int c, int r)
{
    *(*(list+(r-1))+(c-1)) = getInput("Enter value: ", -32767);
}

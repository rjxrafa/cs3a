#include <iostream>
#include "smartarray.h"

using namespace std;

bool getInput(int &size);

void perform(int size);

template<typename D>
void generate(smartArray<D> &list);

template<typename D>
void display(string title, const smartArray<D> &list);

int main()
{
    int size;
    srand(time(nullptr));

    smartArray<char> charArr[5];
    smartArray<int> intArr[5];
    smartArray<double> doubleArr[5];
    smartArray<string> stringArr[5];


    charArr[1] = 'a';



    try
    {
//        while(getInput(size))
//            perform(size);
    }
    catch (MY_ARRAY_ERRORS e)
    {
        switch(e)
        {
            case OUT_OF_BOUNDS_LOW  : cout<<"Index entered was below 0"<<endl;
                break;
            case OUT_OF_BOUNDS_HIGH : cout<<"Index entered was equal to or greater than the size of the array"<<endl;
                break;
            case BAD_SIZE           : cout<<"A bad size was give for the array."<<endl;
        }
    }
    catch(...) // "Catch all" gets anything that you "forgot" to cover
    {
        cout<<"An unknown error occurred."<<endl;
    }
    return 0;
}

bool getInput(int &size)
{
    string line;
    cout<<"What is the size of the array that you wish to use? ";
    getline(cin,line);
    if(line.empty())
        return false;
    if(line.find_first_not_of("-0123456789") < line.size())
    {
        cout<<"Invalid number entered"<<endl;
    }
    else
    {
        size = stoi(line);
    }
    return true;
}

//template <typename D>
//void perform(int size)
//{
//    smart_array<D> list(size);
//    generate(list);
//    display("Unsorted:", list);
//    list.sort();
//    display("Sorted:", list);
//}


//void generate(smart_array &list)
//{
//    for(int i = 0; i < list.size(); ++i)
//        list[i] = rand()%1000;
//}

//void display(string title, const smart_array &list)
//{
//    cout<<endl<<title<<":"<<endl;
//    for(int i = 0; i < list.size(); ++i)
//    {
//        if(i%6 == 0)
//            cout<<endl;
//        cout<<setw(5)<<list[i];
//    }
//    cout<<endl;
//}

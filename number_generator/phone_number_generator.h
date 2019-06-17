/*
@title    Assignment I - Basic Pointers
@author   Rafael Betita
@modified 2019-06-14

@description
  Write a program that will dynamically create a list of phone numbers for an autodialer.
  Your program must ask the user how many telephone numbers to create, dynamically create
  an array for these phone numbers, then create the list of 10 digit numbers. Telephone
  numbers are an Area Code (3 digits in length, with the first digit being between 2 and
  9), a Prefix (3 digits, with the first digit being between 2 and 9), and a Suffix (4
  digits where each digit is from 0 to 9). The Area Code must be within parentheses,
  followed by a space, followed by the Prefix, followed by a space, followed by a hyphen,
  followed by a space, and finally followed by the Suffix. The random phone numbers must
  be written to a file in sorted order (with the lowest area code first), with the first
  entry being an integer that will state how many telephone numbers are in the file.
*/
#ifndef CS003A_PHONE_NUMBER_GENERATOR
#define CS003A_PHONE_NUMBER_GENERATOR


#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

void writeFile(unsigned long long int* &arr, int count); // Writes the number of phone numbers to file followed by all the phone numbers
void sortArray(unsigned long long int* list, int count); // Sorts given array from least to greatest.
void generateNumbers(unsigned long long int* &list, int count); // Fills a given array with phone numbers.
int userInput(char *title); // Takes a question input and returns the user's answer as an int

int main()
{
  char userLoop = 'Y';
  srand(time(NULL));

  do
  {
    unsigned long long int *list;
    int count = 0;
    string fileName;

    count = userInput("How many phone numbers do you want to generate?");
    generateNumbers(list, count);
    sortArray(list, count);
    writeFile(list, count);

    delete []list;

    cout << "\n\nWould you like to run the program again? Y/N\n";
    cin >> userLoop;
    cin.ignore(256,'\n');
  } while (userLoop == 'Y' || userLoop == 'y');

  return 0;
}

void writeFile(unsigned long long int* &arr, int count) // Writes the number of phone numbers to file followed by all the phone numbers
{ // Function courtesy of lecture 8-29
  string filename;
  ofstream out;
  ifstream in;

  cout << "\nWhat is the name of your file?: ";
  cin >> filename;

  if (filename.find('.') > filename.size())
    filename += ".data";

  in.open(filename); // If a file is in use, we cannot write to it, so we have to do this first.
  in.close();
  out.open(filename);

  out << count << endl; // add count at top of file
  for (unsigned int i = 0; i < count; ++i) // Format string as readable phone numbers
  {
    stringstream ss;
    ss << arr[i];
    string phoneNum = ss.str();
    phoneNum.insert(0,"(");
    phoneNum.insert(4,") ");
    phoneNum.insert(9,"-");
    out << phoneNum << endl;
  }
  out.close();
}

void sortArray(unsigned long long int* list, int count)
{ // Sort array from least to greatest
  for (unsigned int i = 1; i < count; )
  {
    if (list[i] < list[i-1])
    {
      unsigned long long int temp;
      temp = list[i];
      list[i] = list[i-1];
      list[i-1] = temp;
      i = 1;
    } else
      ++i;
  }
}

int userInput(char *question)
{ // User validation to check how many phone numbers are wanted.
  int input = -1;

  while (input <= 0 || cin.fail())
  {
    cout << question << ":";
    cin >> input;
    cin.clear();
    cin.ignore(256, '\n');

    if (input <= 0)
      cout << "\nInvalid value, please try again. \n";
  }

  return input;
}

void generateNumbers(unsigned long long int* &list, int count)// Fills a given array with phone numbers.
{
  stringstream ss;
  list = new unsigned long long int[count];

  for (int h = 0; h < count; ++h)
  {
    for (unsigned int i = 0; i < 10; ++i)
    {
      switch(i)
      {
        case 0:
        case 3:
          ss << (rand()%8)+2;
          break;

        default:
          ss << (rand()%10);
          break;
      }
    }
    ss >> list[h];
    ss.clear();
  }
}




#endif //CS003A_PHONE_NUMBER_GENERATOR

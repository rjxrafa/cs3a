#include <iostream>
#include <cmath>
#include <iomanip>
#include <list>

using namespace std;

typedef void (*func)(int *&list, unsigned int size);

void loadFunction(func *arr);
void standBy(int *&list, unsigned int size);
void exit(int *&list, unsigned int size);
void regenerate(int *&list, unsigned int size);
void stdDev(int *&list, unsigned int size);
void median(int *&list, unsigned int size);
int generate(int *&list, int size = 0);
void average(int *&list, unsigned int size);
void displayMenu(ostream &out);
bool programLoop(func* arr, int *&list, unsigned int size);
void nukeArray(int *&list);
int getInput(string title, int min = 1, int max = 32767);
void displayArray(int *&list, unsigned int size);
void fillArray(int *list, unsigned int size, int min, int max);


/*
Write a program that will ask the user how many random numbers to generate.
Then it will present a menu which has the options of Display, Median, Mean, and
Standard Deviation, Regenerate, and Quit. Without the use of a switch statement
or any  if statements, have the program execute the user's selection from the menu.
The program should, like any program we write, account for errors in user input and
provide a message to the user about their erroneous input.
 */

int main()
{
  func commands[128];
  int *list, size;
  loadFunction(commands);

  size = generate(list);
  while (programLoop(commands,list, size));

  nukeArray(list);
  return 0;
}

void loadFunction(func *arr)
{
  for (unsigned int i = 0; i < 128; ++i)
    arr[i] = standBy;

  arr[(unsigned int)'Q'] = arr[(unsigned int )'q'] = exit;
  arr[(unsigned int)'R'] = arr[(unsigned int)'r'] = regenerate;
  arr[(unsigned int)'A'] = arr[(unsigned int)'a'] = average;
  arr[(unsigned int)'M'] = arr[(unsigned int)'m'] = median;
  arr[(unsigned int)'s'] = arr[(unsigned int)'S'] = stdDev;
  arr[(unsigned int)'D'] = arr[(unsigned int)'d'] = displayArray;

}

void standBy(int *&list, unsigned int size)
{
  cout << "Invalid input\n";
}

void exit(int *&list, unsigned int size)
{
  cout << "Exiting program...\n";
  exit(1);
}

bool programLoop(func* arr, int *&list, unsigned int size)
{
  displayMenu(cout);
  cout << "\n>> ";

  char temp;
  cin >> temp;

  arr[(unsigned int)temp](list,size);

  return true;
}

void displayMenu(ostream &out)
{
  cout << "\n\nMAIN MENU\n"
       << " [D]isplay\n"
       << " [R]egenerate\n"
       << " [A]verage\n"
       << " [M]edian\n"
       << " [S]tandard Deviation\n"
       << " [Q]uit\n\n";
}

void regenerate(int *&list, unsigned int size)
{
  generate(list, size);
}

void stdDev(int *&list, unsigned int size)
{
  double std_dev = 0, mean = 0;

  for (unsigned int i = 0; i < size; ++i)
    mean += *(list+i);

  mean /= static_cast<double>(size);

  for (unsigned int i = 0; i < size; ++i)
    std_dev += pow((*(list+i) - mean),2);

  std_dev /= static_cast<double>(size);

  cout << "\nStd Dev: "  << fixed << setprecision(2) << sqrt(std_dev) << endl;

}

void median(int *&list, unsigned int size)
{
  int *sortedArray = new int[size];

  for (unsigned int i = 0; i < size; ++i)
    sortedArray[i] = *(list+i);

  for (unsigned int i = 1; i < size; ++i)
  {
    while (*(sortedArray+i) < *(sortedArray+i-1))
    {
      int temp = *(sortedArray+i);
      *(sortedArray+i) = *(sortedArray+i-1);
      *(sortedArray+i-1) = temp;
      i = 1;
    }
  }

  displayArray(sortedArray, size);

//    if (size%2)
  cout << "\n\nMedian: " << *(sortedArray+(size/2)+1);
//
//    else
  delete [] sortedArray;
}

void average(int *&list, unsigned int size)
{
  double average = 0;
  int count = 0;

  for (unsigned int i = 0; i < size; ++i)
    average += *(list+i);

  cout << fixed << setprecision(2) << "\nAverage:" <<(average/static_cast<double>(size));
}

int generate(int *&list, int size)
{
  if (size == 0)
    size = getInput("How many numbers do you want to generate?");

  int min = getInput("Min num in array: ", -32768);
  int max = getInput("Max num in array: ", min);

  list = new int[size];

//    for (unsigned int i = 0; i < size; ++i)
//        *(list+i) = (rand()%(max-min+1))+min;
  fillArray(list,size,min,max);

  displayArray(list, size);

  return size;
}

void nukeArray(int *&list)
{
  delete [] list;
  list = NULL;
}

int getInput(string title, int min, int max)
{
  bool repeat;
  int input;
  do
  {
    repeat = false;
    cout<<title;
    cin>>input;
    if((repeat = input < min || input > max))
      cout<<"Your input of "<<input<<" is outside of"
          <<" the acceptable input range of "<<min<<" to "<<max
          <<endl<<"You will have to re-enter your input"<<endl;
  }while(repeat);
  return input;
}

void fillArray(int *list, unsigned int size, int min, int max)
{
  for (unsigned int i = 0; i < size; ++i)
    *(list+i) = (rand()%(max-min+1))+min;
}

void displayArray(int *&list, unsigned int size)
{
  int min = *list, max = *list;
  for (unsigned int i = 0; i < size; ++i)
  {
    if (*(list+i) > max)
      max = *(list+i);
    if (*(list+i) < min)
      min = *(list+i);
  }

  int largest = abs(min) > abs(max) ? abs(min) : abs(max),
      neg = min < 0 || max < 0 ? 1 : 0,
      digits = log10(largest) + 3 + neg,
      col = 60 / digits;

  for (unsigned int i = 0; i < size; ++i)
  {
    if (i%col == 0)
      cout << endl;
    cout << setw(digits) << *(list+i);
  }
}

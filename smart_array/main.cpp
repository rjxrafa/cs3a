#include <iostream>
#include "smart_array.h"

bool GetInput(int &size);
void perform(int size);

template<typename D>
void generate(cs3a::SmartArray<D> &list);
template<typename D>
void display(std::string title, const cs3a::SmartArray<D> &list);

int SmartArrayDriver() {
  int size;
  srand(time(nullptr));

  cs3a::SmartArray<char> charArr[5];
  cs3a::SmartArray<int> intArr[5];
  cs3a::SmartArray<double> doubleArr[5];
  cs3a::SmartArray<std::string> stringArr[5];


//  try
//  {
//    while(GetInput(size))
//      perform(size);
//  }
//  catch (MY_ARRAY_ERRORS e)
//  {
//    switch(e)
//    {
//      case OUT_OF_BOUNDS_LOW  : std::cout<<"Index entered was below 0"<<endl;
//        break;
//      case OUT_OF_BOUNDS_HIGH : cout<<"Index entered was equal to or greater than the size of the array"<<endl;
//        break;
//      case BAD_SIZE           : cout<<"A bad size was give for the array."<<endl;
//    }
//  }
//  catch(...) // "Catch all" gets anything that you "forgot" to cover
//  {
//    cout<<"An unknown error occurred."<<endl;
//  }
  return 0;
}

bool GetInput(int &size) {
  std::string line;
  std::cout << "What is the size of the array that you wish to use? ";
  getline(std::cin, line);
  if(line.empty())
    return false;
  if(line.find_first_not_of("0123456789") < line.size())
    std::cout<<"Invalid number entered\n";
  else
    size = stoi(line);
  return true;
}

//template <typename D>
//void perform(int size)
//{
//    smart_array<D> list(size);
//    generate(list);
//    display("Unsorted:", list);
//    list.Sort();
//    display("Sorted:", list);
//}


//void generate(smart_array &list)
//{
//    for(int i = 0; i < list.size(); ++i)
//        list[i] = rand()%1000;
//}

//void display(std::string title, const smart_array &list)
//{
//    std::cout<<endl<<title<<":"<<endl;
//    for(int i = 0; i < list.size(); ++i)
//    {
//        if(i%6 == 0)
//            std::cout<<endl;
//        std::cout<<setw(5)<<list[i];
//    }
//    std::cout<<endl;
//}

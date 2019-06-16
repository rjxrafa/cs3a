#include <iostream>
#include <fstream>
#include <time.h>
#include "statistics.h"

/**
 * Generate a list of random numbers where the first value corresponds to
 * the amount of numbers generated and the filename is the name of the
 * output file. Numbers are delimited by a space.
 * @param size
 * @param filename
 */
void GenerateList (size_t size, const std::string &filename) {
  std::ofstream out(filename);

  out << size << ' ';

  srand(time(NULL));

  for (size_t i = 0; i < size; ++i) {
    out << (rand()%1000)-500 << ' ';
  }

  out.close();
  std::cout << "List auto-generated! Filename: " << filename << '\n';
}

void StatisticsDriver() {

  printf("This program will read a file of integers, where the first number in\n"
         "the file is the amount of data contained within the file. Using the\n"
         "value just read in, your program will then dynamically create an array\n"
         "of integers, display them in the order that they were read in (in tabular format),\n"
         "sort the numbers, and then display the sorted list of numbers. Upon\n"
         "completion of the above, it will then display the following statistical\n"
         "information: mean, first, second, third quartiles, std dev, min and max values.\n\n");
  char userLoop = 'Y';

  do
  {
    GenerateList(1000, "numbers.dat");
    int *list, count, min, max, q1, q2, q3;
    double mean, std_dev;

    count = cs3a::ReadFile(list);
    cs3a::DisplayList(list, count);
    cs3a::SortArray(list, count);
    cs3a::DisplayList(list, count);
    cs3a::Calculate(list, count, min, max, mean, std_dev, q1, q2, q3);
    cs3a::OutputData(count, min, max, mean, std_dev, q1, q2, q3);

    delete []list;

    std::cout << "\n\nWould you like to run the program again? Y/N\n";
    std::cin >> userLoop;
    std::cin.ignore(256,'\n');
  } while (userLoop == 'Y' || userLoop == 'y');
}
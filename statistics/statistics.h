/*
@title    Assignment I - Basic Pointers
@author   Rafael Betita
@modified 2019-06-14

@description
  This program will read a file of integers, where the first number in
  the file is the amount of data contained within the file. Using the
  value just read in, your program will then dynamically create an array
  of integers, display them in the order that they were read in (in tabular format),
  sort the numbers, and then display the sorted list of numbers. Upon
  completion of the above, it will then display the following statistical
  information: mean, first, second, third quartiles, std dev, min and max values.
*/

#ifndef CS003A_STATISTICS_H
#define CS003A_STATISTICS_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

namespace cs3a {
int ReadFile(int *&arr);
void DisplayList(int *list, int count, std::ostream &out = std::cout);
void Calculate(int *list, int count, int &min, int &max, double &mean, double &std_dev, int &q1, int &q2, int &q3);
void SortArray(int *list, int count);
void OutputData(int count, int min, int max, double mean,
                double std_dev, int q1, int q2, int q3,
                std::ostream &out = std::cout);

/**
 * Prompts the user for a filename to open and read from. Inserts integers from the given filename into the
 * given array. Returns the count of integers read.
 *
 * @param arr
 * @return
 */
int ReadFile(int *&arr) {
  std::string filename;
  std::ifstream input;

  do {
    std::cout << "What is the name of the file you want to open?\n";
    getline(std::cin, filename);
    fflush(stdin);
    input.open(filename);
    if (input.fail())
      std::cout << "File not found. Try again.\n";
  } while (input.fail());

  int current, index = 0;
  input >> current;
  arr = new int[current]; // Create a dynamic array based on the first input read.

  while(input >> current)
    arr[index++] = current;

  return index;
}

/**
 * Display a given array list to a given output stream. Adapted from a CS003A lecture by Paul Wilkinson. This function
 * essentially checks for the maximum number of digits, taking negatives into account.
 * @param list
 * @param count
 */
void DisplayList(int *list, int count, std::ostream &out) {
  int min = list[0], max = list[0];

  for (unsigned int i = 0; i < count; ++i) {
    if (min > list[i])
      min = list[i];
    if (max < list[i])
      max = list[i];
  }

  int largest = abs(min) > abs(max) ? abs(min) : abs(max),
      negative = min < 0 || max < 0 ? 1 : 0,
      digits = log10(largest) + 3 + negative,
      cols = 60 / digits;

  for (unsigned int i = 0; i < count; ++i)
  {
    if(i%cols == 0)
      out << '\n';
    out << std::setw(digits) << list[i];
  }

  out << '\n';
}

/**
 * This function performs statistical calculations from a given array (list).
 * @param list
 * @param count
 * @param min
 * @param max
 * @param mean
 * @param std_dev
 * @param q1
 * @param q2
 * @param q3
 */
void Calculate(int *list, int count,
               int &min, int &max,
               double &mean, double &std_dev,
               int &q1, int &q2, int &q3) {
  // Initialize values
  min = list[0];
  max = list[0];
  mean = 0;
  std_dev = 0;

  for (unsigned int i = 0; i < count; ++i) { // Calculate mean
    if (min > list[i])
      min = list[i];
    if (max < list[i])
      max = list[i];

    mean += list[i];
  }
  mean /= count;

  for (unsigned int i = 0; i < count; ++i)     // Calculate std dev
    std_dev += pow(list[i]-mean, 2);

  std_dev = sqrt(std_dev/count);
  q1 = list[((count+1)/4)-1];
  q2 = list[((count+1)/2)-1];
  q3 = list[(3*(count+1)/4)-1];
}

/**
 * Uses a simple algorithm to sort a given list from least to greatest.
 * @param list
 * @param count
 */
void SortArray(int *list, int count) {
  for (unsigned int i = 1; i < count; ) {
    if (list[i] < list[i-1]) {
      int temp;
      temp = list[i];
      list[i] = list[i-1];
      list[i-1] = temp;
      i = 1;
    } else
      ++i;
  }

  std::cout << "\nSORTED LIST";
}

void OutputData(int count,
                int min, int max,
                double mean, double std_dev,
                int q1, int q2, int q3,
                std::ostream &out) {
  out << "\nCount: " << count;
  out << "\nMin: " << min;
  out << "\nMax: " << max;
  out << "\nMean: " << std::setprecision(2) << mean;
  out << "\nSDev: " << std::setprecision(2) << std_dev;
  out << "\nQ1: " << q1;
  out << "\nQ2: " << q2;
  out << "\nQ3: " << q3;
}

}



#endif //CS003A_STATISTICS_H

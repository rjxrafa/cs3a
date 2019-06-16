/**
 * This program represents all of the assignments created for Pasadena City College's CS003A class, an introductory
 * course on C++ taught by Professor Paul J. Wilkinson.
 *
 * @author      Rafael Betita
 * @modified    2019-06-13
 */

#include <iostream>
#include "stack/driver.h"
#include "fraction_quiz/driver.h"
#include "copy/driver.h"
#include "statistics/driver.h"

int main(int argc, char ** argv) {

  std::cout << "This program encompass the several assignments I've created for "
               "my introductory \nComputer Science course: CS003A, at Pasadena City College.\n\n";

  bool menu = true;
  while (menu) {
    std::cout << "\nChoose a program to run (Enter 0 to exit): \n\n"
              << "(1) Palindrome Checker (w/ Stacks)\n"
              << "(2) Fraction Quiz (w/ Fraction class)\n"
              << "(3) File Copier (w/ Command line arguments)\n"
              << "(4) Statistics (w/ Pointers)\n";

    int user_choice = getchar();
    fflush(stdin);

    switch(user_choice) {
      case '1':
        PalindromeChecker();
        break;
      case '2':
        PlayFractionQuiz();
        break;
      case '3':
        CopyDriver(argc, argv);
        break;
      case '4':
        StatisticsDriver();
        break;
      case '0':
        menu = false;
        break;
      default:
        std::cout << "Invalid selection.\n";
    }
  }

}
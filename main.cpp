/**
 * This program represents all of the assignments created for Pasadena City College's CS003A class, an introductory
 * course on C++ taught by Professor Paul J. Wilkinson.
 *
 * @author      Rafael Betita
 * @modified    2019-06-13
 */

#include <iostream>
#include "Stack/driver.h"

int main(int argc, char ** argv) {

  std::cout << "This program encompass the several assignments I've created for "
               "my introductory \nComputer Science course: CS003A, at Pasadena City College.\n\n";

  bool menu = true;
  while (menu) {
    std::cout << "Choose a program to run (Press enter to exit): \n\n"
              << "(1) Palindrome Checker (w/ Stacks)\n";

    int user_choice = getchar();
    fflush(stdin);

    switch(user_choice) {
      case '1':
        PalindromeChecker();
        break;
      case 10:
        menu = false;
        break;
      default:
        std::cout << "Invalid selection.\n";
    }
;
  }

}
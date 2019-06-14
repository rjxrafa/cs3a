#include "stack.h"
#include <iostream>

std::string ProcessLine(const std::string &line);
bool GetInput(std::string &line);
bool Palindrome(const std::string &line);

/**
 * This is the driver function for testing the Stack implementation.
 */
void PalindromeChecker() {
  std::string line, toCheck, is_not;
  try {
    while(GetInput(line)) {
      toCheck = ProcessLine(line);
      is_not = line + " is"+ (Palindrome(toCheck) ? " " : " not ") + "a Palindrome";
      std::cout << is_not << '\n';
    }
  }
  catch (cs3a::MY_STACK_ERRORS e) {
    switch(e) {
      case cs3a::MY_STACK_ERRORS::STACK_EMPTY    : std::cout<<"stack empty error occurred\n";
        break;
      case cs3a::MY_STACK_ERRORS::STACK_FULL     : std::cout<<"stack full error occurred\n";
        break;
      case cs3a::MY_STACK_ERRORS::STACK_BAD_SIZE : std::cout<<"stack size error occurred\n";
    }
  }
}

bool GetInput(std::string &line) {
  std::cout<<"Input: ";
  fflush(stdin);
  getline(std::cin, line);
  fflush(stdin);
  return !line.empty();
}


std::string ProcessLine(const std::string &line) {
  std::string result;

  for(unsigned int i = 0; i < line.size(); ++i)
    if(isalpha(line[i]) || isdigit(line[i]))
      result += toupper(line[i]);

  return result;
}

bool Palindrome(const std::string &line) {
  std::string reversed;
  cs3a::Stack<char> reverse(line.length());

  for(unsigned int i = 0; i < line.size(); ++i)
    reverse.Push(line[i]);

  while(!reverse.empty()) {
    reversed += reverse.top();
    reverse.Pop();
  }

  return reversed == line;
}

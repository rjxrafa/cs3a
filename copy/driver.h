#include <iostream>
#include "copy.h"

void CopyDriver(int argc, char* argv[]) {

    if (argc == 1) {
      printf("No parameters found. Using manual mode..\n");
      printf("\n\nWelcome to the file copy program. Enter command line arguments as follows: \n"
             "/o=peace.txt /i=war.txt\n"
             "/o - represents your output file\n"
             "/i - represents your input file\n"
             "/e - overwrite flag\n"
             "/a - append flag\n");
      printf("Enter command line arguments: \n");
      std::string line;
      getline(std::cin, line);
      if (line.empty()) {
        printf("Exiting program.\n");
        return;
      } else {
        std::stringstream ss(line);
        std::vector<std::string> temp_vector;
        while (ss >> line) {
          temp_vector.push_back(line);
        }
        int size = temp_vector.size()+1;
        char** temp_argv = new char*[size];
        temp_argv[0] = argv[0];
        for (size_t i = 1; i < temp_vector.size()+1; ++i) {
          temp_argv[i] = const_cast<char*>(temp_vector[i-1].c_str());
        }
        cs3a::Copy a(size,temp_argv);
        std::cout << '\n';
        a.PrintVector();
        delete temp_argv;
      }
    } else {
      cs3a::Copy a(argc,argv);
      std::cout << '\n';
      a.PrintVector();
    }

}

/*
File does not exist, creating file: peace.txt

input_filename_: war.txt
output_filename_: peace.txt
overwrite: 1
append: 0

*/
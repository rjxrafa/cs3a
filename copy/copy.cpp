#include "copy.h"

namespace cs3a {
Copy::Copy() = default;

Copy::Copy(int argc, char** argv) {
  if (argc < 3 || argc > 5) {
    std::cout << "Invalid parameters. Exiting program";
    return; // exits program if you receive bad input
  }
  arguments = new std::vector <std::string> (argv,argv+argc);

  ParseVector();

  if (!OpenFiles())
    return;

  WriteToFile();
}

Copy::~Copy() {
  delete arguments;
  arguments = nullptr;
}

void Copy::PrintVector() {
  std::cout << "input filename: " << input_filename_ << '\n'
            << "output filename: " << output_filename_ << '\n'
            << std::boolalpha << "overwrite: " << overwrite << '\n'
            << std::boolalpha << "append: " << append << '\n';
}

void Copy::ParseVector() {

  for (unsigned int i = 0; i < arguments->size(); ++i) {
    if (arguments->at(i) == "/a")
      append = true;
    if (arguments->at(i) == "/e")
      overwrite = true;
    if (arguments->at(i).find("o=") != std::string::npos)
      output_filename_ = arguments->at(i).substr(3);
    if (arguments->at(i).find("i=") != std::string::npos)
      input_filename_ = arguments->at(i).substr(3);
  }
}

bool Copy::OpenFiles() {

  // Checking if output file already exists
  if (DoesFileExist(output_filename_)) {
    if (overwrite) {
      std::cout << "Overwriting file." << '\n';
      if (append)
        output.open(output_filename_, std::ios::app);
      else
        output.open(output_filename_);

      // Prepping input file
      input.open(input_filename_);
      if (input.fail()) {
        std::cout << "Input open failed.";
        return false;
      }
    } else {
      std::cout << "File exists. Exiting program.";
      return false;
    }
  } else
  {
    std::cout << "File does not exist, creating file: " << output_filename_ << '\n';
    output.open(output_filename_);
    input.open(input_filename_);
    if (input.fail()) {
      std::cout << "Input open failed.";
      return false;
    }
  }

  return true;
}

bool Copy::DoesFileExist(const std::string &filename) {
  std::ifstream file(filename);
  return file.good();
}

void Copy::WriteToFile() {
  std::string buffer;

  while (!input.eof()) {
    getline(input, buffer);
    output << buffer << '\n';
    buffer.clear();
  }

  output.close();
  input.close();
}


} // end namespace cs3a
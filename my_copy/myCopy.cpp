//
// Created by rafab on 10/3/2018.
//
#include "myCopy.h"

myCopy::myCopy() {

}

myCopy::myCopy(int argc, char** argv) {
    arguments = new vector <string> (argv,argv+argc);
//    arguments->push_back(to_string(argc));
    if (argc < 3 || argc > 5)
    {
        cout << "Invalid parameters. Exiting program";
        exit(1); // exits program if you receive bad input
    }

    parseVector();

    if (!openFiles())
        exit(1);

    writeToFile();

}

myCopy::~myCopy() {
    arguments = NULL;
    delete arguments;
}

void myCopy::printVector()
{
//    for (auto i: *arguments)
//        cout << i << ' ';
    cout << "in_filename: " << in_filename << endl;
    cout << "out_filename: " << out_filename << endl;
    cout << "overwrite: " << overwrite << endl;
    cout << "append: " << append << endl;
}

void myCopy::parseVector() {

    for (unsigned int i = 0; i < arguments->size(); ++i) {
        if (arguments->at(i) == "/a")
            append = true;
        if (arguments->at(i) == "/o")
            overwrite = true;
        if (arguments->at(i).find("o=") != string::npos)
            out_filename = arguments->at(i).substr(3);
        if (arguments->at(i).find("i=") != string::npos)
            in_filename = arguments->at(i).substr(3);
    }
}

bool myCopy::openFiles() {

    // Checking if output file already exists
    if (doesFileExist(out_filename)) {
        if (overwrite) {
            cout << "Overwriting file." << endl;
            if (append)
                output.open(out_filename, ios::app);
            else
                output.open(out_filename);

            // Prepping input file
            input.open(in_filename.c_str());
            if (input.fail()) {
                cout << "Input open failed.";
                return false;
            }
        } else
        {
            cout << "File exists. Exiting program.";
            exit(1);
        }
    } else
    {
        cout << "File does not exist, creating file: " << out_filename << endl;
        output.open(out_filename);
        input.open(in_filename.c_str());
        if (input.fail()) {
            cout << "Input open failed.";
            return false;
        }
    }

    return true;
}

bool myCopy::doesFileExist(const string &filename) {
    ifstream file(filename);
    return file.good();
}

void myCopy::writeToFile() {
    string buffer;

    while (!input.eof()) {
        getline(input, buffer);
        output << buffer << endl;
        buffer.clear();
    }

    output.close();
    input.close();
}


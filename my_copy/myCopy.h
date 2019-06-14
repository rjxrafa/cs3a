//
// Created by rafab on 10/3/2018.
//

#ifndef UNTITLED15_MYCOPY_H
#define UNTITLED15_MYCOPY_H

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

class myCopy {

    public:
        myCopy();
        ~myCopy();
        myCopy(int argc, char** argv);
        void printVector();

    private:
        string in_filename;
        string out_filename;
        bool overwrite = false;
        bool append = false;
        vector <string>* arguments;
        fstream input;
        ofstream output;
        void parseVector();
        bool openFiles();
        bool doesFileExist(const string &filename);
        void writeToFile();

};


#endif //UNTITLED15_MYCOPY_H

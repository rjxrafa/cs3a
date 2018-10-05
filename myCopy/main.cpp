#include <iostream>
#include "myCopy.h"

using namespace std;

int main(int argc, char* argv[]) {
    myCopy a(argc,argv);


    cout << endl;
    a.printVector();

    return 0;
}

/*
File does not exist, creating file: peace.txt

in_filename: war.txt
out_filename: peace.txt
overwrite: 1
append: 0

Process finished with exit code 0*/
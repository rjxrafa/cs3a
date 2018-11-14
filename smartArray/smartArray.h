#ifndef SMARTARRAY_H
#define SMARTARRAY_H

#include <iomanip>
#include <iostream>
#include <fstream>

enum MY_ARRAY_ERRORS {BAD_SIZE, FULL, EMPTY, OUT_OF_BOUNDS_LOW, OUT_OF_BOUNDS_HIGH};

template<typename D>
class smartArray
{
    public:
        smartArray(int s = 10);
        ~smartArray();
        smartArray(const smartArray<Data> &other);
        smartArray<Data>& operator=(const smartArray<Data> &other   )

        int operator [](int i) const;
        int& operator& [](int i);
        int size() const;
        
        void resize(int i = 10);
        void sort();
        //smartArray slice(int begin, int end, int inc = 1);

        friend
        std::ostream& operator<<( std::ostream& out, const smartArray &array);

        friend
        std::istream& operator>>( std::istream& , const smartArray &);

    private:
        int mySize, 
        Data *list;

        void copy(const smartArray &other);
        void deleteAll();
        void zero();
}

#include "smartArray.cpp"
#endif // SMARTARRAY_H

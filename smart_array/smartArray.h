#ifndef SMARTARRAY_H
#define SMARTARRAY_H

#include <iomanip>
#include <iostream>
#include <fstream>


enum MY_ARRAY_ERRORS {BAD_SIZE, OUT_OF_BOUNDS_LOW, OUT_OF_BOUNDS_HIGH};

template<typename D>
class smartArray
{
public:
    smartArray(int s = 10);
    ~smartArray();
    smartArray(const smartArray<D> &other);
    smartArray<D>& operator=(const smartArray<D> &other);

    D operator [](int i) const;
    D& operator [](int i);

    int size() const;

    void resize(int i = 10);
    void sort();
    //smart_array slice(int begin, int end, int inc = 1);

//    friend
//    std::ostream& operator<<( std::ostream& out, const smart_array &array);
//
//    friend
//    std::istream& operator>>( std::istream& , const smart_array &);

private:
    int mySize;
    D *list;

    void copy(const smartArray &other);
    void deleteAll();
    void zero();
};

template<typename D>
smartArray<D>::smartArray(int s)
{
    resize(s);
}

template<typename D>
smartArray<D>::~smartArray()
{
    deleteAll();
}

template<typename D>
smartArray<D>::smartArray(const smartArray<D> &other)
{
    copy(other);
}

template<typename D>
smartArray<D>& smartArray<D>::operator=(const smartArray<D> &other)
{
    if (this != &other)
    {
        deleteAll();
        copy(other);
    }
    return *this;
}

//Allows access to elements in the array
template<typename D>
D smartArray<D>::operator [](int i) const
{
    if(i < 0)
        throw OUT_OF_BOUNDS_LOW;
    if (i >= mySize)
        throw OUT_OF_BOUNDS_HIGH;
    return list[i];
}

template<typename D>
D& smartArray<D>::operator [](int i)
{
    if (i < 0)
        throw OUT_OF_BOUNDS_LOW;
    if (i >= mySize)
        throw OUT_OF_BOUNDS_HIGH;
    return list[i];
}

template<typename D>
int smartArray<D>::size() const
{
    return mySize;
}

template<typename D>
void smartArray<D>::resize(int i)
{
    if (i < 1)
        throw BAD_SIZE;
    list = new D[mySize = i];
//    zero();
}

template<typename D>
void smartArray<D>::sort()
{
    int temp;
    for(int i = 0; i < mySize; ++i)
        for(int j = 0; j < mySize; ++j)
            if(list[i] < list[j])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
}

//smart_array slice(int begin, int end, int inc = 1);

template<typename D>
void smartArray<D>::copy(const smartArray<D> &other)
{
    list = new D[mySize = other.mySize];
    for(int i = 0; i < other.size(); ++i)
        list[i] = other[i];
}

template<typename D>
void smartArray<D>::deleteAll()
{
    zero();
    delete [] list;
    list = nullptr;
}

template<typename D>
void smartArray<D>::zero()
{
//    for(int i = 0; i < mySize; ++i)
//        list[i] = nullptr;
}

friend
std::ostream& operator<<( std::ostream& out, const smartArray &array)
{
    for (unsigned int i = 0; i < array.size(); ++i)
        out >> array[i];

    return out;
}

//
//friend
//std::istream& operator>>( std::istream& , const smart_array &);

#endif // SMARTARRAY_H

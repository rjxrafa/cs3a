/**
 * This class takes advantage of templates to create dynamic arrays of any data type.
 */
#ifndef CS003A_SMARTARRAY_H
#define CS003A_SMARTARRAY_H

#include <iomanip>
#include <iostream>
#include <fstream>

namespace cs3a {
enum MY_ARRAY_ERRORS {BAD_SIZE, OUT_OF_BOUNDS_LOW, OUT_OF_BOUNDS_HIGH};

template<typename D>
class SmartArray
{
 public:
  SmartArray(int size = 10);
  ~SmartArray();
  SmartArray(const SmartArray<D> &other);
  SmartArray<D>& operator=(const SmartArray<D> &other);

  D operator [](int i) const; // Returns rvalue
  D& operator [](int i);      // Returns lvalue

  int size() const {return size_;}

  void Resize(int new_size = 10);
  void Sort();
  SmartArray Slice(int begin, int end, int inc = 1);

  template <typename S>
  friend
  std::ostream& operator<<( std::ostream& out, const SmartArray<S> &other);

  template <typename S>
  friend
  std::istream& operator>>( std::istream& , const SmartArray<S> &other);

 private:
  int size_;
  D *list;

  void Copy(const SmartArray &other);
  void Clear();
};

template<typename D>
SmartArray<D>::SmartArray(int size) {
  Resize(size);
}

template<typename D>
SmartArray<D>::~SmartArray() {
  Clear();
}

template<typename D>
SmartArray<D>::SmartArray(const SmartArray<D> &other) {
  Copy(other);
}

template<typename D>
SmartArray<D>& SmartArray<D>::operator=(const SmartArray<D> &other) {
  if (this != &other) {
    Clear();
    Copy(other);
  }
  return *this;
}

//Allows access to elements in the array
template<typename D>
D SmartArray<D>::operator [](int i) const {
  if(i < 0)
    throw OUT_OF_BOUNDS_LOW;
  if (i >= size_)
    throw OUT_OF_BOUNDS_HIGH;
  return list[i];
}

template<typename D>
D& SmartArray<D>::operator [](int i) {
  if (i < 0)
    throw OUT_OF_BOUNDS_LOW;
  if (i >= size_)
    throw OUT_OF_BOUNDS_HIGH;
  return &list[i];
}

template<typename D>
void SmartArray<D>::Resize(int new_size) {
  if (new_size < 1)
    throw BAD_SIZE;
  // Copied elements depend on whether the new size is smaller or not.

  D *temp = new D[new_size];
  if (new_size < size_)
    size_ = new_size;

  for (size_t i = 0; i < size_; ++i) { // Copy elements to new array
    temp[i] = list[i];
  }

  delete list;
  list = temp;
  size_ = new_size;
}


template<typename D>
void SmartArray<D>::Sort()
{
  int temp;
  for(int i = 0; i < size_; ++i)
    for(int j = 0; j < size_; ++j)
      if(list[i] < list[j])
      {
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
}

//smart_array slice(int begin, int end, int inc = 1);

template<typename D>
void SmartArray<D>::Copy(const SmartArray<D> &other) {
  Clear();
  list = new D[size_ = other.size_];
  for(int i = 0; i < other.size(); ++i)
    list[i] = other[i];
}

template<typename D>
void SmartArray<D>::Clear() {
  for(int i = 0; i < size_; ++i)
    list[i] = D();

  delete [] list;
  list = nullptr;
}

template <typename S>
std::ostream& operator<<( std::ostream& out, const SmartArray<S> &array) {
  for (unsigned int i = 0; i < array.size(); ++i)
    out << array[i];

  return out;
}

template<typename S>
std::istream &operator>>(std::istream &, const SmartArray<S> &other) {
//  return <#initializer#>;
}

template<typename D>
SmartArray<D> SmartArray<D>::Slice(int begin, int end, int inc) {
//  return SmartArray();
}

} // end namespace cs3a

#endif // CS003A_SMARTARRAY_H

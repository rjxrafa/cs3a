/**
 * This is a templated implementation of a Stack class, which was adapted from CS003A lectures. Uses dynamic
 * array allocation as a container.
 *
 * @author      Rafael Betita
 * @modified    2019-06-13
 */

#ifndef CS003A_STACK_H
#define CS003A_STACK_H

#include <fstream>
#include <iostream>

namespace cs3a {

enum class MY_STACK_ERRORS {STACK_EMPTY, STACK_FULL, STACK_BAD_SIZE};

template<typename Data>
class Stack {
 public:
  Stack(size_t size = 10); // Stack uses a default size of 10
  ~Stack();
  Stack(const Stack<Data> &other);
  Stack<Data>& operator=(const Stack<Data> &other);

  /** Element Access **/
  Data top() const;

  /** Capacity **/
  size_t size() const
    { return top_of_stack_+1; };
  size_t capacity() const
    { return capacity_; };
  bool full() const
    {return capacity_ == top_of_stack_+1;};
  bool empty() const
    {return top_of_stack_ == -1;};

  /** Modifiers **/
  void Push(const Data &data);
  void Pop();
  void Resize(size_t size = 10);

  Stack<Data>& operator<<(const Data &data); // Push
  Stack<Data>& operator>>(Data &data); // top + Pop

  template<typename D>
  friend
  std::ostream& operator<<(std::ostream& out, const Stack<D> &Stack);

  template<typename D>
  friend
  std::istream& operator>>(std::istream& in, Stack<D> &Stack);

 private:
  Data *stack_;
  int top_of_stack_;
  size_t capacity_;

  void Copy(const Stack<Data> &other);
  void Clear();
};

template<typename Data>
Stack<Data>::Stack(size_t size) : capacity_(size) {
  if(size < 2)
    throw MY_STACK_ERRORS :: STACK_BAD_SIZE;
  stack_ = new Data[size];
  top_of_stack_ = -1;
}

template<typename Data>
Stack<Data>::~Stack() {
  Clear();
}

template<typename Data>
Stack<Data>::Stack(const Stack<Data> &other) {
  Copy(other);
}

template<typename Data>
Stack<Data>& Stack<Data>::operator=(const Stack<Data> &other) {
  if(this != &other) {
    Clear();
    Copy(other);
  }
  return *this;
}

template<typename Data>
void Stack<Data>::Push(const Data &data) {
  if(full())
    throw MY_STACK_ERRORS :: STACK_FULL;
  stack_[++top_of_stack_] = data;
}

template<typename Data>
Data Stack<Data>::top() const {
  if(empty())
    throw MY_STACK_ERRORS :: STACK_EMPTY;
  return stack_[top_of_stack_];
}

template<typename Data>
void Stack<Data>::Pop() {
  if(empty())
    throw MY_STACK_ERRORS :: STACK_EMPTY;
  --top_of_stack_;
}

/**
 * This function resizes the current stack size to be smaller or larger.
 * @tparam Data
 * @param size
 */
template<typename Data>
void Stack<Data>::Resize(size_t size) {
  if(size < 2)
    throw MY_STACK_ERRORS :: STACK_BAD_SIZE;
  Data *temp = new Data[size];
  int new_size = std::min(capacity_, size);
  for(unsigned int i = 0; i < new_size; ++i) // Copies current elements
    temp[i] = stack_[i];

  Clear();
  stack_ = temp;
  capacity_ = size;

  top_of_stack_ = capacity_ <= size ? top_of_stack_ :
                  top_of_stack_ <= size - 1 ? top_of_stack_ : size-1;
}

template<typename Data>
Stack<Data>& Stack<Data>::operator<<(const Data &data) {
  Push(data);
  return *this;
}

template<typename Data>
Stack<Data>& Stack<Data>::operator>>(Data &data) {
  data = top();
  Pop();
  return *this;
}

template<typename Data>
void Stack<Data>::Copy(const Stack<Data> &other) {
  top_of_stack_ = other.topOfStack;
  stack_ = new Data[capacity_ = other.myCapacity];
  for(unsigned int i = 0; i < top_of_stack_; ++i)
    stack_[i] = other.stack_[i];
}

template<typename Data>
void Stack<Data>::Clear() {
  for(unsigned int i = 0; i < capacity_; ++i)
    stack_[i] = Data();
  delete [] stack_;
  top_of_stack_ = capacity_ = 0;
  stack_ = nullptr;
}

template<typename D>
std::ostream& operator<<(std::ostream& out, const Stack<D> &stack) {
  if(&out == &std::cout) {
    out<<"Stack capacity: "<< stack.capacity_<< "\n";
    if(stack.empty())
      out<< "The Stack is empty.\n";
    else
      for(int i = stack.top_of_stack_; i > -1; --i)
        out<<"Stack["<<i<<"] = "<< stack.stack_[i]<< "\n";
  }
  else {
    out<<"Stack capacity: "<< stack.capacity_
       <<"\nTop of Stack: "<< stack.top_of_stack_<<"\n";
    for(int i =  stack.top_of_stack_; i > -1; --i)
      out<< stack.stack_[i]<<"\n";
  }  return out;
}

template<typename D>
std::istream& operator>>(std::istream& in, Stack<D> &stack) {
  size_t capacity;
  D value;
  if(&in == &std::cin) {
    std::cout << "New Stack capacity? " << std::endl;
    in >> capacity;
    stack.Resize(capacity);
    while(in >> value)
      stack << value;
  }
  else {
    std::string line;
    getline(in,line,':');
    in >> capacity;
    stack.Resize(capacity);
    getline(in,line,':');
    in >> stack.top_of_stack_;
    for(unsigned int i = 0; i <= stack.top_of_stack_; ++i)
      in >> stack.stack_[i];
  }
  return in;
}

} // end namespace cs3a



#endif // CS003A_STACK_H

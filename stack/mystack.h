#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

enum MY_STACK_ERRORS {STACK_EMPTY, STACK_FULL, STACK_BAD_SIZE};

template<typename Data>
class myStack
{
    public:
        myStack(int s = 10);
        ~myStack();
        myStack(const myStack<Data> &other);
        myStack<Data>& operator=(const myStack<Data> &other);

        void push(const Data &data);
        Data top();
        void pop();
        void size();
        void capacity();
        void resize(int s = 10);
        bool full();
        bool empty();
        myStack<Data>& operator<<(const Data &data);//push
        myStack<Data>& operator>>(Data &data);//top + pop

        template<typename D>
        friend
        std::ostream& operator<<(std::ostream& out, const myStack<D> &stack);

        template<typename D>
        friend
        std::istream& operator>>(std::istream& in, myStack<D> &stack);

    private:
        Data *stack;
        int topOfStack, myCapacity;

        void copy(const myStack<Data> &other);
        void deleteAll();
};

template<typename Data>
myStack<Data>::myStack(int s)
{
    if(s < 2)
        throw STACK_BAD_SIZE;
    stack = new Data[myCapacity = s];
    topOfStack = -1;
}

template<typename Data>
myStack<Data>::~myStack()
{
    deleteAll();
}

template<typename Data>
myStack<Data>::myStack(const myStack<Data> &other)
{
    copy(other);
}

template<typename Data>
myStack<Data>& myStack<Data>::operator=(const myStack<Data> &other)
{
    if(this != &other)
    {
        deleteAll();
        copy(other);
    }
    return *this;
}

template<typename Data>
void myStack<Data>::push(const Data &data)
{
    if(full())
      throw STACK_FULL;
    stack[++topOfStack] = data;
}

template<typename Data>
Data myStack<Data>::top()
{
    if(empty())
        throw STACK_EMPTY;
    return stack[topOfStack];
}

template<typename Data>
void myStack<Data>::pop()
{
    if(empty())
       throw STACK_EMPTY;
    --topOfStack;
}

template<typename Data>
void myStack<Data>::size()
{
    return topOfStack + 1;
}

template<typename Data>
void myStack<Data>::capacity()
{
    return myCapacity;
}

template<typename Data>
void myStack<Data>::resize(int s)
{
    if(s < 2)
        throw STACK_BAD_SIZE;
    Data *temp = new Data[s];
    int toWhere = min(myCapacity,s);
    for(unsigned int i = 0; i < toWhere; ++i)
        temp[i] = stack[i];
    deleteAll();
    stack = temp;
    myCapacity = s;
    topOfStack = myCapacity <= s ? topOfStack :
                 topOfStack <= s - 1 ? topOfStack : s-1;
}

template<typename Data>
bool myStack<Data>::full()
{
    return topOfStack + 1 == myCapacity;
}

template<typename Data>
bool myStack<Data>::empty()
{
    return topOfStack == -1;
}

template<typename Data>
myStack<Data>& myStack<Data>::operator<<(const Data &data)
{
    push(data);
    return *this;
}

template<typename Data>
myStack<Data>& myStack<Data>::operator>>(Data &data)
{
    data = top();
    pop();
    return *this;
}

template<typename Data>
void myStack<Data>::copy(const myStack<Data> &other)
{
    topOfStack = other.topOfStack;
    stack = new Data[myCapacity = other.myCapacity];
    for(unsigned int i = 0; i < topOfStack; ++i)
            stack[i] = other.stack[i];
}

template<typename Data>
void myStack<Data>::deleteAll()
{
    for(unsigned int i = 0; i < myCapacity; ++i)
        stack[i] = Data();
    delete [] stack;
    topOfStack = myCapacity = 0;
    stack = nullptr;
}

template<typename D>
std::ostream& operator<<(std::ostream& out, const myStack<D> &stack)
{
    if(&out == &std::cout)
    {
         out<<"Stack capacity: "<<stack.myCapacity<<std::endl;
         if(stack.empty())
                out<<"The stack is empty"<<std::endl;
         else
             for(int i = stack.topOfStack; i > -1; --i)
                out<<"stack["<<i<<"] = "<<stack.stack[i]<<std::endl;
    }
    else
    {
        out<<"Stack capacity: "<<stack.myCapacity<<std::endl
           <<"Top of Stack: "<<stack.topOfStack<<std::endl;
        for(int i = stack.topOfStack; i > -1; --i)
            out<<stack.stack[i]<<std::endl;
    }
    return out;
}

template<typename D>
std::istream& operator>>(std::istream& in, myStack<D> &stack)
{
     int cap;
     D value;
     if(&in == &std::cin)
     {
         std::cout<<"New stack capacity? ";
         in>>cap;
         stack.resize(cap);
         while(in>>value)
             stack << value;
     }
     else
     {
         std::string line;
         getline(in,line,':');
         in>>cap;
         stack.resize(cap);
         getline(in,line,':');
         in>>stack.topOfStack;
         for(unsigned int i = 0; i <= stack.topOfStack; ++i)
             in>>stack.stack[i];
     }
     return in;
}


#endif // MYSTACK_H

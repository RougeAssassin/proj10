// ArrayStack.h

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_
#include "DataType.h"
#include <iostream>
using namespace std;

const size_t MAX_STACKSIZE = 1000;

template <class DataType> class ArrayStack;
template <class DataType> ostream& operator<<(ostream& os, const ArrayStack<DataType> & arrayStack);

template <class DataType>

class ArrayStack{

public:

  ArrayStack();

  ArrayStack(size_t count, const DataType &value);

  ArrayStack(const ArrayStack &other);

  ~ArrayStack();

  ArrayStack & operator=(const ArrayStack &rhs);
  friend ostream& operator<< <DataType>(ostream& os, const ArrayStack<DataType> &arrayStack);

  DataType & top();

  const DataType & top() const;

  void push(const DataType &value);

  void pop();

  size_t size() const;

  bool empty() const;

  bool full() const;

  void clear();

  void serialize(std::ostream& os) const;

private:

  DataType m_container[MAX_STACKSIZE];

  size_t m_top;

};

template <class DataType>
ArrayStack<DataType>::ArrayStack()
{
  m_container = new DataType[MAX_STACKSIZE];
  m_top = 0;
}
template <class DataType>
ArrayStack<DataType>::ArrayStack(size_t count, const DataType &value)
{
  m_container = new DataType[MAX_STACKSIZE];
  m_top = count;
  for(int i=0;i<count;i++)
    m_container[i] = value;
}
template<class DataType>
ArrayStack<DataType>::ArrayStack(const ArrayStack &other)
{
  m_container = new DataType[MAX_STACKSIZE];
  m_top = other.m_top;
  for(int i=0;i<other.size();i++)
    m_container[i] = other.m_container[i];
}
template <class DataType>
ArrayStack<DataType>::~ArrayStack()
{
  clear();
}
template<class DataType>
ArrayStack<DataType> & ArrayStack<DataType>::operator =(const ArrayStack<DataType> &rhs)
{
  m_top = rhs.m_top;
  for(int i=0;i<rhs.size();i++)
    m_container[i] = rhs.m_container[i];
  return this;
}
template<class DataType>
DataType & ArrayStack<DataType> ::top()
{
  if(!empty())
    return m_container[m_top];
  return NULL;
}
template<class DataType>
const DataType & ArrayStack<DataType> :: top() const
{
  if(!empty())
    return m_container[m_top];
  return NULL;
}
template<class DataType>
void ArrayStack<DataType>:: push(const DataType &value)
{
  if(!full())
  {
    m_container[m_top] = value;
    m_top++;
  }
}
template <class DataType>
void ArrayStack<DataType>::pop()
{
  if(!empty())
    m_top--;
}
template <class DataType>
size_t ArrayStack<DataType>:: size() const
{
  return m_top;
}
template <class DataType>
bool ArrayStack<DataType>::empty() const
{
  if(m_top == 0)
    return true;
  else
    return false;
}
template<class DataType>
bool ArrayStack<DataType>::full() const
{
  if(m_top == MAX_STACKSIZE)
    return true;
  else
    return false;
}
template <class DataType>
void ArrayStack<DataType>::clear()
{
  for(int i = 0; i < m_top; i++)
    m_container[i] = NULL;
  m_top = 0;
}
template <class DataType>
void ArrayStack<DataType>::serialize(std::ostream & os) const
{
  for(int i=m_top-1;i>=0;i--)
    os<<m_container[i]<<std::endl;
}
template <class DataType>
std::ostream& operator<<(std::ostream &os, const ArrayStack<DataType> &arrayStack)
{
  for(int i=arrayStack.m_top-1;i>=0;i--)
    os<<arrayStack.m_container[i]<<std::endl;
  return os;
}
#endif /* ARRAYSTACK_H_ */
//end of ArrayStack.h

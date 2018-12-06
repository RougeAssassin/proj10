#ifndef NODESTACK_H_
#define NODESTACK_H_
#include <iostream>
#include "DataType.h"
using namespace std;
template <class DataType> class NodeStack;
template <class DataType>
class Node{
  friend class NodeStack<DataType>;

public:
  Node();
  Node(const DataType &data, Node *next=NULL);
  DataType &data();
  const DataType &data() const;

//private:
  Node *m_next;
  DataType m_data;
};

template <typename DataType> class NodeStack;
template <class DataType> ostream& operator<<(ostream& os, const NodeStack<DataType> & nodeStack);


template <class DataType>
class NodeStack{

public:
  friend ostream& operator<< <DataType>(ostream& os, const NodeStack<DataType> &nodeStack);
  NodeStack();
  NodeStack(size_t count, const DataType &value);
  NodeStack(const NodeStack &other);
  ~NodeStack();
  NodeStack & operator=(const NodeStack &rhs);
  DataType & top();
  const DataType & top() const;
  void push(const DataType &value);
  void pop();
  size_t size() const;
  bool empty() const;
  bool full() const;
  void clear();
  void serialize(ostream& os) const;
private:
  Node<DataType> *m_top;
};

template<class DataType>
Node<DataType>::Node()
{
  m_data=0;
  m_next=NULL;
}
template<class DataType>
Node<DataType>::Node(const DataType& data, Node<DataType> *next)
{
  m_data = data;
  m_next = next;
}
template <class DataType>
DataType & Node<DataType>::data()
{
  return m_data;
}
template <class DataType>
const DataType & Node<DataType>::data() const
{
  return m_data;
}
template <class DataType>
NodeStack<DataType>::NodeStack()
{
  m_top = NULL;
}
template <class DataType>
NodeStack<DataType>::NodeStack(size_t count, const DataType &value)
{
  m_top = NULL;
  for(int i=0;i<count;i++)
    push(value);
}
template <class DataType>
NodeStack<DataType>::NodeStack(const NodeStack<DataType> &other)
{
  m_top = NULL;
  Node<DataType> *curr = other.m_top;
  Node<DataType> *prev = NULL;
  while(curr != NULL)
  {
    if(m_top == NULL)
    {
      m_top = new Node<DataType>(curr->m_data);
      prev = m_top;
    }
    else
    {
      Node<DataType> *node_pt = new Node<DataType>(curr->m_data);
      prev->m_next = node_pt;
      prev = node_pt;
    }
    curr = curr->m_next;
  }
}
template <class DataType>
NodeStack<DataType>:: ~NodeStack()
{
  clear();
}
template <class DataType>
NodeStack<DataType> & NodeStack<DataType>::operator=(const NodeStack<DataType> &rhs)
{
  if (this != &rhs) ///avoid self-copy
  {
    while(m_top != NULL)
    {
      Node<DataType> *node_pt = m_top;
      m_top = m_top->m_next;
      delete node_pt;
    }
    m_top = NULL;
    Node<DataType> *curr = rhs.m_top;
    Node<DataType> *prev = NULL;
    while(curr != NULL)
    {
      if(m_top == NULL)
      {
        m_top = new Node<DataType>(curr->m_data);
        prev = m_top;
      }
      else
      {
        Node<DataType> *node_pt = new Node<DataType>(curr->m_data);
        prev->m_next = node_pt;
        prev = node_pt;
      }
      curr = curr->m_next;
}
  }
  return *this;
}
template <class DataType>
DataType& NodeStack<DataType>::top()
{
  if(!empty())
    return m_top->m_data;
  return NULL;
}
template <class DataType>
const DataType & NodeStack<DataType>::top() const
{
  if(!empty())
    return m_top->m_data;
  return NULL;
}
template<class DataType>
void NodeStack<DataType>::push(const DataType &value)
{
  if(m_top == NULL)
    m_top =new Node<DataType>(value);
  else
  {
    Node<DataType> *node_pt = new Node<DataType>(value);
    node_pt->m_next = m_top;
    m_top = node_pt;
  }
}
template <class DataType>
void NodeStack<DataType>::pop()
{
  if(!empty())
  {
    Node<DataType> *node_pt = m_top;
    m_top = m_top->m_next;
    delete(node_pt);
  }
}
template <class DataType>
size_t NodeStack<DataType>::size() const
{
  int count = 0;
  Node<DataType> *node_pt = m_top;
  while(node_pt != NULL)
  {
    count++;
    node_pt = node_pt->m_next;
  }
  return count;
}
template <class DataType>
bool NodeStack<DataType>::empty() const
{
  return(m_top == NULL);
}
template <class DataType>
bool NodeStack<DataType>::full() const
{
  return false;
}
template <class DataType>
void NodeStack<DataType>::clear()
{
  while(m_top != NULL)
  {
    Node<DataType> *node_pt = m_top;
    m_top = m_top->m_next;
    delete node_pt;
  }
  m_top = NULL;
}
template <class DataType>
void NodeStack<DataType>::serialize(ostream& os) const
{
  if(m_top == NULL)
    cout <<" Empty Stack" << endl;
  else
  {
    Node<DataType> *curr = m_top;
    while(curr != NULL)
    {
      cout << curr->m_data << endl;
      curr = curr->m_next;
    }
  }
}
template <class DataType>
ostream& operator<<(ostream& os, const NodeStack<DataType> &nodeStack)
{
  if(nodeStack.m_top == NULL)
    cout << " Empty Stack" << endl;
  else
  {
  Node<DataType> *curr = nodeStack.m_top;
  while(curr != NULL)
  {
    cout << curr->m_data << endl;
    curr = curr->m_next;
  }
  }
  return os;
}
#endif

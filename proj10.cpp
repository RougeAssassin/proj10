#include <iostream>
#include "ArrayStack.h"
#include "NodeStack.h"
#include "DataType.h"


using namespace std;

int main(){

  cout << "Testing NodeStack default ctor" << endl;
  NodeStack<DataType>* ns_def = new NodeStack<DataType>;
  cout << *ns_def << endl;
  cout << "Testing Node parm ctor" << endl;
  DataType tester;
  NodeStack<DataType>* ns_parm = new NodeStack<DataType>(5,tester);

  return 0;
}

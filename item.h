#include <iostream>
#ifndef ITEMH_DEFINED
#define ITEMH_DEFINED
using namespace std;

class Item{
 private:
  char* name;
 public:
  Item (char* newName);
  char* getName();
};

#endif

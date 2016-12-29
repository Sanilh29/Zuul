#include <iostream>
#ifndef ITEMH_DEFINED
#define ITEMH_DEFINED
using namespace std;

class item{
 private:
  char* name;
 public:
  item (const char* newName);
  ~item();
  char* getName();
};

#endif

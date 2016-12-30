//Sanil Hattangadi, created method that is going to be used for the item.cpp and created constructor
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

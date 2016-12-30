//Sanil Hattangadi. cpp file for items
#include <iostream>
#include "item.h"
#include <cstring>

using namespace std;

item::item(const char* newName){//creates the actual name of the item
  name = strdup(newName);
}
item::~item(){//to delete the item
  delete name;
}
char* item::getName(){//returns the name of the item
  return name;
}

#include <iostream>
#include "item.h"
#include <cstring>

using namespace std;

item::item(const char* newName){
  name = strdup(newName);
}
item::~item(){
  delete name;
}
char* item::getName(){
  return name;
}

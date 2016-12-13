#include <iostream>
#include "item.h"

using namespace std;

Item::Item(char* newName){
  name = newName;
}
char* Item::getName(){
  return name;
}

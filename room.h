//Sanil Hattangadi, creates the methods that are going to be user and the variables
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include "item.h"
#include <cstring>
#include <vector>

using namespace std;

//for the map, overload the for loop to skip compare
struct cmp_string{
  bool operator() (char const *a, char const *b){
    return strcmp(a,b) < 0;
  }
};

class room{
 private:
  map <const char*, room*, cmp_string> exits;
  vector<item*> items;
  char* description;
  char* name;
 public://methods that are created
  room(const char* newName, const char* newDescription, vector<room*>* roomList);
  ~room();
  char* getName();
  void moveItem(vector<item*>* inventory, char* itemName);
  void dropItem(vector<item*>* inventory, char* itemName);
  void setExit(const char* exitName, room* exitRoom);
  void addItem(item* item);
  void printItems(); 
  void printExit();
  void printDescription();
  room* getExit(char* exitKey);
};

#endif





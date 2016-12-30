#include <iostream>
#include "room.h"
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;

room::room(const char* newDescription, vector<room*>* roomList){
  description = strdup(newDescription);
  roomList-> push_back(this);
}

room::~room(){
  delete description;
  for (vector<item*>::iterator it=items.begin(); it !=items.end(); it++){
    delete *it;
  }
  exits.erase(exits.begin(),exits.end());
}

char* room::getName(){
  return name;
}

void room::moveItem(vector<item*>* inventory, char* itemName){//moving the item from the room to the inventory
  for (vector<item*>::iterator it=items.begin(); it != items.end(); it++){
    if (0==strcmp((*it)->getName(), itemName)){
      inventory->push_back(*it);
      items.erase(it);
      cout << "You picked up:" << itemName << endl;
      return;
    }
  }
  cout << "There's not a " << itemName << "in the room." << endl;
}

void room::dropItem(vector<item*>* inventory, char* itemName){
  for (vector<item*>::iterator it=inventory->begin(); it != inventory->end(); it++){
    if (0== strcmp((*it)->getName(), itemName)){
      items.push_back(*it);
      inventory->erase(it);
      cout << "You dropped:" << itemName << endl;
    }
  }
  cout << "You don't have:" << itemName << endl;
}

void room::setExit(const char* exitName, room* exitRoom){
  exits[exitName] = exitRoom;
}

void room::addItem(item* item){
  items.push_back(item);
}

void room::printItems(){ //print out the items in a room
  bool presentItems=false;
  for (vector<item*>::iterator it=items.begin(); it != items.end(); it++){
    cout << (*it)->getName() << endl;
    presentItems = true;
 }
  cout << "There are no items in the room." << endl;
}

void room::printExit(){
  for (map<const char*, room*>::iterator it=exits.begin(); it != exits.end(); it++){
    cout << (*it).first << endl;
  }
}

void room::printDescription(){
  cout << "You are " << description << endl;
  printItems();
  cout << "The exits are: " << endl;
  printExit();
}

room* room::getExit(char* exitKey){
  map<const char*, room*>::iterator it = exits.find(exitKey);
  if (it !=exits.end()){
    return exits[exitKey];
  }
  else {
    return NULL;
  }
}

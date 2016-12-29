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
  for (vector<item*>::iterator it=items.begin(); it !=items.end() it++){
    delete *it;
  }
  exits.erase(exits.begin(),exits.end());
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
  cout << "There's not a" << itemName << "in the room." << endl;
}

void room::dropItem(vector<item*>* inventory, char* itemName){
  for (vector<item*>::iterator it=inventory.begin(); it != inventory.end(); it++){
    
  }
}

void room::setExit(const char* exitName, room* exitRoom){

}

void room::addItem(item* item){

}

void room::printItems(){

}

void room::printExit(){

}

void room::printDescription(){

}

room* room::getExit(char* exitKey){

}

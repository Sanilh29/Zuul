//Sanil Hattangadi, I actually create my directions for my room methods
#include <iostream>
#include "room.h"
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;

room::room(const char* newName, const char* newDescription, vector<room*>* roomList){
  description = strdup(newDescription);
  name = strdup(newName);
  roomList-> push_back(this);
}

room::~room(){//what to do when i quit so there are no memory leaks
  delete description;
  delete name;
  for (vector<item*>::iterator it=items.begin(); it !=items.end(); it++){
    delete *it;
  }
  exits.erase(exits.begin(),exits.end());
}

char* room::getName(){//get the name of the room
  return name;
}

void room::moveItem(vector<item*>* inventory, char* itemName){//moving the item from the room to the inventory
  for (vector<item*>::iterator it=items.begin(); it != items.end(); it++){//go through item vector
    if (0==strcmp((*it)->getName(), itemName)){//if there is an item named the same thing as the user inputs
      inventory->push_back(*it);//put in inventory
      items.erase(it);//delete it from item vector
      cout << "You picked up:" << itemName << endl;
      return;
    }
  }
  cout << "There's not a " << itemName << " in the room." << endl;
}

void room::dropItem(vector<item*>* inventory, char* itemName){//droping an item from the nventory to the room
  for (vector<item*>::iterator it=inventory->begin(); it != inventory->end(); it++){//go trough inventopry
    if (0== strcmp((*it)->getName(), itemName)){//see if inventory name is same as name inputted by user
      items.push_back(*it);//put it in item vector
      inventory->erase(it);//take out of inventory
      cout << "You dropped:" << itemName << endl;
      return;
    }
  }
  cout << "You don't have:" << itemName << endl;
}

void room::setExit(const char* exitName, room* exitRoom){//set exits
  exits[exitName] = exitRoom;//says what room is in what direction of the room
}

void room::addItem(item* item){//adding items to the vector
  items.push_back(item);
}

void room::printItems(){ //print out the items in a room
  bool presentItems=false;
  for (vector<item*>::iterator it=items.begin(); it != items.end(); it++){//go through item vector
    cout << "The item in the room is:" << (*it)->getName() << endl;//print out the items in the room
    presentItems = true;
 }
  if (!presentItems){//if there are no items in the room
  cout << "There are no items in the room." << endl;
  }
}

void room::printExit(){//print out the exits for the user
  for (map<const char*, room*>::iterator it=exits.begin(); it != exits.end(); it++){
    cout << (*it).first << endl;
  }
}

void room::printDescription(){//prints out the exits, items and description of the room
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

/*void room::checkWin(vector<item*>* inventory, char* itemName)
  for (vector<item*>::iterator it=inventory->begin(); it !=inventory.end();it++){
    if (0==strcmp((*it)->getName(), "keys")){
      cout << "You win. You made it to the dungeon with the keys." << endl;
      return;
    }
  }
  }*/

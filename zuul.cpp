#include <iostream>
#include <vector>
#include <cstring>
#include "item.h"
#include "room.h"
using namespace std;

void roomSetup (vector<room*>* roomList);
bool wordCompare (char* a, const char* b);

int main() {
  vector<room*> roomList;
  vector<item*> inventory;
  room* currentRoom;
  char command[30];
  cout << "Welcome to Zuul. Get to the closet to win." << endl;
  bool playing = true;
  roomSetup(&roomList);
  currentRoom = *roomList.begin();
  currentRoom->printDescription();
  cout << "Enter a command: go, drop, inventory, get, or quit." << endl;
  cin >> command;
  cin.ignore();
  while (playing==true){
    cout << "Enter a command: go, drop, inventory, get, or quit." << endl;
    cin >> command;
    if (wordCompare(command, "go")){
      char direction[30];
      cout << "north, south, east, or west" << endl;
      cin >> direction;
      room* newRoom = currentRoom->getExit(command + 3); 
      if (newRoom){
	currentRoom = newRoom;
	currentRoom->printDescription();
	if (0== strcmp(currentRoom->getName(), "closet")){
	  cout <<"You win! You made it to the end." << endl;
	  playing = false;
	 }
      }
    }
    else if (wordCompare(command, "drop")){
      currentRoom->dropItem(&inventory, command + 5);
    }
    else if (wordCompare(command, "get")){
      currentRoom->moveItem(&inventory, command + 4);
    }
    else if (wordCompare(command, "quit")){
      playing = false;
    }
    else if (wordCompare(command, "inventory")){
      bool items = false;
      for (vector<item*>::iterator it = inventory.begin(); it !=inventory.end(); it++){
	cout << (*it)->getName();
	items= true;
      }
      if (!items){
	cout << "You don't have any items in your inventory yet." << endl;
      }
    }
    /* cin.ignore();
    else {
      cout << "Please enter a command: go, drop, get, inventory, or quit." << endl;
      }*/
    cin.ignore();
  }
  for (vector<item*>::iterator it = inventory.begin(); it !=inventory.end(); it++){
    delete *it;
  }
  for (vector<room*>::iterator it = roomList.begin(); it != roomList.end(); it++){
    delete *it;
  }
  // vector<item*> items;
  // items.push_back(tuxedo);
  // items.push_back(volleyball);
  // items.back_back(42);
  // items.push_back(bottle);
  // items.push_back(keys);
}

void roomSetup(vector<room*>* roomList){
  room* kitchen = new room ("in the kitchen... there seems to be a lot of luxurious foods on the counter", roomList);
  room* pool = new room ("in the indoor pool area...it looks like there in a huge water slide going from the roof to the pool", roomList);
  room* theatre = new room ("in a movie theatre... the movie playing is Star Wars", roomList);
  room* pub = new room ("in an empty pub...there are overturned chairs and tables", roomList);
  room* storage = new room ("in the storage room... there are boxes all over the room", roomList);
  room* office = new room ("in the office... there is a computer running League of Legends", roomList);
  room* conference_room = new room ("in the conference room...there is a broken table", roomList);
  room* closet = new room ("in the closet... there is a variety of tuxedos", roomList);
  room* game_room = new room ("in the game room...there is a PS3 running Fallout", roomList);
  room* bedroom = new room ("in the bedroom...the bed is made and the floor is spotless", roomList);
  room* bunker = new room ("in the bunker...it's cold and there is 1 hard bed", roomList);
  room* lab = new room ("in the science lab...there are gamma radiation suits", roomList);
  room* wine_cellar = new room ("in the wine cellar...there are ancient empty wine bottles in the cabinet", roomList);
  room* gym = new room ("in the gym...there are basketballs and volleyballs lying on the ground", roomList);
  room* dungeon = new room ("in the dungeon...there is a 1 empty cellar", roomList);

  kitchen->setExit("south", pub);

  pool->setExit("east", theatre);
      
  theatre->setExit("east", pub);
  theatre->setExit("west", pool);
      
  pub->setExit("north", kitchen);
  pub->setExit("east", storage);
  pub->setExit("south", conference_room);
  pub->setExit("west", theatre);
      
  storage->setExit("east", office);
  storage->setExit("west", pub);
      
  office->setExit("south", closet);
  office->setExit("west", storage);
 
  closet->setExit("south", bedroom);
  closet->setExit("north", office);
      
  bedroom->setExit("north", closet);
      
  conference_room->setExit("north", pub);
  conference_room->setExit("south", game_room);
      
  game_room->setExit("north", conference_room);
  game_room->setExit("south", wine_cellar);
      
  lab->setExit("east", wine_cellar);
  lab->setExit("west", bunker);
  
  bunker->setExit("east", lab);

  wine_cellar->setExit("north", game_room);
  wine_cellar->setExit("east", gym);
  wine_cellar->setExit("west", lab);
      
  gym->setExit("east", dungeon);
  gym->setExit("west", wine_cellar);
      
  dungeon->setExit("west", gym);
    
  item* tuxedo = new item ("tuxedo");
  item* volleyball = new item ("volleyball");
  item* movie = new item ("42");
  item* bottle = new item ("bottle");
  item* keys= new item ("keys");

  closet->addItem(tuxedo);
  gym->addItem(volleyball);
  theatre->addItem(movie);
  wine_cellar->addItem(bottle);
  dungeon->addItem(keys);
}

bool wordCompare(char* a, const char* b){
  for (int i=0; i < strlen(b); i++){
    if (a[i] != b[i]){
      return false;
    }
  }
  return true;
}

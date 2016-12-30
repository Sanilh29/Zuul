//Sanil Hattangadi, December 30th, c++
//The program is called Zuul. You walk around the map, can pick up items, drop items, and win.
#include <iostream>
#include <vector>
#include <cstring>
#include "item.h"
#include "room.h"
#include <algorithm>
using namespace std;

void roomSetup (vector<room*>* roomList);
bool wordCompare (char* a, const char* b);

int main() {
  vector<room*> roomList; //create vecotr that hold rooms
  vector<item*> inventory; //create vector that holds items in the inventory
  room* currentRoom;
  char command[32];
  cout << "Welcome to Zuul. Get to the dungeon with the keys to win." << endl;
  bool playing = true; //start with true
  roomSetup(&roomList);
  currentRoom = *roomList.begin();//player starts in kitchen because its the first room in roomSetup
  currentRoom->printDescription();//prints description of kitchen
  while (playing==true){
    cout << "=======================================" << endl;
    cout << "Enter a command: go, drop, inventory, get, or quit." << endl;
    cout << "If you type go, follow it up with a direction: north, south, east, west." << endl;
    cin.getline(command, 32);
    if (wordCompare(command, "go")){//if go
      room* newRoom = currentRoom->getExit(command + 3);//add 3 to skip the word go and look at direction 
      if (newRoom){
	currentRoom = newRoom;
	currentRoom->printDescription();
	if (0== strcmp(currentRoom->getName(), "dungeon")){//must be in dungeon with the keys
	  if (inventory.begin() != inventory.end()){
	    for (vector<item*>::iterator it = inventory.begin(); it!= inventory.end(); it++){
	      if ((strcmp((*it)->getName(),"keys"))==0){//if you have keys
		cout <<"You win! You made it to the end." << endl;//you win
		return 0;
	      }
	    }
	    for (vector<item*>::iterator it = inventory.begin(); it!= inventory.end(); it++){
              if ((strcmp((*it)->getName(),"keys"))!=0){//if you have keys
                cout <<"You lose! You do not have the keys." << endl;//you win
                return 0;
              }
            }
	  }
	  else {//if theres nothing in the inventory, you lose 
	    cout <<"You don't have the keys. You lose." << endl;
	    playing =false;
	  }
	}
      }
    }
    else if (wordCompare(command, "drop")){//if user inputs drop
      currentRoom->dropItem(&inventory, command + 5); //skip the word drop and look at the item
    }
    else if (wordCompare(command, "get")){//if user inputs get
      currentRoom->moveItem(&inventory, command + 4);//skip the word get and look at the item
    }
    else if (wordCompare(command, "quit")){
      playing = false;//stop while loop
    }
    else if (wordCompare(command, "inventory")){//print out the items in the inventory
      bool items = false;//print out each item in the inventory until true
      for (vector<item*>::iterator it = inventory.begin(); it !=inventory.end(); it++){
	cout << (*it)->getName()<< endl;
	items= true;
      }
      if (!items){
	cout << "You don't have any items in your inventory yet." << endl;
      }
    }
    //cin.ignore();
    /* else {
      cout << "Please enter a command: go, drop, get, inventory, or quit." << endl;
      }*/
  }
  for (vector<item*>::iterator it = inventory.begin(); it !=inventory.end(); it++){
    delete *it;
  }
  for (vector<room*>::iterator it = roomList.begin(); it != roomList.end(); it++){
    delete *it;
  } 
}

void roomSetup(vector<room*>* roomList){//creates new room and within the (), the name and description is given, added to the vector
  room* kitchen = new room ("kitchen", "in the kitchen... there seems to be a lot of luxurious foods on the counter", roomList);
  room* pool = new room ("pool", "in the indoor pool area...it looks like there in a huge water slide going from the roof to the pool", roomList);
  room* theatre = new room ("theatre", "in a movie theatre... the movie playing is Star Wars", roomList);
  room* pub = new room ("pub", "in an empty pub...there are overturned chairs and tables", roomList);
  room* storage = new room ("storage", "in the storage room... there are boxes all over the room", roomList);
  room* office = new room ("office", "in the office... there is a computer running League of Legends", roomList);
  room* conference_room = new room ("Conference room", "in the conference room...there is a broken table", roomList);
  room* closet = new room ("closet", "in the closet... there is a variety of tuxedos", roomList);
  room* game_room = new room ("game room", "in the game room...there is a PS3 running Fallout", roomList);
  room* bedroom = new room ("bedroom", "in the bedroom...the bed is made and the floor is spotless", roomList);
  room* bunker = new room ("bunker", "in the bunker...it's cold and there is 1 hard bed", roomList);
  room* lab = new room ("lab", "in the science lab...there are gamma radiation suits", roomList);
  room* wine_cellar = new room ("wine cellar", "in the wine cellar...there are ancient empty wine bottles in the cabinet", roomList);
  room* gym = new room ("gym", "in the gym...there are basketballs and volleyballs lying on the ground", roomList);
  room* dungeon = new room ("dungeon", "in the dungeon...there is a 1 empty cellar", roomList);

  //sets the exits and tells what rooms are where in relation to the room
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
 
  //creates the items and name
  item* tuxedo = new item ("tuxedo");
  item* volleyball = new item ("volleyball");
  item* movie = new item ("movie");
  item* bottle = new item ("bottle");
  item* keys= new item ("keys");

  //adds the items to the rooms
  closet->addItem(tuxedo);
  gym->addItem(volleyball);
  theatre->addItem(movie);
  wine_cellar->addItem(bottle);
  game_room->addItem(keys);
}

bool wordCompare(char* a, const char* b){//compares the first word from the user input command to a given word
  for (int i=0; i < strlen(b); i++){//go through certain word (go, get, quit, drop)
    if (a[i] != b[i]){//see if user input is exactly the same
      return false;
    }
  }
  return true;
}

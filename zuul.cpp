#include <iostream>
#include <vector>
#include <cstring>
#include "item.h"
#include "room.h"
using namespace std;

int main() {
  vector<room*> roomList;
  vector<item*> inventory;
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
     
    
}

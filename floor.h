#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <iostream>
#include <vector>
#include "chamber.h"
#include "cell.h"
#include "character.h"
#include "player.h"
#include <string>
#include <fstream>
#include "posn.h"

class Floor 
{ 
  std::vector<std::vector<Cell*>> theFloor;
  std::vector<Chamber*> theChambers;
  std::vector<Character*> theEnemies;
  int level, len, wid;
  
  Player* mainChar;

  public:
  
  Floor( int lvl, std::string cmd );
  ~Floor();
  void clearFloor();
  void move( Character* cp1, std::string direction );
  void moveEnemies();
  void init();
  std::string isWon();
  bool isAtStairs();
  void set(int r, int c, Character* pc1 );
  Character* getMainChar();    
  void newTurn();
  void attack(std::string direction);
  friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif

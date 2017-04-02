#include "character.h"
#include "player.h"
#include "enemy.h"
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "cell.h"
#include "floor.h"
int main() 
{
  std::string str;
  std::cout << "Choose your race" << std::endl;
  std::cout << "(S)hade, (D)row, (V)ampire, (T)roll, (G)oblin" << std::endl;
  std::string cmd;
  Floor *floor;
  int level = 1;
  int turn = 0;  
  //choose character
  while(std::cin >> cmd )
  {
    if (std::cin.eof()) return 0;
  
    if (cmd == "s" || cmd == "S" || cmd == "D" || cmd == "d" || cmd == "V" || cmd == "v" || cmd == "T" || cmd == "t" || cmd == "G" || cmd == "g") 
    { 
      floor = new Floor( 1, cmd );
      break;
    }
    else {
       std::cout << "Try again" << std::endl; 
    }
  }
  floor->init();
  std::cout << *floor;
  std::string s;
  
  //action loop:  
  while(std::cin >> s)
  {
    if(s == "no" || s == "so" || s == "ea" || s == "ew" || s == "ne" || s == "se" || s == "we" || s == "sw"){
    floor->move(floor->getMainChar(), s);
}
    if(s == "a"){
    std::string atkPos;
    std::cin >> atkPos;
    floor->attack(atkPos);
}
    floor->moveEnemies();
    std::cout << *floor;
  }
}
 

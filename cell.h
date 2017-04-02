#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <vector>
#include <utility>
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "player.h"
#include "enemy.h"
#include "subscriptions.h"
#include <string>

class Cell 
{

  std::vector< Cell* > nbors;
  
  Character* cp;
  char symbol;
  std::string name;
  int row, col;
  bool emov, pmov, imov;
  bool stair;
 public:

  void attachNbor( Cell* cell );
  void notifyNbors();

  Cell( char sym, int r, int c );
  ~Cell();
  void set( Character* cp1);       
  void setStair();
  void unSet();
  char getSymbol() const;
  std::string getname() const;
  Character* getCp() const;
  int getRow() const;
  int getCol() const;
  bool getEmov() const;
  bool getPmov() const;
  bool getImov() const;
  bool getStair()const;
  void link( Cell* nbor );
  void notify( Cell &whoNoitified );

};
#endif

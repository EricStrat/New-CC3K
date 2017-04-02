#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>

class Character 
{

  protected:

  int HP;
  int baseHP;
  int atk;
  int baseAtk;
  int def;
  int baseDef;
  int gold;
  std::string race;
  std::string type;
  char symbol;  
  int Row;
  int Col;

  public:

  Character( int HP, int baseHP, int atk, int baseAtk, int def, int baseDef, int gold, std::string race, char symbol, std::string type );
  virtual ~Character();
  Character & operator=(const Character &cp1); 
  int getHP();
  int getAtk();
  int getDef();
  int getGold();
  int getBaseHP();
  int getBaseAtk();
  int getBaseDef();
  std::string getType();
  char getSymbol();
  int getRow();
  int getCol();
  void setHP();
  void setAtk();
  void setDef();
  std::string getRace();
  virtual int damage( Character &defender );
  virtual void mutAtk( int i );
  virtual void mutDef( int i );
  virtual void mutHP( int i );
  virtual void mutGold( int i );
  virtual void mutRow(int r);
  virtual void mutCol(int c);
  virtual void slain();
  virtual bool fiftyFifty(); 
  virtual std::string getInfo();  

};
#endif

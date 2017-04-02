		


#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"

void Cell::attachNbor( Cell* cell ) { nbors.emplace_back( cell );  }

void Cell::notifyNbors()
{
  for ( auto it = nbors.begin(); it != nbors.end(); ++it ) (*it)->notify( *this );
}


Cell::Cell( char sym, int r, int c) : cp{nullptr}, row{r}, col{c} 
{
	if ( sym == 'A' || sym == 'B' || sym == 'C' || sym == 'D' || sym == 'E' )
	{
		symbol = '.';
		name = "tile";
		pmov = true;
		imov = true;
		emov = true;
		stair = false;

	}
	else {
		symbol = sym;
		if ( sym == '#' )
		{
			name = "passage";
			pmov = true;
			imov = false;
			emov = false;
			stair = false;
		}
		else if ( sym == '|' )
		{
			name = "Vwall";
			pmov = false;
			imov = false;
			emov = false;
			stair = false;
		}
		else if ( sym == '-' )
		{
			name = "Hwall";
			pmov = false;
			imov = false;
			emov = false;
			stair = false;
		}
		else if ( sym == ' ' )
		{
			name = "blank";
			pmov = false;
			imov = false;
			emov = false;
			stair = false;
		}
		else if ( sym == '\n' )
		{
			name = "newline";
			pmov = false;
			imov = false;
			emov = false;
			stair = false;
		}
		else if ( sym == '\\' )
		{
			name = "stairs";
			pmov = true;
			imov = false;
			emov = false;
			stair = true;
		}       
		else if ( sym == '+' )
		{
			name = "exit";
			pmov = true;
			imov = false;
			emov = false;
			stair = false;
		}
	}
}

Cell::~Cell() { delete cp; }

void Cell::link( Cell* nbor )
{
   attachNbor( nbor );
   nbor->attachNbor( this );
}

Character* Cell::getCp() const { return cp; }
char Cell::getSymbol() const { return symbol; }
std::string Cell::getname() const { return name; }
int Cell::getRow() const { return row; }
int Cell::getCol() const { return col; }
bool Cell::getEmov() const { return emov; }
bool Cell::getImov() const { return imov; }
bool Cell::getPmov() const { return pmov; }
bool Cell::getStair() const {return stair; }
void Cell::unSet() {
  if ( cp->getType() == "enemy" ) { 
     emov = true;
     pmov = true;
  }
  else  pmov = true;
  cp = nullptr;
}


void Cell::set( Character* cp1 ) 
{ 
    cp = cp1;
    emov = false;
    pmov = false;
}

void Cell::notify( Cell &whoNotified )
{
  if (cp) if ( whoNotified.cp->getType() == "player" ) static_cast<Player*>(whoNotified.cp)->attackedBy( *static_cast<Enemy*>(cp) ); 
}
void Cell::setStair(){
 cp = nullptr;
  symbol = '\\';
  stair = true;
  name = "stair";
  emov = false;
  pmov = true;
  imov = false;
} 

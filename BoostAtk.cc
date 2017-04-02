#include "BoostAtk.h"

BoostAtk::BoostAtk(Player * player) : Potion{player} {
	potiontype = "BA";
	this->mutAtk(5);
}

std::string BoostAtk::getInfo() {
	return potiontype;
}

BoostAtk::~BoostAtk() {
	delete player;
}

void BoostAtk::attack( Human &e ) {}
void BoostAtk::attack( Dwarf &e ) {}
void BoostAtk::attack( Elf &e ) {}
void BoostAtk::attack( Orc &e ) {}
void BoostAtk::attack( Merchant &e ) {}
void BoostAtk::attack( Dragon &e ) {}
void BoostAtk::attack( Halfling &e ) {}
void BoostAtk::attackedBy( Enemy &e ) {}


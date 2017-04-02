#include "BoostDef.h"

BoostDef::BoostDef(Player * player) : Potion{player} {
	potiontype = "BD";
	this->mutDef(5);
}

std::string BoostDef::getInfo() {
	return potiontype;
}

BoostDef::~BoostDef() {
	delete player;
}

void BoostDef::attack( Human &e ) {}
void BoostDef::attack( Dwarf &e ) {}
void BoostDef::attack( Elf &e ) {}
void BoostDef::attack( Orc &e ) {}
void BoostDef::attack( Merchant &e ) {}
void BoostDef::attack( Dragon &e ) {}
void BoostDef::attack( Halfling &e ) {}
void BoostDef::attackedBy( Enemy &e ) {}


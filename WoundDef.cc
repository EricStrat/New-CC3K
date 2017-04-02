#include "WoundDef.h"

WoundDef::WoundDef(Player * player) : Potion{player} {
	potiontype = "WD";
	this->mutDef(-5);
}

std::string WoundDef::getInfo() {
	return potiontype;
}

WoundDef::~WoundDef() {
	delete player;
}

void WoundDef::attack( Human &e ) {}
void WoundDef::attack( Dwarf &e ) {}
void WoundDef::attack( Elf &e ) {}
void WoundDef::attack( Orc &e ) {}
void WoundDef::attack( Merchant &e ) {}
void WoundDef::attack( Dragon &e ) {}
void WoundDef::attack( Halfling &e ) {}
void WoundDef::attackedBy( Enemy &e ) {}


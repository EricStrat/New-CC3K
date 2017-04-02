#include "Potion.h"
Potion::Potion(Player * player) : Player{player->getHP(), player->getBaseHP(), player->getAtk(), player->getBaseAtk(), player->getDef(), player->getBaseDef(), player->getGold(), player->getRace()}, player{player} {
	potiontype = "N/A";
}


Potion::~Potion() { delete player; }                                             

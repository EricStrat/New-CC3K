#ifndef POTION_H
#define POTION_H
#include <string>
#include "player.h"


class Potion : public Player {
        protected:
	Player * player;
        std::string potiontype;
        public:
        Potion(Player * player);
        virtual ~Potion();
};

#endif

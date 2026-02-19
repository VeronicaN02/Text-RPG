#pragma once
#include "Poition.h"

class ManaPotion : public Poition {
public:
	void use(Character& character) override {
		character.addMana(2);
		std::cout << "Мана увеличелась на 2!\n";
	}
};
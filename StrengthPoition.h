#pragma once
#include "Poition.h"

class StrengthPotion : public Poition {
public:
	void use(Character& character) override {
		character.addStrength(2);
		std::cout << "Сила увеличелась на 2!\n";
	}
};
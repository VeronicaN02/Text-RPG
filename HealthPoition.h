#pragma once
#include "Poition.h"

class HealthPotion : public Poition {
public:
	void use(Character& character) override {
		character.addHealth(2);
		std::cout << "Здоровье увеличелось на 2!\n";
	}
};
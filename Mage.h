#pragma once
#include "Character.h"

//Класс наследуется от базового
class Mage : public Character {
public:
	Mage(const std::string& name) : Character(name) {
		mana += 3;
	}
};
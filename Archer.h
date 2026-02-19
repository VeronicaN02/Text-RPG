#pragma once
#include "Character.h"

//Класс наследуется от базового
class Archer : public Character {
public:
	Archer(const std::string& name) : Character(name) {
		health += 3;
	}
};
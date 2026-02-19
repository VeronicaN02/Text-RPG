#pragma once
#include "Character.h"

//Класс наследуется от базового
class Warrior : public Character {
public:
	Warrior(const std::string& name) : Character(name) {
		strength += 3;
	}
};
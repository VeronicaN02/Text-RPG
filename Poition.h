#pragma once
#include "Character.h"

//Базовый класс зелья
class Poition {
public:
	virtual ~Poition() {}
	virtual void use(Character& character) {
		std::cout << "Ничего не произошло\n";
	}
};
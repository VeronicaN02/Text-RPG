#pragma once
#include <iostream>
#include <string>
#include <vector>

//Базовый класс
class Character {
protected:
	std::string name;

	int health = 5;
	int mana = 5;
	int strength = 5;

	std::vector<std::string> inventory;

public:
	Character(const std::string& name) : name(name) {}
	virtual ~Character() {}

	virtual void showStatus() const {
		std::cout << "\nИмя: " << name << "\n";
		std::cout << "Здоровье: " << health << "\n";
		std::cout << "Мана: " << mana << "\n";
		std::cout << "Сила: " << strength << "\n";
	};

	//Для других классов
	void addHealth(int amount) { health += amount; }
	void addMana(int amount) { mana += amount; }
	void addStrength(int amount) { strength += amount; }

	//Инвентарь
	void addToInventory(const std::string& item) {
		inventory.push_back(item);
	}

	void showInvetory() const {
		if (inventory.empty()) {
			std::cout << "Пусто\n";
			return;
		}
		std::cout << "Инвентарь:\n";
		for (size_t i = 0; i < inventory.size(); ++i) {
			if (inventory[i] == "Зелье здоровья") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			else if (inventory[i] == "Зелье маны") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			else if (inventory[i] == "Зелье силы") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

			std::cout << i + 1 << ". " << inventory[i] << "\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	}

	std::string useItem(size_t index) {
		if (index == 0 || index > inventory.size()) return"";
		std::string item = inventory[index - 1];
		inventory.erase(inventory.begin() + index - 1);
		return item;
	}

	size_t getInventorySize() const {
		return inventory.size();
	}
};
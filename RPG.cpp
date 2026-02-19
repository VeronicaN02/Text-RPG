// RPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"

#include "HealthPoition.h"
#include "ManaPoition.h"
#include "StrengthPoition.h"

//Создание персонажа
std::unique_ptr<Character> createCharacter() {
    std::string name;
    int choice;

    std::cout << "Введите имя персонажа: ";
    std::cin >> name;

    std::cout << "\nВыберите класс:\n";
    std::cout << "1. Воин\n";
    std::cout << "2. Маг\n";
    std::cout << "3. Лучник\n";
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    std::unique_ptr<Character> hero;
    switch (choice) {
    case 1: hero = std::make_unique<Warrior>(name);
    case 2: hero = std::make_unique<Mage>(name);
    case 3: hero = std::make_unique<Archer>(name);
    default:
        std::cout << "Неверный выбор. Создан Воин\n";
        hero = std::make_unique<Warrior>(name);
        break;
    }
    //Генерация зелий
    int numPoitions = std::rand() % 5 + 1;
    for (int i = 0; i < numPoitions; ++i) {
        int type = std::rand() % 3;
        if (type == 0) hero->addToInventory("Зелье здоровья");
        else if (type == 1) hero->addToInventory("Зелье маны");
        else hero->addToInventory("Зелье силы");
    }
    return hero;
}

//Меню зелий
//void poitionMenu(Character& hero) {
//    int choice;
//
//    std::cout << "\nВыберите зелье:\n";
//    std::cout << "1. Здоровья\n";
//    std::cout << "2. Маны\n";
//    std::cout << "3. Силы\n";
//    std::cout << "Ваш выбор: ";
//    std::cin >> choice;

//    std::unique_ptr<Poition> poition;
//    switch (choice) {
//    case 1: poition = std::make_unique<HealthPotion>(); break;
//    case 2: poition = std::make_unique<ManaPotion>(); break;
//    case 3: poition = std::make_unique<StrengthPotion>(); break;
//    default:
//        std::cout << "Неверный выбор\n";
//        return;
//    }
//    poition->use(hero);
//}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    //Генератор для инвентаря
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    auto hero = createCharacter();

    int choice;

    while (true) {
        std::cout << "\n===== Меню =====\n";
        std::cout << "1. Характеристики\n";
        std::cout << "2. Инвентарь\n"; //"2. Использовать зелье\n";
        std::cout << "3. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        if (choice == 1) {
            hero->showStatus();
        }
        else if (choice == 2) {
            hero->showInvetory();
            if (hero->getInventorySize() == 0) {
                continue; 
            }
            int itemChoice;
            std::cout << "Выберите предмет для использования (0 - отмена): ";
            std::cin >> itemChoice;
            if (itemChoice != 0) {
                std::string item = hero->useItem(itemChoice);
                if (item == "Зелье здоровья") HealthPotion().use(*hero);
                else if (item == "Зелье маны") ManaPotion().use(*hero);
                else if (item == "Зелье силы") StrengthPotion().use(*hero);
                else std::cout << "Ничего не произошло.\n";
            }
        }
        else if (choice == 3) {
            std::cout<<"Выход из игры.\n";
            break;
        }
        else {
            std::cout << "Неверный выбор\n";
        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

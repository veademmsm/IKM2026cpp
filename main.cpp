#include <iostream>
#include <limits>
#include "game.h"
#include "windows.h"

void showMenu();
int getSafeInt();

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice;
    do {
        showMenu();
        choice = getSafeInt();

        switch (choice) {
            case 1: startGame(); break;
            case 2: printRules(); break;
            case 3: std::cout << "Выход...\n"; break;
            default: std::cout << "Неверный выбор\n";
        }
    } while (choice != 3);

    return 0;
}

// функция для проверки на корректность ввода
int getSafeInt() {
    int value;
    while (true) {
        if (std::cin >> value) {
            // очистка буффера от остатка
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            // блок для ошибок
            std::cout << "Ошибка! Введите числовое значение: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка
        }
    }
}

// функция для отображения главного меню
void showMenu() {
    std::cout << "\n=== ИГРА \"ПЬЯНИЦА\" ===\n";
    std::cout << "1. Начать игру\n";
    std::cout << "2. Правила\n";
    std::cout << "3. Выход\n";
    std::cout << "Выбор: ";
}

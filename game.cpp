#include "game.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

const int MaxRounds = 5000;
const int DeckSize = 36;

void initDeck(std::vector<Card>& deck);

void startGame() {
    std::vector<Card> deck;
    initDeck(deck);

    // генератор случайных чисел
    std::srand(time(0));

    // перемешивание
    for (size_t i = deck.size() - 1; i > 0; --i) {
        size_t j = std::rand() % (i + 1);
        std::swap(deck[i], deck[j]);
    }

    // раздача карт
    std::vector<Card> p1(deck.begin(), deck.begin() + DeckSize / 2);
    std::vector<Card> p2(deck.begin() + DeckSize / 2, deck.end());

    std::cout << "\nНажмите Enter, чтобы начать игру...";
    std::string buffer;
    std::getline(std::cin, buffer);

    int round = 1;
    bool fastMode = false;

    // основной игровой цикл
    while (!p1.empty() && !p2.empty() && round <= MaxRounds) {
        // информация текущего раунда
        std::cout << "\n=============================\n";
        std::cout << "Раунд " << round << "\n";
        std::cout << "Игрок 1: " << p1.size()
                  << " карт | Игрок 2: " << p2.size() << " карт\n";
        std::cout << "=============================\n";

        // управление игрой и быстрый режим
        if (!fastMode) {
            std::cout << "[Enter] — ход | [s] — ускоренный режим: ";
            std::string action;
            std::getline(std::cin, action);

            if (action == "s" || action == "S") {
                fastMode = true;
                std::cout << ">>> Ускоренный режим включен\n";
            }
        }

        // взятие верхних карт
        Card c1 = p1.front();
        Card c2 = p2.front();
        p1.erase(p1.begin());
        p2.erase(p2.begin());

        std::cout << "Карта игрока 1: " << c1.name << c1.suit << "\n";
        std::cout << "Карта игрока 2: " << c2.name << c2.suit << "\n";

        // сравнение карт и определение победителя
        if (c1.rank > c2.rank) {
            p1.push_back(c1);
            p1.push_back(c2);
            std::cout << "→ Победил игрок 1\n";
        }
        else if (c2.rank > c1.rank) {
            p2.push_back(c1);
            p2.push_back(c2);
            std::cout << "→ Победил игрок 2\n";
        }
        else {
            p1.push_back(c1);
            p2.push_back(c2);
            std::cout << "→ Ничья\n";
        }

        round++;
    }

    // конец и результат игры
    std::cout << "\n******** ИГРА ЗАВЕРШЕНА ********\n";
    if (p1.empty()) {
        std::cout << "Победитель: Игрок 2\n";
    }
    else if (p2.empty()) {
        std::cout << "Победитель: Игрок 1\n";
    }
    else {
        std::cout << "Результат: ничья (лимит раундов)\n";
    }
    std::cout << "Всего раундов: " << round - 1 << "\n";
    std::cout << "********************************\n";

    std::cout << "\nНажмите Enter для возврата в меню...";
    std::getline(std::cin, buffer);
}

// правила игры
void printRules() {
    std::cout << "\nПРАВИЛА ИГРЫ:\n";
    std::cout << "Игроки вскрывают по одной карте.\n";
    std::cout << "Старшая карта забирает обе.\n";
    std::cout << "Цель — собрать все карты.\n";
    std::cout << "\nНажмите Enter для возврата...";
    std::string tmp;
    std::getline(std::cin, tmp);
}

// создание полной колоды карт
void initDeck(std::vector<Card>& deck) {
    const std::string names[] = {"6", "7", "8", "9", "10", "В", "Д", "К", "Т"};
    const std::string suits[] = {"♥", "♦", "♣", "♠"};

    for (int i = 0; i < 4; ++i) {          // масти
        for (int j = 0; j < 9; ++j) {      // карты
            deck.push_back({j + 6, names[j], suits[i]});
        }
    }
}



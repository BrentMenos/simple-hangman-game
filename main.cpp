//
// Created by Brenty on 25/03/2026.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "WordBank.h"
#include "HangmanGame.h"

using namespace std;

class GameInterface {
public:
    static void showMenu() {
        cout << "\nHANGMAN\n1. Play\n2. How to Play\n0. Exit\nChoice: ";
    }

    static void howToPlay() {
        cout << "\nGuess letters to reveal the word. 6 mistakes allowed.\nPress Enter to return...";
        cin.ignore(); cin.get();
    }
};

int main() {
    srand(time(0));

    WordBank myWordBank("wordbank.txt");

    HangmanGame game;

    int choice;
    do {
        GameInterface::showMenu();
        cin >> choice;

        if (choice == 1) {
            if (!myWordBank.isEmpty()) {
                WordEntry randomWord = myWordBank.getRandomWord();
                game.playRound(randomWord);
            }
        } else if (choice == 2) {
            GameInterface::howToPlay();
        }
    } while (choice != 0);

    return 0;
}
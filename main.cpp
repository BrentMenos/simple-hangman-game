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
        cout << "\n--- HANGMAN OOP ---\n1. Play\n2. How to Play\n0. Exit\nChoice: ";
    }

    static void howToPlay() {
        cout << "\nGuess letters to reveal the word. 6 mistakes allowed.\nPress Enter to return...";
        cin.ignore(); cin.get();
    }
};

int main() {
    srand(time(0));

    // 1. Initialize the dictionary
    WordBank myWordBank("wordbank.txt");

    // 2. Initialize the game engine
    HangmanGame game;

    int choice;
    do {
        GameInterface::showMenu();
        cin >> choice;

        if (choice == 1) {
            if (!myWordBank.isEmpty()) {
                WordEntry randomWord = myWordBank.getRandomWord();
                game.playRound(randomWord); // Pass the word to the game engine
            }
        } else if (choice == 2) {
            GameInterface::howToPlay();
        }
    } while (choice != 0);

    return 0;
}
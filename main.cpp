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
        cout << "\nGuess letters to reveal the word. 6 mistakes allowed.\nPress Enter to return";
        cin.ignore();
        cin.get();
    }
};

int main() {
    WordBank bank;
    HangmanGame game;
    int choice;

    do {
        GameInterface::showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int diffChoice;
                cout << "\nSelect Difficulty:\n";
                cout << " 1. Easy\n 2. Medium\n 3. Hard\n";
                cout << "Choice: ";
                cin >> diffChoice;

                string difficulty;
                if (diffChoice == 1) {
                    difficulty = "Easy";
                } else if (diffChoice == 2) {
                    difficulty = "Medium";
                } else if (diffChoice == 3) {
                    difficulty = "Hard";
                } else {
                    cout << "  Invalid choice. Defaulting to Easy.\n";
                    difficulty = "Easy";
                }

                WordEntry chosenWord = bank.getRandomWord(difficulty);
                game.playRound(chosenWord);
                break;
            }
            case 2:
                GameInterface::howToPlay();
                break;
            case 0:
                cout << "\nThanks for playing! Goodbye.\n";
                break;
            default:
                cout << "\nInvalid option. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
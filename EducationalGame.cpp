//
// Created by Brenty on 17/03/2026.
//

#include "EducationalGame.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

struct WordEntry {
    string word;
    string hint;
    string category;
};

vector<WordEntry> wordBank = {
    { "Brent Menos", "Pogi", "Oat"},
    {"elephant",  "Large gray animal with a trunk",       "Animals"},
    {"dolphin",   "Smart ocean mammal",                   "Animals"},
    {"penguin",   "Bird that cannot fly but can swim",    "Animals"},
    {"giraffe",   "Tallest animal on land",               "Animals"},
    {"kangaroo",  "Australian animal with a pouch",       "Animals"},

    {"gravity",   "Force that pulls objects downward",    "Science"},
    {"oxygen",    "Gas we breathe to survive",            "Science"},
    {"molecule",  "Smallest unit of a chemical compound", "Science"},
    {"volcano",   "Mountain that can erupt with lava",    "Science"},
    {"eclipse",   "When one celestial body blocks another","Science"},

    {"keyboard",  "Used to type on a computer",           "Technology"},
    {"internet",  "Global network of connected computers","Technology"},
    {"software",  "Programs that run on a computer",      "Technology"},
    {"database",  "Organized collection of data",         "Technology"},
    {"compiler",  "Converts source code into machine code","Technology"},

    {"mountain",  "Very tall landform",                   "Geography"},
    {"volcano",   "Fire mountain",                        "Geography"},
    {"desert",    "Hot and very dry region",              "Geography"},
    {"glacier",   "Slow-moving mass of ice",              "Geography"},
    {"peninsula", "Land surrounded by water on three sides","Geography"},
};


void drawHangman(int wrong) {
    cout << "\n";
    cout << "  +---+\n";
    cout << "  |   |\n";
    cout << "  |   " << (wrong >= 1 ? "O" : " ") << "\n";
    cout << "  |  " << (wrong >= 3 ? "/" : " ") << (wrong >= 2 ? "|" : " ") << (wrong >= 4 ? "\\" : " ") << "\n";
    cout << "  |  " << (wrong >= 5 ? "/" : " ") << " " << (wrong >= 6 ? "\\" : " ") << "\n";
    cout << "  |\n";
}


void displayWord(const string& word, const vector<char>& guessed) {
    cout << "  Word: ";
    for (char ch : word) {
        bool found = find(guessed.begin(), guessed.end(), ch) != guessed.end();
        cout << (found ? ch : '_') << " ";
    }
    cout << "\n";
}


bool isWordGuessed(const string& word, const vector<char>& guessed) {
    for (char ch : word)
        if (find(guessed.begin(), guessed.end(), ch) == guessed.end())
            return false;
    return true;
}


void displayGuessed(const vector<char>& guessed) {
    cout << "  Letters guessed: ";
    for (char ch : guessed)
        cout << ch << " ";
    cout << "\n";
}


WordEntry pickRandomWord() {
    return wordBank[rand() % wordBank.size()];
}


void playGame() {
    WordEntry entry = pickRandomWord();
    string word = entry.word;
    string hint = entry.hint;
    string category = entry.category;

    vector<char> guessedLetters;
    int wrongGuesses = 0;
    const int MAX_WRONG = 6;

    cout << "\n  Category : " << category << "\n";
    cout << "  Hint     : " << hint << "\n";
    cout << "  (The word has " << word.length() << " letters)\n";

    while (wrongGuesses < MAX_WRONG) {
        drawHangman(wrongGuesses);
        displayWord(word, guessedLetters);
        displayGuessed(guessedLetters);
        cout << "  Wrong guesses left: " << (MAX_WRONG - wrongGuesses) << "\n";

        if (isWordGuessed(word, guessedLetters)) {
            cout << "\n  ★ Congratulations! You guessed the word: " << word << " ★\n";
            return;
        }

        cout << "\n  Enter a letter: ";
        char guess;
        cin >> guess;
        guess = tolower(guess);

        if (!isalpha(guess)) {
            cout << "  Please enter a valid letter!\n";
            continue;
        }

        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "  You already guessed '" << guess << "'! Try a different letter.\n";
            continue;
        }

        guessedLetters.push_back(guess);

        if (word.find(guess) != string::npos) {
            cout << "  ✓ Good guess! '" << guess << "' is in the word.\n";
        } else {
            wrongGuesses++;
            cout << "  ✗ Nope! '" << guess << "' is not in the word.\n";
        }
    }

    drawHangman(wrongGuesses);
    cout << "  ✗ Game Over! The word was: " << word << "\n";
}

void showMenu() {
    cout << "        HANGMAN             \n";
    cout << "  1. Play Game                    \n";
    cout << "  2. How to Play                  \n";
    cout << "  0. Exit                         \n";;
    cout << "  Enter your choice: ";
}

void howToPlay() {
    cout << "  HOW TO PLAY HANGMAN\n";
    cout << "  1. A random word is chosen for you.\n";
    cout << "  2. You are shown the category & hint.\n";
    cout << "  3. Guess one letter at a time.\n";
    cout << "  4. Each wrong guess draws part of\n";
    cout << "     the hangman figure.\n";
    cout << "  5. You have 6 wrong guesses max.\n";
    cout << "  6. Guess all letters to WIN!\n";
    cout << "  7. If the figure is complete, you LOSE.\n";
    cout << "  Press ENTER to go back...";
    cin.ignore();
    cin.get();
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    cout << "\n  Welcome to Hangman!\n";
    cout << "  Guess the hidden word before the man is hanged.\n";

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                playGame();
                cout << "\n  Play again? Going back to menu...\n";
                break;
            }
            case 2:
                howToPlay();
                break;
            case 0:
                cout << "\n  Thanks for playing Hangman! Goodbye!\n\n";
                break;
            default:
                cout << "\n  Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
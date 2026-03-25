#include "HangmanGame.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

void HangmanGame::drawHangman(int wrong) const {
    cout << "\n  +---+\n  |   |\n";
    cout << " |   " << (wrong >= 1 ? "O" : " ") << "\n";
    cout << " |  " << (wrong >= 3 ? "/" : " ") << (wrong >= 2 ? "|" : " ") << (wrong >= 4 ? "\\" : " ") << "\n";
    cout << " |  " << (wrong >= 5 ? "/" : " ") << " " << (wrong >= 6 ? "\\" : " ") << "\n";
    cout << " |\n";
}

bool HangmanGame::isWordGuessed(const string& word, const vector<char>& guessed) const {
    for (char ch : word) {
        if (ch == ' ') continue; 
        if (find(guessed.begin(), guessed.end(), tolower(ch)) == guessed.end())
            return false;
    }
    return true;
}

void HangmanGame::playRound(const WordEntry& entry) const {
    vector<char> guessedLetters;
    int wrongGuesses = 0;

    cout << "\nCategory: " << entry.category << " | Hint: " << entry.hint << "\n";

    while (wrongGuesses < MAX_WRONG) {
        drawHangman(wrongGuesses);

        cout << "  Word: ";
        for (char ch : entry.word) {
            if (ch == ' ') cout << "  ";
            else cout << (find(guessedLetters.begin(), guessedLetters.end(), tolower(ch)) != guessedLetters.end() ? ch : '_') << " ";
        }

        if (isWordGuessed(entry.word, guessedLetters)) {
            cout << "\n\n WINNER! The word was: " << entry.word << " \n";
            return;
        }

        cout << "\n\n  Enter letter: ";
        char guess;
        cin >> guess;
        guess = tolower(guess);

        if (!isalpha(guess) || find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "  Invalid or already guessed!\n";
            continue;
        }

        guessedLetters.push_back(guess);
        if (entry.word.find(guess) == string::npos && entry.word.find(toupper(guess)) == string::npos) {
            wrongGuesses++;
            cout << " Wrong!\n";
        }
    }
    drawHangman(MAX_WRONG);
    cout << " Game Over! Word was: " << entry.word << "\n";
}
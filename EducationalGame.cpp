#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// Data structure remains simple
struct WordEntry {
    string word;
    string hint;
    string category;
};

class HangmanGame {
private:
    vector<WordEntry> wordBank;
    const int MAX_WRONG = 6;

    // Internal helper methods (Private)
    void drawHangman(int wrong) {
        cout << "\n  +---+\n  |   |\n";
        cout << "  |   " << (wrong >= 1 ? "O" : " ") << "\n";
        cout << "  |  " << (wrong >= 3 ? "/" : " ") << (wrong >= 2 ? "|" : " ") << (wrong >= 4 ? "\\" : " ") << "\n";
        cout << "  |  " << (wrong >= 5 ? "/" : " ") << " " << (wrong >= 6 ? "\\" : " ") << "\n";
        cout << "  |\n";
    }

    bool isWordGuessed(const string& word, const vector<char>& guessed) {
        for (char ch : word) {
            if (ch == ' ') continue; // Skip spaces in check
            if (find(guessed.begin(), guessed.end(), tolower(ch)) == guessed.end())
                return false;
        }
        return true;
    }

public:
    // Constructor: Loads the word bank immediately
    HangmanGame(string filename) {
        ifstream file(filename);
        string line;
        if (!file.is_open()) {
            wordBank.push_back({"Brent Menos", "Pogi", "Oat"}); // Default fallback
        } else {
            while (getline(file, line)) {
                stringstream ss(line);
                string w, h, c;
                if (getline(ss, w, ',') && getline(ss, h, ',') && getline(ss, c, ',')) {
                    wordBank.push_back({w, h, c});
                }
            }
            file.close();
        }
    }

    void play() {
        if (wordBank.empty()) return;

        WordEntry entry = wordBank[rand() % wordBank.size()];
        vector<char> guessedLetters;
        int wrongGuesses = 0;

        cout << "\n  Category: " << entry.category << " | Hint: " << entry.hint << "\n";

        while (wrongGuesses < MAX_WRONG) {
            drawHangman(wrongGuesses);

            // Display Logic
            cout << "  Word: ";
            for (char ch : entry.word) {
                if (ch == ' ') cout << "  ";
                else cout << (find(guessedLetters.begin(), guessedLetters.end(), tolower(ch)) != guessedLetters.end() ? ch : '_') << " ";
            }

            if (isWordGuessed(entry.word, guessedLetters)) {
                cout << "\n\n  ★ WINNER! The word was: " << entry.word << " ★\n";
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
                cout << "  ✗ Wrong!\n";
            }
        }
        drawHangman(MAX_WRONG);
        cout << "  ✗ Game Over! Word was: " << entry.word << "\n";
    }
};

// Interface Class for the Menu
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
    HangmanGame game("wordbank.txt"); // The object
    int choice;

    do {
        GameInterface::showMenu();
        cin >> choice;
        if (choice == 1) game.play();
        else if (choice == 2) GameInterface::howToPlay();
    } while (choice != 0);

    return 0;
}
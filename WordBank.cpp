#include "WordBank.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

WordBank::WordBank() {
    ifstream file("wordbank.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string w, h, c, d;

        if (getline(ss, w, ',') && getline(ss, h, ',') && getline(ss, c, ',') && getline(ss, d)) {
            words.push_back({w, h, c, d});
        }
    }
    if (words.empty()) {
        words.push_back({"Default", "No file found", "Error", "Easy"});
    }
    srand(time(0));
}

WordEntry WordBank::getRandomWord(string targetDifficulty) {
    vector<WordEntry> filteredWords;

    for (const WordEntry& entry : words) {
        if (entry.difficulty == targetDifficulty) {
            filteredWords.push_back(entry);
        }
    }

    if (filteredWords.empty()) {
        return words[rand() % words.size()];
    }

    return filteredWords[rand() % filteredWords.size()];
}

bool WordBank::isEmpty() const {
    return words.empty();
}
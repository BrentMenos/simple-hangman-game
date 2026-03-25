#include "WordBank.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

WordBank::WordBank(const string& filename) {
    ifstream file(filename);
    string line;
    if (!file.is_open()) {
        words.push_back({"Brent Menos", "Pogi", "Oat"});
    } else {
        while (getline(file, line)) {
            stringstream ss(line);
            string w, h, c;
            if (getline(ss, w, ',') && getline(ss, h, ',') && getline(ss, c, ',')) {
                words.push_back({w, h, c});
            }
        }
        file.close();
    }
}

WordEntry WordBank::getRandomWord() const {
    return words[rand() % words.size()];
}

bool WordBank::isEmpty() const {
    return words.empty();
}
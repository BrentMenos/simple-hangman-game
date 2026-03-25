//
// Created by Brenty on 25/03/2026.
//

#ifndef INC_9348_CPLUSPLUS_WORDBANK_H
#define INC_9348_CPLUSPLUS_WORDBANK_H
#pragma once
#include <string>
#include <vector>

struct WordEntry {
    std::string word;
    std::string hint;
    std::string category;
};

class WordBank {
private:
    std::vector<WordEntry> words;

public:
    // Constructor
    WordBank(const std::string& filename);

    // Method to get a random word
    WordEntry getRandomWord() const;

    // Check if the bank successfully loaded words
    bool isEmpty() const;
};


#endif //INC_9348_CPLUSPLUS_WORDBANK_H
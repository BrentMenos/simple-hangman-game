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
    WordBank(const std::string& filename);

    WordEntry getRandomWord() const;

    bool isEmpty() const;
};


#endif //INC_9348_CPLUSPLUS_WORDBANK_H
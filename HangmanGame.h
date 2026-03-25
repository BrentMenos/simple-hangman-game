//
// Created by Brenty on 25/03/2026.
//

#ifndef INC_9348_CPLUSPLUS_HANGMANGAME_H
#define INC_9348_CPLUSPLUS_HANGMANGAME_H

#pragma once
#include "WordBank.h"
#include <vector>

class HangmanGame {
private:
    const int MAX_WRONG = 6;
public:
    static void drawHangman(int wrong) ;
    static bool isWordGuessed(const std::string& word, const std::vector<char>& guessed) ;

public:
    void playRound(const WordEntry& entry) const;
};


#endif //INC_9348_CPLUSPLUS_HANGMANGAME_H
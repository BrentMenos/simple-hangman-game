# Simple Hangman Game 
A classic terminal-based Hangman game built with C++. This project demonstrates fundamental programming logic, including string manipulation, loops, and user input handling.

# Description
The game selects a random word from a predefined list, and the player must guess it one letter at a time. Be careful—too many wrong guesses and the game is over!

# Objective
Guess the secret word before the hangman is fully drawn.

# Difficulty
Players only have 5 guesses availabe if it exceeded 5 it will be game over.
Each words have their respective hints and difficulty.
Players can Choose 3 difficulties from Easy to Hard.

# Platform
Command Line Interface (CLI).

# Features
Interactive Gameplay: Real-time updates on correctly guessed letters.

Win/Loss Logic: Clear notifications when the player wins or runs out of lives.

Input Validation: Handles basic user inputs to ensure a smooth experience.

# Project Structure
```Plaintext
/
├── main.cpp             # Entry point
├── wordbank.cpp         # Word picker
├── hangmanGame.cpp      # Main game Logic
└── README.md            # Project documentation
```
# How to Run
Make sure you have any IDE that is compatible with Cplusplus such as Clion or VS Code installed on your machine.

Clone the repository:
Bash
git clone https://github.com/BrentMenos/simple-hangman-game.git

Navigate to the folder:
Bash
cd simple-hangman-game

Compile
g++ *.cpp -o hangman

Run the game:
Bash
hangman.exe

# Author
Brent Menos - GitHub Profile

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to choose a random word from a list
string chooseRandomWord() {
    vector<string> words = {"apple", "banana", "cherry", "dog", "elephant", "flower", "grape", "horse", "jungle", "koala"};
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

// Function to display the current state of the word with underscores for unrevealed letters
void displayWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    srand(time(0));  // Seed the random number generator

    string secretWord = chooseRandomWord();
    int maxAttempts = 6;  // You can change this to set the maximum number of incorrect attempts
    vector<bool> guessedLetters(secretWord.length(), false);
    int attempts = 0;

    cout << "Welcome to Hangman!" << endl;

    while (attempts < maxAttempts) {
        cout << "\nAttempts left: " << maxAttempts - attempts << endl;
        displayWord(secretWord, guessedLetters);

        char guess;
        cout << "Enter a letter guess: ";
        cin >> guess;

        bool found = false;
        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == guess && !guessedLetters[i]) {
                guessedLetters[i] = true;
                found = true;
            }
        }

        if (!found) {
            cout << "Incorrect guess. Try again." << endl;
            attempts++;
        }

        bool allGuessed = true;
        for (bool letterGuessed : guessedLetters) {
            if (!letterGuessed) {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed) {
            cout << "\nCongratulations! You guessed the word: " << secretWord << endl;
            break;
        }
    }

    if (attempts >= maxAttempts) {
        cout << "\nSorry, you've run out of attempts. The word was: " << secretWord << endl;
    }

    return 0;
}

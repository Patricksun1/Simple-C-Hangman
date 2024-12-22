#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    printf("Welcome to Hangman!\n");
    char guessWords[4][100];
    printf("Please enter 4 words to guess from\n");
    for (int i = 0; i < 4; i++) {
        printf("Enter a word: ");
        fgets(guessWords[i], 100, stdin);
    }

    char *selectedWord =  guessWords[rand() % 4];

    int numLives = 5;
    int numCorrect = 0;
    int usedWords[26] = {0}; // account for capital letters later
    char *guessedWord = malloc((strlen(selectedWord) + 1) * sizeof(char));
    for (int i = 0; i < strlen(selectedWord) - 1; i++) {
        guessedWord[i] = '-';
    }

    printf("Starting Game...\n");
    printf("You have %d lives remaining\n", numLives);
    while (numLives > 0 && numCorrect != (strlen(selectedWord) - 1)) {
        char curr;
        printf("Select a character: ");
        if (curr < 'a' || curr > 'z') {
            printf("Invalid Character\n");
            continue;
        }
        if (usedWords[curr - 'a']) {
            printf("Character already used\n");
            continue;
        }
        usedWords[curr - 'a'] = 1;
        bool charFound = false;
        for (int i = 0; i < strlen(selectedWord); i++) {
            if (selectedWord[i] == curr) {
                guessedWord[i] = curr;
                charFound = true;
                numCorrect++;
            }
        }
        if (!charFound) {
            numLives--;
            printf("You have %d lives remaining\n", numLives);
        }
        printf("Current Guess: %s\n", guessedWord);
    }
    if (numLives == 0) {
        printf("You Lose :(\n");
        return 0;
    } else {
        printf("You Win!\n");
    }
    return 0;
}


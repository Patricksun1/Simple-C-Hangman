#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>


int main() {
    printf("Welcome to Hangman!\n");
    char guessWords[8][10] = {
        "generation",
        "motivation",
        "discovery",
        "reasonable",
        "adventure",
        "guidelines",
        "leadership",
        "connection"
    };
    printf("I'm thinking of a word to pick...\n");
    sleep(4);
    srand(time(NULL));
    int index = rand() % 8;
    printf("%d\n", index);
    char *selectedWord =  guessWords[index];

    int numLives = 5;
    int numCorrect = 0;
    int usedWords[26] = {0}; // account for capital letters later
    char *guessedWord = malloc((strlen(selectedWord) + 1) * sizeof(char));
    for (int i = 0; i < strlen(selectedWord) - 1; i++) {
        guessedWord[i] = '-';
    }
    char response;
    printf("I have a word...\n");
    printf("Ready to start game?(y/n)\n");
    scanf(" %c", &response);
    if (!(response == 'y' || response == 'Y')) {
        printf("See you next time!\n");
        return 0;
    }
    printf("You have %d lives remaining\n", numLives);
    while (numLives > 0 && numCorrect != (strlen(selectedWord) - 1)) {
        char curr;
        printf("Select a character (a - z): ");
        scanf(" %c", &curr);
        
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


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "game.h"

// draw a card using #include <stdlib.h> and
// rand() method that output random number between 1 - 13
int drawCard() {
    return (rand() % 13) + 1;
}

void game() {
    int playerScore = 0;
    int dealerScore = 0;
    bool keepPlay = true;

    while (keepPlay) {
        int choice;
        int card = drawCard();

        printf("1. Draw a card\n");
        printf("2. Stop draw a card\n");
        printf("3. Quit\n");
        printf("Choose an option: \n");

        // Check if input successfully read an integer
        if (scanf("%d", &choice) != keepPlay) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue; // Skip the rest of the loop and ask for user input
        }

        switch (choice) {
            case 1:
                printf("You drew card %d\n", card);
                playerScore += card;
                printf("Your current score: %d\n", playerScore);
                if (playerScore > 21) {
                    printf("You lost! Your score is over 21.\n");
                    keepPlay = false;
                }
                break;
            case 2:
                while (dealerScore < 17) {
                    int dealerCard = drawCard();
                    printf("The dealer drew card %d\n", dealerCard);
                    dealerScore += dealerCard;
                }
                printf("Dealer's score: %d\n", dealerScore);

                if (dealerScore > 21 || playerScore > dealerScore) {
                    printf("You win!");
                } else if (playerScore == dealerScore) {
                    printf("It's a tie!\n");
                } else {
                    printf("Dealer wins!\n");
                }
                keepPlay = false;
                break;
            case 3:
                keepPlay = false;
                break;
        }
    }
}
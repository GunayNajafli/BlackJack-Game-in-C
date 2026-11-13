#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 


int getCard(); 
int getCardValue(int card); 
int playerTurn(); 
int dealerTurn(); 

int main() {
    int player; 
    int dealer; 


    srand(time(NULL)); 

    printf(" - BLACKJACK Game - \n"); 

    player = playerTurn(); 

    if (player > 21) { 
        return 0; 
    }

    dealer = dealerTurn(); 

    if (dealer > 21) { 
        printf("Dealer busts! Its total is over 21.\n");
        printf("You win!\n");
    }
    else {
        printf("\nPlayer total: %d\n", player);
        printf("Dealer total: %d\n", dealer);

        if (player > dealer) {
            printf("You win!\n");
        }
        else if (dealer > player) {
            printf("Dealer wins.\n");
        }
        else {
            printf("Draw! Nobody wins!\n");
        }
    }

    return 0;
}


int getCard() {
    return rand() % 13 + 1;
}


int getCardValue(int card) {
    if (card == 1) { 
        return 1;
    }
    else if (card >= 2 && card <= 10) { 
        return card;
    }
    else {
        return 10; 
    }
}

int playerTurn() {
    int player = 0; 
    int card; 
    int choice; 

    printf("\nPLAYER TURN\n");

    while (1) { 
        card = getCard();

        if (card == 1) {
            printf("You draw: A\n");
        }
        else if (card >= 2 && card <= 10) {
            printf("You draw: %d\n", card);
        }
        else if (card == 11) {
            printf("You draw: J\n");
        }
        else if (card == 12) {
            printf("You draw: Q\n");
        }
        else {
            printf("You draw: K\n");
        }

        player += getCardValue(card);

        printf("Your total: %d\n", player);

        if (player > 21) {
            printf("BUST! Your total is over 21.\n");
            printf("Dealer wins.\n");
            return player;
        }

        printf("1. Hit\n");
        printf("2. Stand\n");
        printf("Choice: ");
        scanf("%d", &choice);

        while (choice != 1 && choice != 2) { 
            printf("Please enter 1 or 2: ");
            scanf("%d", &choice);
        }

        if (choice == 2) {
            break;
        }
    }

    return player;
}




int dealerTurn() {
    int dealer = 0;
    int card;

    printf("\nDEALER TURN\n");

    while (dealer < 17) {
        card = getCard();

        if (card == 1) {
            printf("Dealer draws: A\n");
        }
        else if (card >= 2 && card <= 10) {
            printf("Dealer draws: %d\n", card);
        }
        else if (card == 11) {
            printf("Dealer draws: J\n");
        }
        else if (card == 12) {
            printf("Dealer draws: Q\n");
        }
        else {
            printf("Dealer draws: K\n");
        }

        dealer += getCardValue(card);

        printf("Dealer total: %d\n", dealer);
    }

    printf("Dealer stands.\n");

    return dealer;
}




// gcc 23791_Gunay_Najafli_Project1.c -o 23791_Gunay_Najafli_Project1  

// ./23791_Gunay_Najafli_Project1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// create the deck -
// find a way to get a card
// randomly select a card
// remember if a card was already used

#define SUITE_SIZE 4
#define RANK_SIZE 13

#define FALSE 0
#define TRUE 1

typedef int boolean;

int main(void) {
    char suites[SUITE_SIZE] = {'c', 'd', 'h', 's'};
    char ranks[RANK_SIZE]
        = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};

    boolean usedCards[SUITE_SIZE][RANK_SIZE];

    for (int i = 0; i < SUITE_SIZE; i++) {
        for (int j = 0; j < RANK_SIZE; j++) {
            usedCards[i][j] = FALSE;
        }
    }

    printf("Tell me how many cards I have to draw: ");
    int numOfCards;
    scanf("%d", &numOfCards);

    srand((unsigned int)time(NULL));

    while (numOfCards > 0) {
        int suitIndex = rand() % SUITE_SIZE;
        int rankindex = rand() % RANK_SIZE;
        if (usedCards[suitIndex][rankindex] == FALSE) {
            char suit                       = suites[suitIndex];
            char rank                       = ranks[rankindex];
            numOfCards                      = numOfCards - 1;
            usedCards[suitIndex][rankindex] = TRUE;
            printf("%c%c ", rank, suit);
        }
    }
    for (int i = 0; i < SUITE_SIZE; i++) {
        for (int j = 0; j < RANK_SIZE; j++) {
            printf("rank %d, size %d, value %d\n", i, j, usedCards[i][j]);
        }
    }
    printf("\n");
}
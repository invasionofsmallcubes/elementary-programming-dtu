#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define SYMBOLS 13
#define FALSE 0
#define TRUE 1

int main(void) {

    const char suites[SUITS] = {'c', 's', 'h', 'd'};
    const char symbols[SYMBOLS]
        = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
    short cardsSeen[SUITS][SYMBOLS] = {FALSE};

    // void srand(unsigned int seed)
    srand((unsigned)time(NULL));

    printf("Enter number of cards in hand: ");
    int num_of_cards;
    scanf("%d", &num_of_cards);

    while (num_of_cards > 0) {
        int suiteIndex  = rand() % SUITS;
        int symbolIndex = rand() % SYMBOLS;
        if (!cardsSeen[suiteIndex][symbolIndex]) {
            printf("%c%c ", symbols[symbolIndex], suites[suiteIndex]);
            num_of_cards = num_of_cards - 1;
            cardsSeen[suiteIndex][symbolIndex] = TRUE;
        }
    }
    printf("\n");
}
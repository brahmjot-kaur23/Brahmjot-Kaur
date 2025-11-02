#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 100

// Snakes and ladders
int snakes_and_ladders(int pos) {
    switch (pos) {
        // Ladders
        case 4: return 14;
        case 9: return 31;
        case 20: return 38;
        case 28: return 84;
        case 40: return 59;
        case 51: return 67;
        case 63: return 81;
        case 71: return 91;
        // Snakes
        case 17: return 7;
        case 54: return 34;
        case 62: return 19;
        case 64: return 60;
        case 87: return 24;
        case 93: return 73;
        case 95: return 75;
        case 99: return 78;
        default: return pos;
    }
}

void print_board(int p1, int p2) {
    printf("\nBoard Positions:\n");
    for (int i = 1; i <= BOARD_SIZE; i++) {
        if (p1 == i && p2 == i)
            printf("[B]"); // Both players on same cell
        else if (p1 == i)
            printf("[1]");
        else if (p2 == i)
            printf("[2]");
        else
            printf("[%d]", i);

        if (i % 10 == 0) printf("\n");
    }
    printf("\n");
}

int main() {
    int player[2] = {1, 1};
    int turn = 0;
    int dice;
    char ch;

    srand(time(NULL));
    printf("Welcome to Snakes and Ladders!\n");
    printf("Player 1: [1]\nPlayer 2: [2]\n");

    while (player[0] < BOARD_SIZE && player[1] < BOARD_SIZE) {
        print_board(player[0], player[1]);
        printf("Player %d's turn. Press Enter to roll dice...", turn + 1);
        while ((ch = getchar()) != '\n' && ch != EOF); // Wait for Enter

        dice = rand() % 6 + 1;
        printf("Player %d rolled a %d!\n", turn + 1, dice);

        player[turn] += dice;
        if (player[turn] > BOARD_SIZE)
            player[turn] = BOARD_SIZE;

        int before = player[turn];
        player[turn] = snakes_and_ladders(player[turn]);
        if (player[turn] > before)
            printf("Yay! Ladder to %d\n", player[turn]);
        else if (player[turn] < before)
            printf("Oh no! Snake to %d\n", player[turn]);

        if (player[turn] == BOARD_SIZE) {
            printf("Player %d wins!\n", turn + 1);
            break;
        }
        turn = 1 - turn; // Switch turns
    }
    return 0;
}

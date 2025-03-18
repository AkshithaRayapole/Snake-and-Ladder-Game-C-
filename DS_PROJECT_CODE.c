#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 100

typedef struct {
    char name[50];
    int position;
} Player;

void initializeBoard(int board[]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = 0;
    }
    // Define snakes and ladders (example positions)
    board[16] = -10;  // Snake: move from 16 to 6
    board[47] = -21;  // Snake: move from 47 to 26
    board[49] = -38;  // Snake: move from 49 to 11
    board[56] = -3;   // Snake: move from 56 to 53
    board[62] = -43;  // Snake: move from 62 to 19
    board[64] = -4;   // Snake: move from 64 to 60
    board[87] = -63;  // Snake: move from 87 to 24
    board[93] = -20;  // Snake: move from 93 to 73
    board[95] = -20;  // Snake: move from 95 to 75
    board[98] = -20;  // Snake: move from 98 to 78

    board[1] = 37;    // Ladder: move from 1 to 38
    board[4] = 10;    // Ladder: move from 4 to 14
    board[9] = 22;    // Ladder: move from 9 to 31
    board[21] = 21;   // Ladder: move from 21 to 42
    board[28] = 56;   // Ladder: move from 28 to 84
    board[36] = 8;    // Ladder: move from 36 to 44
    board[51] = 16;   // Ladder: move from 51 to 67
    board[71] = 20;   // Ladder: move from 71 to 91
    board[80] = 20;   // Ladder: move from 80 to 100
}

void initializePlayer(Player* player, const char* name) {
    strcpy(player->name, name);
    player->position = 0;
}

int rollDice() {
    return (rand() % 6) + 1;
}

void movePlayer(Player* player, int roll, int board[]) {
    player->position += roll;
    if (player->position >= BOARD_SIZE) {
        player->position = BOARD_SIZE;
        return;
    }
    player->position += board[player->position];
    if (player->position < 0) {
        player->position = 0;
    }
}

void displayBoard(int board[], Player* player1, Player* player2) {
    printf("Current Board Positions:\n");
    for (int i = 1; i <= BOARD_SIZE; i++) {
        if (i == player1->position && i == player2->position) {
            printf("[B] ");  // Both players
        } else if (i == player1->position) {
            printf("[1] ");  // Player 1
        } else if (i == player2->position) {
            printf("[2] ");  // Player 2
        } else {
            printf("[%d] ", i);
        }
        if (i % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void playGame(Player* player1, Player* player2, int board[]) {
    while (player1->position < BOARD_SIZE && player2->position < BOARD_SIZE) {
        printf("%s's turn. Press enter to roll the dice...\n", player1->name);
        getchar();
        int roll = rollDice();
        printf("%s rolled a %d\n", player1->name, roll);
        movePlayer(player1, roll, board);
        printf("%s is now at position %d\n", player1->name, player1->position);
        if (player1->position >= BOARD_SIZE) {
            printf("%s wins!\n", player1->name);
            break;
        }

        printf("%s's turn. Press enter to roll the dice...\n", player2->name);
        getchar();
        roll = rollDice();
        printf("%s rolled a %d\n", player2->name, roll);
        movePlayer(player2, roll, board);
        printf("%s is now at position %d\n", player2->name, player2->position);
        if (player2->position >= BOARD_SIZE) {
            printf("%s wins!\n", player2->name);
            break;
        }

        displayBoard(board, player1, player2);
    }

    printf("Game Over! Thank you for playing.\n");
}

int main() {
    srand(time(NULL));
    int board[BOARD_SIZE];
    Player player1, player2;

    initializeBoard(board);
    initializePlayer(&player1, "Player 1");
    initializePlayer(&player2, "Player 2");

    printf("Welcome to Snakes and Ladders!\n");
    displayBoard(board, &player1, &player2);

    playGame(&player1, &player2, board);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

void print(char a[]);
bool equality(char a, char b, char c);

int main() {
    char a[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    printf("Welcome to terminal tick, tac, toe!\n\n");
    print(a);
    
    int p1_move = 0;
    int p2_move = 0;
    
    int turn = 1;
    while(true) {
        switch(turn) {
            case 1:
            {
                printf("Player 1: Enter placement in the grid(1-9): ");
                scanf("%d", &p1_move);
                bool controller = true;
                while(controller) {
                    if(!(p1_move > 0 && p1_move < 10)) {
                        printf("Invallid grid position.\nPlayer 1: Try Again! : ");
                        scanf("%d", &p1_move);
                    }
                    else if(a[p1_move-1] == 'X' || a[p1_move-1] == 'O') {
                        printf("Position Already Taken.\nPlayer 1: Try Again! : ");
                        scanf("%d", &p1_move);
                    }
                    else {
                        controller = false;
                    }
                }

                a[p1_move-1] = 'X';
                
                printf("\n");
                print(a);
                turn = 2;
                break;
            }
            case 2:
            {
                printf("Player 2: Enter placement in the grid(1-9): ");
                scanf("%d", &p2_move);
                bool controller = true;
                while(controller) {
                    if(!(p2_move > 0 && p2_move < 10)) {
                        printf("Invallid grid position.\nPlayer 2: Try Again! : ");
                        scanf("%d", &p2_move);
                    }
                    else if(a[p2_move-1] == 'X' || a[p2_move-1] == 'O') {
                        printf("Position Already Taken.\nPlayer 2: Try Again! : ");
                        scanf("%d", &p2_move);
                    }
                    else {
                        controller = false;
                    }
                }
                
                a[p2_move-1] = 'O';
                
                printf("\n");
                print(a);
                turn = 1;
                break;
            }
        }
        
        // Winning condition
        // Might find a better solution later
        
        // Checking rows
        for(int i = 0; i < 7; i = i + 3) {
            if(equality(a[i], a[i+1], a[i+2])) {
                if(a[i] == 'X') {
                    printf("Player 1 Won!\n");
                    return 0;
                }
                else if(a[i] == 'O') {
                    printf("Player 2 Won!\n");
                    return 0;
                }
            }
        }
        
        // Checking columns
        for(int i = 0; i < 3; i++) {
            if(equality(a[i], a[i+3], a[i+6])) {
                if(a[i] == 'X') {
                    printf("Player 1 Won!\n");
                    return 0;
                }
                else if(a[i] == 'O') {
                    printf("Player 2 Won!\n");
                    return 0;
                }
            }
        }
        
        // Checking diagonals
            if(equality(a[0], a[4], a[8])) {
                if(a[0] == 'X') {
                    printf("Player 1 Won!\n");
                    return 0;
                }
                else if(a[0] == 'O') {
                    printf("Player 2 Won!\n");
                    return 0;
                }
            }
            
            if(equality(a[2], a[4], a[6])) {
                if(a[2] == 'X') {
                    printf("Player 1 Won!\n");
                    return 0;
                }
                else if(a[2] == 'O') {
                    printf("Player 2 Won!\n");
                    return 0;
                }
            }
            
            // Checking for draw
            bool flag = false;
            for(int i = 0; i < 9; i++) {
                if(a[i] == ' ')
                    flag = true;
            }
            
            if(!flag) {
                printf("Draw!");
                return 0;
            }
    }
}

void print(char a[]) {
    printf("#------Grid------#\n\n");
    printf("  %c  |  %c  |  %c  \n", a[0], a[1], a[2]);
    printf("-----+-----+-----\n");
    printf("  %c  |  %c  |  %c  \n", a[3], a[4], a[5]);
    printf("-----+-----+-----\n");
    printf("  %c  |  %c  |  %c  \n\n", a[6], a[7], a[8]);
}

bool equality(char a, char b, char c) {
    if(a != ' ' && a == b && b == c) return true;
    else return false;
}



// New improved tic tac toe
// With less LoC

#include <stdio.h>
#include <stdbool.h>

void print(char b[]);
bool win(char b[]);

int main() {
    char b[9] = {' '};
    int move, turn = 0;

    printf("Welcome to terminal tic-tac-toe!\n\n");

    while (1) {
        print(b);

        char mark = turn % 2 ? 'O' : 'X';
        int player = turn % 2 ? 2 : 1;

        do {
            printf("Player %d (%c): ", player, mark);
            scanf("%d", &move);
        } while (move < 1 || move > 9 || b[move - 1] != ' ');

        b[move - 1] = mark;

        if (win(b)) {
            print(b);
            printf("Player %d Won!\n", player);
            break;
        }

        if (++turn == 9) {
            print(b);
            printf("Draw!\n");
            break;
        }
    }
}

void print(char b[]) {
    printf("\n %c | %c | %c\n---+---+---\n %c | %c | %c\n---+---+---\n %c | %c | %c\n\n",
           b[0], b[1], b[2],
           b[3], b[4], b[5],
           b[6], b[7], b[8]);
}

bool win(char b[]) {
    int w[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for (int i = 0; i < 8; i++) {
        int a = w[i][0], c = w[i][1], d = w[i][2];
        if (b[a] != ' ' && b[a] == b[c] && b[c] == b[d])
            return true;
    }

    return false;
}
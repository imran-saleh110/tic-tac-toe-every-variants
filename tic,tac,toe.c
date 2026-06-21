#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 9
#define EMPTY ' '
#define PLAYER_ONE 1
#define PLAYER_TWO 2
#define DRAW 0

void print_board(char a[]);
bool equality(char a, char b, char c);
int win(char a[]);

int main() {
    char board[BOARD_SIZE] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    printf("Welcome to terminal tick, tac, toe!\n\n");
    print_board(board);

    int players_move;
    int which_player = PLAYER_ONE;

    while(true) {
      printf("Player %d: Enter placement in the grid(1-9): ", which_player);
      scanf("%d", &players_move);

      bool wait_for_valid_input = true;
      while(wait_for_valid_input) {
        if(!(players_move > 0 && players_move < 10)) {
          printf("Invallid grid position.\nPlayer %d: Try Again! : ", which_player);
          scanf("%d", &players_move);
        }
        else if(board[players_move-1] == 'X' || board[players_move-1] == 'O') {
          printf("Position Already Taken.\nPlayer %d: Try Again! : ", which_player);
          scanf("%d", &players_move);
        }
        else {
          wait_for_valid_input = false;
        }
      }

      board[players_move-1] = which_player == PLAYER_ONE ? 'X' : 'O';
      printf("\n");
      print_board(board);
      which_player = which_player == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;

      int w = win(board);

      switch(w) {
        case PLAYER_ONE:
          printf("Player 1 Won!\n");
          return 0;
        case PLAYER_TWO:
          printf("Player 2 Won!\n");
          return 0;
        case DRAW:
          printf("Draw!");
          return 0;
      }
    }
}

// Winning condition
int win(char a[]) {
// Checking rows
  for(int i = 0; i < 7; i = i + 3) {
    if(equality(a[i], a[i+1], a[i+2])) {
      if(a[i] == 'X') {
        return PLAYER_ONE;
      }
      else if(a[i] == 'O') {
        return PLAYER_TWO;
      }
    }
  }

  // Checking columns
  for(int i = 0; i < 3; i++) {
    if(equality(a[i], a[i+3], a[i+6])) {
      if(a[i] == 'X') {
        return PLAYER_ONE;
      }
      else if(a[i] == 'O') {
        return PLAYER_TWO;
      }
    }
  }

  // Checking diagonals
  if(equality(a[0], a[4], a[8])) {
    if(a[0] == 'X') {
      return PLAYER_ONE;
    }
    else if(a[0] == 'O') {
      return PLAYER_TWO;
    }
  }

  if(equality(a[2], a[4], a[6])) {
    if(a[2] == 'X') {
      return PLAYER_ONE;
    }
    else if(a[2] == 'O') {
      return PLAYER_TWO;
    }
  }

  // Checking for draw
  bool flag = false;
  for(int i = 0; i < BOARD_SIZE; i++) {
    if(a[i] == ' ') {
      flag = true;
      break;
    }
  }
  if(!flag) {
    return 0;
  }

  // To continue the loop if its none of the above
  return 3;
}

void print_board(char a[]) {
    printf("#------Grid------#\n\n");
    printf("  %c  |  %c  |  %c  \n", a[0], a[1], a[2]);
    printf("-----+-----+-----\n");
    printf("  %c  |  %c  |  %c  \n", a[3], a[4], a[5]);
    printf("-----+-----+-----\n");
    printf("  %c  |  %c  |  %c  \n\n", a[6], a[7], a[8]);
}

bool equality(char a, char b, char c) {
    if(a != EMPTY && a == b && b == c) return true;
    else return false;
}

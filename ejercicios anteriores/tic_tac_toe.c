#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpace();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);


/**
 * The main function is the main function of the program
 * 
 * @return the number of free spaces on the board.
 */
int main(){
    char winner = ' ';

    resetBoard();
    while(winner == ' ' && checkFreeSpace() != 0) {
        printBoard();

        //player move
        playerMove();
        winner = checkWinner();

        if (winner != ' ' || checkFreeSpace() == 0) {
            break;
        }

        //computer move
        computerMove();
        winner = checkWinner();
        
        if (winner != ' ' || checkFreeSpace() == 0) {
            break;
        }

    }

    printBoard();
    printWinner(winner);
    
    return 0;
}


/**
 * This function resets the board to all spaces.
 */
void resetBoard(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

/**
 * It prints the board.
 */
void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

/**
 * It checks the board for free spaces and returns the number of free spaces
 * 
 * @return The number of free spaces on the board.
 */
int checkFreeSpace(){
    int freeSpace = 9;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] != ' '){
                freeSpace --;
            }
        }
    }
    return freeSpace;
}

/**
 * The function asks the user to enter a row and column number, then checks to see if the space is
 * empty. If it is, it places the player's marker in that space. If it isn't, it tells the user that
 * the move is invalid and asks them to try again.
 */
void playerMove(){
    int x;
    int y;

    do{
        printf("Enter row #(1-3):");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-3):");;
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' '){
            printf("Invalid Move\n");
        }else{
            board[x][y] = PLAYER;
            break;
        }
    }while(board[x][y] != ' ');
}

/**
 * It creates a random number between 0 and 2, and then checks if the board at that position is empty.
 * If it is, it places the computer's character there. If it isn't, it tries again.
 */
void computerMove(){
    //creates a seed based on time
    srand(time(0));
    int x;
    int y;
    
    if (checkFreeSpace() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;

        }while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else{
        printWinner(' ');
    }
}

/**
 * It checks each row, column, and diagonal to see if there is a winner
 * 
 * @return the character that is the winner.
 */
char checkWinner(){
    //chech each row
    for (int i = 0; i < 3; i++){
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }
    //chech each column
    for (int i = 0; i < 3; i++){
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }
    //check diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return board[0][2];
    }

    return ' ';
}

/**
 * It prints the winner of the game
 * 
 * @param winner The winner of the game.
 */
void printWinner(char winner){
    if(winner == PLAYER){
        printf("you win");
    }
    if(winner == COMPUTER){
        printf("you loose");
    }
    if(winner == ' '){
        printf("Draw");
    }
}
#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void printBoard() {
    system("cls");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}
int checkWin(char player){
    for(int i=0; i<3; i++){
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player ||
           board[0][i]==player && board[1][i]==player && board[2][i]==player ){
            return 1;
           }
        }
        if(board[0][0]==player && board[1][1]==player && board[2][2]==player ||
           board[0][2]==player && board[1][1]==player && board[2][0]==player ){
            return 1;
           }
        return 0;
}

int isBoardFull(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]==' '){
                return 0;
            }
        }
    }
    return 1;
}
int evaluate(){
    if(checkWin('x')){
        return -1;
    }
    else if(checkWin('O')){
        return 1;
    }
    else{
        return 0;
    }
}
int isValidMove(int row, int col){
    return(row>=0 && row<3 && col>=0 && col<3 && board[row][col]==' ');
}
int minimax(int depth,int isMax){
    int score = evaluate();
        if(score == 1){
            return score;
        }
        if(score == -1){
            return score;
        }
        if(isBoardFull){
            return 0;
        }
    if(isMax){
        int maxEval = -1000;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]==' '){
                    board[i][j]=='O';
                    int eval=minimax(depth+1, !isMax);
                    board[i][j]==' ';
                    maxEval = (eval>maxEval) ? eval : maxEval;
                }
            }
        }
        return maxEval;
    }
    else{
        int minEval = 1000;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]==' '){
                    board[i][j]=='X';
                    int eval= minimax(depth + 1, !isMax);
                    board[i][j]==' ';
                    int minEval = (eval<minEval) ? eval: minEval;
                }
            }
    }
    return minEval;
    }
}
void findBestMove(){
    int bestVal = -1000;
    int bestMoveRow;
    int bestMoveCol;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]=' '){
                board[i][j]='O';
                int moveVal = minimax(0, 0);
                board[i][j]=' ';

                if(moveVal > bestVal){
                    bestMoveRow = i;
                    bestMoveCol = j; 
                }
            }
        }
    }
    board[bestMoveRow][bestMoveCol]='O';
}
int main() {
    int userRow, userCol;

    printf("\n      TIC TAC TOE \n \nYou are 'X' and the AI is 'O'\n");
    
    while (1) {

        printf("\n    LET THE GAMES BEGIN \n\n(row and column = 1 1 for first move)\n: ");
        scanf("%d %d", &userRow, &userCol);

        if (isValidMove(userRow - 1, userCol - 1)) {
            board[userRow - 1][userCol - 1] = 'X';
        } else {
            printf("Invalid move. Try again.\n");
            continue;
        }

        printBoard();

        if (checkWin('X')) {
            printf("YOU HAVE WON THE GAME \n");
            break;
        }

        if (isBoardFull()) {
            printf("\nIT'S A DRAW!\n");
            break;
        }

        printf("AI TURNS...\n");
        findBestMove();
        printBoard();

        if (checkWin('O')) {
            printf("AI WINS! DO BETTER NEXT TIME. \n");
            break;
        }

        if (isBoardFull()) {
            printf("\nIT'S A DRAW!\n");
            break;
        }
    }

    return 0;

    FILE *fptr;
    fptr= fopen("toe.txt","w");
    if(fptr==NULL){
        printf("ERROR");
    }
    int score = evaluate();
    {
    if(score= 1){
        printf("AI WINS");
    }
    else if(score=-1){
        printf("PLAYER WINS");
    }
    else{
        printf("DRAW");
    }
    fputc(score,fptr);
    }
    fclose(fptr);
}

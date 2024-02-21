#include <stdio.h>
#include <stdlib.h>

int board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

void printBoard(){
    printf(" %c | %c | %c ",board[0,0],board[0,1],board[0,2]);
    printf("--------------");
    printf(" %c | %c | %c ",board[1,0],board[1,1],board[1,2]);
    printf("--------------");
    printf(" %c | %c | %c ",board[2,0],board[2,1],board[2,2]);
}
int checkWin(char player){
    for(int i=0; i<3; i++){
        if(board[i,0]==player && board[i,1]== player && board[i,2]==player || board[0,i]==player && board[1,i]== player && board[2,i]==player){
            return 0;
        }
    }
        if(board[0,0]==player && board[1,1]== player && board[2,2]==player || board[0,2]==player && board[1,1]== player && board[2,0]==player){
            return 0;
    }
    return 1;
}
int evaluate(){
    if (checkWin('X')){
        return -1;
    }
    else if (checkWin('O')){
        return 1;
    }
    else{
        return 0;
    }
}
int isBoardFull(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]=' '){
                return 0;
            }
        }
    }
    return 1;
}

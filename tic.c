#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

char num[11]={'0','1','2','3','4','5','6','7','8','9'};
int statuscheck();
void shape();

int main(){
    int player = 1, i,option;
    char sign;
    do {
        shape();
        player = (player % 2) ? 1:2;
        printf("Player %d please make your move: ",player);
        scanf("%d",&option);
        sign = (player == 1)? 'x':'o';
        if(option == 1 && num[1]=='1')
            num[1]=sign;
        else if(option==2 && num[2]=='2')
            num[2]=sign;
            else if(option==3 && num[3]=='3')
            num[3]=sign;
            else if(option==4 && num[4]=='4')
            num[4]=sign;
            else if(option==5 && num[5]=='5')
            num[5]=sign;
            else if(option==6 && num[6]=='6')
            num[6]=sign;
            else if(option==7 && num[7]=='7')
            num[7]=sign;
            else if(option==8 && num[8]=='8')
            num[8]=sign;
            else if(option==9 && num[9]=='9')
            num[9]=sign;

            else{
                printf("ERROR");
                player--;
                getch();
            }
            i = statuscheck();
            player++;
    }while(i ==-1);

    shape();
    if(i==1){
        printf("Player %d is the WINNER",--player);
    }
    else{
    printf("DRAW");
    }
    getch();
    return 0;
}

int statuscheck(){
    if(num[1]==num[2] && num[2]==num[3])
    return 1;
    else if (num[4]==num[5] && num[5]==num[6])
    return 1;
    else if (num[7]==num[8] && num[8]==num[9])
    return 1;
    else if (num[1]==num[4] && num[4]==num[7])
    return 1;
    else if (num[2]==num[5] && num[5]==num[8])
    return 1;
    else if (num[3]==num[6] && num[6]==num[9])
    return 1;
    else if (num[1]==num[5] && num[5]==num[9])
    return 1;
    else if (num[3]==num[5] && num[5]==num[7])
    return 1;
    else if (num[1]!='1' && num[1]!='1' && num[2]!='2' && num[3]!='3' && num[4]!='4' && num[5]!='5' && num[6]!='6' && num[7]!='7' && num[8]!='8' &&num[9]!='9')
    return 0;
    else
    return -1;
}
void shape(){
    system("cls");
    printf("\n\n    TIC TAC TOE     \n\n");
    printf("PLAYER 1 (X) - PLAYER 2 (O)\n\n\n");
    printf("    |    |   \n");
    printf(" %c  | %c  | %c  \n",num[1],num[2],num[3]);
    printf("____|____|____\n");
    printf("    |    |   \n");
    printf("  %c |  %c |  %c \n",num[4],num[5],num[6]);
    printf("____|____|____\n");
    printf("    |    |   \n");
    printf("  %c |  %c |  %c \n",num[7],num[8],num[9]);
    printf("    |    |   \n");
}
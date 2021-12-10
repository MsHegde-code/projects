#include<stdio.h>
int i,j,win_check_ttt,playagain_ttt;;
char assign_player1,assign_player2,tictactoe[5][5],player_selection_game3;
void print_updated_grid_ttt(){
    for ( i = 0; i < 3; i++)
                {
                    for ( j = 0; j < 5; j++)
                        {
                            printf("%c\t",tictactoe[i][j]);   
                        }               
                printf("\n");
                }
}
int input_compare_ttt_X(){//to check 'X';return1;
                    if((tictactoe[0][0]=='X') && (tictactoe[0][2]=='X') && (tictactoe[0][4]=='X')){
                        printf("'X' won the match\n");
                        win_check_ttt=1;}//1
                    else if((tictactoe[1][0]=='X') && (tictactoe[1][2]=='X') && (tictactoe[1][4]=='X')){
                        printf("'X' won the match\n");
                        win_check_ttt=1;}//2
                    else if((tictactoe[2][0]=='X') && (tictactoe[2][2]=='X') && (tictactoe[2][4]=='X')){
                        printf("'X' won the match\n");
                        win_check_ttt=1;}//3
                    else if((tictactoe[0][0]=='X') && (tictactoe[1][0]=='X') && (tictactoe[2][0]=='X')){
                        printf("'X' won the match\n");
                        win_check_ttt=1;}//4
                    else if((tictactoe[0][2]=='X') && (tictactoe[1][2]=='X') && (tictactoe[2][2]=='X')){
                        printf("'X' won the match\n");
                        win_check_ttt=1;}//5
                    else if((tictactoe[0][4]=='X') && (tictactoe[1][4]=='X') && (tictactoe[2][4]=='X')){
                        printf("'X' won the match\n");
                        win_check_ttt=1;}//6
                    else if((tictactoe[0][0]=='X') && (tictactoe[1][2]=='X') && (tictactoe[2][4]=='X')){
                        printf("'X' won the match\n");
                        win_check_ttt=1;}//7
                    else if((tictactoe[0][4]=='X') && (tictactoe[1][2]=='X') && (tictactoe[2][0]=='X')){
                        printf("'X' won the match\n");
                        win_check_ttt=1;}//8
                    return win_check_ttt;
}
int input_compare_ttt_O(){//to check 'O';return2;
                    if((tictactoe[0][0]=='O') && (tictactoe[0][2]=='O') && (tictactoe[0][4]=='O')){
                        printf("'O' won the match\n");
                        win_check_ttt=2;}//1
                    else if((tictactoe[1][0]=='O') && (tictactoe[1][2]=='O') && (tictactoe[1][4]=='O')){
                        printf("'O' won the match\n");
                        win_check_ttt=2;}//2
                    else if((tictactoe[2][0]=='O') && (tictactoe[2][2]=='O') && (tictactoe[2][4]=='O')){
                        printf("'O' won the match\n");
                        win_check_ttt=2;}//3
                    else if((tictactoe[0][0]=='O') && (tictactoe[1][0]=='O') && (tictactoe[2][0]=='O')){
                        printf("'O' won the match\n");
                        win_check_ttt=2;}//4
                    else if((tictactoe[0][2]=='O') && (tictactoe[1][2]=='O') && (tictactoe[2][2]=='O')){
                        printf("'O' won the match\n");
                        win_check_ttt=2;}//5
                    else if((tictactoe[0][4]=='O') && (tictactoe[1][4]=='O') && (tictactoe[2][4]=='O')){
                        printf("'O' won the match\n");
                        win_check_ttt=2;}//6
                    else if((tictactoe[0][0]=='O') && (tictactoe[1][2]=='O') && (tictactoe[2][4]=='O')){
                        printf("'O' won the match\n");
                        win_check_ttt=2;}//7
                    else if((tictactoe[0][4]=='O') && (tictactoe[1][2]=='O') && (tictactoe[2][0]=='O')){
                        printf("'O' won the match\n");
                        win_check_ttt=2;}//8
                    return win_check_ttt;
}
            int tic_tac_toe(){
            game3:
            printf("TIC TAC TOE GAME\n");
            printf("player 1 to choose sides...to choose 'O' , press 'O' .. OR to choose 'X' , press 'X'... :)\n");
            scanf("%s",&player_selection_game3);
            if(player_selection_game3=='o' || player_selection_game3=='O'){
                assign_player1='O';
                assign_player2='X';
                printf("player 1 will play with 'O' and player 2 will play with 'X'\n");
            }
            else if(player_selection_game3=='x'|| player_selection_game3=='X'){
                assign_player1='X';
                assign_player2='O';
                printf("player 1 will play with 'X' and player 2 will play with 'O'\n");
            }
            else{
                printf("invalid input..\n");
                goto game3;
            }
            for ( i = 0; i < 3; i++)
                {
                    for ( j = 0; j < 5; j++)
                        {
                            if(j%2==0){
                            tictactoe[i][j]=' ';
                            printf("%c\t",tictactoe[i][j]);
                            }
                            else{
                            tictactoe[i][j]='|';
                            printf("%c",tictactoe[i][j]);
                            }
                        }               
                printf("\n");
                }
                //accept user input
                if(assign_player2=='O'){
                    goto player2_input_ttt;
                }
                int player1_position_ttt,player2_position_ttt;
                while(1){
                    player1_input_ttt:printf("player 1 : enter the position (1-9)\t");
                    scanf("%d",&player1_position_ttt);
                    switch(player1_position_ttt){
                        case 1: tictactoe[0][0]=assign_player1;
                                print_updated_grid_ttt();
                                break;
                        case 2: tictactoe[0][2]=assign_player1;
                                print_updated_grid_ttt();
                                break;
                        case 3: tictactoe[0][4]=assign_player1;
                                print_updated_grid_ttt();
                                break;
                        case 4: tictactoe[1][0]=assign_player1;
                                print_updated_grid_ttt();
                                break;
                        case 5: tictactoe[1][2]=assign_player1;
                                print_updated_grid_ttt();
                                break;
                        case 6: tictactoe[1][4]=assign_player1;
                                print_updated_grid_ttt();
                                break;
                        case 7: tictactoe[2][0]=assign_player1;
                                print_updated_grid_ttt();
                                break;
                        case 8: tictactoe[2][2]=assign_player1;
                                print_updated_grid_ttt();
                                break;
                        case 9: tictactoe[2][4]=assign_player1;
                                print_updated_grid_ttt();
                                break;
                        default: printf("invalid input\n");
                                 goto player1_input_ttt;
                                 break;
                    }
                        input_compare_ttt_X();
                        if(win_check_ttt==1){
                        printf("to play again press '1' or to go back press '0'\n");
                        scanf("%d",&playagain_ttt);
                        if(playagain_ttt==1){
                            printf("play again..\n");
                            win_check_ttt=-1;
                            goto game3;
                        }
                        else if(playagain_ttt==0){
                            printf("going back to game menu\n");
                            win_check_ttt=-1;
                            return 1;//main function
                        }
                        else{
                            printf("default:play again\n");
                            win_check_ttt=-1;
                            goto game3;
                        }
                    }
                    input_compare_ttt_O();
                    if(win_check_ttt==2){
                        printf("to play again press '1' or to go back press '0'\n");
                        scanf("%d",&playagain_ttt);
                        if(playagain_ttt==1){
                            printf("play again..\n");
                            win_check_ttt=-1;
                            goto game3;
                        }
                        else if(playagain_ttt==0){
                            printf("going back to game menu\n");
                            win_check_ttt=-1;
                            return 1;//main function
                        }
                        else{
                            printf("default:play again\n");
                            win_check_ttt=-1;
                            goto game3;
                        }
                    }
                    player2_input_ttt:printf("player 2: enter the position(1-9)\t");
                    scanf("%d",&player2_position_ttt);
                    switch(player2_position_ttt){
                        case 1: tictactoe[0][0]=assign_player2;
                                print_updated_grid_ttt();
                                break;
                        case 2: tictactoe[0][2]=assign_player2;
                                print_updated_grid_ttt();
                                break;
                        case 3: tictactoe[0][4]=assign_player2;
                                print_updated_grid_ttt();
                                break;
                        case 4: tictactoe[1][0]=assign_player2;
                                print_updated_grid_ttt();
                                break;
                        case 5: tictactoe[1][2]=assign_player2;
                                print_updated_grid_ttt();
                                break;
                        case 6: tictactoe[1][4]=assign_player2;
                                print_updated_grid_ttt();
                                break;
                        case 7: tictactoe[2][0]=assign_player2;
                                print_updated_grid_ttt();
                                break;
                        case 8: tictactoe[2][2]=assign_player2;
                                print_updated_grid_ttt();
                                break;
                        case 9: tictactoe[2][4]=assign_player2;
                                print_updated_grid_ttt();
                                break;
                        default: printf("invalid input\n");
                                 goto player2_input_ttt;
                                 break;
                    }
                    input_compare_ttt_O();
                    if(win_check_ttt==2){
                        printf("to play again press '1' or to go back press '0'\n");
                        scanf("%d",&playagain_ttt);
                        if(playagain_ttt==1){
                            printf("play again..\n");
                            win_check_ttt=-1;
                            goto game3;
                        }
                        else if(playagain_ttt==0){
                            printf("going back to game menu\n");
                            win_check_ttt=-1;
                            return 1;//main function
                        }
                        else{
                            printf("default:play again\n");
                            win_check_ttt=-1;
                            goto game3;
                        }
                    }
                    input_compare_ttt_X();
                    if(win_check_ttt==1){
                        printf("to play again press '1' or to go back press '0'\n");
                        scanf("%d",&playagain_ttt);
                        if(playagain_ttt==1){
                            printf("play again..\n");
                            win_check_ttt=-1;
                            goto game3;
                        }
                        else if(playagain_ttt==0){
                            printf("going back to game menu\n");
                            win_check_ttt=-1;
                            return 1;//main function
                        }
                        else{
                            printf("default:play again\n");
                            win_check_ttt=-1;
                            goto game3;
                        }
                    }
                }//while-input
                //testing for inputs
}
#include<stdio.h>
#include<stdlib.h>
int i,j,playagain_var,accept_gridkey1,accept_gridkey2,user_playagain2,user_playagain3;
char grid[5][5];
int guess_the_mines(){
playagain_3:printf("'find the mines in the grid..'\n");
                    int life_count_mines=3;
                    if(playagain_var==1){
                        printf("playing again..\tATB..\n");
                    }
                    //grid printing
                    for (i = 0; i < 4; i++)
                    {
                        for (j = 0; j < 4; j++)
                        {
                            grid[i][j]='x';
                        }
                    }
                    for (size_t i = 0; i < 4; i++)
                    {
                        for (size_t j = 0; j < 4; j++)
                        {
                            printf("%c\t",grid[i][j]);
                        }
                        printf("\n");
                        
                    }
                    //grid key 
                    grid[2][3]='o';
                    printf("enter the position (x,y) of your guess.. !!!\n");
                    guess_again_mines:scanf("%d%d",&accept_gridkey1,&accept_gridkey2);
                    if(grid[2][3]==grid[accept_gridkey1][accept_gridkey2]){
                        //to update the correct mine 
                        for (size_t i = 0; i < 4; i++)
                        {
                            for (size_t j = 0; j < 4; j++)
                            {
                                printf("%c\t",grid[i][j]);
                            }
                            printf("\n");
                            
                        }
                        printf("awesome !! you found the correct one...\n ");
                        printf("press '1' to play again or '0' to exit..\n");
                        scanf("%d",&user_playagain2);
                        if(user_playagain2==1){
                            printf("play again..\n");
                            playagain_var=1;
                            goto playagain_3;
                        }
                        else if(user_playagain2==0){
                            printf("going back to game menu\n");
                            return 3;
                        }
                        else{
                            printf("default : play again..\n");
                            playagain_var=1;
                            goto playagain_3;
                        }
                    }
                    else {
                        for (size_t i = 0; i < 2; i++)
                        {
                            printf("wrong guess..\n%d life remaining..guess again...\n",life_count_mines-1);
                            life_count_mines--;
                            if(life_count_mines==0){
                                printf("out of lives...Better luck next time\nto play again press '1' or to  go back press '0'\n");
                                scanf("%d",&user_playagain3);
                                if(user_playagain3==1){
                                    printf("play again..\n");
                                    goto playagain_3;
                                }
                                else if(user_playagain3==0){
                                    printf("going back to start menu...\n");
                                    return 4;
                                }
                                else{
                                    printf("default: play again..\n");
                                    goto playagain_3;
                                }
                            }
                            goto guess_again_mines;
                        }
                        
                    }
}
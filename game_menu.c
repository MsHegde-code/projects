#include<stdio.h>
#include<stdlib.h>
//functions
int games(int start_selection){
    //game menu code
    while(1){
        switch(start_selection){
            case 1: playagain_1 : printf("GUESS THE LUCKY NUMBER\n");
                    int game_1[10]={1,2,3,4,5,6,7,8,9,10},i,life_count=2;
                    for ( i = 0; i < 10; i++)
                    {
                        printf("%d\t",game_1[i]);
                    }
                    printf("\n");
                    int lucky_number=game_1[6],guess_number,user_choice,guess_again1;
                    guess_again : scanf("%d",&guess_number);
                    if(guess_number==lucky_number){
                        printf("Superb...you guessed it right\n");
                        printf("to play again press '1' OR to exit to game menu press '0'\n");
                        scanf("%d",&user_choice);
                        if(user_choice==1){
                            printf("play again...\n");
                            goto playagain_1;
                        }
                        else if(user_choice==0){
                            printf("going back to game menu\n");
                            return 1;//start menu return
                        }
                        else{
                            printf("default : play again\n");
                            goto playagain_1;
                        }
                    }
                    //outer else block
                    else
                        {
                        for(;life_count>=0;){
                        printf("oops...Wrong guess!!\nguess again..\n");
                        printf("%d life remaining..\n",life_count);
                            if(life_count==0){
                                printf("Out of lives!!..better luck next time..\n");
                                printf("press '1' to play again or '0' to go back\n");
                                scanf("%d",&guess_again1);
                                if (guess_again1==1)
                                {
                                    printf("play again\n");
                                    goto playagain_1;
                                }
                                else if(guess_again1==0){
                                    printf("going back..\n");
                                    return 1;
                                }
                                else{
                                    printf("default : play again..\n");
                                    goto playagain_1;
                                }
                                
                            }
                        life_count--;
                        goto guess_again;

                        }//for loop
                    }//else
                    break;
            case 2: printf("welcome to find the mines in the grid..\n");


            }//switch_block
        }
    }

int help_menu(){
    //help menu
    printf("HELP MENU\n");
    int help_selection,exit_back;
    help_menu1 : printf("ENTER THE SELECTION\n1.help for the game 'guess the lucky number'\n2.help for the game 'search the mines'\n3.help for the game crossword puzzle\n0.exit to main menu");
    scanf("%d",&help_selection);
    while(1){
        switch(help_selection){
            case 1: printf("guess the lucky number\n");
                    printf("Here, you need to guess the lucky number from the give set of numbers, the selection should be from\n 1 to 10 numbers..you will be having 2 lives to complete the game..\nALL THE BEST FOR YOUR LUCK\n...");
                    printf("press '0' to go back\n");
                    scanf("%d",&exit_back);
                    if(exit_back==0){
                        printf("exiting...\n");
                        goto help_menu1;
                    }
                    else{
                        printf("default : going back\n");
                        goto help_menu1;
                    }
                    break;
            case 2: printf("guess the mines in the grid..\n");
                    printf("here, you need to guess the mines hidden inside the grid, by guessing the position of the mines..\nthe position starts from '0', and goes on row wise..you will be having 3 lives to guess the mines from the grid\nthe mines to be searched depends the grid number..i.e for a\n1.'2x2' grid '1'mine\n2. 3x3 grid 2 mines\n3. 4x4 grid 4 mines and so on\nTry your luck !!!\n");
                    printf("to go back press '0'\n");
                    scanf("%d",&exit_back);
                    if (exit_back==0)
                    {
                        printf("going back..");
                        goto help_menu1;
                    }
                    else{
                        printf("default: going back..\n");
                        goto help_menu1;
                    }
                    break;
            case 0: printf("going back to main menu\n");
                    return 1;
                    break;
                    
        }
    }
}
int main(){
    int menu_loop,selection,start_selection,option_selection,sound_selection,assign_sound;
    char exit_selection;
    while (1)
    {
        main_menu : printf("\tMAIN MENU\nSELECT AN OPTION\n");//main menu screen
        printf("1.START\n2.OPTIONS\n3.HELP\n0.EXIT\n");
        scanf("%d",&selection);
        switch(selection){
            //start selection
            case 1: start_menu: printf("\tENTER YOUR SELECTION\n1.GUESS THE LUCKY NUMBER\n2.FIND THE MINES IN THE GRID\n3.CROSSWORD PUZZLE\n0.EXIT\n");
                    scanf("%d",&start_selection);
                    if(start_selection==0){
                        printf("going back to main menu\n");
                        goto main_menu;
                        break;
                    }
                    if (start_selection>=4 || start_selection<0)
                    {
                        printf("enter a valid selection\n");
                        goto start_menu;
                    }
                    
                    else
                        games(start_selection);//games selection
                        goto start_menu;
                    break;
            //option screen selection
            case 2: option_menu :printf("select an option\n1.Sound\n2.music\n0.Back to main menu\n");
                    scanf("%d",&option_selection);
                    if(option_selection==1){
                        //sound menu
                        sound_menu : printf("select an option\n1.enable sound\n2.disable sound\n3.Back\n");
                        scanf("%d",&sound_selection);
                        if(sound_selection==1){
                            if(assign_sound==1){
                                printf("sound is already on...raise up the volume\n");
                                goto sound_menu;
                            }
                            printf("sound enabled\n");
                            assign_sound=1;
                            goto sound_menu;
                        }
                        else if(sound_selection==2){
                            if(assign_sound==2){
                                printf("sound already disabled\n");
                                goto sound_menu;
                            }
                            printf("sound disabled\n");
                            assign_sound=2;
                            goto sound_menu;
                        }
                        else{
                            printf("going back..\n");
                            goto option_menu;
                        }
                    
                    }
                    break;
            case 3: printf("HELP..\n");
                    help_menu();
                    goto main_menu;
                    break;
            case 0: exit_menu : printf("Are you sure to exit the game??\nYes(Y) or No(N)\n");
                    scanf("%s",&exit_selection);
                    if(exit_selection=='y'|| exit_selection=='Y')
                    {
                        printf("exiting...\n");
                        exit(0);
                    }
                    else if(exit_selection=='n' || exit_selection=='N'){
                            printf("going back to main menu\n");
                            goto main_menu;
                    }
                    else{
                        printf("enter a valid input\n");
                        goto exit_menu;
                    }
                    break;
            default: printf("enter a valid selection\n");
                     goto main_menu;
                     break;
        }
    }
}
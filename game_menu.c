#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"guess_the_mines.h"
#include"tic_tac_toe.h"
int games(int start_selection){
        switch(start_selection){
            case 1: 
                guess_the_mines();
                break;
            case 2:
                tic_tac_toe();
                break;
            }
        }
int help_menu(){
    //help menu
    printf("HELP MENU\n");
    int help_selection,exit_back;
    help_menu1 : printf("ENTER THE SELECTION\n1.help - 'search the mines'\n2.help - 'tic tac toe'\n0.exit to main menu");
    scanf("%d",&help_selection);
    while(1){
        switch(help_selection){
            case 1: printf("guess the mines in the grid..\n");
                    printf("here, you need to guess the mines hidden inside the grid, by guessing the position (row,column) of the mines..\nthe position starts from (0,0) and goes on...\nyou will be having 3 lives to guess the mines from the grid\nTry your luck !!!\n");
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
    int menu_loop,selection,start_selection,option_selection,sound_selection,assign_sound=0,assign_music=0,music_selection;
    char exit_selection;
    while (1)
    {
        main_menu : printf("\t\tMAIN MENU\nSELECT AN OPTION\n");//main menu screen
        printf("1.START\n2.OPTIONS\n3.HELP\n0.EXIT\n");
        scanf("%d",&selection);
        switch(selection){
            //start selection
            case 1: start_menu: printf("\t\tENTER YOUR SELECTION\n1.FIND THE MINES IN THE GRID\n2.TIC-TAC-TOE\n0.EXIT\n");
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
                        sound_menu : printf("select an option\n1.enable sound\n2.disable sound\n3.Go Back\n");
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
                    else if(option_selection==2){
                        music_menu:printf("MUSIC\n1. press '1' to enable music\n2.press '2' to disable music\n3. press '0' to go back\n");
                        scanf("%d",&music_selection);
                        if(music_selection==1){
                            if(assign_music==1){
                            printf("music is already on...raise the volume..\n");
                            goto music_menu;
                        }
                        printf("music is turned on..\n");
                        assign_music=1;
                        }
                        else if(music_selection==2){
                            if(assign_music==2){
                                printf("music already disabled..\n");
                                goto music_menu;
                            }
                            printf("music is disabled..\n");
                            assign_music=2;
                        }
                        else if(music_selection==0){
                            printf("going back..\n");
                            goto option_menu;
                        }
                        else{
                            printf("invalid input\n");
                            goto music_menu;
                        }
                    }
                    else if(option_selection==3){
                        printf("going back..\n");
                        goto main_menu;
                    }
                    else{
                        printf("invalid input..\n");
                        goto option_menu;
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
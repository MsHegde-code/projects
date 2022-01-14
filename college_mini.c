#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct movies{
    char movie_name[20],day[10],place[20];
    int date,time,total;
    struct movies *next,*prev;
}node;
node *start=NULL,*head;
node* create(){
    node *new;
    new=(node*)malloc(sizeof(node));
    new->next=new;
    new->prev=new;
    return new;
}
void insert_rear(node *new){
    node *temp=start;
    if(start==NULL){
        head=create();
        start=new;
        //head node and updation of pointer fields
        head->total=1; head->next=new;  new->prev=head; head->prev=new; new->next=head;
        return;
    }
    if(start->next==head){
        start->next=new;    new->prev=start;    new->next=head;     head->prev=new;
        return;
    }
    while(temp->next!=head)     temp=temp->next;
    temp->next=new;     new->prev=temp;     new->next=head;     head->prev=temp;
    return;
}
void display_menu(){
    int ch;
    for (size_t i = 0; i < 20; i++)
    {
        printf("---");
    }//display the border
    printf("\n|\t1.BOOK TICKET\n|\t2.EDIT TICKET\n|\t3.CANCEL TICKET\n|\t4.DISPLAY TICKET\n|\t5.EXIT\n");
}
node* book_ticket(node *new){
    int ch,user_ddt;
    display_movie:printf("\n|\tavaliable movies\t|\n|\t1.KGF CHAPTER 2\n|\t2.BAHUBALLI REBORN\n|\t3.SPIDER MAN : AT HOME\n|\t4.***COMING SOON ***\nwaiting for your choice :)  .....\t");
    scanf("%d",&ch);
    printf("|date & day|\t|time|\t|theatre|\n");
    switch(ch){
        case 1:
                ddt_sel1:printf("1.12th wed\t2:40pm\tvega city mall\n2.14th fri\t9:00pm\torion mall\n3.16th sun\t5:45pm\troyal mall\n");
                printf("waiting for your choice :) ....\t");
                scanf("%d",&user_ddt);
                //movie="KGF CHAPTER 2"
                switch(user_ddt){
                    case 1: strcpy(new->movie_name,"KGF CHAPTER 2");    new->date=12;   strcpy(new->day,"wednesday");   new->time=2.40; strcpy(new->place,"VEGA CITY MALL"); 
                            break;
                    case 2: strcpy(new->movie_name,"KGF CHAPTER 2");    new->date=14;   strcpy(new->day,"friday");   new->time=9.00; strcpy(new->place,"ORION MALL");
                            break;
                    case 3: strcpy(new->movie_name,"KGF CHAPTER 2");    new->date=16;   strcpy(new->day,"sunday");   new->time=5.45; strcpy(new->place,"ROYAL MALL");
                            break;
                    default:printf("\ninvalid input\n");
                            goto ddt_sel1;
                }
                break;
        case 2: ddt_sel2:printf("1.11th TUE\t8:40pm\tvega city mall\n2.13th THU\t3:00pm\torion mall\n3.15th SAT\t6:45pm\troyal mall\n");
                printf("waiting for your choice :) ....\t");
                scanf("%d",&user_ddt);
                //movie="BAHUBALLI REBORN"
                switch(user_ddt){
                    case 1: strcpy(new->movie_name,"BAHUBALLI REBORN");    new->date=11;   strcpy(new->day,"TUESDAY");   new->time=8.40; strcpy(new->place,"VEGA CITY MALL");
                            break;
                    case 2: strcpy(new->movie_name,"BAHUBALLI REBORN");    new->date=13;   strcpy(new->day,"THURSDAY");   new->time=3.00; strcpy(new->place,"ORION MALL"); 
                            break;
                    case 3: strcpy(new->movie_name,"BAHUBALLI REBORN");    new->date=15;   strcpy(new->day,"SATURDAY");   new->time=6.45; strcpy(new->place,"ROYAL MALL");
                            break;
                    default:printf("\ninvalid input\n");
                            goto ddt_sel2;
                }
                break;
        case 3: ddt_sel3:printf("1.17th MON\t6:40pm\tvega city mall\n2.19th WED\t2:00pm\torion mall\n3.20th THU\t8:45pm\troyal mall\n");
                printf("waiting for your choice :) ....\t");
                scanf("%d",&user_ddt);
                //movie="SPIDER MAN : AT HOME"
                switch(user_ddt){
                    case 1: strcpy(new->movie_name,"SPIDER MAN : AT HOME");    new->date=17;   strcpy(new->day,"MONDAY");   new->time=2.40; strcpy(new->place,"VEGA CITY MALL");
                            break;
                    case 2: strcpy(new->movie_name,"SPIDER MAN : AT HOME");    new->date=19;   strcpy(new->day,"WEDNESDAY");   new->time=2.40; strcpy(new->place,"ORION MALL");
                            break;
                    case 3: strcpy(new->movie_name,"SPIDER MAN : AT HOME");    new->date=20;   strcpy(new->day,"FRIDAY");   new->time=2.40; strcpy(new->place,"ROYAL MALL");
                            break;
                    default:printf("\ninvalid input\n");
                            goto ddt_sel3;
                }
                break;
        default: printf("\ninvalid input\n");
                    goto display_movie;
    }
    return new;
}
void checkout(){

}
void edit_ticket(){}
void cancel_ticket(){}
void display_ticket(){}
int main(){
    int ch;node *new;
    while(1){
        printf("\n\t|\tMOVIE TICKET BOOKING SYSTEM\t|\n");
        display_menu(); 
        printf("waiting for your choice.....\t");
        scanf("%d",&ch);
        switch(ch){
            //when user hits back, use goto function and jump to display menu
            case 1: new=create();
                    new=book_ticket(new);
                    insert_rear(new);
                    checkout(new);
                    break;
            case 2: edit_ticket();
                    break;
            case 3: cancel_ticket();
                    break;
            case 4: display_ticket();
                    break;
            default:    printf("exiting...\n");
                        exit(0);
        }
    }
    return 0;
}
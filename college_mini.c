#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct movies{
    char movie_name[20],day[10],place[20],name[20];
    int date,time,total,phone,bookseats,mov_sel,user_ddt;
    float bill;
    struct movies *next,*prev;
}node;
int ava_seat[3][3];//updating the available seats
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
        head->total=1; head->next=new;  new->prev=head; head->prev=new; new->next=head;
        return;
    }
    if(start->next==head){
        start->next=new;    new->prev=start;    new->next=head;     head->prev=new;     (head->total)++;
        return;
    }
    while(temp->next!=head)     temp=temp->next;
    temp->next=new;     new->prev=temp;     new->next=head;     head->prev=temp;        (head->total)++;
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
    display_movie:printf("\n|\tavaliable movies\t|\n|\t1.KGF CHAPTER 2\n|\t2.BAHUBALLI REBORN\n|\t3.SPIDER MAN : AT HOME\n|\t4.***COMING SOON ***\nwaiting for your choice :)  .....\t");
    scanf("%d",&new->mov_sel);
    printf("|date & day|\t|time|\t|theatre|\t|available seats|\n");
    switch(new->mov_sel){
        case 1: ddt_sel1:printf("1.12th wed\t2:40pm\tvega city mall\t%d\n2.14th fri\t9:00pm\torion mall\t%d\n3.16th sun\t5:45pm\troyal mall\t%d\n",ava_seat[1][1],ava_seat[1][2],ava_seat[1][3]);
                printf("waiting for your choice :) ....\t");
                scanf("%d",&new->user_ddt);
                //movie="KGF CHAPTER 2"
                switch(new->user_ddt){
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
        case 2: ddt_sel2:printf("1.11th TUE\t8:40pm\tvega city mall\t%d\n2.13th THU\t3:00pm\torion mall\t%d\n3.15th SAT\t6:45pm\troyal mall\t%d\n",ava_seat[2][1],ava_seat[2][2],ava_seat[2][3]);
                printf("waiting for your choice :) ....\t");
                scanf("%d",&new->user_ddt);
                //movie="BAHUBALLI REBORN"
                switch(new->user_ddt){
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
        case 3: ddt_sel3:printf("1.17th MON\t6:40pm\tvega city mall\t%d\n2.19th WED\t2:00pm\torion mall\t%d\n3.20th THU\t8:45pm\troyal mall\t%d\n",ava_seat[3][1],ava_seat[3][2],ava_seat[3][3]);
                printf("waiting for your choice :) ....\t");
                scanf("%d",&new->user_ddt);
                //movie="SPIDER MAN : AT HOME"
                switch(new->user_ddt){
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
node* checkout(node *new){
        char ch;
        form:printf("\nENTER CUSTOMER INFORMATION\nNAME : \t");
        scanf("%s",new->name);
        printf("\nENTER THE PHONE NUMBER : \t");
        scanf("%d",&new->phone);
        printf("\nCOST PER SEAT : RS.230.25 (INCL GST)\nHOW MANY SEATS?? : \t");
        scanf("%d",&new->bookseats);
        new->bill=0;
        new->bill=(new->bookseats)*230.25;
        printf("AMOUNT TO BE PAID : Rs.%.3f\n",new->bill);
        printf("TO CONFIRM PRESS (Y)ES OR (N)O TO GO BACK TO FILL AGAIN\n");
        scanf("\n%c",&ch);
        if(ch=='Y'||ch=='y'){
                printf("Ticket Successfully booked\nREDIRECTING TO MAIN MENU\n");
                return new;
                }
        else    goto form;
}
void edit_ticket(){}
void cancel_ticket(){}
void display_ticket(){}
int main(){
        ava_seat[1][1]=25,ava_seat[1][2]=31,ava_seat[1][3]=28,ava_seat[2][1]=29,ava_seat[2][2]=35,ava_seat[2][3]=33,ava_seat[3][1]=25,ava_seat[3][2]=29,ava_seat[3][3]=32;
        int ch;node *new;
        while(1){
        printf("\n\t|\tMOVIE TICKET BOOKING SYSTEM\t|\n");
        display_menu(); 
        printf("waiting for your choice.....\t");
        scanf("%d",&ch);
        switch(ch){
            case 1: new=create();
                    new=book_ticket(new);
                    new=checkout(new);
                    ava_seat[new->mov_sel][new->user_ddt]=ava_seat[new->mov_sel][new->user_ddt]-(new->bookseats);
                    insert_rear(new);
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
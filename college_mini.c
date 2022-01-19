#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct movies{
    char movie_name[22],day[10],place[20],name[20];
    int date,total,phone,bookseats,mov_sel,ticket_id;
    float bill,time;
    struct movies *next,*prev;
}node;
int id;//updating the available seats
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
node* book_ticket(node *new,int ava_seat1,int ava_seat2,int ava_seat3){
        display_movie:printf("|avaliable movies| |date & day| |time| |theatre|\t|available seats|\n");
        printf("| 1.Movie 1\t  12th wed\t2:40pm\tvega city mall\t%d\n| 2.Movie 2\t  13th THU\t3:00pm\torion mall\t%d\n| 3.Movie 3\t  20th THU\t8:45pm\troyal mall\t%d\n",ava_seat1,ava_seat2,ava_seat3);
        printf("Waiting for your choice :)...\t");
        scanf("%d",&new->mov_sel);
        switch(new->mov_sel){
                case 1: if(ava_seat1==0){
                        printf("Sorry!!\tNO SEATS AVAILABLE\n");        goto display_movie;
                        }
                        else{
                                strcpy(new->movie_name,"Movie 1");    new->date=12;   strcpy(new->day,"wednesday");   new->time=2.40; strcpy(new->place,"VEGA CITY MALL");;
                        }
                        break;
                case 2: if(ava_seat2==0){
                        printf("Sorry!!\tNO SEATS AVAILABLE\n");        goto display_movie;
                        } 
                        else{
                                strcpy(new->movie_name,"Movie 2");    new->date=13;   strcpy(new->day,"THURSDAY");   new->time=3.00; strcpy(new->place,"ORION MALL");
                        }
                        break;
                case 3: if(ava_seat3==0){
                                printf("Sorry!!\tNO SEATS AVAILABLE\n");        goto display_movie;
                        }
                        else{
                                strcpy(new->movie_name,"Movie 3");    new->date=20;   strcpy(new->day,"FRIDAY");   new->time=2.40; strcpy(new->place,"ROYAL MALL");
                        }
                break;
        default: printf("\ninvalid input\n");
                 goto display_movie;
    }
    return new;
}
node* checkout(node *new,int ava_seat1,int ava_seat2,int ava_seat3){
        char ch;
        form:printf("\nENTER CUSTOMER INFORMATION\nNAME : \t");
        scanf("%s",new->name);
        printf("\nENTER THE PHONE NUMBER : \t");
        scanf("%d",&new->phone);
        ask:printf("\nCOST PER SEAT : RS.230.25 (INCL GST)\nHOW MANY SEATS?? : \t");
        scanf("%d",&new->bookseats);
        switch(new->mov_sel){
            case 1: if(new->bookseats>ava_seat1){
                        printf("Selected Number of Seats not available\nSelect within the Range\n");
                        goto ask;
                        }
                    break;
            case 2: if(new->bookseats>ava_seat2){
                        printf("Selected Number of Seats not available\nSelect within the Range\n");
                        goto ask;
                        }
                    break;
            default: if(new->bookseats>ava_seat3){
                        printf("Selected Number of Seats not available\nSelect within the Range\n");
                        goto ask;
                        }
                    break;
        }
        new->bill=0;
        new->bill=(new->bookseats)*230.25;
        printf("AMOUNT TO BE PAID : Rs.%.3f\n",new->bill);
        printf("TO CONFIRM PRESS (Y)ES OR (N)O TO GO BACK TO FILL AGAIN\n");
        scanf("\n%c",&ch);
        if(ch=='Y'||ch=='y'){
                printf("TICKET ID : %d SUCCESSFULLY BOOKED\nREDIRECTING TO MAIN MENU\n",new->ticket_id);
                return new;
                }
        else    goto form;
}
void edit_ticket(){}
void cancel_ticket(){}
void display_ticket(node *new){
        node *temp=start;int ticket,pass,tick_id;
        display:printf("\n|\tDisplay Ticket\t|\n1.View all Tickets\n2.View Indivisual tickets\n3.Exit\n");
        scanf("%d",&ticket);
        if(start==0){
                printf("NO TICKETS BOOKED\n");
                return;
        }
        switch(ticket){
                case 1: pass:printf("ENTER ADMIN PASSWORD..\nTo Exit press 0\n..");
                        scanf("%d",&pass);
                        if(pass==1234){
                                printf("Displaying all Tickets booked\n");
                                while(temp!=head){
                                        printf("|Name : %s|\t|Phone : %d|\t|Ticket ID : %d|\n|Movie : %s|\t|Date/Time : %d %s at %.2f|\n|Venue : %s|\t|Seats : %d|\n",temp->name,temp->phone,temp->ticket_id,temp->movie_name,temp->date,temp->day,temp->time+12,temp->place,temp->bookseats);
                                        printf("node:%p\nnext:%p\nprev:%p\n",temp,temp->next,temp->prev);
                                        temp=temp->next;
                                        printf("\n");
                                }
                                printf("\nTotal Number of Tickets Booked : %d\nnode:%p\nnext:%p\nprev:%p\n",head->total,head,head->next,head->prev);
                        }
                        else if(pass==0){
                                printf("going back..\n");
                                goto display;
                        }
                        else{
                                printf("Invalid ID...Try Again\n");
                                goto pass;
                        }
                        break;
                case 2: printf("ENTER THE TICKET ID : ");
                        scanf("%d",&tick_id);
                        while(temp!=head){
                                if(tick_id==temp->ticket_id){
                                        printf("|Name : %s|\t|Phone : %d|\t|Ticket ID : %d|\n|Movie : %s|\t|Date/Time : %d %s at %.2f|\n|Venue : %s|\t|Seats : %d|\n",temp->name,temp->phone,temp->ticket_id,temp->movie_name,temp->date,temp->day,temp->time+12,temp->place,temp->bookseats);
                                        return;
                                }
                                temp=temp->next;
                        }
                        printf("Invalid Ticket ID");
                default: return;
        }
}
int main(){
        id=1321;
        int ava_seat1=25,ava_seat2=3,ava_seat3=14;
        int ch;node *new;
        while(1){
        printf("\n\t|\tMOVIE TICKET BOOKING SYSTEM\t|\n");
        display_menu(); 
        printf("waiting for your choice.....\t");
        scanf("%d",&ch);
        switch(ch){
            case 1: new=create();
                    new=book_ticket(new,ava_seat1,ava_seat2,ava_seat3);
                    new->ticket_id=id++;
                    new=checkout(new,ava_seat1,ava_seat2,ava_seat3);
                    if(new->mov_sel==1)           ava_seat1=ava_seat1-(new->bookseats);
                    else if(new->mov_sel==2)          ava_seat2=ava_seat2-(new->bookseats);  
                    else if(new->mov_sel==3)        ava_seat3=ava_seat3-(new->bookseats);            
                    insert_rear(new);
                    break;
            case 2: edit_ticket();
                    break;
            case 3: cancel_ticket();
                    break;
            case 4: display_ticket(new);
                    break;
            default:    printf("exiting...\n");
                        exit(0);
        }
    }
    return 0;
}
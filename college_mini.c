#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct movies{
    char movie_name[22],day[10],place[20],name[20];
    int date,total,phone,bookseats,mov_sel,ticket_id,flag;
    float bill,time;
    struct movies *next,*prev;
}node;
int id;//updating the available seats
int ava_seat1=25,ava_seat2=3,ava_seat3=14;
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
    temp->next=new;     new->prev=temp;     new->next=head;     head->prev=new;        (head->total)++;
    return;
}
node* book_ticket(node *new){
        int ch;
        display_movie:printf("|avaliable movies| |date & day| |time| |theatre|\t|available seats|\n");
        printf("| 1.Movie 1\t  12th wed\t2:40pm\tvega city mall\t%d\n| 2.Movie 2\t  13th THU\t3:00pm\torion mall\t%d\n| 3.Movie 3\t  20th THU\t8:45pm\troyal mall\t%d\n",ava_seat1,ava_seat2,ava_seat3);
        printf("Waiting for your choice :)...\t");
        scanf("%d",&ch);
        switch(ch){
                case 1: if(ava_seat1==0){
                        printf("Sorry!!\tNO SEATS AVAILABLE\n");        goto display_movie;
                        }
                        else{  
                            if(new->flag==1){
                                printf("Cannot select the same movie\n");
                                return new;
                                }
                                new->mov_sel=1;
                                strcpy(new->movie_name,"Movie 1");    new->date=12;   strcpy(new->day,"wednesday");   new->time=2.40; strcpy(new->place,"VEGA CITY MALL");  new->flag=1;
                        }
                        break;
                case 2: if(ava_seat2==0){
                        printf("Sorry!!\tNO SEATS AVAILABLE\n");        goto display_movie;
                        } 
                        else{
                                if(new->flag==2){
                                printf("Cannot select the same movie\n");
                                return new;
                                }
                                new->mov_sel=2;
                                strcpy(new->movie_name,"Movie 2");    new->date=13;   strcpy(new->day,"THURSDAY");   new->time=3.00; strcpy(new->place,"ORION MALL");   new->flag=2;
                        }
                        break;
                case 3: if(ava_seat3==0){
                                printf("Sorry!!\tNO SEATS AVAILABLE\n");        goto display_movie;
                        }
                        else{
                                if(new->flag==3){
                                printf("Cannot select the same movie\n");
                                return new;
                                }
                                new->mov_sel=3;
                                strcpy(new->movie_name,"Movie 3");    new->date=20;   strcpy(new->day,"FRIDAY");   new->time=2.40; strcpy(new->place,"ROYAL MALL"); new->flag=3;
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
        ask:printf("\nCOST PER SEAT : RS.230.25 (INCL GST)\nBOOK 3+ TICKETS TO GET A DISCOUNT OF 10 PERCENT ON THE TOTAL BILL\nHOW MANY SEATS?? : \t");
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
        //to update the seats
        if(new->mov_sel==1)           ava_seat1=ava_seat1-(new->bookseats);
        else if(new->mov_sel==2)          ava_seat2=ava_seat2-(new->bookseats);  
        else if(new->mov_sel==3)        ava_seat3=ava_seat3-(new->bookseats);
        new->bill=0;
        if(new->bookseats>2)    new->bill=(new->bookseats)*207.225;
        else    new->bill=(new->bookseats)*230.25;
        printf("AMOUNT TO BE PAID : Rs.%.3f\n",new->bill);
        printf("TO CONFIRM PRESS (Y)ES OR (N)O TO GO BACK TO FILL AGAIN\n");
        scanf("\n%c",&ch);
        if(ch=='Y'||ch=='y'){
                printf("TICKET ID : %d SUCCESSFULLY BOOKED\nREDIRECTING TO MAIN MENU\n",new->ticket_id);
                return new;
                }
        else    goto form;
}
void edit_ticket(node *new){
    int user_id,ch;node *temp=head->next;
    printf("Enter the Ticket ID...\t");
    scanf("%d",&user_id);
    edit_menu:printf("\n1.Edit Name,phone,number of seats\n2.Edit movie\n3.go back\n");
    scanf("%d",&ch);
    switch(ch){
        case 1: 
                while(temp!=head){
                    if(user_id==temp->ticket_id){
                        //updating the total seats
                        if(temp->mov_sel==1)    ava_seat1=ava_seat1+temp->bookseats;
                        else if(temp->mov_sel==2)   ava_seat2=ava_seat2+temp->bookseats;
                        else if(temp->mov_sel==3) ava_seat3=ava_seat3+temp->bookseats;
                        checkout(temp);
                        printf("Updated Ticket :\n");
                        printf("|Name : %s|\t|Phone : %d|\t|Ticket ID : %d|\n|Movie : %s|\t|Date/Time : %d %s at %.2f|\n|Venue : %s|\t|Seats : %d|\n",temp->name,temp->phone,temp->ticket_id,temp->movie_name,temp->date,temp->day,temp->time+12,temp->place,temp->bookseats);
                        return;
                    }
                    temp=temp->next;
                }
                printf("INVALID TICKET ID\n");
                break;
        case 2: 
                while(temp!=head){
                    if(user_id==temp->ticket_id){      
                        //to update the seats as per movie selection
                        if(temp->mov_sel==1)    ava_seat1=ava_seat1+temp->bookseats;
                        else if(temp->mov_sel==2)   ava_seat2=ava_seat2+temp->bookseats;
                        else if(temp->mov_sel==3) ava_seat3=ava_seat3+temp->bookseats;
                        printf("CHECK: MOV:%d\tCHECK SEATS:%d\n",temp->mov_sel,temp->bookseats);
                    book_ticket(temp);
                        if(temp->mov_sel==1)    ava_seat1=ava_seat1-temp->bookseats;
                        else if(temp->mov_sel==2)   ava_seat2=ava_seat2-temp->bookseats;
                        else if(temp->mov_sel==3) ava_seat3=ava_seat3-temp->bookseats;
                        printf("CHECK: MOV:%d\tCHECK SEATS:%d\n",temp->mov_sel,temp->bookseats);
                    if(temp->flag>0)    goto edit_menu;
                        printf("Updated Ticket :\n");
                        printf("|Name : %s|\t|Phone : %d|\t|Ticket ID : %d|\n|Movie : %s|\t|Date/Time : %d %s at %.2f|\n|Venue : %s|\t|Seats : %d|\n",temp->name,temp->phone,temp->ticket_id,temp->movie_name,temp->date,temp->day,temp->time+12,temp->place,temp->bookseats);
                        return;
                    }
                    temp=temp->next;
                }
                printf("Invalid ticket ID\n");
                break;
        default: return;
    }
}
void cancel_ticket(){
    //deduct the cancellation amount 
    node *temp=head,*prev;int id;
    printf("enter the ticket id\n");
    scanf("%d",&id);
    if(temp->next==head || head->total==0){//temp started from head
        printf("no tickets booked to be canceled\n");
        return;
    }
    while(temp->next!=head){
        prev=temp;      temp=temp->next;
        if(temp->ticket_id==id){
            printf("deleted item:%d",temp->ticket_id);
            prev->next=temp->next;  (temp->next)->prev=prev;
            head->total--;      temp=NULL ;
               free(temp);      return;
        }
    }
    if(temp->ticket_id==id && temp->next==head){ //to delete the last node
        printf("deleted item:%d",temp->ticket_id);
        head->prev=temp->prev;      (temp->prev)->next=head;       head->total--;
        temp=NULL; free(temp);
        return;
    }
}
void display_ticket(node *new){
        node *temp=start;int ticket,pass,tick_id;
        display:printf("\n|\tDisplay Ticket\t|\n1.View all Tickets\n2.View Indivisual tickets\n3.Exit\n");
        scanf("%d",&ticket);
        if(start==0){
                printf("NO TICKETS BOOKED\n");
                return;
        }
        switch(ticket){
                case 1:
                        printf("Displaying all Tickets booked\n");
                            while(temp!=head){
                                        printf("|Name : %s|\t|Phone : %d|\t|Ticket ID : %d|\n|Movie : %s|\t|Date/Time : %d %s at %.2f|\n|Venue : %s|\t|Seats : %d|\n",temp->name,temp->phone,temp->ticket_id,temp->movie_name,temp->date,temp->day,temp->time+12,temp->place,temp->bookseats);
                                        printf("node:%p\nnext:%p\nprev:%p\n",temp,temp->next,temp->prev);
                                        temp=temp->next;
                                        printf("\n");
                            }
                        printf("\nTotal Number of Tickets Booked : %d\nnode:%p\nnext:%p\nprev:%p\n",head->total,head,head->next,head->prev);
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
        int ch;node *new;
        while(1){
        printf("\n\t|\tMOVIE TICKET BOOKING SYSTEM\t|\n");
        for (size_t i = 0; i < 20; i++)
            printf("---");
        printf("\n|\t1.BOOK TICKET\n|\t2.EDIT TICKET\n|\t3.CANCEL TICKET\n|\t4.DISPLAY TICKET\n|\t5.EXIT\n"); 
        printf("waiting for your choice.....\t");
        scanf("%d",&ch);
        switch(ch){
            case 1: new=create();
                    new=book_ticket(new);
                    new->ticket_id=id++;
                    new=checkout(new);            
                    insert_rear(new);
                    break;
            case 2: edit_ticket(new);
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
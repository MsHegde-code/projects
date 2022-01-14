#include<stdio.h>
#include<stdlib.h>
typedef struct movies{
    char movie_name[20],day[10],place[20];
    int date,time,total;
    struct movie *next,*prev;
}node;
node *start=NULL,*head;
node* create(){
    //only storing data
    node *new;
    new=(node*)malloc(sizeof(node));
    new->next=new;
    new->prev=new;
    return new;
}
void insert_rear(node *new){
    if(start==NULL){
        start=new;
        //head node and updation of pointer fields
        head->total=1; head->next=new;  new->prev=head; head->prev=new; new->next=head;
        return;
    }
}
void display_menu(){
    int ch;
    for (size_t i = 0; i < 20; i++)
    {
        printf("---");
    }//display the border
    printf("\n|\t1.BOOK TICKET\n|\t2.EDIT TICKET\n|\t3.CANCEL TICKET\n|\t4.DISPLAY TICKET\n|\t5.EXIT\n");
}
void book_ticket(node *new){
    int ch,user_ddt;
    printf("\n|\tavaliable movies\t|\n");
    display_movie:printf("1.KGF CHAPTER 2\n2.BAHUBALLI REBORN\n3.SPIDER MAN : AT HOME\n4.***COMING SOON ***\n");
    scanf("%d",&ch);
    printf("\t|date & day|\t|time|\t|theatre|\n");
    switch(ch){
        case 1:
                ddt_sel:printf("1.12th wednesday\t2:40pm\tvega city mall\n2.14th friday\t9:00pm\torion mall\n3.16th sunday\t5:45pm\troyal mall\n");
                scanf("%d",&user_ddt);
                //movie="KGF CHAPTER 2"
                switch(user_ddt){
                    case 1: //date=12;day="wednesday";time=2.40;theatre="vega city mall";
                            strcpy(new->movie_name,"KGF CHAPTER 2");    new->date=12;   strcpy(new->day,"wednesday");   new->time=2.40; strcpy(new->place,"VEGA CITY MALL");
                            insert_rear(new);
                            break;
                    case 2: strcpy(new->movie_name,"KGF CHAPTER 2");    new->date=14;   strcpy(new->day,"friday");   new->time=9.00; strcpy(new->place,"ORION MALL");
                            insert_rear(new);
                            break;
                    case 3: strcpy(new->movie_name,"KGF CHAPTER 2");    new->date=16;   strcpy(new->day,"sunday");   new->time=5.45; strcpy(new->place,"ROYAL MALL");
                            insert_rear(new);
                            break;
                    default:printf("\ninvalid input\n");
                            goto ddt_sel;
                }
                break;
        case 2: ddt_sel:printf("1.11th TUESDAY\t8:40pm\tvega city mall\n2.13th THURSDAY\t3:00pm\torion mall\n3.15th SATURDAY\t6:45pm\troyal mall\n");
                scanf("%d",&user_ddt);
                //movie="BAHUBALLI REBORN"
                switch(user_ddt){
                    case 1: //date=12;day="wednesday";time=2.40;theatre="vega city mall";
                            strcpy(new->movie_name,"BAHUBALLI REBORN");    new->date=11;   strcpy(new->day,"TUESDAY");   new->time=8.40; strcpy(new->place,"VEGA CITY MALL");
                            insert_rear(new);
                            break;
                    case 2: strcpy(new->movie_name,"BAHUBALLI REBORN");    new->date=13;   strcpy(new->day,"THURSDAY");   new->time=3.00; strcpy(new->place,"ORION MALL");
                            insert_rear(new);
                            break;
                    case 3: strcpy(new->movie_name,"BAHUBALLI REBORN");    new->date=15;   strcpy(new->day,"SATURDAY");   new->time=6.45; strcpy(new->place,"ROYAL MALL");
                            insert_rear(new);
                            break;
                    default:printf("\ninvalid input\n");
                            goto ddt_sel;
                }
                break;
        case 3: ddt_sel:printf("1.17th MONDAY\t6:40pm\tvega city mall\n2.19th WEDNESDAY\t2:00pm\torion mall\n3.20th THURSDAY\t8:45pm\troyal mall\n");
                scanf("%d",&user_ddt);
                //movie="SPIDER MAN : AT HOME"
                switch(user_ddt){
                    case 1: //date=12;day="wednesday";time=2.40;theatre="vega city mall";
                            strcpy(new->movie_name,"SPIDER MAN : AT HOME");    new->date=17;   strcpy(new->day,"MONDAY");   new->time=2.40; strcpy(new->place,"VEGA CITY MALL");
                            insert_rear(new);
                            break;
                    case 2: strcpy(new->movie_name,"SPIDER MAN : AT HOME");    new->date=19;   strcpy(new->day,"WEDNESDAY");   new->time=2.40; strcpy(new->place,"ORION MALL");
                            insert_rear(new);
                            break;
                    case 3: strcpy(new->movie_name,"SPIDER MAN : AT HOME");    new->date=20;   strcpy(new->day,"FRIDAY");   new->time=2.40; strcpy(new->place,"ROYAL MALL");
                            insert_rear(new);
                            break;
                    default:printf("\ninvalid input\n");
                            goto ddt_sel;
                }
                break;
        default: printf("\ninvalid input\n");
                    goto display_movie;
    }
}
void edit_ticket(){}
void cancel_ticket(){}
void display_ticket(){}
int main(){
    int ch;node *new;
    printf("\n");
    printf("\t");
    printf("|\tMOVIE TICKET BOOKING SYSTEM\t|\n");
    display_menu();//displays the avaliable movies 
    //in "display" function, display the option to be typed 
    while(1){
        printf("waiting for your choice.....\t");
        scanf("%d",&ch);
        switch(ch){
            //when user hits back, use goto function and jump to display menu
            case 1: new=create();
                    book_ticket(new);
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
    }//while
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
struct Node{
     char foodname[20];
     int data,stock;
       float price;
       struct Node *next;
       int foodlist;
};
typedef struct Node node;
node *head, *menu;

        char problem_box[20];
        int credit_card[20];
        float total_poisa[20];
void print(char list[])
{
    printf("%s",list);
}
void line(int cnt)
{
    int i;
    for(i=1;i<=cnt;i++);
    printf("\n");
}
void tab(int cnt)
{
  int i;
    for(i=1;i<=cnt;i++);
    printf("\t");
}
void scr()
{
    system("cls");
}
void foodlist()
{
     line(10); tab(10);printf("1.food Menu                  ");line(2);
     line(10); tab(10);printf("2. Admin Log In              ");line(2);
     line(10); tab(10);printf("3.Rules & Reg                ");line(2);
     line(10); tab(10);printf("4.Problem & Suggestion       ");line(2);
     line(10); tab(10);printf("5.Exit                       ");line(2);
}

void insertfood(char foodname[20],int data,int stock,float price)
{
    node *temp;
    temp=(node*) malloc(sizeof(node));
    temp->data=data;
    temp->stock=stock;
    temp->price=price;
    strcpy(temp->foodname,foodname);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        menu=head;
    }
    else
    {
        while(head->next!=NULL)
        {
            head=head->next;
        }
        head->next=temp;
    }
}

void foodlist()
{
    node *start;
    start=menu;
    printf("--------------------------------------------------------\n");
    printf(" Item Number     |   Food name   |   price   |   Stock   \n");
    while(start!=NULL)
    {
        printf("------------------------------------------------------\n");
        line(30); tab(30);
        printf("%d   |   %s  |   %d  |   %.2f    \n",start->data,start->foodname,start->stock,start->price);Sleep(100);line(3);
        printf("-------------------------------------------------------\n");

    }
}

int count()
{
    int cnt=0;
    node *temp;
    temp=menu;
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;

}

int total_money(int foodchoice,int much)
{
    scr();
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp=menu;
    while(temp->data!=foodchoice)
    {
        temp=temp->next;
    }
        if(temp->data==foodchoice)
        {
            int o;
            float tota=temp->price*much;

             line(3); tab(2);printf("Total money for your order :");line(2);system("color 7C");
             line(3); tab(2);printf("%.2f",&total_money);line(2);
             line(10); tab(15);printf("your table number :");line(2);
             line(10); tab(50);scanf("%d",& o);line(2);
             //return total_money;
        }

}

void payment(float money)
{
    scr();
    back_option:

        line(10); tab(20);printf("how you pay this money :");line(2);system("color 0F");
        line(10); tab(20);printf("1. Cash");line(2);
        line(10); tab(20);printf("2. Credit Card");line(2);

        int choose;
        float taka;
        line(5); tab(2);scanf("%d",&choose);line(2);

        if(choose=='1')
        {
            scr();
            give :
            line(5); tab(5);printf("how much you give :");line(2);system("color 69");
            line(5); tab(5);scanf("%f",&taka);line(2);
            if(money>taka)
            {
                scr();
                line(10); tab(10);printf("Please give %.2f same also",money-taka);line(2);
                goto give;
            }
            else
            {
                scr();
                 line(10); tab(10);printf("You will get %.2f",taka-money);line(2);
            }
        }
        else if(choose =='2')
        {
            scr();
            int card_num[20],i=0;
             line(5); tab(5);printf("Please give your card number :");line(2);
             line(5); tab(5);scanf("%d",&card_num[i]);line(2);
             credit_card[i]=card_num[i];
             i++;

             scr();
             line(2); tab(2);printf("Please enter your password :");line(2);
             goto back_option;

        }
}

void orderlist()
{
    int foodchoice, much,i,j,k;
    food_choice :
         line(2);printf("Which product :");line(3);
         tab(2);scanf("%d",&foodchoice);
         i=count();

         if(foodchoice>=1 && foodchoice<=1)
         {
             line(2);tab(2);printf("hoe much you need :");
             tab(3);scanf("%d",&much);

             k=total_money(foodchoice,much);
             payment(k);
             //return k;
         }
         else
         {
             scr();
             line(2);tab(2);printf("Enter item number please :"); line(2);
             foodlist();
             goto food_choice;
         }



int main();
{
    int windows();

     line(2);tab(2);printf("******************************************"); line(2);
     line(2);tab(2);printf("               WELCOME                     "); line(2);
     line(2);tab(2);printf("                  TO                       "); line(2);
     line(2);tab(2);printf("             OYR RESTURANT                 "); line(2);
     line(2);tab(2);printf("******************************************"); line(2);
     main_menu:
         line(2);tab(2);printf("Enter your choice/MEDAM :"); line(4);
}
    foodlist();

         head=NULL;

         insertfood("Beef",1,50,150);
         insertfood("Chikn",2,45,50);
         insertfood("Shing",3,30,60);
         insertfood("Utkol",4,45,70);
         insertfood("gojal",5,430,80);

         int choos, foodstock,fooddata,backmenu;
         float foodprice;
         char choice,addfood[30];
         char problem[2000],problem_box[2000];
         line(2);tab(2);print("-->");
         scanf("%c",choice);

         if(choice>='1' && choice<='1')
            if(choice=='1')
         {
             food_list :
                 scr();
                  line(20);tab(20);printf("Enter your for choice :"); line(3);

                  foodlist();
                  orderlist();
                  line(10);tab(5);printf("Thank your choosing"); line(2);

                  another_food :
                      line(10);tab(5);printf("Are you want to bay another food"); line(2);
                      line(3);tab(2);printf("Prass 1 for main menu, 2 for foodlist or 0 for Exit =>");
                      tab(5);fflush(stdin);
                      scanf("%d",backmenu);
                      switch(backmenu)
                      {
                      case 1:
                            scr();
                            goto main_menu;
                            break;

                      case 2:
                            scr();
                            goto food_list;
                            break;

                      case 0:
                            scr();
                            line(10);tab(5);printf("*****Thank your*****"); line(2);
                            break;
                      default :
                            printf("Enter correct press :");
                            goto another_food;
                      }

         }
         else if(choice=='2')
         {
             scr();
             int pass;

             admin_log :
                 line(10);tab(5);printf("Enter 0 for go to the main menu");line(2);
                 line(10);printf("Enter the password"); line(4);
                 line(3);tab(2);fflush(stdin);
                 scanf("%d",&pass);

                 if(pass==3047)
                 {
                     choose_option:
                         scr();

                         line(5);tab(5);printf("1. Total money");line(2);
                         line(5);tab(5);printf("2. problem & suggestion");line(2);
                         line(5);tab(5);printf("3. Add food");line(2);
                         line(5);tab(5);printf("4. Delete food");line(2);
                         line(5);tab(5);printf("5. All Card number");line(2);
                         line(5);tab(5);printf("6. Total item");line(2);
                         line(5);tab(5);printf("Enter 0 for go to the main menu");line(2);
                         line(5);tab(5);
                         scanf("%d",&choice);
                         if(choice>=0 && choice<=7)
                         {
                             if(choice==1)
                             {
                                 scr();
                                 int k;
                                 line(5);tab(5);
                                 orderlist(k);
                                 scanf("%d",k);
                                 line(2);
                             }
                             else if(choice==3)
                             {
                                 scr();
                                 printf("Enter list number :");
                                 scanf("%d",fooddata);
                                 printf("Enter the Food name :");
                                 scanf("%s",addfood);
                                 printf("Enter food price:");
                                 scanf("%f",foodprice);
                                 print("Enter food stock :");
                                 scanf("%d",foodstock);
                                 line(5);tab(5);printf("Sorry... we work for improving this software : thank you");line(2);
                             }
                             else if(choice==4)
                             {
                                 scr();
                                 line(5);tab(5);printf("Sorry... we work for improving this software : thank you");line(2);
                             }
                             else if(choice==5)
                             {
                                 int k=0;
                                 scr();
                                     line(5);tab(5);printf("%d", credit_card[k]);line(2);
                                     k++;
                             }
                             else if(choice==0)
                             {
                                 int k=0;
                                 scr();
                                 goto main_menu;
                             }
                             else if(choice==6)
                             {
                                 scr();
                                 int total,k;
                                 total=count();
                                     line(20);tab(20);printf("Enter 0 for back\n");
                                     line(5);tab(5);fflush(stdin);
                                     scanf("%d",&k);
                                     if(k==0)
                                     {
                                         scr();
                                         goto choose_option;
                                     }
                                     else
                                     {
                                         scr();
                                         line(5);tab(5);printf("Please enter correot pass");line(2);
                                         goto admin_log;
                                     }
                             }
                         }
                         else
                         {
                            line(10);tab(5);printf("Enter between 1 and 7");
                            goto choose_option;
                         }
                 }
                         else
                         {
                             scr();
                             line(5);printf("Wrong Password....Please enter correot pass");line(5);
                             line(5);tab(5);printf("Enter 0 for go to the main menu");line(2);

                             if(pass==0)
                             {
                                 scr();
                                 goto main_menu;
                             }
                             else
                             {
                                 goto admin_log;
                             }
                         }


                 }
                 else if(choice=='3')
                 {
                     scr();
                     int rulrs;
                     rulrs_option:
                         line(5);tab(20);printf("****Rules and Reglution****");line(2);
                         line(5);tab(10);printf("1. hasib");line(5);Sleep(500);
                         line(5);tab(10);printf("2.");line(5);Sleep(500);
                         line(5);tab(10);printf("3.");line(5);Sleep(500);
                         line(5);tab(10);printf("4.");line(5);Sleep(500);
                         line(5);tab(10);printf("5.");line(5);Sleep(500);
                         line(5);tab(10);printf("6.");line(5);Sleep(500);
                         line(5);tab(20);printf("**** Keep smiling and enjoy your food****");line(5);
                         line(10);tab(10);printf("pass 0 for back :");
                         scanf("%d",rulrs);

                         if(rulrs==0)
                         {
                             scr();
                             fflush(stdin);
                             goto main_menu;
                         }
                         else
                         {
                             scr();
                             line(5);tab(5);printf("Enter correct pass");
                             goto rulrs_option;
                         }

                 }
                 else if(choice=='4')
                 {
                     scr();
                     int back,m=0;
                     line(10);tab(10);printf("***Please write your problem or suggestion***");line(5);
                     line(10);tab(5);fflush(stdin);
                     gets(problem);line(5);
                     //problem_box[m]=problem;
                     m++;

                     scr();
                     line(10);tab(10);printf("***Thank you***");line(5);

                     back_option:

                     line(10);tab(10);printf("--> 0 for back");
                     tab(3);
                     scanf("%d",&back);

                     if(back==0)
                     {
                         scr();
                         fflush(stdin);
                         goto main_menu;
                     }
                     else
                     {
                         scr();
                         line(10);tab(10);printf("***Thank you***");line(5);
                         goto back_option;
                     }
                 }
                 else if(choice=='5')
                 {
                     scr();
                     line(20);tab(3);printf("***Thank you");line(20);
                 }
                else if(choice>='a' && choice<='z')
         {
             scr();
             line(20);tab(3);printf("please, Enter a number between 1 and 5");line(3);
             goto main_menu;
         }
         else
         {
             scr();
             line(20);tab(3);printf("please, Enter a number between 1 and 5");line(3);
             goto main_menu;
         }
}


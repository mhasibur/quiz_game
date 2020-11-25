#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int username;
    struct node *next;
}
*head;
int main()
{
    int menu;

    while (1)
    {
        printf ("your option");
        printf ("\n1.Add\n2.print\n3.next\n4.Exit\n");
        scanf("%d",&menu);
        switch (menu)
        {
        case 1:
            break;

        case 2:
            break;

        case 3:
             exit(0);
             break;
             
        default:
            printf("ENTER A RIGHT VALUE\n");
            break;
        }
    }
}
